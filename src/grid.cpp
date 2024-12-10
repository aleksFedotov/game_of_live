#include "grid.hpp"  // Include the header file for the Grid class implementation


const Color ALIVE_COLOR = {0, 255, 0, 255};
const Color DEAD_COLOR = {55, 55, 55, 255};

// Draws the grid on the screen with cells colored based on their state
void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            // Determine the color of the cell: green if alive (1), grey if dead (0)
            Color color = cells[row][col] ? ALIVE_COLOR : DEAD_COLOR;
            
            // Draw the cell as a rectangle, leaving a 1-pixel gap between cells for grid lines
            DrawRectangle(col * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

// Sets the value of a cell at the specified row and column (1 = alive, 0 = dead)
void Grid::SetValue(int row, int col, int value)
{
    // Check if the specified cell is within bounds of the grid
    if (IsWithInBounds(row, col))
    {
        cells[row][col] = value;
    }
}

// Returns the value of a cell (1 = alive, 0 = dead); returns 0 if out of bounds
int Grid::GetValue(int row, int col)
{   
    if (IsWithInBounds(row, col))
    {
        return cells[row][col];
    }
    return 0;  // Default to dead (0) for out-of-bounds cells
}

// Checks if the specified row and column are within the grid bounds
bool Grid::IsWithInBounds(int row, int col)
{
    if (row >= 0 && row < rows && col >= 0 && col < columns)
    {
        return true;
    }
    return false;  // Return false if out of bounds
}

// Returns the total number of rows in the grid
int Grid::GetRows()
{
    return rows;
}

// Returns the total number of columns in the grid
int Grid::GetColumns()
{
    return columns;
}

// Fills the grid with a random state (some cells alive and some dead)
void Grid::FillRandom()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            // Generate a random value; cells become alive only if the value is 4
            int randomValue = GetRandomValue(0, 4);
            cells[row][col] = randomValue == 4 ? 1 : 0;
        }
    }
}

// Clears the grid by setting all cells to dead (0)
void Grid::Clear()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            cells[row][col] = 0;  // Set each cell to dead (0)
        }
    }
}

// Toggles the state of a cell between alive (1) and dead (0)
void Grid::ToggleCell(int row, int col)
{
    if (IsWithInBounds(row, col))
    {
        cells[row][col] = !cells[row][col];  // Flip the cell's state
    }
}
// Ensures that an index wraps around within the valid range [0, max-1].
// This is useful for implementing a toroidal (wrap-around) grid, where cells
// on the edges of the grid logically connect to the opposite edge.
int Grid::WrapIndex(int index, int max) const
{
    return (index + max) % max;;
}
