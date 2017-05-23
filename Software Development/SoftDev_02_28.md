# Aim: Vector-ize me

### Creating SVG Elements in Javascript

- ```javascript
  document.createElementNS(<NAMESPACE>, <ELEMENT>);
  ```

  - Creates an element from a specified XML namespace.

### SVG Example:

- ```javascript
  var c1 = document.createElementNS("http://www.w3.org/2000/svg", "circle")
  ```

  - Once created, you can modify it with ```setAttribute```.

  - ```javascript
    cl.setAttribute("cx", "200");
    ```

