# Relative Coordinate System

- Maintain a stack of coordinate systems.
  - ```push```: add a <u>copy</u> of the top to the stack
  - ```pop```
- All transformations are immediately applied to the top of the stack.
- Object Commands:
  1. Generate a polygon list
  2. Apply the top coordinate system
  3. Draw to the screen
  4. Clear the polygon list

|     Command     |          Stack           |             Image              |
| :-------------: | :----------------------: | :----------------------------: |
|      push       |          I / I           |      bottom left red dot       |
|   move x y z    |        I * M0 / I        |         center red dot         |
| box x y z w h d |        I * M0 / I        |   box around center red dot    |
|      push       |   I * M0 / I * M0 / I    |   box around center red dot    |
|   move x y z    | I * M0 * M1 / I * M0 / I |         dot above box          |
| sphere x y z r  | I * M0 * M1 / I * M0 / I | sphere around circle above box |

