#include <iostream>

#include "raylib.h"
#include "snake.hpp"
#include "food.hpp"
#include "other.hpp"

// std::cout<<"Found it Found it Found it\n";

int main()
{
        extern int snake_x, snake_y;

        int screen_height, screen_width;

        screen_height = GetScreenHeight();
        screen_width = GetScreenWidth();

        Snake snake_obj;
        Food food_obj;
        Other other_obj;

        InitWindow(screen_width, screen_height, "SNAKE");

        SetTargetFPS(60);

        while (!WindowShouldClose())
        {

                BeginDrawing();
                ClearBackground(DARKGREEN);

                food_obj.spawn_food();    // // //Renders food
                snake_obj.render_snake(); // // //Renders Snake

                if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
                {
                        return WindowShouldClose();
                }

                other_obj.user_input();
                other_obj.eat_food(&snake_x, &snake_y, food_obj.food_x, food_obj.food_y, food_obj);

                EndDrawing();
        }

        CloseWindow();

        return 0;
}
