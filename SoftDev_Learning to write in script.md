# SoftDev::Learning to write in script

javascript

  


    Programming language originally designed to augment html and be run locally on a web browser.  


  


    No direct relationship with java, though both have similar syntax.  


  


    Dynamically typed - variable types are provided at runtime (like python).  


  


    Most development will be done through a web browser’s console.  


  


    console.log  


        There is no built in i/o. console.log() will display a string to the console.  


  


    C-style syntax  


  


    Variable basics

    var x = 4;  


    var s = “hello”;  


    var l = [4, 3, 19];  


    var o = { ‘a’ : 10, ‘x’: ‘hello’ };  


  
  


Document Object Model (DOM)

  


    Javascript derives most of its utility through being able to interact with html and xml documents.  


      


    The DOM is an API for interacting with html. It provides a structure that we can interact with and can be manipulated by functions.  


  


    Pages are represented as trees.  


  


    Selecting HTML elements  


    document.getElementById(&lt;ID&gt;)  


  


    document.getElementsByTagName(&lt;TAG&gt;)  


  


    document.getElementByClassName(&lt;CLASS&gt;)  


  


    Manipulating DOM Elements

        .remove()

  


        .innerHTML

  


        document.createElement( &lt;HTML TAG NAME&gt; )

  


        .appendChild( &lt;ELEMENT&gt; )  


      


        .setAttribute( &lt;NAME&gt;, &lt;VALUE&gt; )  


  


        .getAttribute( &lt;NAME&gt; )  


  


        .addEventListener( &lt;EVENT&gt;, &lt;FUNCTION&gt; )  


  


Functions in javascript!

  


    Javascript is functional. Like Scheme (Racket)!  


  


    Functions are first class objects that can be used like any other value.  


  


    function() creates anonymous functions (like lambda!).  


    function() { console.log(“yo”); };  


  

