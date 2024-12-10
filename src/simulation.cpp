#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::Update()
{
    if(IsRunning())
    {
        for(int row = 0; row < grid.GetRows(); row++)
            {
                for(int col = 0; col < grid.GetColumns(); col++)
                {
                    int liveNeighbors = CountLiveNeighbors(row, col);
                    int cellValue = grid.GetValue(row, col);
                    
                    if(cellValue == 1)
                    {
                        if(liveNeighbors > 3 || liveNeighbors < 2)
                        {
                            tempGrid.SetValue(row, col, 0);
                        }
                        else
                        {
                            tempGrid.SetValue(row, col, 1);
                        }
                    }
                    else
                    {
                        if(liveNeighbors == 3)
                        {
                            tempGrid.SetValue(row, col, 1);
                        }
                        else
                        {
                            tempGrid.SetValue(row, col, 0);
                        }
                    }
                }
            }
            grid = tempGrid;
    }
    
}

void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row,col,value);
}

int Simulation::CountLiveNeighbors(int row, int col)
{
    int liveNeighbors = 0;
    std::vector<std::pair<int,int>> neighborsOffsets = 
    {
        {-1, 0}, 
        {1, 0},  
        {0, -1}, 
        {0, 1},  
        {-1, -1},
        {-1, 1}, 
        {1, -1}, 
        {1, 1} 
    };


    for( auto& offset : neighborsOffsets)
    {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborColumn = (col + offset.second + grid.GetColumns()) % grid.GetColumns();
        
        
        liveNeighbors += grid.GetValue(neighborRow,neighborColumn);
    }
 
    return liveNeighbors;
}

bool Simulation::IsRunning()
{
    return run;
}

void Simulation::Start()
{
    run = true;
}

void Simulation::Stop()
{
    run = false;
}

void Simulation::clearGrid()
{
    if(!IsRunning())
    {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if(!IsRunning())
    {
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int col)
{
    if(!IsRunning())
    {
        grid.ToggleCell(row,col);
    }
}
