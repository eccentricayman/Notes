# Softdev: Defeating the Trojans with the Help of AJAX

AJAX

Asynchronus Javascript and XML

System created to send data to a server in the background of a page without having to reload the page

or wait for the server to acknowledge the change.

It is a combination of technologies including javascript, html, DOM, and XML.

AJAX calls can send data to a server using GET or POST (for example), and then catch the data sent by

the server in response.

Originally, XML was the only supported format for sending/recieving data, but now many formats are

used, including JSON and plaintext.

AJAX calls can be made via the XMLHttpRequest javascript object.

Using jquery for AJAX

The jquery library provides clean wrapper fucntion for making AJAX calls.
    
    
       $.ajax( <SETTINGS> );
    
    
                 
    
    
                 Settings is an associative array containing all the information required to make the given ajax     
    
    
                 call.
    
    
              
    
    
                 Notable settings key:
    
    
                 
    
    
                    url: Server target link
    
    
                 
    
    
                    type: Method ("POST" or "GET")
    
    
          
    
    
                    data: Data to be sent
    
    
                    
    
    
                    success: Function to be called if the server responds
    
    
                    
    
    
                        This function can take an argument if the server sends data in 
    
    
                        response.
    
    
                 
    
    
                 $.ajax ({
    
    
                    url: '/foo',
    
    
                    type: 'GET',
    
    
                    data: "look it's information!",
    
    
                    success: function(d) {
    
    
                        console.log( d );
    
    
                    }
    
    
                 })
    
    
                 
    
    
                 jquery also has $.get() and $.post() wrappers
    
    
                 
    
    
                    $.get( <url>, <callback function> );
    
    
                    
    
    
                    $.get( "/foo", {'text' : input }, function(d) {
    
    
                        console.log(d);
    
    
                    });
    
    
      
    

  


  


  

