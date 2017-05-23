# Systems::How do we flag down a resource?

Semaphores (created by Edsger Dijkstra)

  


    IPC construct used to control acces sto a shared resource (like a file or shared memory).  


  


    Essentially, a semaphore is a counter that represents how many processes can access a resource at any given time.  


  


        If a semaphore has a value of 3, then it can have 3 active “users”.  


  


        If a semaphore has a value of 0, then it is unavailable.  


  


        Semaphores with a value of 1 are called mutex.  


  


    Most semaphore operations are “atomic”, meaning they will not be split up into multiple processor instructions.  


  


Semaphore operations:

  


    Create a semaphore  


  


    Set an initial value  


  


    Up(S) / V(S)  


        Release the semaphore to signal you are done with its associated resource.  


      


        pseudocode:  


            S++  


  


    Down(S) / P(S)  


        Attempts to take the semaphore.  


  


        If the semaphore is 0, wait for it to be available.  


  


        pseudocode:  


            while( S == 0 )  


                block  


            S--  


      


    Remove a semaphore  


              


Semaphores in C - &lt;sys/types.h&gt; &lt;sys/ipc.h? &lt;sys/sem.h&gt;

  


    semget  


  


            Create/Get access to a semaphore.  


  


            This is not the same as Up(S) or Down(S), it does not modify the semaphore.  


  


            Returns a semaphore descriptor or -1 (errno).  


  


        semget( &lt;KEY&gt;, &lt;AMOUNT&gt;, &lt;FLAGS&gt; );  


  


            KEY  


                Unique semaphore identifier (use ftok)  


            AMOUNT  


                Semaphores are stored as sets with potentially many semaphores together. This parameter sets the number of 

                semaphores to create/get.  


            FLAGS  


                Includes permission for the semaphore.  


              


                Combine with bitwise or  


      


                IPC_CREAT: Create the semaphore and set value to 0.  


          


                IPC_EXCL: Fail if the semaphore already exists and IPC_CREAT is on.  


  


Semaphore code

    semctl - &lt;sys/types.h&gt; &lt;sys/ipc.h&gt; &lt;sys/sem.h&gt;  


  


        Control the semaphore, including:  


          


            Set the semaphore value  


            Remove the semaphore  


            Get the current value  


            Get information about the semaphore  


      


        These operations are not atomic.

  


        semctl( &lt;DESCRIPTOR&gt;, &lt;INDEX&gt;, &lt;OPERATION&gt;, &lt;DATA&gt; );  


  


            DESCRIPTOR  


                The sem descriptor.  


  


            INDEX  


                The index of the semaphore you want to control in the semaphore set identified by the descriptor.  


  


                For a single semaphore set, 0.  


  


            OPERATION  


                One of the following constraints (There are others as well)  


  


                IPC_RMID: Remove the semaphore  


  


                SETVAL: Set the value (requires DATA)  


  


                SETALL: Set the value of every semaphore in the set (requires DATA)  


  


                GETVAL: Return the value  


          


                IPC_STAT: Populate buffer with information about the semaphore (requires DATA)  


  


  

