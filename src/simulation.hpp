#pragma once
#include "grid.hpp"

class Simulation
{
private:
    Grid grid;
    Grid tempGrid;
    bool run;
public:
    Simulation(int width, int height, int cellSize)
    : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false){};
    void Draw();
    void Update();
    void SetCellValue(int row, int col, int value);
    int CountLiveNeighbors(int row, int col);
    bool IsRunning();
    void Start();
    void Stop();
    void clearGrid();
    void CreateRandomState();
    void ToggleCell(int row, int col);
   
};

