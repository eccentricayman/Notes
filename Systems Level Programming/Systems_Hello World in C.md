# Systems::Hello World in C

**Hello World**

`#include <stdlib.h> //#include is similar to "import ..." in java `

#include &lt;stdio.h&gt;

  


/*

Also, you use #include &lt;\---.h&gt; when the file is coming from C and you use #include "\---.h" when the file is coming from you.

`  
`

You will have to frequently #include the two files above later on.

*/

`  
`

int main() {

//no String[] args needed &amp; no protections because there are no classes in C.

`  
  printf("Hello World"); //Strings in C can't be concatenated using a "+" sign`

  


`  return 0; //returns 0 if function runs smoothly (1 or -1 if not).  
  
  // COMPILING + RUNNING STEPS IN TERMINAL (for Ubuntu/Linux)  
  // (1)-  gcc hello.c  
  // (2)-  ./a.out  
}`

**  
**

**C Primitive Types Difference**

  * No boolean and byte
  * All primitives are represented by numbers (ex. char -&gt; ASCII values).
  * The differences are floating point vs integer and the size of the variable.



  


C Primitive Types

Primitive Type | Description | Bytes | Range  
---|---|---|---  
int | integer | 4 | -2,147,483,648 to 2,147,483,647  
short | integer | 2 | -32,768 to 32,767  
long | integer | 8 | –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807  
char | character/symbol | 1 | -128 to 127  
float | floating-point number | 4 | -3.4E+38 to +3.4E+38; precise to 7 decimal places  
double | floating-point number | 8 | -1.7E+308 to +1.7E+308; precise to 16 decimal places  
  
  


  * Variable size can be platform-dependent
  * 1 byte = 8 bits
  * The range is -[2^(numBits-1)] to [2^(numBits-1)]-1



### [](https://github.com/mks65/dwsource/blob/master/%23sizeof-function)

`sizeof(type)` finds the size of the type in bytes.

### Two's Complement

  * First bit represents whether the number is positive(0) or negative(1)
  * 0 only has one representation (no negative 0)
  * Positive and negative numbers "wrap around" each other



  

