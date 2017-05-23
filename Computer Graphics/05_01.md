# What we need before writing a compiler

- Identify valid tokens
- Define language structure (grammar)
- Map the syntax/tokens to operations/symbols
- Map the operations to machine code



# MDL

- Items separated by | means you must choose one of them in an input line.
- Items enclosed in [] are optional.
- For example, rotate is specified as:
  - ```rotate x|y|z degrees [knob]```
- The following would be valid rotations:
  - ```rotate x 20```
  - ```rotate y 23 k1```
- While the following would be invalid:
  - ```rotate x|y 20```
  - ```rotate x y 33```

### Transformations

- All transformations will operate as follows:
  1. If there is a kob, scale the transformation by the knob value.
  2. Create the appropriate transformation matrix M
  3. Multiply top_off_stack * M and replace the old top of the stack with this result.
- ```move x y z [knob]```
- ```scale x y z [knob]```
- ```rotate x y z [knob]```

 