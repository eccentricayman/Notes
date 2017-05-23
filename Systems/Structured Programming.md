# Systems::Structured Programming

void *

     The dynamic memory functions deal in arbitrary blocks of memory. There is no regular type associated with the block.

     

     void * is considered to be a pointer to a 1 byte block of emory, so pointer arithmetic will be based on 1.

  


     Whenever possible you should typecast void * values to the appropriate type.

  


     ex:

          int *ip;

          ip = (int *)malloc(5 * sizeof(int));

  


Struct

     A collection of values in a single data type.

     

     struct { int a ; char x ; } s;

  


          Here, s is a variable of type struct { int a ; char x ; }
