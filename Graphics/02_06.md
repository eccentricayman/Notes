# Aim: Bresenham's Line Algorithm

- We start in the center of the pixel.

- 0, 0 is in the bottom left corner.
  $$
  y = mx + b\\y = {\triangle y \over \triangle x}x + b\\(\triangle x)y = (\triangle y)x + (\triangle x)b\\0 = (\triangle y)x - (\triangle x)y + (\triangle x)b\\
  \boxed {A = \triangle y\\B = -(\triangle x)\\C = (\triangle x) b}
  $$



- $$
  f(x, y) = \\
  {= 0: (x, y)\text{ is on the line}\\}
  \lt 0: (x, y)\text{ is above the line}\\
  \gt 0: (x, y)\text{ is below the line}
  $$




- Possible points: (x + 1, y), (x + 1, y + 1)

- Midpoint: (x + 1, y + 1/2)

- $$
  f(x + 1, y + 1/2)\\
  \lt 0 : plot (x + 1, y)\\
  \gt 0 : plot (x + 1, y + 1)\\
  = 0 : \text{either one}
  $$


### Psuedo-Algorithm

$$
x = x_0, y = y_0\\
d = f(x + 1, y + 0.5)\\
\text{while } x \lt x_1:\\
	plot(x, y)\\
	\text{if} (d > 0):\\
	\text{y++;}\\
	\text{x++;}\\
	d = f(x + 1, y + 0.5)
$$

