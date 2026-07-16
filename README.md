# Senkou
A [in development] custom 3D game engine built from the ground up in C++ and OpenGL.

Many choices I make within this project may actually just be made to understand rendering, graphics, and learning linear algebra.

---

## Current Features

### 1. Linear Algebra
A self-implemented vector math library designed for 3D coordinate space transformations.
- **Vector Operations** - Full, intuitive support for vector operations utilizing overloading. Adding, Subtracting, Scalar Multiplication, and Division.
- **Precision Safeguards** - Implementation of floating-point threshholds (`EpsilonThreshold = 0.000001f`) to guarantee precise equality checks and prevent division by zero related crashing or other issues.
- **Geometric Primitives**
  - **Dot Product:** Handles visibility between vectors.
  - **Cross Product:** Generates vector of defined perpendicular axis.
  - **Magnitude Functions:** Fast squared magnitude functions alongside precise distance/magnitude math to minimize square-root overhead during collision and range sweeps.
  - **Linear Interpolation (Lerp):** Supports smooth transition between points with reimplementation of clamping in order to guard from overshooting.

### 2. Matrix Multiplication Library
A self-implemented 4x4 matrix math library designed for coordinate space transformations and projection.
- **Memory Layout** - Stored as a flat 16-element float array (`M[16]`) utilizing row-major alignment in order to map cleanly.
- **Space Transformation** - Supports matrix-vector multiplication utilizing homogeneous coordinates (helper W = 1.0f for vertices) to apply spatial transformation.
- **Matrix Multiplication** - The main purpose of the matrix class, overload multiplication operator utilizing unrolled row-by-column calculations, that took me longer than wanted honestly, in order to combine multiple transformations into a single matrix.
- **Transformation Generators**
  - **Translation** (`makeTranslation(x,y,z)`) stores spatial position offsets directly on bottom row of matrix.
  - **Scaling** (`makeScale(x,y,z)`) maps size multipliers along the diagonal.
  - **Rotation** (`makeRotationX(R) makeRotationY(R) makeRotationZ(R) R = Radians`) constructs rotation matrices with trigonometric basis vectors for each individual axis.

---

## Roadmap

- [ ] **Phase 3: Learning to write ReadMe files**
