#pragma once
#include <raylib.h>
#include <vector>


class Grid
{
private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
public:
    Grid(int width, int height, int cellSize)
    : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns,0)) {};
    void Draw();
    void SetValue(int row, int  col, int value);
    int GetValue(int row, int col);
    bool IsWithInBounds(int row, int col);
    int GetRows();
    int GetColumns();
    void FillRandom();
    void Clear();
    void ToggleCell(int row, int col);
    
};

