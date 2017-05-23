# Aim: Canvasing the area

### HTML5

- Redesign of HTML with a focus on making the more "modern" features of web browsers easy to work with.
- Designed around javascript and a standardized DOM.
- Includes built in support for audio and video playback.
- Includes an element that can be directly drawn on.

### Canvas

- HTML5 element that provides a drawing area.
- Javascript functions can draw onto a canvas element.
  - You must declare what context you are drawing in.
  - For example 2D drawing, 3D drawing, raw bitmap rendering…
- HTML

```html
<!DOCTYPE html>
<html>
  <style>
  	#slate {
      border: 1px dotted #222;
  	}
  </style>
  
  <h1>Canvas Fun!</h1>
  	
  	<canvas width="500" height="500" id="slate">
  </canvas>
  
</html>
```

- Javascript

```javascript
var c = document.getElementById("slate");
var ctx = c.getContext('2d');
ctx.fillStyle = "#ff0000";
//fill a rectangle using the fill style color
ctx.fillRect(50, 50, 100, 200);
// clear a rectangle
ctx.clearRect(0, 0, 20, 100);
```

