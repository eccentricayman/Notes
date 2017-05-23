# Aim: Transformations

### Using Edge Lists

- Store image information as a list of edges.

- Each pair of entries in the list will define 1 line.

  ```[P0, P1, P2, P3, P4, P5, ...]```

- The edge list can be used to apply transformations.

- Storing/representing the edge list:

  - Each point is made of x, y, and z components.
  - Each component is a floating point number.

```x0 x1 ... xn```

```y0 y1 ... yn```

```z0 z1 ... zn```

```1.0 1.0 … 1.0```

```4 * N```

### Matrix Math

- Scalar Multiplication
  - Multiplying a matrix by a constant.
- Matrix Multiplication
- Identity Matrix