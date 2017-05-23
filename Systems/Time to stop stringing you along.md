# Systems::Time to stop stringing you along

Do Now: Create a character array of a reasonable size.

               Print it out using %s as the formatting character.

  


C strings (ctrings?)

     Strings are character arrays that end with a null character (either “” or “\0”)

  


     The terminating null character is a convention, string functions will not work correctly without it.

     

     When you create a literal string using “”, an immutable string is created in memory, so if you create the same

     string literal again, the computer does not need to allocate more memory. These strings are always null

     terminated.

  


     The following are valid ways to declare strings:

          char s[256];

               Normal array declaration, allocates 256 bytes,

               nothing is set automatically

     

          char s[256] = “Imagine”;

               Allocates 256 bytes. Creates the immutable string “Imagine” and then copies it (including the terminating

               null) into the array.

     

          char s[] = “Thursday”;

               Allocates 8 bytes. Creates the immutable string “Thursday” and then copies it (including the terminating null) into the

               array.

     

          char *s = “Mankind”;

               Creates the immutable string “Mankind”, and returns a pointer to that string. Since the pointer is to an immutable piece     

               of memory, you cannot modify strings in this way.
