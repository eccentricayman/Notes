# Systems::Malloc & free: The dynamic duo!

Seperate compilation

  


          You can combine multiple c files into a c program by including them all in one gcc command.

  


          You cannot have duplicate function or global variable names across these.

  


gcc -c

  


     Generate a compiled “object”, or .o file

  


     Does not create a fully functional program, but it is compiled code.

  


     .o files can be linked together with .c files through gcc

  


0: malloc, free

1: calloc, realloc

  


malloc(int x) (Fast, O(1))

     Allocates x bytes of memory (from the heap)

  


calloc(int n, int x) (Slow, O(n))

     Allocates n * x bytes of memory

     

     Ensures that each bit is set to 0

  


realloc(void *p, int x)

     Changes the amount of memory allocated to a given block.

  


     p must be a pointer to the beginning of an allocated block of memory, but it does not have to be the original pointer.

  


free

     Releases dynamically allocated memory.
