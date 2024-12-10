#include <raylib.h>
#include <iostream>
#include "simulation.hpp"


int main() 
{

    Color grey = {29,29,29,255};

    const int screenWidth = 1000;
    const int screenHeigth = 1000;
    const int cellSize = 10;
    int fps = 12;

    Simulation simulation(screenWidth,screenHeigth,cellSize);
 
    

    InitWindow(screenWidth,screenHeigth, "Game of Live");

    SetTargetFPS(fps);

    while(!WindowShouldClose()) 

    {   
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / cellSize;
            int col = mousePosition.x / cellSize;
            simulation.ToggleCell(row,col);
        }
        if(IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game of Life is running");
        }
        else if(IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of Life has stopped");
        }
        else if(IsKeyPressed(KEY_F))
        {
            fps += 2;
            SetTargetFPS(fps);
        }
        else if(IsKeyPressed(KEY_S))
        {
            if(fps > 5) 
            {
                fps -= 2;
                SetTargetFPS(fps);
            }
        }
        else if(IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }
        else if(IsKeyPressed(KEY_C))
        {
            simulation.clearGrid();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(grey);
        simulation.Draw();
        EndDrawing();
    }


    CloseWindow();
}