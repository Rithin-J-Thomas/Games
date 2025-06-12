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
                std::uniform_int_distribution<> distx(70, 1845);
                food_x = distx(gen);


                std::uniform_int_distribution<> disty(75, 965);
                food_y = disty(gen);
                std::cout<<food_x<<"\t"<<food_y<<"\n";
                is_spawned = true;
        }

        DrawCircle(food_x, food_y, 20, RED);

}
