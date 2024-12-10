#include <raylib.h>  // Include raylib library for graphics and input handling
#include <iostream>  // Include iostream for standard input/output
#include "simulation.hpp"  // Include custom simulation header for the Game of Life logic

int main() 
{
    // Define a custom color for the background
    Color grey = {29, 29, 29, 255};

    // Set screen dimensions and cell size for the grid
    const int screenWidth = 1000;
    const int screenHeigth = 1000;
    const int cellSize = 10;

    // Initial frames per second (FPS)
    int fps = 12;

    // Initialize the Simulation object with screen dimensions and cell size
    Simulation simulation(screenWidth, screenHeigth, cellSize);

    // Initialize the window with a title
    InitWindow(screenWidth, screenHeigth, "Game of Life");

    // Set the initial target FPS for the game
    SetTargetFPS(fps);

    // Main game loop: runs until the user closes the window
    while (!WindowShouldClose()) 
    {   
        // Check if the left mouse button is pressed
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            // Get the mouse position and calculate the corresponding grid cell
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / cellSize;
            int col = mousePosition.x / cellSize;

            // Toggle the state of the selected cell (alive or dead)
            simulation.ToggleCell(row, col);
        }

        // Check if the Enter key is pressed to start the simulation
        if (IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();  // Start the simulation
            SetWindowTitle("Game of Life is running");
        }
        // Check if the Space key is pressed to stop the simulation
        else if (IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();  // Stop the simulation
            SetWindowTitle("Game of Life has stopped");
        }
        // Increase the simulation speed if the 'F' key is pressed
        else if (IsKeyPressed(KEY_F))
        {
            fps += 2;  // Increment FPS by 2
            SetTargetFPS(fps);
        }
        // Decrease the simulation speed if the 'S' key is pressed
        else if (IsKeyPressed(KEY_S))
        {
            if (fps > 5)  // Ensure FPS does not drop below a threshold
            {
                fps -= 2;  // Decrement FPS by 2
                SetTargetFPS(fps);
            }
        }
        // Create a random grid state when the 'R' key is pressed
        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }
        // Clear the grid when the 'C' key is pressed
        else if (IsKeyPressed(KEY_C))
        {
            simulation.clearGrid();
        }

        // Update the simulation state (e.g., calculate the next generation)
        simulation.Update();

        // Begin drawing frame
        BeginDrawing();
        ClearBackground(grey);  // Clear the screen with the background color
        simulation.Draw();  // Draw the grid and cells
        EndDrawing();  // End drawing frame
    }

    // Close the game window and release resources
    CloseWindow();
}
