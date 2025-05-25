#include <iostream>
#include "raylib.h"
#include "snake.hpp"
#include "food.cpp"

int main()
{

        int screen_height, screen_width;

        screen_height = GetScreenHeight();
        screen_width = GetScreenWidth();

        Snake snake_obj;
        Food food_obj;


        InitWindow(screen_width,screen_height, "SNAKE");

        SetTargetFPS(60);
        
        while (!WindowShouldClose())
        {

                BeginDrawing();
                ClearBackground(DARKGREEN);

                if (IsKeyDown(KEY_F9))  // // //exit shortcut
                {
                        return WindowShouldClose();
                }

                snake_obj.move_snake();
                food_obj.spawn_food();


                EndDrawing();
        }

        CloseWindow();

        return 0;
}
