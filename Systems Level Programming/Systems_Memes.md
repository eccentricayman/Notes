# Systems::Memes

More Shared Memory

  


    shmdt  


  


        Detach a variable from a shared memory segment.  


  


        Returns 0 upon success or -1 upon failure.

  


    shmdt( pointer );  


  


        pointer  


            The address used to access the segment  


  


shmctl

  


    Perform operations on the shared memory segment  


  


    Reach shared memory segment has metadata that can be stored in a struct (struct shmid_ds)  


  


    Some of the data stored: last access, size, pid of creator, pid of last modification  


  


    shmctl( descriptor, command, buffer );  


  


        descriptor  


            Return value of shmget  


  


        commands:  


            IPC_RMID: Remove a shared memory segment, buffer arg can be 0  


  


            IPC_STAT: Populate the buffer (struct shmid_ds) with information  


  


            IPC_SE: Set some of the information for the segment to the info in buffer  


  


ftok - &lt;sys/ipc.h&gt;

  


    Generate a key useful for IPC functions

  

    ftok( path, x );  


  


        path  


            A path to some file, the file must be accessible by the program.  


          


        x  


            An int used to generate the key  


  


        The same path and x will always generate the same key  


  


    sd = shmget( ftok( “dir/file”, 12 ), 1024, IPC_CREAT | 0664 );  


  
  


  

