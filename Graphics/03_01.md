# Aim: Transformations

### Translations

- T(a, b, c)
  - (x, y, z) → (x + a, y + b, z + c)

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



### Scaling

- S(a, b, c)
  - (x, y, z) → (xa, yb, zc)

  - T → S → T

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



### Rotation

- R(θ, T, Z)

  - (x, y, z) → (?, ? , z)
  - x = r * cos θ
  - y = r * sin θ
  - x1 = rcos (&fi;  θ)
  - r cos &fi; * cos θ - r sin &fi; * sin θ
  - y1 = r sin( &fi +θ )
  - y * cos θ + y * sin θ

  $$
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

- R * e0 = E1 

- S

- e3 = T * S *r * E0

- r * e0
