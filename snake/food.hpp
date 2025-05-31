#ifndef MY_FOOD_HPP
#define MY_FOOD_HPP

class Food
{

public:
        bool is_spawned = false;

        int food_x = 5, food_y = 5;

        void spawn_food();
};

#endif