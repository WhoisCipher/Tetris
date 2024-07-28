#include "Block.h"
#include "Color.h"

Block::Block(){
    size = 30;
    rotationState = 0;
    colors = GetColors();
    xOffset = 0;
    yOffset= 0;
}

void Block::Draw(int xOff, int yOff){
    vector<Position> blockDisplay = GetTilePositions();
    for(Position pos: blockDisplay){
        DrawRectangle(pos.y*size+21 + xOff, pos.x*size+21+yOff, size-1, size-1, colors[colorID]);
    }
}

void Block::Move(int x, int y){
    xOffset += x;
    yOffset += y;
}

void Block::Rotate()
{
    rotationState++;

    // Wrap Around
    if(rotationState == (int)cells.size())
        rotationState = 0;
}

void Block::UndoRotate()
{
    rotationState--;

    // Wrap Around
    if(rotationState == -1)
        rotationState = cells.size() - 1;
}

vector<Position> Block::GetTilePositions(){
    vector<Position> blockDisplay = cells[rotationState];
    vector<Position> movedPos;
    for(Position item: blockDisplay){
        Position newPos = Position(item.x+yOffset, item.y+xOffset);
        movedPos.push_back(newPos);
    }
    return movedPos;
}

OBlock::OBlock(){
    colorID = 1;
    cells[0] = {Position(0,0), Position(1,0), Position(0,1), Position(1,1)};
    Move(4, 0);
}

IBlock::IBlock(){
    colorID = 2;    
    cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
    cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
    cells[2] = {Position(3,0), Position(3,1), Position(3,2), Position(3,3)};
    cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
    Move(3, -1);
}

SBlock::SBlock(){
    colorID = 3;
    cells[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
    cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
    cells[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
    cells[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
    Move(3, 0);


}

ZBlock::ZBlock(){
    colorID = 4;
    cells[0] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
    cells[1] = {Position(0,2), Position(1,1), Position(1,2), Position(2,1)};
    cells[2] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
    cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,0)};
    Move(3, 0);
}

LBlock::LBlock(){
    colorID = 5;
    cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
    cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
    cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
    cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
    Move(3, 0);
}

JBlock::JBlock(){
    colorID = 6;
    cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
    cells[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
    cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
    cells[3] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
    Move(3, 0);
}

TBlock::TBlock(){
    colorID = 7;
    cells[0] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
    cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
    cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
    cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
    Move(3, 0);
}

