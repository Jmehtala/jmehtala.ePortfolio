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
#include <vector>
#include <time.h>

using namespace std;

const int TABLE_SIZE = 101;

struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites; 

    
    Course() : courseNumber(""), courseName("") {}

    Course(const string& num, const string& name, const vector<string>& prereqs)
        : courseNumber(num), courseName(name), prerequisites(prereqs) {
    }

    bool isEmpty() const {
        return courseNumber.empty();
    }
};

vector<Course> courseTable[TABLE_SIZE];

int hashFunction(const string& courseNumber) {
    int hash = 0;
    for (char c : courseNumber) {

        hash = (hash * 31 + c) % TABLE_SIZE;
    }
    return hash % TABLE_SIZE;
}


void printCourse(const Course& course) {

    if (course.isEmpty()) return;

    cout << "Course Number: " << course.courseNumber << endl;
    cout << "Course Name: " << course.courseName << endl;

    if (!course.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            cout << course.prerequisites[i];
            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else {
        cout << "No Prerequisites." << endl;
    }
    cout << endl;
}

void loadCourses(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: File cannot be opened" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r\f\v"));
            token.erase(token.find_last_not_of(" \t\n\r\f\v") + 1);
            tokens.push_back(token);
        }

        if (tokens.size() >= 2) {
            string courseNumber = tokens[0];
            string courseName = tokens[1];
            vector<string> prerequisites;

            for (size_t i = 2; i < tokens.size(); ++i) {
                if (!tokens[i].empty()) {
                    prerequisites.push_back(tokens[i]);
                }
            }

            Course course(courseNumber, courseName, prerequisites);

            int hashIndex = hashFunction(courseNumber);

            courseTable[hashIndex].push_back(course);
        }
        else {
            cout << "Warning: Skipping line with fewer than 2 parameters: " << line << endl;
        }
    }

    file.close();
    cout << "Course data loaded successfully." << endl;
}

void displayCourses() {
    vector<Course> allCourses;

    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (const auto& course : courseTable[i]) {
            if (!course.isEmpty()) {
                allCourses.push_back(course);
            }
        }
    }

    sort(allCourses.begin(), allCourses.end(),
        [](const Course& a, const Course& b) {
            return a.courseNumber < b.courseNumber;
        });

    cout << "\n--- All Courses in Alphanumeric Order ---\n" << endl;
    for (const auto& course : allCourses) {
        printCourse(course);
    }
}

void findCourse(const string& courseNumber) {
    int hashIndex = hashFunction(courseNumber);
    const vector<Course>& chain = courseTable[hashIndex];

    for (const auto& course : chain) {
        if (course.courseNumber == courseNumber) {
            cout << "\n--- Course Found ---\n" << endl;
            printCourse(course);
            return; 
        }
    }

    cout << "Course " << courseNumber << " not found." << endl;
}

clock_t ticks;

void printMenu() {
    cout << "---------------------------------------" << endl;
    cout << "Welcome to the ABCU Course Advising Program" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Load Data Structure" << endl;
    cout << "2. Print Course List" << endl;
    cout << "3. Print Course" << endl;
    cout << "9. Exit" << endl;
}

int main() {
    int choice = 0;

    for (int i = 0; i < TABLE_SIZE; ++i) {
        courseTable[i] = vector<Course>();
    }

    while (choice != 9) {
        printMenu();
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from the menu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            ticks = clock();
            string fileName = "CS 300 ABCU_Advising_Program_Input.csv";
            loadCourses(fileName);

            ticks = clock() - ticks;
            cout << "Operation time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;
        }
        case 2: {
            displayCourses();
            break;
        }
        case 3: {
            string courseNumber;
            cout << "Enter course number: ";
            cin >> courseNumber;

            ticks = clock();
            findCourse(courseNumber);

            ticks = clock() - ticks;
            cout << "Operation time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;
        }
        case 9: {
            cout << "Thank you for using the ABCU Advising Program. Goodbye!" << endl;
            break;
        }
        default: {
            cout << "Invalid option. Please choose a number from the menu." << endl;
            break;
        }
        }
    }

    return 0;
}