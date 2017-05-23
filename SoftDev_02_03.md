# Mongo likes py

### Working with pymongo

```python
from pymongo import MongoCLient
```

Connecting to a mongoDB server and database

```python
server = MongoClient(<IP>)
```

To access databases, collections and documents, you can use either [] or .

```python
db = server['mydb']
db = server.mydb

c = db['students'] #db.students
```

Databases and collections are not created until a document has been added to them!



### To add a document

1. Create a dictionary

2. Insert it into the collection

   ```python
   doc = { 'name': 'bob', 'age': 65 }
   c.insert_one( doc )
   ```

   ​