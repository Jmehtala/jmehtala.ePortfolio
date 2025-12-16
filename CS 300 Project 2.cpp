//============================================================================
// Name        : CS 300 Project 2.cpp
// Author      : Jared Mehtala
// Description : CS 300 Project 2 Submission
//============================================================================


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <time.h>

using namespace std;
//Set max number of courses
const int TABLE_SIZE = 100;

//Course struct
struct Course {
    string courseNumber;
    string courseName;
    string prerequisites[10];
    int prerequisiteCount;
    Course() : prerequisiteCount(0) {}
};

//Hash table to store courses
Course courseTable[TABLE_SIZE];

//Function to map course #'s to indices (increase efficiency for lookup times)
int hashFunction(const string& courseNumber) {
    int hash = 0;
    for (char c : courseNumber) {
        hash += c;
    }
    return hash % TABLE_SIZE;
}

//Create course object
Course createCourse(const string& courseNumber, const string& courseName, string prerequisites[], int prerequisiteCount) {
    Course course;
    course.courseNumber = courseNumber;
    course.courseName = courseName;
    course.prerequisiteCount = prerequisiteCount;
    for (int i = 0; i < prerequisiteCount; ++i) {
        course.prerequisites[i] = prerequisites[i];
    }
    return course;
}

//Print course information
void printCourse(const Course& course) {
    cout << "Course Number: " << course.courseNumber << endl;
    cout << "Course Name: " << course.courseName << endl;
    if (course.prerequisiteCount > 0) {
        cout << "Prerequisites: ";
        for (int i = 0; i < course.prerequisiteCount; ++i) {
            cout << course.prerequisites[i];
            if (i < course.prerequisiteCount - 1)
                cout << ", ";
        }
        cout << endl;
    }
    else {
        cout << "No Prerequisites." << endl;
    }
    cout << endl;
}

//Open, read, and load information from file
void loadCourses(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: File cannot be opened" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);  //Parsing
        string courseNumber, courseName;
        string prerequisites[10];  //Array to hold prerequisites
        int prerequisiteCount = 0;

        //Read course number and name
        if (getline(ss, courseNumber, ',') && getline(ss, courseName, ',')) {
            //Read prerequisites
            while (getline(ss, prerequisites[prerequisiteCount], ',') && prerequisiteCount < 10) {
                prerequisiteCount++;
            }

            //Create the course object
            Course course = createCourse(courseNumber, courseName, prerequisites, prerequisiteCount);

            //Store the course in the hash table
            int hashIndex = hashFunction(courseNumber);
            courseTable[hashIndex] = course;
        }
        else {
            cout << "Error: Line has fewer than 2 parameters" << endl;
        }
    }

    file.close();
}

//Function to display all courses in the hash table
void displayCourses() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (!courseTable[i].courseNumber.empty()) {
            printCourse(courseTable[i]);
        }
    }
}

//Function to search for a course by course number
void findCourse(const string& courseNumber) {
    int hashIndex = hashFunction(courseNumber);
    if (courseTable[hashIndex].courseNumber == courseNumber) {
        printCourse(courseTable[hashIndex]);
    }
    else {
        cout << "Course " << courseNumber << " not found." << endl;
    }
}
//Timer variable
clock_t ticks; 

//Menu function
void printMenu() {
    cout << "1. Load Courses" << endl;
    cout << "2. Display All Courses" << endl;
    cout << "3. Find Course" << endl;
    cout << "9. Exit" << endl;
}

int main() {
    int choice = 0;

    while (choice != 9) {
        printMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            //Initialize time variable before loading bids
            ticks = clock();
            //Load courses from file
            string fileName = "CS 300 ABCU_Advising_Program_Input.csv";

            loadCourses(fileName);

            //Calculate elapsed time and display result
            ticks = clock() - ticks; //Current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
        }
        else if (choice == 2) {
            //Display all courses
            displayCourses();
        }
        else if (choice == 3) {
            //Find a specific course by number
            string courseNumber;
            cout << "Enter course number: ";
            cin >> courseNumber;

            //Hash the course number to find the course in the table
            int hashIndex = hashFunction(courseNumber);

            //Check if the course exists 
            if (courseTable[hashIndex].courseNumber == courseNumber) {
                //If the course is found print all information
                Course course = courseTable[hashIndex];
                cout << "Course Number: " << course.courseNumber << endl;
                cout << "Course Name: " << course.courseName << endl;

                //Prereq Check
                if (course.prerequisiteCount > 0) {
                    cout << "Prerequisites: ";
                    for (int i = 0; i < course.prerequisiteCount; ++i) {
                        cout << course.prerequisites[i];
                        if (i < course.prerequisiteCount - 1)
                            cout << ", ";
                    }
                    cout << endl;
                }
                else {
                    cout << "No prerequisites found." << endl;
                }
            }
            else {
                //If course is not found display an error message
                cout << "Course " << courseNumber << " not found." << endl;
            }
            
            ticks = clock() - ticks; //Current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
        }
        else if (choice == 9) {
            cout << "Have a good day! Goodbye." << endl;
        }
        else {
            cout << "Invalid input. Try again." << endl;
        }
    }

    return 0;
}

