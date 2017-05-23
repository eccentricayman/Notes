# SoftDev::Sqlite, the low-fat alternative to SQL

python sqlite module

     import sqlite3

  


     connect

          Open/create an sqlite database.

  


          If the database does not exist, create it.

  


          db = sqlite3.connect(&lt;db name&gt;)

  


     cursor

          Create a database cursor object that will allow you to perform operations of the database

  


     execute

          Cursor method to perform the provided SQL operation, given as a string.

  


          c.execute(&lt;SQL statement&gt;)

  


     commit

          Database method to save changes to the db

  


          db.commit()

    

     db.close()

  


python protip format strings:

     "(" \+ x + ", " \+ y + ") is a point"

     "(%d, %d) is a point”%(x, y)

  


SQL SELECT statement

     

     Used to get data from a database

  


     Creates a results table based on the query

  


     SELECT &lt;column 1&gt;, … FROM &lt;table 1&gt;, …;

  


     SELECT name FROM students;
