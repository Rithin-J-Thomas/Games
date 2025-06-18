#include <iostream>
#include "player.hpp"
#include "other.hpp"
#include <raylib.h>

// // //global variables

int screenWidth = GetMonitorWidth(0);
int screenHeight = GetMonitorHeight(0);


int main()
{
       // // //std::cout<<;

       InitWindow(screenWidth, screenHeight, "BOUND BY TIME");


       SetWindowPosition(0, 10);

       Player playerObj;
       Other otherObj;

       SetTargetFPS(60);

       playerObj.LoadPlayerImage();
       otherObj.loadBackgroundImage();

       while (!WindowShouldClose())

       {
              screenWidth = GetMonitorWidth(0), screenHeight = GetMonitorHeight(0); // // takes screen size both Height , Width

              BeginDrawing();

              ClearBackground(WHITE);

              otherObj.renderBackgroundImage();
              playerObj.renderPlayerImg();


              if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
              {
                     return WindowShouldClose();// //  Exit shortcut
              }

              playerObj.movePlayer();



              EndDrawing();
       }

       playerObj.unloadPlayerImage();
       otherObj.unloadPlayerImage();
       CloseWindow();
       return 0;
}