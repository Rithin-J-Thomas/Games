#ifndef MY_OTHER_HPP
#define MY_OTHER_HPP


class Other
{
public:
        void user_input();

        int AddPoint(int &score);

        void DisplayScore(int score);

        void eat_food(int *x, int *y, int fx, int fy, Food &food_obj);

        void CheckGameOver(int snake_x,int snake_y,bool &game_over);

        void Border();

};

#endif