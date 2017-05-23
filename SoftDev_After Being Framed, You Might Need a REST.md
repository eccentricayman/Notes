# SoftDev::After Being Framed, You Might Need a REST

Tips for using frameworks

  


    Many files have .min equivalents, which contains the same code without any extra formatting.  


  


jQuery

  


    jQuery is a popular Javascript library used in many frameworks.  


  


    The order in which you include Javascript files is important.  


  


Javascript in &lt;head&gt; or at the end of &lt;body&gt;??

  


    Yet another programmer holy war  


  


    Advantages to head  


  


        Scripts will definitely be loaded before anything else, so page elements that need scripting will be attached.  


  


    Disadvantages to head  


  


        loading scripts will take longer and then entire page will be delayed

  


    Advantages to end of body  


  


        Page content loads much faster  


      


    Disadvantages to end of body  


  


        PAGE might look fully loaded while script files continue to be downloaded and parsed.  


  


REST APIs

  


    API (Application Program Interface)  


   


        A pusblished set of protocols that can be used to have your program interact with another program/service.  


  


    REST (Representational Data Transfer)  


  


        APIs that transmit data after receiving a HTML[s]

  


        Returned data can be in various formats, most common are html, xml, and json.  


  


    JSON (Javascript object notation)

  


    Standard way of repprsenting data. Can be easily translated into a python dictionary.  


  

