# Systems::Seek and ye shall find

DN: Prepare 4 demo

  


lseek - &lt;unistd.h&gt;

  


     Set the current position in an open file

  


lseek( &lt;FILE DESCRIPTOR&gt;, &lt;OFFSET&gt;, &lt;WHENCE&gt; );

  


     offset

          Number of bytes to move the position by.

          Can be negative.

  


     whence

          Where to measure the offset from

  


          SEEK_SET

               offset is evaluated from the beginning of the file

  


          SEEK_CUR

               offset is relative to the current position

  


          SEEK_END

               offset is evaluated from the end of the file

  


     returns the number of bytes the current position is from

     the beginning of the file, or -1 (errno)
