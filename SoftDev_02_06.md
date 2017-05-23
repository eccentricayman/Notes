# Aim: Where'd mongo put that data?

### Retrieving data from mongoDB

- .find()
  - Collection method that returns a cursor object that can be used to iterate through all the documents in a collection.

- .find_one()

  - Collection method that returns a single document as a dictionary.

- Querying in mongoDB

  - Queries in pymongo are formatted as documents

  - ```python
    foo.find( {'age' : 25 } )
    ```

  - Search criteria can be modified using '$and', '$or', and '$not'

  - ```python
    foo.find_one( {
      '$and' : [
        { 'name' : 'bob' },
        { 'age' : 25 }
      ]
    })
    ```

  - Using inequalities in searches

  - $gt, $lt, $gte, $lte, $ne

  - ```python
    foo.find( {
      'age' : { '$gte' : 21 }
    } )
    ```