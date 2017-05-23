# Aim: Your path to success starts here

### Javascript Path Functions

- Paths are used to draw arbitrary shapes, including circles and curves.
- A context can keep track of one path at a time.
- The path is not drawn until ```stroke()``` is called.
- A path is considered done when a new ```beginPath()``` is called.
- ```beginPath()```
  - Starts or resets the current path.
- ```moveTo(X, Y)```
  - Moves the path to position (x, y), does not result in a line or filled in section.
- ```lineTo(X, Y)```
  - Moves the path to position (X, Y) will result in a line and a filled in section.
- ```closePath()```
  - Results in a line from the current position to the starting position. 
  - The path can be continued after.
- ```stroke()```
  - Renders all the lines in the path.
  - Does not end the path.
- ```fill()```
  - Fills the interior of the path, will not work if the path has fewer than 3 points in it.