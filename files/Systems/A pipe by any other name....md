# Systems::A pipe by any other name...

Named Pipes

    Also known as FIFOs.  


  


    Same as unnamed pipes except FIFOs have a name that can be used to identify them via different programs.  


  


    Like unnamed pipes, FIFOs are unidirectional.  


  


    mkfifo  


        Shell command to make a FIFO  


  


    $ mkfifo &lt;pipe name&gt;  


  


    mkfifo - &lt;sys/types.h&gt; &lt;sys/stat.h&gt;  


  


        C function to create a FIFO  


  


        Returns 0 on success and -1 on failure  


  


        Once created, the FIFO acts like a regular file, and we can use open, read, write, and close on it.  


        


    mkfifo( &lt;name&gt;, &lt;permissions&gt; )  


  


        FIFOs will block on open until both ends of the pipe have a connection.  
  


  

