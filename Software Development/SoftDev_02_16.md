# Aim: Let's Get Animated

DN: HTML / JS combo that draws a circle on a canvas.



### Animation in JS

- We will be using ```requestAnimationFrame``` instead of ```setInterval```
- ```requestAnimationFrame``` tells the browser to run a specified function before drawing the next frame.
- The browser will attempt to run ~60 frames per second.
- It lets the browser handle when the code should be executed (as opposed to ```setInterval```, which is based on specific times).
- It also lets the browser pause animation when a page is not in the foreground.
- ```window.requestAnimationFrame( <FUNCTION> )```
- ​