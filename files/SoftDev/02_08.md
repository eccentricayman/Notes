# Aim: upDAT(A)img mongo

### Modifying data

- ```.delete_one(<QUERY>)```
  - Deletes the first document that matches the query
- ```.delete_many(<QUERY>)```
  - Deletes all the documents that match the query
- ```.update(<QUERY>, <OPERATION>)```
  - Updates  a document that matches the query
  - Operation is a document that matches an update operation:
    - ```'$set'```
      - Changes the value of a field.
    - ```'$unset'```
      - Remove a field.
    - ```'$inc'```
      - Increment the value of a field.
      - It has to use numbers.

