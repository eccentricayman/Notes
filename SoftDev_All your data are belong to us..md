# SoftDev::All your data are belong to us.

Relational database

     

     Database that stores information as a collection of tables.

  


     Field: Column data in a RDB

  


     Record: Row in a RDB

  


     Data can be linked between tables based on field values.

  


SQL (Structured Query Language)

  


     Standard language designed to work with relational databases.

  


     Is used for many major db programs, though the implementations may not (mostly are not) compatible.

  


     MySQL, PostgreSQL, SQLite, Oracale are different SQL implementations.

  


SQLite

  


     SQL implementation that relies entirely on function calls in the parent program. There is no database server.

  


     All database information is stored in a single file.

  


     Data is dynamically typed as values are inserted into a table.

  


Basic SQLite Operations

     

     CREATE TABLE

          

          Add a table to a database

  


          CREATE TABLE &lt;name&gt; (&lt;column name&gt; &lt;data type&gt;, …)

  


               The data type will help to convert entered values to a suggested type.

  


               TEXT, INTEGER, REAL, NUMERIC, BLOB

  


               NUMERIC will default to an integer, but can be a floating point.

     

               BLOB means no suggested type.

         

          Columns can be given a PRIMARY KEY attribute, denoting that every entry in that column is unique and cannot be NULL.

  


          Columns can be given a NOT NULL attribute, denoting that no entry can be null.

  


          INSERT INTO

          

               Insert a record into a table.

  


                    Will add a record to a table matching the values to the columns in order.

  


                    NULL can be used in any entry.

  


          SELECT * FROM &lt;name&gt;;

               Show all entries in a table

  


          SQLite Shell commands

               .quit

               .tables

               .header on|off

               .mode column|csv|list|html|insert|line|tabs
