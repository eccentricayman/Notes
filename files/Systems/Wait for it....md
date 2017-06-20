# Systems::Wait for it...

But what about threads you ask?

  


    A quick note on threads: A thread is a separate executable entity similar to a child process, except a thread is not a     

    standalone process.  


  


    It does not have its own memory space, instead it shares its parent’s memory.  


  


    wait - &lt;unistd.h&gt;  


  


        Stops a parent process from running until any child has provided status information to the parent via a signal. (usually the 

        child has exited).  


  


        Returns the pid of the child that exited, or -1 (errno).  


  

