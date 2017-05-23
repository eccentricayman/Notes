## 02-01-2017 | Aim: Bits o' Pixels##

*Do Now*: How would you represent color data if you only had the following amount of space for each pixel?

1. 1 bit  ==  black or white
2. 2 bit  ==  black, white, gray 
   - 2nd bit for intensity
3. 3 bits == rgb (basic)
4. 4 bits == rgba (basic)
5. 6 bits == rgb
   - each color given its own intensity

Color depth -- number of bits used for a pixel

*Revolution in the Valley* - book on development of Macintosh computer

**Image Files**

- File Types
  - Uncompressed 
  - Compressed
  - Lossless -- Direct representation of original data
  - Lossy -- Loss of data through compression
- File extensions
  - gif ( C, L )
  - png( C, L )
  - jpg( C, Ly )
  - bmp( U, L )
  - tif( U, L)

## 02-02-2017 | Aim:  ##

#### Image File Formats ####

**Image Files**

- **Uncompressed** (U) - each pixel has a piece of data 
- **Compressed** (C) - not every pixel has a piece of data attached
- **Lossless** (L) - direct representation of original source
- **Lossy** (LY) - loss of the direct representation

**Image File Extensions ( Raster Format )**

- JPG - ( C, LY )
- PNG - ( C, L )
  - Uses *Run Length Encoding*, which counts the number of repeating characters and etc. 
    - Ex. GGGRPPPP -- > 3G 1R 4P
  - Works well for computer generated images, because there are a lot of repeating color. 
  - Does NOT work well for cameras / photographs of real-world, because shading
- GIF - ( C, L )
  - Lossy initially ( pixelating of images), but lossless when putting it all together 
