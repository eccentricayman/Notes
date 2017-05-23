# Systems::A little bit of wisdom

Bit shift operators

     Work on each individual bit of a value.

  


     &gt;&gt; right shift

          ex. x &gt;&gt;1

  


          Move all bits to the right, add 0s to the front

  


     &lt;&lt; left shift

          ex. x &lt;&lt; 2

  


          Move all bits to the left, add 0s in the back

  


     Left shift and right shift will now overflow end bits into adjacent memory.

  


     ~ negation

          ex: ~x

  


               Flip every bit.

  


     | or

          ex: a | b

  


          Perform or for each pair of bits in (a, b)

  


     &amp; and

          ex: a &amp; b

  


     ^ xor

          ex: a ^ b

               Perform xor for each pair of bits in (a, b)

  


xor swap:

     1) a = a ^ b;

     2) b = a ^ b;

     3) a = a ^ b;
