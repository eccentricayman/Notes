# SoftDev::Stuylin'

Cascading Style Sheets (CSS)

      


    Created to separate the presentation of an html/xml page and it’s content.  


  


    Basic syntax:  


      


        PROPERTY: VALUE;  


  


   color: lightsteelblue;

   text-align: center;

   border: 10px;  


  


    There are 3 ways to incorporate CSS into a page; inline, internal style sheet, and external style sheet.  


  


    Inline CSS  


      


        Add CSS code to the style attribute of a tag

          


   &lt;TAG style=“CSS CODE”&gt;  


  


   &lt;p style=“color: green; font-size: 2em”&gt; … &lt;/p&gt;  


  


    Internal Style Sheet  


      


        Add a &lt;style&gt; element to the &lt;head&gt; section of the page.  


        Include all your CSS code inside the &lt;style&gt; … &lt;/style&gt; block.  


  


        Internal and External style sheets require the addition of a selector so that it is clear what element you are styling.  


  


   SELECTOR {

       CSS CODE

   }

     


   h1 {  


       color: #FF00FF;  


   }  


   


    External Style Sheets  


  


        Create a separate .css file that contains all your CSS code.   


        It cannot contain any other kind of code, including html or xml.  


  


        Include a link to the css file inside the &lt;head&gt; section of your page.  


  


    &lt;head&gt;  


        &lt;link rel=“stylesheet” type=“text/css” href=“STYLE FILE”&gt;

        ...  


    &lt;/head&gt;  


  


Styles are generally inherited by elements inside other elements.

  


body {

    color: green;  


}

  


h1 {

    position: fixed;  


    top: 10px;  


}

  


h1 elements will be green.

  

