# Systems::Redirection; how does it ... SQUIRREL

File Redirection

  


    Changing the usual input/output behavior of a program  


  


    Command line redirection  


        &gt;  


            Redirects stdout to a file  


              


            Overwrites the contents of the file  


  


        &lt;COMMAND&gt; &gt; &lt;FILE&gt;  


        ls &gt; filelist.txt  


  


        &gt;&gt;  


            Redirects stdout to a file by appending  


  


        2&gt;  


            Redirects stderr to a file  


  


            Overwrites the file (2&gt;&gt; appends)  


  


        &amp;&gt;  


            Redirect stdout and stderr  


  


        &lt;  


            Redirects stdin from a file  


  


        |  


            Pipe redirects the stdout from one command to stdin of the next  


  


Redirection in c programs

  


    dup2 - &lt;unistd.h&gt;  


  


    dup2(fd1, fd2);      


        

        Duplicates the behavior for fd1 at fd2

  


        Redirects fd2 to fd1  
  


        You will lose any reference to the original fd2, that file is closed.  


  


    dup - &lt;unistd.h&gt;  


  


        Duplicates an existing entry in the file table.  


  


        Returns a new file descriptor for the duplicate entry.  


  

