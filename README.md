**CS499 Milestone Four**

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
