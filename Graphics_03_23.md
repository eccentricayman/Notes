# 3D Shapes

### Rectangular Prism

- **Given**: One vertex, height, width, and depth
- Defining Points: Vertices
  - Combinations of ```x```, ```x + w```, ```y```, ```y + h```, ```z```, and ```z + d```

### Sphere

- **Given**: center, circle, radius
- **Define Points**: Points on the surface
- **Generate**: Rotate a circle about the x or y axis

$$
\begin {vmatrix}
1 & 0 & 0\\
0 & \cos{\phi} & -\sin{\phi}\\
0 & \sin\phi & \cos\phi\\
\end {vmatrix}
*
\begin {vmatrix}
r\cos\theta\\
r\sin\theta\\
0
\end {vmatrix}
=
\begin {vmatrix}
r\cos\theta\\
r\sin\theta\cos\phi\\
r\sin\theta\sin\phi
\end {vmatrix}
\\\text{ x-rotation                 circle              sphere}\\
\theta: 0 \rightarrow 2\pi\\
\phi: 0\rightarrow \pi
\\\text{or}\\
\theta: 0 \rightarrow \pi\\
\phi: 0\rightarrow 2\pi
$$

### Torus

$$
\begin {vmatrix}
\cos{\phi} & 0 &\sin{\phi}\\
0 & 1 & 0\\
-\sin{\phi} & 0 & \cos\phi\\
\end {vmatrix}
*
\begin {vmatrix}
r\cos\theta + R\\
r\sin\theta\\
0
\end {vmatrix}
=
\begin {vmatrix}
\cos\phi(r\cos\theta + R)\\
r\sin\theta\\
-\sin\phi(r\cos\theta + R)
\end {vmatrix}
\\\text{ (y-rotation + translation)   circle                       torus}\\
$$
