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

### Rotation

- Rotations across different Axes

  - **Z-Axis:**```( x, y, z ) --R(θ,axis)--> ( xcosθ - ysinθ, ycosθ + xsinθ, z)```

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
    xa \\
    yb \\
    zc \\
    1 \\
    \end{vmatrix}

    \\

    R * E
    $$

  - ​