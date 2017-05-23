# Systems::Read your writes!

DO NOT SUBMIT EXECUTABLE FILES

INCLUDE A MAKEFILE FOR EVERY ASSIGNMENT

DO NOT AUTOMATICALLY CALL RUN IN YOUR MAKEFILE

  


umask - &lt;sys/stat.h&gt;

  


     Set the file creator permission mask

     

     By default, created files are not given the exact permissions provided in the mode argument to open. Some permissions are     

     automatically shut off.

  


     Umask is applied by using bitwise negation on the mask, then bitwise and-ing it to the mode.

  


          new_permissions = ~mask &amp; mode

  


     The default mask is 0022.

  


     umask( &lt;MASK&gt; );

          You can define the mask as a 3 digit octal number.

  


read - &lt;unistd.h&gt;

     Read in data from a file

  


     read( &lt;FILE DESCRIPTOR&gt;, &lt;BUFFER&gt;, &lt;AMOUNT&gt; );

  


     read (df, buff, n);

  


     Read n bytes from the fd’s file and put that data into buff

  


     Returns the number of bytes actually read. Returns -1 and sets errno if unsuccessful.

  


     BUFFER must be a pointer.

  


write - &lt;unistd.h&gt;

     Write data to a file

  


     write( &lt;FILE DESCRIPTOR&gt;, &lt;BUFFER&gt;, &lt;AMOUNT&gt; );

  


     write (fd, buff, n)

  


     Write n bytes from buff into fd’s file

  


     Returns the number of bytes actually written. Returns -1 and sets errno if unsuccessful.

  


     BUFFER must be a pointer.
