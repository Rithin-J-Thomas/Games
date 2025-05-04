#include "raylib.h"
#include <iostream>
#include <string>

void Move_Player(int *player_Y_pos, int move_how_much)
{


    *player_Y_pos += move_how_much;// //player_Y_pos = 360 starting

    // // std::cout<<"\n player y ps = " <<*player_Y_pos;

    // // std::cout<<"\n player y ps ending = " <<*player_Y_pos+200;

}

void Ball_direction(char dir,int* ball_x)
{
    if(dir=='r')  
    {
        *ball_x -=5;

    }
}



void Ball_hit_paddle(int* player_1_pos ,int* player_2_pos, int* ball_x , int* ball_y,int* ball_speed)
{
    int player_2_pos_end = *player_2_pos+200;
    int player_1_pos_end = *player_1_pos+200;
    char direction;


    // // //checks if ball touched paddles ,why 100 because 30+25 =155 & 1775 is -25 ,25 is radius of ball
    if(*ball_x == 155 || *ball_x == 150)
    {
        //360 560
        if((*player_1_pos <= *ball_y )&&(player_1_pos_end >=  *ball_y)){
            *ball_speed *= -1;
        }
    }        
        
    else if(*ball_x == 1775 || *ball_x == 1780)
    {
        if((*player_2_pos <= *ball_y )&&(player_2_pos_end >=  *ball_y)){
            *ball_speed *= -1;
        }

    }
}





void Ball(int* X ,int ball_speed)
{

    *X +=ball_speed; //X=960 starting
    // //  std::cout<<"\n ball x = " <<*X;
    // // std::cout<<"\n ball y = " <<*Y;


}


void Lost_ball(int* ball_x ,int ball_speed )
{
    std::cout<<*ball_x<<"\n";


    if(*ball_x >= 2000)
    {
        std::cout<<"passed limit";

        Ball(ball_x,ball_speed);

         
    }

}


void Check_Input_Movement(int* player_1_Y,int* player_2_Y)
{
    // // //check left side player's input
    if (IsKeyDown(KEY_DOWN))
    {
        Move_Player(player_2_Y, 10);
    }
    else if (IsKeyDown(KEY_UP))
    {
        Move_Player(player_2_Y, -10);
    }

    // // //check right side player's input
    if (IsKeyDown(KEY_W))
    {
        Move_Player(player_1_Y, -10);
    }
    else if (IsKeyDown(KEY_S))
    {
        Move_Player(player_1_Y, 10);
    }
}

int main()
{

    InitWindow(600, 700, "PONG");

    int height, width;
    height = GetMonitorHeight(0);
    width = GetMonitorWidth(0);

    int  ball_speed = 10;

    
    int player_1_Y = height / 3, player_2_Y = height / 3;

    int ball_x = width / 2 ,ball_y = (height / 3) + 100;

    InitWindow(width, height, "PONG");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground({28, 28, 74});

        // // //func for make player move
        Check_Input_Movement(&player_1_Y,&player_2_Y);


        // // //for left side board
        DrawRectangle(100, player_1_Y, 30, 200, WHITE);

        // // //for ball placement  "(height/3)+100"= to place same level as board position
        DrawCircle(ball_x,ball_y, 25, YELLOW);
        Ball(&ball_x,ball_speed);

        // // //for right side board
        DrawRectangle(1800, player_2_Y, 30,200, WHITE);
        

        Ball_hit_paddle(&player_1_Y,&player_2_Y,&ball_x,&ball_y,&ball_speed);

        Lost_ball(&ball_x,ball_speed);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
