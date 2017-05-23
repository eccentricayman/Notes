# Systems::Cisco in an hour VII: Adrian's Revenge

Remaining Layers
    
    
    5. Session  
    6. Presentation  
    7. Application
    
    These layers are incorporated into programs that use network connections.  
    
    Session layer represents end-to-end connectinos in a program (sockets).  
    
    Presentation layer represents how programs package transmitted data.  
    
    Application layer represents the program that the users interact with.
    

Sockets (sys/socket.h, sys/types.h)
    
    
    A socket is a network connection between two programs.  
    
    A socket has 2 ends, each one consisting of an IP Address/Port pair.
    
    To use a socket  
        1. Create the socket  
        2. Bind it to an address and port  
        3. Listen/initiate a connection  
        4. send/recieve data  
    
    socket <sys/socket.h>  
    
        Creates a socket  
    
        Returns a socket descriptor (int that works like a file descriptor)  
    
        socket( <domain>, <type>, <protocol> )  
    
            domain: type of address, IPv4, IPv6...  
                    AF_INET: IPv4  
    
            type: tcp/udp  
                SOCK_STREAM: tcp  
                SOCK_DGRAM: udp  
    
            protocol  
                Combination of domain and type settings  
    
                If set to 0 the OS will set to correct protocol  
    
            example:  
                int sd = socket( AF_INET, SOCK_STREAM, 0);  
    
    bind <sys/socket.h>  
    
        Binds the socket to an address and port  
    
        Returns 0 (success) or -1 (failure)  
    
        A server might bind to any incoming address but only a specific port, whereas a client would bind to a specific address and port.  
    
        bind( <socket descriptor>, <address>, <address length> )  
    
            address: pointer to a struct sockaddr_in  
    
                sin_family: address domain (eg. AF_INET)  
    
                sin_addr:  
    
                    IP address in binary  
    
                    INADDR_ANY: Any incoming connection  
    
                    inet_aton( <string>, <address variable> )  
    
                        Will convert a string representing an ip address to the correct format and place it in the second parameter
    
