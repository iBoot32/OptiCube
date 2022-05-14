# OptiCube
Uses a breadth-first search algorithm to exhaustively search every node in a tree of possible states on a 2x2 cube, resulting in an optimal solution to any scramble. Typically searches about 14,000,000 nodes per second, and solves most scrambles at around depth 8 (with an upper bound of 11).

I plan on implementing opticube into a two-phase solver, first reducing the 2x2 to G1 (therefore pruning the search space down to [R2, U, U', U2, L2]), then further reducing to G2 (solved state). 

Key for inputting / reading moves:

```
a b c = r, r', r2
d e f = u, u', u2
g h i = l, l', l2
j k l = d, d', d2
m n o = f, f', f2
p q r = b, b', b2
```
For example, the scramble `F R F R2 U' F' R U2 R'` would be input as `opticube.exe m a m c e n a f b`
