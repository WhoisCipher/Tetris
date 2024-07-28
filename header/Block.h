#pragma once

#include <raylib.h>
#include <map>
#include <vector>
#include "Position.h"

using namespace std;

class Block{
public: 
    
    // Functions
    Block();
    void Draw(int, int);
    void Move(int, int);
    void Rotate();
    void UndoRotate();
    vector<Position> GetTilePositions();
    
    // Variables
    map<int, vector<Position>> cells;
    int colorID;

private:
    int size;
    int rotationState;
    int xOffset;
    int yOffset;
    vector<Color> colors;
};

class OBlock : public Block{
public:
    OBlock();
};

class IBlock : public Block{
public:
    IBlock();
};

class SBlock : public Block{
public:
    SBlock();
};

class ZBlock : public Block{
public:
    ZBlock();
};

class LBlock : public Block{
public:
    LBlock();
};

class TBlock : public Block{
public:
    TBlock();
};

class JBlock : public Block{
public:
    JBlock();
};