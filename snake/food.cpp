#include <iostream>
#include <random>
#include "raylib.h"
#include "food.hpp"

void Food::spawn_food()
{
        // // //int *addr_x = &food_x, *addr_y = &food_y;
        if (is_spawned == false)
        {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distx(50, 1880);
                food_x = distx(gen);

                std::uniform_int_distribution<> disty(50, 1040);
                food_y = disty(gen);

                is_spawned = true;
        }

        DrawCircle(food_x, food_y, 20, RED);
}
