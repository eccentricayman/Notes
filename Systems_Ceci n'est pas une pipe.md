# Systems::Ceci n'est pas une pipe

(This is not a pipe; this is a picture of a pipe)

  


ex:

     struct stat sb;

     stat( "story.txt", &amp;sb );

     int size = sb.st_size;

     char * s = (char*) malloc(size);

     int fd = open( "story.txt.", ...  

  


Pipe

     A conduit between 2 separate processes. (Not a network direction)

     Pipes have 2 ends, a read end and a write end.

     Pipes are unidirectional (a single pipe must be either read or write only in a process)

  


     You can transfer any data you like through a pipe using read/write

  


     Unnamed pipes have no external identification (pipes act like files)

          - limited to child-parent situations (childs inherit)

  


pipe - &lt;unistd.h&gt;

     Create an unnamed pipe

  


     Returns 0 if the pipe was created, -1 if not

  


     Opens both ends of the pipe as files.

  


pipe( int descriptrors[2] )

         descriptors

             Array that will contain the descriptors for each end of the pipe.  


  


  


ex:

          int fds[2];

          char s[20];

  


          pipe( fds );

  


          int fork();

          if( f = 0 ) {

              close( fd[1] );

              read( fds[0], s, sizeof(s) );

              printf( "[child] recieved: %s\n", s );

          }

          else {

               close( fd[0] );

               sleep(3);

               write( fds[1], "hello child", 12 );

          }  


  

