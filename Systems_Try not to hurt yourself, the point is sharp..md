# Systems::Try not to hurt yourself, the point is sharp.

More Pointer Fun

  


     Pointer arithmetic

          Declaring a pointer as a specific type allows you to add and subtract  to the pointer by the size of

          its associated type.

          

               int *ip;

               long *lp;

               ip++; //will add 4 to ip

               lp++; //will add 8 to lp

  


           Pointer arithmetic only works with + and - of integers.

  


     Array variables are immutable pointers

  


     %p prints out the memory pointer in hexadecimal.

  


     Array variables: value and addresses are the same.

  


     De-reference

          

          * is also used as the de-reference operator

          It accesses the value at the memory location stored in a pointer

  


               int i = 5;

               int *ip = &amp;i;

               *ip++; //this will set i to 6

     

     darr[2] &lt;=&gt; *(dp + 2)

  


     [ ] in C: Add and de-reference   


          
