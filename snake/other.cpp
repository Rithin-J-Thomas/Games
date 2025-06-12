#include "food.hpp"
#include "snake.hpp"
#include "other.hpp"
#include "raylib.h"
#include <iostream>

int score = 0;

Snake snake_obj;
Color darker_green = {3, 84, 0, 255};

void  Other::user_input()
{
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) // // //exit shortcut
        {
                char where_to = 'r';
                snake_obj.move_snake(where_to);

        }
        else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) // // //exit shortcut
        {
                char where_to = 'l';
                snake_obj.move_snake(where_to);
        }
        else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) // // //exit shortcut
        {
                char where_to = 'u';
                snake_obj.move_snake(where_to);
        }
        else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) // // //exit shortcut
        {
                char where_to = 'd';
                snake_obj.move_snake(where_to);
        }
}

int Other::AddPoint(int &score)
{
        return score + 1;
}

void Other::DisplayScore(int score)
{
        std::cout << score;
}

void Other::eat_food(int *x, int *y, int fx, int fy, Food &food)
{
        // // //std::cout<<*x<<"\t"<<*y<<"\t"<<fx<<"\t"<<fy<<"\n";

        int snke_x_end = *x + 50, snke_y_end = *y + 50;

        if ((*x <= fx && snke_x_end >= fx) && (*y <= fy && snke_y_end >= fy))
        {

                score = AddPoint(score);
                std::cout << score;

                food.is_spawned = false;
        }
}

void Other::CheckGameOver(int snake_x, int snake_y, bool &game_over)
{
        // std::cout<<snake_x<<"\t"<<snake_y<<"\n";

        if (snake_x <= 50 || snake_x >= 1820 || snake_y <= 50 || snake_y >= 940)
        {
                game_over = true;
        }
}

void Other::Border()
{
        DrawRectangle(0, 0, 50, 1080, darker_green);
        DrawRectangle(1870, 0, 50, 1080, darker_green);
        DrawRectangle(0, 0, 1920, 50, darker_green);
        DrawRectangle(0, 990, 1920, 50, darker_green);
}