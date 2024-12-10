#include "simulation.hpp"  // Include the header file for the Simulation class

// Draws the current state of the grid
void Simulation::Draw()
{
    grid.Draw();  // Calls the Grid's Draw method to render the grid
}

// Updates the simulation state based on the rules of Conway's Game of Life
void Simulation::Update()
{
    if (IsRunning())  // Only update if the simulation is running
    {
        // Iterate over each cell in the grid
        for (int row = 0; row < grid.GetRows(); row++)
        {
            for (int col = 0; col < grid.GetColumns(); col++)
            {
                int liveNeighbors = CountLiveNeighbors(row, col);  // Count live neighbors
                int cellValue = grid.GetValue(row, col);  // Get the current cell value (alive or dead)
                
                // Apply the rules of Conway's Game of Life
                if (cellValue == 1)  // Cell is alive
                {
                    // A live cell dies if it has less than 2 or more than 3 live neighbors
                    if (liveNeighbors > 3 || liveNeighbors < 2)
                    {
                        tempGrid.SetValue(row, col, 0);  // Cell dies
                    }
                    else
                    {
                        tempGrid.SetValue(row, col, 1);  // Cell survives
                    }
                }
                else  // Cell is dead
                {
                    // A dead cell becomes alive if it has exactly 3 live neighbors
                    if (liveNeighbors == 3)
                    {
                        tempGrid.SetValue(row, col, 1);  // Cell becomes alive
                    }
                    else
                    {
                        tempGrid.SetValue(row, col, 0);  // Cell remains dead
                    }
                }
            }
        }
        grid = tempGrid;  // Copy the temporary grid to the main grid
    }
}

// Sets the value of a specific cell (1 = alive, 0 = dead)
void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

// Counts the number of live neighbors around a specific cell
int Simulation::CountLiveNeighbors(int row, int col)
{
    int liveNeighbors = 0;
    int rows = grid.GetRows();
    int cols = grid.GetColumns();
    // Offsets for all 8 possible neighbors relative to a cell
    std::vector<std::pair<int, int>> neighborsOffsets = 
    {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Top-left
        {-1, 1},  // Top-right
        {1, -1},  // Bottom-left
        {1, 1}    // Bottom-right
    };

    // Loop through each neighbor offset
    for (auto& offset : neighborsOffsets)
    {
        // Calculate the position of the neighbor (using wrapping for grid edges)
        int neighborRow = grid.WrapIndex(row + offset.first, rows);
        int neighborCol = grid.WrapIndex(col + offset.second, cols);
        
        // Add the value of the neighbor cell to the liveNeighbors count
        liveNeighbors += grid.GetValue(neighborRow, neighborCol);
    }

    return liveNeighbors;  // Return the total number of live neighbors
}

// Returns whether the simulation is currently running
bool Simulation::IsRunning()
{
    return run;
}

// Starts the simulation
void Simulation::Start()
{
    run = true;
}

// Stops the simulation
void Simulation::Stop()
{
    run = false;
}

// Clears the grid by setting all cells to dead, but only if the simulation is stopped
void Simulation::clearGrid()
{
    if (!IsRunning())  // Prevent clearing while the simulation is running
    {
        grid.Clear();
    }
}

// Randomly populates the grid with live and dead cells, but only if the simulation is stopped
void Simulation::CreateRandomState()
{
    if (!IsRunning())  // Prevent randomization while the simulation is running
    {
        grid.FillRandom();
    }
}

// Toggles the state of a specific cell between alive and dead, but only if the simulation is stopped
void Simulation::ToggleCell(int row, int col)
{
    if (!IsRunning())  // Prevent toggling while the simulation is running
    {
        grid.ToggleCell(row, col);
    }
}
