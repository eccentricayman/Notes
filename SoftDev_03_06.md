# Aim: Capturing Bubbles

### DN

- Create an HTML file with an SVG and a clear button.
- JS function that creates and returns a circle in an SVG.
- JS function that calls the function above and adds returned circle to the SVG.
- Attach a draw circle function to the SVG.
- JS function that clears SVG.



### JS Event Propagation

- Events initially propagate downward from the topmost node in the DOM tree to the target element. This is known as **event capturing**.

- After an event reaches its target, it then propagates back up the DOM tree. This is known as **event bubbling**.

- By default, event listeners do not trigger until the event bubbling phase.

- Triggering events at the capture phase can be done by adding ```<true>``` as a third argument to ``` addEventListener.```

  ```javascript
  x.addEventListener("click", foo, true)
  ```

- You can cancel event propagation with:

  ```javascript
  e.stopPropogation();
  ```

  ​