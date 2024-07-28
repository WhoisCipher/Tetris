#include "Handler.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

GameHandler::GameHandler(){
        grid = Grid();
        gameOver = false;
        blocks = InitializeBlocks();
        currBlock = GetRandomBlock();
        nextBlock = GetRandomBlock();
        score = 0;
        std::srand(std::time(0));

        InitAudioDevice();
        bgMusic = LoadMusicStream("assets/sounds/bgMusic.mp3");
        SetMusicVolume(bgMusic, 1.0f);
        PlayMusicStream(bgMusic);
        bgMusic.looping = true;

        clearRowSound = LoadSound("assets/sounds/clear.wav");
        GameOverSound = LoadSound("assets/sounds/GameOver.mp3");

        moveDownTimer = 0.0f;
        moveDownInterval = 0.15f;
}

GameHandler::~GameHandler(){
    UnloadSound(clearRowSound);
    UnloadSound(GameOverSound);
    UnloadMusicStream(bgMusic);
    CloseAudioDevice();
}

bool GameHandler::isGameOver(){
    return gameOver;
}

void GameHandler::LockBlock() {
    vector<Position> blockTiles = currBlock.GetTilePositions();
    for(Position item: blockTiles)
        grid.grid[item.x][item.y] = currBlock.colorID;
    
    currBlock = nextBlock;
    if(!SpaceforBlock()){
        gameOver = true;
        PlaySound(GameOverSound);
        StopMusicStream(bgMusic);
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.clearRows();
    if(rowsCleared>0) {
        PlaySound(clearRowSound);
        UpdateScore(rowsCleared);
    }   
}

bool GameHandler::SpaceforBlock() {
    vector<Position> blockTiles = currBlock.GetTilePositions();
    for(Position item: blockTiles)
        if(grid.cellEmpty(item.x, item.y) == false)
            return false;
    return true;
}

bool GameHandler::boundBlockToGrid() {
    vector<Position> blockTiles = currBlock.GetTilePositions();
    for(Position item: blockTiles){
        if(grid.checkBounds(item.x, item.y))
            return true;
    }
    return false;
}

void GameHandler::UpdateScore(int clearedRows) {
    switch (clearedRows)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }
}

void GameHandler::Restart() {
    grid.Initialize();
    blocks = InitializeBlocks();
    currBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    PlayMusicStream(bgMusic);
    score = 0;
}

Block GameHandler::GetRandomBlock(){

    if(blocks.empty()){
        blocks = InitializeBlocks();
    }

    int randIdx = rand() % blocks.size();

    Block block = blocks[randIdx];

    // Deletes after showing up once in a cycle
    blocks.erase(blocks.begin() + randIdx);
    return block;
}

vector<Block> GameHandler::InitializeBlocks(){
    return {OBlock(), IBlock(), SBlock(), ZBlock(), LBlock(), JBlock(), TBlock()};
}

void GameHandler::Draw(){
    grid.DrawGrid();
    currBlock.Draw(0, 0);
    switch (nextBlock.colorID)
    {
    case 1:
        nextBlock.Draw(280, 280);
        break;
    case 2:
        nextBlock.Draw(285, 300);
        break;
    default:
        nextBlock.Draw(300, 280);
        break;
    }
}

void GameHandler::InputHandler(float deltaTime){
    int keyInput = GetKeyPressed();

    if(gameOver && keyInput == KEY_R){
        gameOver = false;
        Restart();
    }

    if (IsKeyDown(KEY_DOWN)) {
        moveDownTimer += deltaTime;
        if (moveDownTimer >= moveDownInterval) {
            moveDown();
            moveDownTimer = 0.0f;
        }
    }

    if(keyInput == KEY_LEFT)
        moveLeft();
    
    if(keyInput == KEY_RIGHT)
        moveRight();
    
    if(keyInput == KEY_UP)
        Rotate();
    if(keyInput == KEY_SPACE)
        Drop();
    
}

void GameHandler::moveLeft(){
    if(!gameOver){
        currBlock.Move(-1, 0);
        if(boundBlockToGrid() || !SpaceforBlock())
            currBlock.Move(1, 0);
    }
}

void GameHandler::moveRight(){
    if(!gameOver){
        currBlock.Move(1, 0);
        if(boundBlockToGrid() || !SpaceforBlock())
            currBlock.Move(-1, 0);
    }
}

void GameHandler::moveDown(){
    if(!gameOver){    
        currBlock.Move(0, 1);
        if(boundBlockToGrid() || !SpaceforBlock()){
            currBlock.Move(0, -1);
            LockBlock();    
        }
    }
}

void GameHandler::Rotate(){
    if(!gameOver) {
        currBlock.Rotate();
        if(boundBlockToGrid() || !SpaceforBlock())
            currBlock.UndoRotate();
    }
}

void GameHandler::Drop(){
    if(!gameOver){
        while(!boundBlockToGrid()){
            if(SpaceforBlock())
                currBlock.Move(0, 1);
            else
                break;
        }
        currBlock.Move(0,-1);
        LockBlock();
    }
}