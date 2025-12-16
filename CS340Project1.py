#!/usr/bin/env python
# coding: utf-8

# In[4]:


from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self):
        # Initializing the MongoClient. This helps to 
        # access the MongoDB databases and collections.
        # This is hard-wired to use the aac database, the 
        # animals collection, and the aac user.
        # Definitions of the connection string variables are
        # unique to the individual Apporto environment.
        #
        # You must edit the connection variables below to reflect
        # your own instance of MongoDB!
        #
        # Connection Variables
        #
        USER = 'aacuser'
        PASS = 'Jared1234'
        HOST = 'nv-desktop-services.apporto.com'
        PORT = 34891
        DB = 'AAC'
        COL = 'animals'
        #
        # Initialize Connection
        #
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
        self.database = self.client['%s' % (DB)]
        self.collection = self.database['%s' % (COL)]

# Complete this create method to implement the C in CRUD.
    def create(self, data):
        try:
            result = self.collection.insert_one(data)
            return True if result.inserted_id else False
        except Exception as e:
            print(f"Error inserting data: {e}")
            return False

# Create method to implement the R in CRUD.
    def read(self,query):
        try:
            cursor = self.collection.find(query)
            return list(cursor)
        except Exception as e:
            print(f"Error querying documents: {e}")
            return []
    
# Create method to implement the U in CRUD.
    def update(self, query, new_data):
        try: 
            result = self.collection.update_many(query, {'$set' : new_data})
            return result.modified_count
        except Exception as e:
            print(f"Error Occured: {e}")
            return 0
        
# Create method to implement the D in CRUD.
    def delete(self, query):
        try:
            result = self.collection.delete_many(query)
            return result.deleted_count
        except Exception as e:
            print(f"Error Occured: {e}")
            return 0


# In[8]:


shelter = AnimalShelter()

test_animal = {"name": "Buddy",
               "animal_id":"A100000",
               "animal_type": "Dog",
               "breed": "Beagle","age": 
               "4","gender": "Male",
               "color": "Tri-color"
              }

# Create Method
print(" CREATE ")
insert_success = shelter.create(test_animal)
print("Create Result:", "Success" if insert_success else "Failed")

# Read Method
print("\n READ ")
read_result = shelter.read({"animal_id":"A100000"})
print("Read Result:")
for doc in read_result:
    print(doc)

# Update Method 
print("\n UPDATE ")
update_query = {"animal_id":"A100000"}
update_data = {"age": "5"}
update_count = shelter.update(update_query, update_data)
print(f"Documents Updated: {update_count}")

#Verify Update
print("\nUpdated Document:")
updated_result = shelter.read(update_query)
for doc in updated_result:
    print(doc)

# Delete Method
print("\n DELETE ")
delete_count = shelter.delete(update_query)
print(f"Documents Deleted: {delete_count}")

# Verify Deletion
print("\nPost-Delete Read:")
post_delete_result = shelter.read(update_query)
if not post_delete_result:
    print("No documents found. Deletion confirmed.")
else:
    for doc in post_delete_result:
        print(doc)


# In[ ]:




