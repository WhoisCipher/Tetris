#pragma once
#include<raylib.h>
#include<vector>    
using namespace std;

class Grid {
public:
    
    int grid[20][10];
    
    Grid();
    void Initialize();
    void DrawGrid();
    bool checkBounds(int, int);
    bool cellEmpty(int, int);
    int clearRows();
    const char* GetScore();

private:
    bool isRowCompleted(int);
    void clearCompletedRow(int);
    void moveRowDown(int, int);
    int score;
    int rows;
    int cols;
    int cellSize;
    vector<Color> colors;
};
