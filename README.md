# ePortfolio

**Artifact 1: Animal Shelter Dashboard (CS340):**

This artifact strongly demonstrates full-stack development and database management proficiency, particularly using the MERN-like stack components 
(MongoDB, Python/Dash for backend/frontend).

**Artifact 2: Investment Calculator (CS210):**

This project showcases a foundational understanding of programming principles, 
with recent enhancements focusing on code stability and user experience improvements, reflecting significant growth since the artifact's original creation.

**Artifact 3: Course Prerequisite System (CS300)**

This artifact demonstrates strong growth in managing complex data structures and algorithms, which are crucial for performance and scalability in software design.

______________________________________________________________________________________________________________________________________________________________________


**CS499 ePortfolio Narratives**

**CS499 Milestone 2** 

https://github.com/Jmehtala/jmehtala.ePortfolio/tree/Jmehtala-Milestone-2

1)	Briefly describe the artifact. What is it? When was it created?

This artifact is from CS340 and it is a dashboard to search through all of the different animals in shelters by using certain filters and graphics.

2)	Justify the inclusion of the artifact in your ePortfolio. Why did you select this item?

I selected this item because I thought it would give a full in depth look at my full stack development skills.

3) What specific components of the artifact showcase your skills and abilities in software development? 

The first skill I wanted to show off was full stack integration by connecting a MongoDB database to a Python based dashboard which shows the ability to manage both back and front-end skills. The second skill was displaying my CRUD knowledge by implementing Create, Read, Update, and Delete operations within the AnimalShelter class.
Lastly, I wanted to show off skills relating to visualization and user experience through using interactive dashboard components and interactive maps.

5)	How was the artifact improved?

The artifact was improved through a few key enhancements:
Migrating from JupyterDash to Standard Dash which makes the project usable outside of Jupyter (which has deprecated) and allows it to run as a standalone application. 
I also refactored portions of the code like the callbacks and modularized the database interactions to increase the level of organization and readability. 

6)	Did you meet the course outcomes you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?

Yes and no; Yes because I successfully migrated from JupyterDash to just Dash which was my main plan, but I was unable to implement some of the visual upgrades I wanted to do. I will continue to work on this as the class goes on and will finish those enhancements before it is over.

7)	Reflect on the process of enhancing and modifying the artifact. What did you learn as you were creating it and improving it? What challenges did you face?

The main challenge I faced was getting a MongoDB database hosted locally while trying to migrate everything to Dash. The original project was made in a VM on the SNHU site which came with Mongo Client integrated with specific ports and needed specific code to access it.
In the enhancement, I had to find a port and install brand new modules that would allow me to host MongoDB locally and run the code. 

**CS499 Milestone 3** 

https://github.com/Jmehtala/jmehtala.ePortfolio/tree/Jmehtala-Milestone-3 

https://github.com/Jmehtala/jmehtala.ePortfolio/tree/Jmehtala-Milestone-3-Enhancements

1)	Briefly describe the artifact. What is it? When was it created?

This artifact is from CS210 and it is an investment calculator that takes in initial investment, monthly investment, interest, and how long the investment is.

2)	Justify the inclusion of the artifact in your ePortfolio. Why did you select this item?

I selected this item because it was one of the first projects I put together in my degree and wanted to make some updates to it.

3)	What specific components of the artifact showcase your skills and abilities in software development? 

I wanted to show how my foundation had grown over the past couple years. More specifically around user input validation and code organization.

4)	How was the artifact improved?

The artifact was improved through a few key enhancements:

(a)	Fixed issue with the investment calculations not properly calculating the yearly growth with monthly investments.

(b)	Added a pause function that users can press to pause and come back.

(c)	Cleaned up code and used better coding methods.

5)	Did you meet the course outcomes you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?

I think I met the outcomes for this enhancement, I want to add charts and better displays to this project in the future to take it that extra step.

7)	Reflect on the process of enhancing and modifying the artifact. What did you learn as you were creating it and improving it? What challenges did you face?

Biggest challenge I faced was getting the Visual Studio code to function properly on the  2026 version as the original code was written on the 2019 version which I had installed at the time of creation.
A few methods were out of date and insecure and it took a little while to get everything up to par with modern security and coding standards.

**CS499 Milestone Four**

https://github.com/Jmehtala/jmehtala.ePortfolio/tree/Jmehtala-Milestone-4

1)	Briefly describe the artifact. What is it? When was it created?

The artifact is the final project from CS300 and it involved creating a project that read data from a file and allowed users to navigate through a menu to choose their courses and find the prerequisites.

2)	Why did you select this item? What specific components of the artifact showcase your skills and abilities in software development? How was the artifact improved?

I selected this item because it was the earliest form of data structure handling I did while at SNHU. I made a few improvements to this artifact:

i)	Defining Data Structures: First, I changed the course prerequisites to use std::vector<string> instead of the original fixed size array which makes the structure more flexible for future additions. Then I added an isEmpty() method to the course struct to check if a slot in the table/course object is valid.

ii)	Hash Storage: The hash table had some collision issues so I declared it as vector<Course> courseTable[TABLE_SIZE] which gets rid of the issue of storing one course per index by having each index store a std::vector of courses. Now, if two courses have the same index, the new course is added to the end of the vector.

iii)	Display: The display didn’t need that much updating, all I did was order the courses in alphanumeric order via course number using a lambda function to sort them.

3)	Did you meet the course outcomes you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?

Yes, I updated the overall data structure and hash storage which was my main goal. I could create a bigger list with more courses or link it directly to the SNHU site and get the courses from there to make it an actual usable application.

4)	Reflect on the process of enhancing and modifying the artifact. What did you learn as you were creating it and improving it? What challenges did you face?

I learned that working with vectors and hashes is a lot simpler than I remember, back when I was first taking CS300 I would struggle with understanding how the code flows but now it all makes sense. 
