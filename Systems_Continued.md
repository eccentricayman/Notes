# Systems::Continued

From [Systems::FileStream](evernote:///view/2147483647/s466/f99275c2-e6b2-4d17-9d1e-a380d5d448f9/f99275c2-e6b2-4d17-9d1e-a380d5d448f9/)

  


fgets - &lt;stdio.h&gt;

  


    Reads in from a file stream and stores it in a string  


      


fgets(&lt;DESTINATION&gt;, &lt;BYTES&gt;, &lt;FILE POINTER&gt;);

fgets(S, N, F);

  


    Reads at most N - 1 characters from file stream F and stores it in S.  


  


File pointer

  


    FILE * type, more complex than a file descriptor  


  


    stdin is a FILE * variable  


  


    Fget stops at newline, end of file, or reaches the byte limit.  


      


    If applicable, keeps the newline character as part of the string, appends NULL after  


  

