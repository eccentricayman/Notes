# Systems::Opening up a world of possibilites

DN:

0) open/close

1) read/write

  


open - &lt;fcnctl.h&gt;

     Add a file to the file table and returns its file descriptor

  


     If open fails, -1 is returned, extra error information can be found in errno.

  


     

          errno is an int variable that can be found in &lt;errno.h&gt;, using strerror (in string.h) on errno will return a string descriptor    

          of the error

  


     open( &lt;PATH&gt;, &lt;FLAGS&gt;, &gt;MODE&gt;)

  


     mode

          Only used when creating a file. Set the new file’s permissions using a 3 digit octal #

  


          Octal #s have a leading 0

               0644, 0777...

  


     All open close read write are in &lt;unistd.h&gt;

  


flags

     Determine what you plan to do with the file.

     

     4 read 2 write 1 exec

  


     Use the following constants:

          O_RDONLY

          O_WRONLY

          O_RDWR

          O_APPEND

          O_TRUNC

          O_CREAT

          O_EXCL: when combined with O_CREAT, will return an error if the file exists

  


     Each flag is a number, to combine flags we use bitwise or 

  


          O_WRONLY =  1              = 00000001

          O_APPEND = 8                = 00001000

          O_WRONLY | O_APPEND = 00001001

  


close - &lt;unistd.h&gt;

     Remove a file from the filetable.

  


     Returns 0 if successful. Returns -1 and does shit to errno if unsuccessful.
