# Systems::Are your processes running? - Then you should go out and catch them!

Processes

    Every running program is a process. A process can create subprocesses, but these are no different from regular processes. A 

    processor can handle 1 process per cycle (per core). “Multitasking” appears to happen because the processor switches 

    between all the active processes quickly.  


  


    pid  


        Every process has a unique identifier called the pid.  


  


        pid 1 is the init process  


  


        Reach entry in the /proc directory is a current pid  


      


    getpid() - &lt;unistd.h&gt;  


        returns the current process’ pid  


  


    getppid() - &lt;unistd.h&gt;  


        return’s the current process’ parent id  


  


Signals

      


    Limited way of sending information to a process.  


  


    kill  


        Command line utility to send a signal to a process  


  


        s kill &lt;PID&gt;  


            Sends SIGNAL to PID  


  


    killall [-&lt;SIGNAL&gt;-] &lt;PROCESS&gt;  


  


        Sends SIGTERM (or SIGNAL if provided) to all processes with PROCESS as the name  


  


Signal handling in c programs &lt;signal.h&gt;

  


    kill  


        kill(&lt;PID&gt;, &lt;SIGNAL&gt;);  


  


        Returns 0 on success or -1 (errno) on failure.  


  


To intercept in c, you need this function:

static void sighandler(int signo)

And inside main:

signal(&lt;SIGNAL&gt;, sighandler);

  

