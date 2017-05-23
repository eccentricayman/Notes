# Systems::Always remember to tip your servers

Design a program that has 2 executables

  


    One is designed to ask a user for input and send that input to the second program  


  


    The second program should take input from the first, “process” it in some way, and send a response to the first  


    Do not write this program, design how it would work. How many pipes would you need? What kind of pipes?  


  


Server/Client 

      


    Handshake  


        A procedure to ensure that a connection has been established  


  


        Both ends of the connection must verify that they can send and receive data to and from each other.  


  


        Basic Handshake Procedure

    1. Server creates a FIFO (Well Known Pipe)
    2. Server waits for a connection
    3. Client creates a “private” FIFO
    4. Client connects to server and sends the private FIFO name
    5. Client waits for a message from the server
    6. Server receives client’s message and removes the WKP
    7. Server connects to client FIFO, sending an initial acknowledgement message.
    8. Client receives server’s message, removes it’s private
    9. The client sends an acknowledgment message back to the server.



  

