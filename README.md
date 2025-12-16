**CS499 Milestone 2** 

[Milestone 2 Files](https://github.com/Jmehtala/jmehtala.ePortfolio/tree/Jmehtala-Milestone-2)

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
