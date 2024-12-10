#include "grid.hpp"



void Grid::Draw()
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < columns; col++)
        {
            Color color = cells[row][col] ? Color{0, 255, 0,255} : Color{55,55,55,255};
            DrawRectangle(col *cellSize, row * cellSize, cellSize-1,cellSize-1, color);
        }
    }
}

void Grid::SetValue(int row, int col, int value)
{
    if(IsWithInBounds(row,col))
    {
        cells[row][col] = value;
    }
}

int Grid::GetValue(int row, int col)
{   
    if(IsWithInBounds(row, col))
    {
        return cells[row][col];
    }
    return 0;
}

bool Grid::IsWithInBounds(int row, int col)
{
    if(row >=0 && row < rows && col >= 0 && col < columns)
    {
        return true;
    }

    return false;
}

int Grid::GetRows()
{
    return rows;
}

int Grid::GetColumns()
{
    return columns;
}

void Grid::FillRandom()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            int randomValue = GetRandomValue(0,4);
            cells[row][col] = randomValue == 4 ? 1 : 0;
        }
        
    }
    
}

void Grid::Clear()
{
    for (int row = 0; row < rows; row++)
    {
        for (int  col = 0; col < columns; col++)
        {
            cells[row][col] = 0;
        }
        
    }
    
}

void Grid::ToggleCell(int row, int col)
{
    if(IsWithInBounds(row,col))
    {
        cells[row][col] = !cells[row][col];
    }
}
