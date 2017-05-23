# Systems::Cisco in an hour III: In 3-D!

Data Link Layer
    
    
        Point-to-point transmission between devices on the same local network.
    
    
        Ethernet Connection:  
            Each device is given a unique 6-Byte MAC (Media Access Control) address,  
            this is set on each network card when it is made.
    
    
            Data is packaged into frames
    
                Ethernet Frame:  
                    <prefix><dest><source><.....><data><checksum>  
                       8B     6B    6B      6B  46-1500B   4B
    
                   prefix: 10101010 x7 + 10101011
    
                   destination/source: MAC addresses
    
                   <...>: Information about frame type
    
                   <checksum>: To ensure data integrity  
    
               MTU  
                   Maximum Transmission Unit  
    
                   1500 bytes for ethernet
    
