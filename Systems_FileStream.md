# Systems::FileStream

getcwd - &lt;unistd.h&gt;

  


    Gets the current working directory (cwd) of a program  


  


      


getcwd(&lt;STRING BUFFER&gt;, &lt;SIZE&gt;);

  


    Copies the path to the cwd into the buffer argument (char *)

  


    Copies at most size characters of the path.

  


chdir - &lt;unistd.h&gt;

  


    Change the working directory of a program

      


chdir(&lt;PATH&gt;);

    

    Returns 0 if successful , -1 (errno) if not.

  


    Keep track of file path

  


Command Line Arguments:

      


int main( int argc, char *argv[])

    

    program name is considered the first command line argument

  


    argc

        Number of command line arguments

  


    argv

        Array of command line arguments

  


scanf - &lt;stdio.h&gt;

      


scanf( &lt;FORMAT STRING&gt;, &lt;VAR!&gt;, &lt;VAR 2&gt; …);

  


    Reads in data from stdin using the format string to determine types.  


  


    Puts the data in each variable.  


  


    Variables must be pointers.  


  


      


  

