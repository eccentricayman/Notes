# Systems::Let's take it to delimit

strsep - &lt;string.h&gt;

  


    Used for parsing a string with a common delimiter  


      


    strsep( &lt;SOURCE&gt;, &lt;DELIMITER&gt; );  


    //You can make delimiter a string like  


    //“abc”  


    //so it parses a, b, and c; no multi-length seperator  


  
    Locates the first occurence of any of the specificed delimiters in a string and replaces it with NULL

  


    Returns the beginning of the original string, sets the source string to the string starting at 1 index past the location of the 

    new NULL  


  

