# FDF - 3D Wireframe Renderer

**FDF** is a 3D wireframe visualization program that supports multiple projection modes, including **isometric and orthographic projections (top, front, and side views)**. It processes `.fdf` files containing elevation data and renders them using the **MiniLibX** graphical library.

<img width="800" height="608" alt="tom" src="https://github.com/user-attachments/assets/1a8a4651-38bb-42a9-abcc-75146d4d8d2a" />

> **Note**: Check out the [screenshots](#screenshots) below or this [demo video](https://youtu.be/oSNFE0wsfEY) to see it in action.

This project also integrates **submodules** for both the **MiniLibX** and **libft** libraries, which are automatically pulled and compiled via the Makefile.

## Features

- **3D wireframe rendering** of `.fdf` files.
- **Multiple projections**: Isometric, top, front, and side views.
- **Interactive controls** for zoom, translation, and rotation.
- **Automatic submodule handling** for MiniLibX and libft.
- **Error handling** for invalid or malformed files.
- **Smooth window and event management** with MiniLibX.
- **Preset maps** included in the `maps/` folder.

## Dependencies

- A C compiler (`gcc` or `clang`)
- `make` (for building the project)
- MiniLibX for Linux requires xorg, x11 and zlib, therefore you will need to install the following dependencies: xorg, libxext-dev and zlib1g-dev. Installing these dependencies on Ubuntu can be done as follows:
`sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`
## Installation

Clone the repository and build the project:

```sh
git clone https://github.com/Nabil080/fdf
cd fdf
make
```

The Makefile will automatically pull and compile the required submodules.

## Usage

Run the program with a valid `.fdf` file:

```sh
./fdf maps/42.fdf
```

You can create yours or use the ones stored inside the `maps/` directory.

## File Format (.fdf)

The `.fdf` file contains a grid of integers representing **elevation points** in a 3D space.
Each value represents a point’s **height (Z-coordinate)**.

Example:
```
0  0  0  0  0
0  5  10 5  0
0  10 20 10 0
0  5  10 5  0
0  0  0  0  0
```

## Controls

- **Escape** → Exit
- **Spacebar** → Reset view
- **Scroll Up/Down or + / -** → Zoom in/out
- **W (Up) / A (Left) / S (Down) / D (Right)** → Move the model
- **1 (Rotate X) / 4 (Rotate Y) / 7 (Rotate Z)** → Rotate
- **I** → Switch to Isometric projection
- **T (Top) / F (Front) / R (Right Side)** → Switch to Orthographic projections
- **C** → Change color
- **Enter** → Hide/Show input guide

## Cleaning Up

To remove compiled files, run:

```sh
make clean
```

To completely remove all binaries and object files:

```sh
make fclean
```

## Screenshots

<div style="text-align: center;">
  <p>Screenshots showcasing some maps/rotations/colors. See the <a target="_blank" href="https://youtu.be/oSNFE0wsfEY">demo video</a> for dynamic interactions.</p>
</div>

<div style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/4018bc8d-de0e-4469-a60f-84efae48915b" alt="Pyramide" width="600">
  <p><em>Pyramide</em></p>
</div>

<div style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/85a36ffe-c418-4d8a-9e1e-26473de9c3a7" alt="Pylone" width="600">
  <p><em>Pylone</em></p>
</div>

<div style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/eb795445-e160-49fd-b7b1-5c29ea2c8ae1" alt="Pylone Rotated Color" width="600">
  <p><em>Pylone (Rotated + color changed)</em></p>
</div>

<div style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/217b22ed-90c2-499b-a8e6-fdc974e2d426" alt="Julia Fractol Top View" width="600">
  <p><em>Julia fractol (Top view + color change)</em></p>
</div>

