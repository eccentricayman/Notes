# Splines

```
for t : 1 -> 0
	x = r * cos t
	y = r * sin t
```

- Problem: Given information does not match the coefficients.

### Hermite Curves

- Given: P0, P1, M0, M1

- $$
  f(t)=at^3+bt^2+ct+d \ \ \ \ \ \ \ \ \text{Points at the curve}\\
  f^1(t)=3at^2+2bt+c \ \ \ \ \ \ \ \ \ \text{Slopes at each point}\\
  H * C = G\\
  C = H^{-1} * G
  $$


