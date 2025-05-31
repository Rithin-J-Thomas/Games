#include "food.hpp"
#include "snake.hpp"
#include "other.hpp"
#include "raylib.h"
#include <iostream>

Snake snake_obj;

void Other::user_input()
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

// void Other::get_point()
// {

// }

void Other::eat_food(int *x, int *y, int fx, int fy, Food &food)
{
        // // //std::cout<<*x<<"\t"<<*y<<"\t"<<fx<<"\t"<<fy<<"\n";

        int snke_x_end = *x + 50, snke_y_end = *y + 50;

        if ((*x <= fx && snke_x_end >= fx) && (*y <= fy && snke_y_end >= fy))
        {
                // get_point();

                food.is_spawned = false;
        }
}
