#pragma once
#include "Grid.h"
#include "Block.h"

class GameHandler {
public:
    GameHandler();
    ~GameHandler();
    void InputHandler(float);
    void moveLeft();
    void moveRight();
    void moveDown();
    void Rotate();
    void Drop();
    void LockBlock();
    void Restart();
    void Draw();
    bool isGameOver();
    Block GetRandomBlock();
    vector<Block> InitializeBlocks();
    bool SpaceforBlock();
    bool boundBlockToGrid();
    void UpdateScore(int clearedRows);
    int score;
    Music bgMusic;

private:
    Grid grid;

    bool gameOver;
    
    float moveDownTimer;
    float moveDownInterval; 

    vector<Block> blocks;
    Block currBlock;
    Block nextBlock;

    Sound clearRowSound;
    Sound GameOverSound;
};
