#include "Grid.h"
#include <string>
#include "Color.h"

Grid::Grid() {
    rows = 20;
    cols = 10;
    cellSize = 30;
    score = 0;
    Initialize();
    colors = GetColors();
}

void Grid::Initialize() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = 0;
        }
    }
    score = 0;
}

void Grid::DrawGrid(){
    for(int i=0;i < rows;++i){
        for(int j=0;j < cols;++j){
            int indexVal = grid[i][j];
            DrawRectangle(j*cellSize+21, i*cellSize+21, cellSize-1, cellSize-1, colors[indexVal]);
        }
    }   
}

bool Grid::checkBounds(int x, int y)
{
    if(x >= 0 && x < rows && y >= 0 && y < cols)
        return false;
    return true;
}

bool Grid::cellEmpty(int x, int y){
    if(grid[x][y]==0)
        return true;    
    return false;
}

int Grid::clearRows() {
    int completed = 0;
    for(int i = rows-1; i>=0;--i) {
        if(isRowCompleted(i)){
            clearCompletedRow(i);
            completed++;
        }
        else if(completed > 0){
            moveRowDown(i, completed);
        }
    }
    return completed;
}

const char* Grid::GetScore() {
    std::string scoreStr = std::to_string(score);
    return scoreStr.c_str();
}


bool Grid::isRowCompleted(int checkRow) {
    for(int i=0;i<cols;++i) 
        if(grid[checkRow][i] == 0)
            return false;
    return true;
}

void Grid::clearCompletedRow(int completedRow) {
    for(int i=0;i<cols;++i)
        grid[completedRow][i] = 0;
    score+=100;
}

void Grid::moveRowDown(int completedRow, int numRows) {
    for(int i = 0; i < cols; ++i) {
        grid[completedRow + numRows][i] = grid[completedRow][i]; // Corrected indices
        grid[completedRow][i] = 0;  // Clear the original row
    }
}