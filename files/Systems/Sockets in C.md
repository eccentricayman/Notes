# Systems::Sockets in C

accept (server only) &lt;sys/socket.h&gt;

  


    returns the socket descriptor of the new socket  


  


    accept ( &lt;socket descriptor&gt;, &lt;socket address&gt;, &lt;address length&gt; );  


  


        socket descriptor: return value of socket  


  


        address: pointer to a struct sockaddr  


                      Will contain the correct address information after the connection is made  


                      

        length: pointer to a variable  


  


connect (client only) &lt;sys/socket.h&gt; &lt;sys/types.h&gt;

  


    Connect to another program over a socket.  


  


    Handles the client end of the 3 way handshake.  


  


    connect( &lt;socket descriptor&gt;, &lt;address&gt;, &lt;address size&gt; );  


  


        Address struct is the same as in bind  


  

