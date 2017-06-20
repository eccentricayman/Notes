# Compilers

##### Source Code → Lexer → Parser → Semantic Analyzer → Optimizer → Machine Code Generator



1. ### Lexer

   - Performs lexical analysis

   - "Knows" all valid tokens in the language

   - Identify the tokens in your code

   - Input: <u>Source code</u>

   - Output: <u>Token list</u>

   - ```
     int
     main
     (
     )
     {
     long
     x
     =
     5
     +
     6
     ;
     printf
     (
     ```

2. ### Parser

   - Performs syntax analysis.

   - Knows the grammar of the language.

   - Input: <u>Token list</u>

   - Output: <u>Syntax tree</u>

   - ```
       int
        |
       main -----------
      /    \          |
     long  printf     |
      |     /   \    return
      x   "%d"  x     |
      |               8
      =
      |
     / \
     5  6
     ```

3. ### Semantic Analyzer

   - Knows how to map tokens to operations, values, and identifiers.

   - Input: <u>Syntax tree</u>

   - Output:

     - <u>Operation list</u>

     - ```
       int
       long
       +: 5, 6
       =: x -> goes to symbol table link
       ```

     - <u>Symbol table</u>

     - ```
       main: int
       x: long
       printf
       ```

     - <u>Identifier list</u>

4. ### Optimizer

   - We won't be optimizing.

5. ### Code Generator

   - Input: <u>Operations list and symbol table</u>

   - Output: <u>Machine code instructions</u>

   - ```
     101011...
     ```