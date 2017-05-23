# Systems::C, the ultimate hipster, using # decades before it was cool

#

     Used to provide preprocessor instructions.

  


     These directives are handled before the compiler really kicks in

  


     #include &lt;LIBRARY&gt; | “LIBRARY"

          Link libraries to your code

  


     #define &lt;NAME&gt; &lt;VALUE&gt;

          replace all occurrences of NAME with VALUE

  


          #define TRUE 1

  


          macros:

               #define SQUARE(x) x * x

               ...

               int y = SQUARE(9); —&gt; int y = 9 * 9;

  


     conditional statement:

          #ifndef &lt;IDENTIFIER&gt;

          &lt;CODE&gt;

          #endif
