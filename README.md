# Game of Life

This project is an implementation of **Conway's Game of Life**, a zero-player game where the evolution of the grid is determined by its initial state and a set of simple rules. It uses the **Raylib** library for rendering and interactive gameplay.

---

## Features

- **Dynamic Grid Display**: The grid visually represents live (green) and dead (grey) cells.
- **Interactive Cell Editing**: Use the mouse to toggle the state of individual cells.
- **Simulation Controls**:
  - **Start/Stop**: Toggle the simulation using the keyboard.
  - **Random State Generation**: Randomize the grid's initial state.
  - **Clear Grid**: Reset the grid to an empty state.
  - **Adjust Speed**: Increase or decrease simulation speed dynamically.
- **Toroidal Grid Wrapping**: The edges of the grid connect seamlessly, creating a "wrap-around" effect.

---

## Controls

| Key/Mouse           | Action                                 |
|---------------------|----------------------------------------|
| `Left Mouse Button` | Toggle the state of a cell (alive/dead)|
| `Enter`             | Start the simulation                  |
| `Space`             | Stop the simulation                   |
| `R`                 | Randomize the grid state              |
| `C`                 | Clear the grid                        |
| `F`                 | Increase simulation speed             |
| `S`                 | Decrease simulation speed             |

---

## Rules of the Game

1. **For a live cell**:
   - It survives if it has 2 or 3 live neighbors.
   - It dies if it has fewer than 2 neighbors (underpopulation) or more than 3 neighbors (overpopulation).

2. **For a dead cell**:
   - It becomes alive if it has exactly 3 live neighbors (reproduction).

---

## Code Structure

- **Main File (`main.cpp`)**: Handles the game loop and user input.
- **Grid Class (`grid.hpp`, `grid.cpp`)**:
  - Manages the grid's state, including drawing, toggling cells, and random state generation.
  - Implements toroidal wrapping for seamless grid boundaries.
- **Simulation Class (`simulation.hpp`, `simulation.cpp`)**:
  - Encapsulates the Game of Life logic, including rules application and neighbor counting.
  - Controls the grid update process and state transitions.

---

## Code Structure

- Grid Size: Modify screenWidth, screenHeight, or cellSize in the main.cpp file to adjust the grid dimensions.
- Simulation Speed: Change the initial fps value in main.cpp to set a different starting speed.

---

Enjoy exploring the fascinating patterns of Conway's Game of Life! 😊