- BMP - ( U, L )
  - Generally used for maps in games ( don't need to worry about compression )
- TIF - ( C, L )

**Image File Extensions ( Vector Format )**

- SVG
- PDF

**Raster Format** -- Where images are stored as a grid of pixels

**Vector Format** -- Where images are stored as a set of drawing instructions 

#### FORMAT FOR CLASSWORK : NetPBM

- Uncompressed and Lossless 
- *.ppm* file extension
- All whitespace is the same

**Format**

- Header
  - P3 -- Denotes what netPBM file it is 
  - XRES  -- Width of resolution
  - YRES  -- Height of resolution
  - MAX COLOR -- 
- Pixel Data
  - RGB RGB RGB ... ( ASCII Numeric Values )
- NOTE : Newline at the end of the file

## 02-03-2017 | Aim: ##

```$ convert``` can convert an image from one format to another.

## 02-06-2017 | Aim: Bresenham's Line Algorithm  

#### Drawing Lines

- Have to color entire pixels ( in contrast to part of a pixel ) 

- The screen is discrete ( not continuous ) -- Have to deal with integers 

- We care about the pixels themselves, not the grid lines 

  - Center of Pixel is coord of Pixel? 

- Assumption for inital line development:

  - 0 < *m* <= 1 

    - reduces the number of pixels we have to look at to decide if we have to go there

  - Endpoints are known 

  - We are not going backwards

  - Standard Equation for Line: A*x* + B*y* + C = 0

    - f(x,y) = Ax + By + C

      - $$
        A = Δy,
        B = -(Δx),
        C = (Δx)b
        $$

    - f(x,y) = {  0 : if (x,y) is on the line 

      ​		< 0 : if (x,y) is above the line

      ​		> 0 : if (x,y) is below the line 

      ​		} 


## 02-07-2017 | Aim: BresenHam's Line algo. ( Cont. ) 

### Drawing Lines (Cont.)

- Possible Points: (x +1, y), (x+1, y+1)

  - Midpoint: (x+1, y + 0.5) 
    - Check whether midpoint is above or below the line
      - If above, choose the point below
      - If below, choose the point above
      - If 0, choose either, just be consistent  

- ```
  ( x0, y0 ) --> ( x1, y0 )

  x = x0, y = y0
  d = f( x + 1, y + 0.5 )
  while x <= x1:
  	plot( x, y )
      if ( d > 0 ):
      	y++;
      x++;
      d = f(x + 1, y + 0.5 )
  ```

## 02-08-2017 | Aim: BresenHam's Line algo. ( Cont. )

### Drawing Lines ( Cont. )

- Increase efficiency by removing the function inside the while loop:

  - ```
    d = f( x + 1, y + 0.5 )
    while x <= x1:
    	plot( x, y )
    	if( d > 0 ):
    		y++
    		d+=B
    	x++
    	d+=A
    ```

- We can increase efficiency more:

  - ```
    d = f( x0 + 1, y0 + 0.5 )
    d = Ax0 + By0 + C + A + 0.5B
      Becomes 
    d = A + 0.5B ( Don't even need the function anymore )
    ```

- Double Everything ( So no division ):

  - ```
    	plot( x, y )
    	if( d > 0 ):
    		y++
    		d+=2B
    	x++
    	d+=2A
    ```


## 02-16-2017 | Aim:

### Using Edgelists

- Store image information as a list of edges 

- Each pair of entries in the list will define one line

  - [ p0, p1, p2, p3, p4, p5, ... ]
    - {p0, p1}, {p2, p3}, {p4, p5}

- The edge list can be used to apply transformations

- Storing / Representing the edge list

  - Each point is made of x, y, z components

  - Each component is a floating point number  

  - ```
    x0   x1   ...  xN
    y0   y1   ...  yN
    z0   z1   ...  zN
    1.0  1.0  ...  1.0
    ------------------
    4 x N
    ```

- Matrix Math

  - Scalar Multiplication
  - Matrix Multiplication
    - For M * N
      - \# of Cols in M = \# of Rows in N
  - Identity Matrix 

## 02-17-2017 | Aim: MATRICES

### Matrix Multiplication

- ( 4 x N ) * ( N x N ) = ( 4 x N ) *vs* ( 4 x 4 ) * ( 4 x N ) = ( 4 x N )

- $$
  \begin{vmatrix}
  A & B & C \\
  D & E & F \\
  \end{vmatrix}
  * 
  \begin{vmatrix}
  g & h \\
  i & j \\
  k & l \\
  \end{vmatrix}
  =
  \begin{vmatrix}
  (Ag + Bi + Ck) & (Ah + Bj + Cl) \\
  (Dg + Ei + Fk ) & (Dh + Ej + Fl) \\
  \end{vmatrix}
  $$

- #### Multiplicative Identity Matrix

  - $$
    \begin{vmatrix}
    1 & 0 & 0 & 0 \\
    0 & 1 & 0 & 0 \\
    0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 1 \\
    \end{vmatrix}
    *
    \begin{vmatrix}
    x \\
    y \\
    z \\
    1 \\
    \end{vmatrix}
    =
    \begin{vmatrix}
    x \\
    y \\
    z \\
    1 \\
    \end{vmatrix}
    $$

  - I * M = M

  - Square Matrix

  - Mostly filled with 0's 

  - 1's along the diagonal


## 03-01-2017 | Aim: Transformations

### Transformations

- Scaling, Translations, and Rotations

#### Translation

- ```( x, y, z ) --T(a,b,c)--> ( x+a, y+b, z+c )```

- $$
  \begin{vmatrix}
  1 & 0 & 0 & a \\
  0 & 1 & 0 & b \\
  0 & 0 & 1 & c \\
  0 & 0 & 0 & 1 \\
  \end{vmatrix}

  * 

  \begin{vmatrix}
  x \\
  y \\
  z \\
  1 \\
  \end{vmatrix}

  = 

  \begin{vmatrix}
  x + a \\
  y + b \\
  z + c \\
  1 \\
  \end{vmatrix}

  \\

  T * E
  $$













#### Scaling

- ```( x, y, z ) --S(a,b,c)--> ( x*a, y*b, z*c )``` 

- $$
  \begin{vmatrix}
  a & 0 & 0 & 0 \\
  0 & b & 0 & 0 \\
  0 & 0 & c & 0 \\
  0 & 0 & 0 & 1 \\
  \end{vmatrix}

  * 

  \begin{vmatrix}
  x \\
  y \\
  z \\
  1 \\
  \end{vmatrix}

  = 

  \begin{vmatrix}
  xa \\
  yb \\
  zc \\
  1 \\
  \end{vmatrix}

  \\

  S * E
  $$

- To do an in-place scaling, translate to origin, scale, and then translate back

#### Rotation

- Rotations across different Axes

  - **Z-Axis:**```( x, y, z ) --R(θ,z-axis)--> ( xcosθ - ysinθ, ycosθ + xsinθ, z )```

  - $$
    \begin{vmatrix}
    cosθ & -sinθ & 0 & 0 \\
    sinθ & cosθ & 0 & 0 \\
    0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 1 \\
    \end{vmatrix}

    * 

    \begin{vmatrix}
    x \\
    y \\
    z \\
    1 \\
    \end{vmatrix}

    = 

    \begin{vmatrix}
    xcosθ - ysinθ \\
    ycosθ + xsinθ \\
    z \\
    1 \\
    \end{vmatrix}

    \\

    R * E
    $$

  - **X-Axis:**```( x, y, z ) --R(θ, x-axis)--> ( x, ycosθ - zsinθ, zcosθ + ysinθ )```

  - $$
    \begin{vmatrix}
    1 & 0 & 0 & 0 \\
    0 & cosθ & -sinθ & 0 \\
    0 & sinθ & cosθ & 0 \\
    0 & 0 & 0 & 1 \\
    \end{vmatrix}

    * 

    \begin{vmatrix}
    x \\
    y \\
    z \\
    1 \\
    \end{vmatrix}

    = 

    \begin{vmatrix}
    x \\
    ycosθ - zsinθ \\
    zcosθ + ysinθ \\
    1 \\
    \end{vmatrix}

    \\

    R * E
    $$

  - **Y-Axis:**```( x, y, z ) --R(θ, y-axis)--> ( xcosθ + zsinθ, y, zcosθ - xsinθ)```

  - $$
    \begin{vmatrix}
    cosθ & 0 & sinθ & 0 \\
    0 & 1 & 0 & 0 \\
    -sinθ & 0 & cosθ & 0 \\
    0 & 0 & 0 & 1 \\
    \end{vmatrix}

    * 

    \begin{vmatrix}
    x \\
    y \\
    z \\
    1 \\
    \end{vmatrix}

    = 

    \begin{vmatrix}
    xcosθ + zsinθ \\
    y \\
    zcosθ - xsinθ \\
    1 \\
    \end{vmatrix}

    \\

    R * E
    $$

  - ​

### Combining Transformations

E0, R, S, T

- R * E0 = E1
- S * E1 = E2
- T * E2 = E3 
- E3 = ( T * S * R ) * E0 


## 03-09-2017 | Aim: Parametric Equations

### Parametric Equations

- A way to describe a curve with respect to an independent variable ( *t* )

  - $$
    x = f(t) \\
    y = g(t) \\ 
    ---- \\
    Line  \\
    x = x0 + (Δx)t \\
    y = y0 + (Δy)t \\
    ----\\
    Circle\\
    x = rcos(t) + cx\\
    y = rsin(t) + cy\\
    $$










## 03-10-2017 | Aim: Splines 

**Problem**: Given information does not match coefficients

### Hermite Curves

- Given: P0, P1 (endpoints), M0, M1 (slopes at endpoints) 

- Points on the curve: 

- $$
  f(t) = at^3 + bt^2 + ct + d
  $$

- Slopes at each point:

- $$
  f'(t) = 3at^2 + 2bt + c
  $$

- Finding the coefficients

- $$
  f(0) = d = P0 \\
  f(1) = a + b + c + d = P1 \\
  f'(0) = c = M0 \\
  f'(1) = 3a + 2b + c = M1 \\
  $$

- Using Matrices

- $$
  \begin{vmatrix}
  0 & 0 & 0 & 1 \\
  1 & 1 & 1 & 1 \\
  0 & 0 & 1 & 0 \\
  3 & 2 & 1 & 0 \\
  \end{vmatrix}

  * 

  \begin{vmatrix}
  a \\
  b \\
  c \\
  d \\
  \end{vmatrix}

  = 

  \begin{vmatrix}
  P0 \\
  P1 \\
  M0 \\
  M1 \\
  \end{vmatrix}

  \\

  H * C = G

  \\

  ----

  \\

  \begin{vmatrix}
  2 & -2 & 1 & 1 \\
  -3 & 3 & -2 & -1 \\
  0 & 0 & 1 & 0 \\
  1 & 0 & 0 & 0 \\
  \end{vmatrix}

  * 
  \begin{vmatrix}
  P0 \\
  P1 \\
  M0 \\
  M1 \\
  \end{vmatrix}

  = 

  \begin{vmatrix}
  a \\
  b \\
  c \\
  d \\
  \end{vmatrix}

  \\

  H^{-1} * G = C
  $$









## 03-13-2017 | Bezier Curves

### Bezier Curves

#### Linear Curves

- $$
  P(t) = (1 - t)P0 + tP1
  $$









#### Quadratic Curves

- $$
  Q(t) = (1 -t)Q0 + tQ1 \\
  Q0 = (1 - t)P0 + tP1 \\
  Q1 = (1- t)P1 + tP2 \\
  ----\\
  Q(t) = (1-t)^2P0 + 2t(1-t)P1 + t^2P2
  $$









#### Cubic Curves

$$
R(t) = (1-t)R0 + tR1 \\
R0 = (1-t)^2P0 +2t(1-t)P1 +t^2P2 \\
R1 = (1-t)^2P1 + 2t(1-t)P2 + t^2P3 \\
---- \\
R(t) = (1-t)^3P0 + 3t(1-t)^2P1 + 3t^2(1-t)P2 + t^3P3 \\
R(t) = (-P0 + 3P1 -3P2 + P3)t^3 + (3P0 -6P1 + 3P2)t^2 + (-3P0 + 3P1)t + P0 \\
$$

#### Bezier Matrix

$$
\begin{vmatrix}
-1 & 3 & -3 & 1 \\
3 & -6 & 3 & 0 \\
-3 & 3 & 0 & 0 \\
1 & 0 & 0 & 0 \\
\end{vmatrix}

* 
\begin{vmatrix}
P0 \\
P1 \\
P2 \\
P3\\
\end{vmatrix}

= 

\begin{vmatrix}
a \\
b \\
c \\
d \\
\end{vmatrix}

\\

B * G = C
$$

## 03-22-2017 | Aim: 3-D Shapes 

#### Rectangular Prism

- **Given**: One vertex, height, width, and depth
- **Defining Points**: Vertices 
  - Combinations of ``x``, ``x+w``, ``y``, ``y-h``, ``z``, and ``z-d``

#### Sphere

- **Given**: Center, radius

- **Defining Points**: Points on the surface 

- **Generate**: Rotate a circle about the x or y-axis

- $$
  \begin {vmatrix}
  1 & 0 & 0 \\
  0 & cosϕ & -sinϕ \\
  0 & sin\phi & cos\phi \\
  \end{vmatrix}

  *

  \begin{vmatrix}
  rcos\theta \\
  rsin\theta \\
  0 \\
  \end{vmatrix}

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

- **Given**: Center, Radius, Outer Radius

- **Defining Points**: Points on the surface

- **Generate**: Rotate a circle about a point

- $$
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




## 03-30-2017 | aim: Meshes

### Wireframe Meshes

- Defining points are connected to make edges
- Without lighting, we don't lose any detail
- No filling in 
- Don't need to repeat edges 
- Works with our existing edge matrix structure
- Cannot generate good solid objects 

### Polygon Meshes

- Defining points are used as vertices of polygons (triangles) 

- Can be used to generate more realistic 3D objects 

- Can be filled in 

- Cannot use an edge matrix

- Need a new polygon-based drawing system

- Requires more resources than wire frame meshes 

- edge matrix -- > polygon matrix

  - $$[ P_0, P_1, P_2, \ \ \ \ \ \ P_3, P_4, P_5 ... ] $$
  - triangle 0          triangle 1

- ```
  add_box
  add_sphere
  add_torus
  ```

  - adding triangles,
  - points must be added counter-clockwise

- Points for a sphere:

  - semi-circle, so 11 points per slice (if step is 0.1)
  - i, i+11, i+1, i+12


## 04-05-2017 | Aim: Hidden Surface Removal

### Backface Calling

- Ignore any backward-facing polygons

- Important information

  - *V*: vector from the surface of any polygon to the viewer
  - *N*: surface normal ( perpendicular to the plane of the polygon )
  - $$\theta$$ : the angle between *V* and *N*

- Procedure:

  1. Calculate *N*
     - Pick 2 vectors (edges) that share an endpoint, but go in opposite directions
     - *A* = $$P_1 - P_0$$ = $$<x_1 - x_0, y_1 - y_0, z_1 - z_0 >$$ , *B* = $$P_2 - P_0$$ = $$<x_2- x_0, y_2 - y_0, z_2 - z_0 >$$
     - *N* = *A* x *B* ( Cross Product )
     - *N* = $$< a_yb_z - a_zb_y, a_zb_x - a_xb_z, a_xb_y - a_yb_x >$$
  2. Find $$\theta$$ between *V* and *N* 
     - *N* $$*$$ *V* = $$ n_xv_x + n_yv_y + n_zv_z $$ 
     - *N* $$*$$ *V* = $|$ *N* $|$ $|$ *V* $|$ $cos\theta$ 
  3. If $$ -90 < \theta < 90$$, then draw
     - if $$ -90 < \theta < 90$$, then $cos\theta > 0$

  - *V* = $< 0, 0, 1>$ 
  - *N* $$*$$ *V* = $n_zv_z$ 

