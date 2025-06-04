#include "snake.hpp"
#include "raylib.h"
#include <iostream>


int snake_x = 800, snake_y = 400;
int *addr_x = &snake_x, *addr_y = &snake_y;
extern char where_to;

void Snake::render_snake()
{
        DrawRectangle(snake_x, snake_y, 50, 50, BLACK);

}

void Snake::move_snake(char where_to)
{
        if (where_to == 'r')
        {
                *addr_x += 5;
        }
        else if (where_to == 'l')
        {
                *addr_x -= 5;
        }
        else if (where_to == 'u')
        {
                *addr_y -= 5;
        }
        else if (where_to == 'd')
        {
                *addr_y += 5;
        }

        // eat_food(&snake_x,&snake_y);
}
