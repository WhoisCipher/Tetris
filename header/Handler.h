#pragma once
#include "Grid.h"
#include "Block.h"

class GameHandler {
public:
    GameHandler();
    ~GameHandler();
    void InputHandler();
    void moveLeft();
    void moveRight();
    void moveDown();
    void Rotate();
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
    vector<Block> blocks;
    Block currBlock;
    Block nextBlock;
    float moveLeftTime;
    float moveRightTime;
    float moveDownTime;
    float moveInterval;
    Sound clearRowSound;
    Sound GameOverSound;
};
