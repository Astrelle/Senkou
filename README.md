# Senkou
### An [in development] custom 3D game engine built from the ground up in C++ and OpenGL. 

This project is a personal development challenge to build a functional 3D engine, focusing on low-level optimizations, studying linear algebra, and handling real-time rendering. Many directions may be taken simply for the sake of exploration, learning, and hardware-level performance engineering.

---

## 🛠️ Features

### 📐 1. Linear Algebra Core (Vector3 Library)
A custom, lightweight vector math library designed to handle coordinate space manipulation and calculations.
- **Operator Overloading:** Full, intuitive support for vector addition, subtraction, scalar multiplication, and scalar division.
- **Epsilon Safeguards:** Custom floating-point comparison threshold (`EpsilonThreshold = 0.000001f`) to guarantee precise equality checks and prevent zero-division related application crashes.
- **Spatial Mechanics:** - **Dot Product:** Used for camera visibility, direction checks, and determining relative angles.
  - **Cross Product:** Generates perpendicular axes, essential for computing camera right/up basis vectors.
  - **Magnitude Functions:** Fast squared magnitude functions alongside precise distance/magnitude math to minimize square-root overhead during collision and range sweeps.
  - **Linear Interpolation (Lerp):** Smooth spatial transitions clamped mathematically to protect coordinate overshooting.

### 🧮 2. 4x4 Coordinate Space Transformations (Matrix4 Library)
A complete homogeneous coordinate system designed to feed structured spatial data to the graphics pipeline.
- **Row-Major Memory Alignment:** Matches flat array indexing (`float M[16]`) to local space matrices, ensuring seamless cache access patterns.
- **Homogeneous Coordinates ($W$ coordinate manipulation):** Exploits $W = 1.0f$ projection vectors to translate positional data from the bottom row matrix buffers.
- **High-Performance Matrix Multiplication:** An unrolled row-by-column operator (`*`) implementation designed to compress complex hierarchical matrix transforms.
- **Static Transformation Generators:**
  - `makeTranslation(x, y, z)`: Places position data perfectly on the bottom row.
  - `makeScale(x, y, z)`: Maps spatial scaling coefficients along the main diagonal matrix.
  - `makeRotationX / Y / Z(radians)`: Trignometric rotation matrices utilizing localized basis vectors.
- **Pipeline Optimization:** Support for nested compound model matrices (calculated via reverse-order multiplication: $\text{Model} = \text{Translate} \times \text{Rotate} \times \text{Scale}$) to squash multiple positional passes into a single 64-byte payload.

---

## 📈 Roadmap & Planned Modules

- [ ] **Phase 3: Window Integration & GLFW Infrastructure** — Configure cross-platform dependencies, handle hardware context initialization, and spin up an active engine render window.
- [ ] **Phase 4: Shader Pipelines & OpenGL Primitive Rendering** — Write GLSL pipelines to process coordinate translations directly inside GPU shader memory registers.
- [ ] **Phase 5: Camera Systems** — Design Look-At algorithms and Projection Matrices to translate world vectors into screen space coordinates.
- [ ] **Phase 6: Actually Prioritizing Senkou and Not Working On Tendou!**
