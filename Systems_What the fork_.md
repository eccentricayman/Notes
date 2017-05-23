# Systems::What the fork?

fork() - &lt;unistd.h&gt;

    Creates a separate process based on the current one, the new process called the child, the original is the parent.  


  


    The child process is a duplicate of the parent process. All parts of the parent process are copied, including stack and heap 

    memory, and the file table.  


  


    Returns 0 to the child and the child’s pid to the parent or -1 (errno).  


  


    If a parent process ends before the child, the child’s new parent pid is 1.  


  

