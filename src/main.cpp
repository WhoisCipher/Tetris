#include <raylib.h>
#include "Handler.h"
#include <iostream>

double lastUpdate = 0;

bool EventTriggered(double interval);

int main() {
    
    Color bg = {1,1,20,255};
    double blockSpeed = 0.5f;
    GameHandler gameHandler;
    
    InitWindow(600, 650, "Tetris");

    Font TetrisFont = LoadFontEx("assets/fonts/gameFont.ttf", 32, 0, 250);
    
    SetTargetFPS(60);
    
    float deltaTime = 0.0f;

    while (!WindowShouldClose()) {
    
        float startTime = GetTime();  
        
        gameHandler.InputHandler(deltaTime);
        UpdateMusicStream(gameHandler.bgMusic);

        BeginDrawing();
        ClearBackground(bg);
        
        DrawTextEx(TetrisFont, "Score", {400, 50}, 36, 4, WHITE);
        
        char scoreText[10];
        sprintf(scoreText, "%d", gameHandler.score);
        Vector2 TextSize = MeasureTextEx(TetrisFont, scoreText, 36, 2);
        DrawRectangleRounded({370, 100, 170, 60}, 0.3, 6, DARKGRAY);
        DrawTextEx(TetrisFont, scoreText, {385 + (140 - TextSize.x)/2, 110}, 36, 2, WHITE);
 
        DrawTextEx(TetrisFont, "Next Block", {370, 200}, 32, 4, WHITE);
        DrawRectangleRounded({370, 250, 170, 170}, 0.3, 6, DARKGRAY);
        if(gameHandler.isGameOver()){
            DrawTextEx(TetrisFont, "Game Over", {365, 450}, 36, 4, WHITE);
            DrawTextEx(TetrisFont, "Press R to Restart", {375, 490}, 12, 4, WHITE);
        }

        if(EventTriggered(blockSpeed))
            gameHandler.moveDown();

        gameHandler.Draw();
        
        EndDrawing();
        deltaTime = GetTime() - startTime;
    }

    UnloadFont(TetrisFont);
    CloseWindow();
    return 0;
}

bool EventTriggered(double interval){
    double currTime = GetTime();
    if(currTime - lastUpdate >= interval){
        lastUpdate = currTime;
        return true;
    }
    return false;
}