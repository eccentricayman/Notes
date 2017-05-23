# Systems::Sharing is caring!

DN: C program for child process and have parent wait for child to exit. Primitive variable in parent before forking, then modify that variable in child and print it out in both child and parent.

  


Shared Memory - &lt;sys/shm.h&gt;, &lt;sys/ipc.h&gt;, &lt;sys/types.h&gt;

  


shm = shared memory

ipc = interprocess communication

  


    A segment of heap memory that can be accessed by multiple processes.  


  


    Shared memory is accessed via some key that is known by any process that needs to access it.  


      


    Shared memory does not get released when a program exits.  


  


    5 Shared memory operations:  


  


        Create the segment (happens once)  


        Access the segment (happens once per process)  


        Attach the segment to a variable (once per process)

        Detach the segment from a variable (once per process)  


        Remove the segment (happens once)  


  


shmget

    Create or access a shared memory segment.  


  


    Returns a shared memory descriptor (similar idea to a file descriptor), or -1 if it fails.  


  


    shmget ( key, size, flags );  


  


        key  


            Unique integer identifier for the shared memory segment (like a file name).  


  


        size  


            How much memory to request  


  


        flags  


            Include permissions for the segment.  


  


            Combine with bitwise or  


  


            IPC_CREAT: Create the segment  


                If segment is new, will set value to all 0s

  


            IPC_EXCL: Fail if the segment already exists and IPC_CREAT is on  


  


shmat

    Attach a shared memory segment to a variable.  


  


    Returns a pointer to the segment, or -1 (errno).  


    


    shmat( descriptor, address, flags);  


      


        descriptor  


            The return value of shmget  


  


        address  


            If 0, the OS will provide the appropriate address  


  


        flags  


            Usually 0, there is one useful flag  


              


            SHM_RDONLY: Makes the memory read only  


  
  


  

