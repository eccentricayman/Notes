### Wireframe Meshes

- Defining points are connected to make edges
- Without lighting, we don't lose any detail
- No filling in
- No need to repeat edges
- Works with our existing edge matrix structure



- Cannot generate good solid objects

### Polygon Meshes

- Defining points are used are vertices of polygons (triangles)
- Can be used to generate more realistic 3D objects
- Can be filled in



- Cannot use edge matrix
- Need a new polygon based drawing system
- Requires more resources than wire frame meshes



edge matrix → polygon matrix
$$
[P_0, P_1, P_2, P_3, P_4, P_5...]\\
\text{triangle 0    triangle 1}
$$
add_box

add_sphere

add_torus

- Adding triangles
- Points must be added counterclockwise


- Must be semi-circle, and 11 points per slice