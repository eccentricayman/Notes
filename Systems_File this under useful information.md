# Systems::File this under useful information

DN: What are the different kinds of file permissions?

  


File permissions

  


     3 types of permissions

          read, write, execute

  


     Permissions can be represented as 3-digit binary numbers,

     or 1-digit octal numbers

  


          100 &lt;==&gt; 4 -&gt; read only

          111 &lt;==&gt; 7 -&gt; read, write, execute

  


     There are 3 permission "areas"

          user, group, others

  


          each area can have its own permissions

  


          644 = user: read + write, group: read, other: read

  


File Table

     A list of all files used by a program while it is running.

         

     Contains basic information like the file’s location and size.

  


     The file table has a limited size, which is a power of 2 and commonly 256. getdtablesize() will return this value.

  


     Each file is given an integer index, starting a 0, this is referred to as the file descriptor

  


     There are 3 files always open in the table:

          0 or STDIN_FILENO: stdin

          1 or STDOUT_FILENO: stdout

          2 or STDERR_FILENO: stderr
