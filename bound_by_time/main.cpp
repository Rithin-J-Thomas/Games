#include <iostream>
#include "player.hpp"
#include "other.hpp"
#include <raylib.h>

// // //global variables
int screenWidth = GetMonitorWidth(0), screenHeight = GetMonitorHeight(0);

int main()
{
       // // //std::cout<<;

       InitWindow(screenWidth, screenHeight, "BOUND BY TIME");



       SetWindowPosition(0, 10);

       Player playerObj;
       Other otherObj;
       Box BoxObj;
       MiniGame minigameObj;

       SetTargetFPS(60);

       playerObj.LoadPlayerImage();
       otherObj.loadBackgroundImage();
       BoxObj.loadMissioBoxImage();

       screenWidth = GetMonitorWidth(0), screenHeight = GetMonitorHeight(0);
       int screenSize[2] = {screenWidth, screenHeight};

       while (!WindowShouldClose())

       {

              BeginDrawing();

              ClearBackground(WHITE);

              otherObj.renderBackgroundImage();

              BoxObj.renderMissioBoxImage();

              playerObj.renderPlayerImg();

              if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
              {
                     return WindowShouldClose(); // //  Exit shortcut
              }

              playerObj.movePlayer();

              otherObj.playerTouchMiniGame(playerObj, BoxObj, screenSize);

              DrawFPS(100, 100);
              EndDrawing();
       }

       playerObj.unloadPlayerImage();
       otherObj.unloadBackgroundImage();
       BoxObj.unloadMissioBoxImage();
       CloseWindow();
       return 0;
}