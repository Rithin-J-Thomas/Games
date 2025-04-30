#include "raylib.h"
#include <iostream>
#include <string>

void Move_Player(int *player, int move_how_much)
{

    *player += move_how_much;

    std::cout << "testing pointer   = " << *player << "\n";
}


void Ball(int* X ,int* Y)
{
    *X +=10;
    std::cout<<*X<<"\n\n";
}


void Check_Input_Movement(int* player_1,int* player_2)
{
    // // //check left side player's input
    if (IsKeyDown(KEY_DOWN))
    {
        Move_Player(player_2, 10);
    }
    else if (IsKeyDown(KEY_UP))
    {
        Move_Player(player_2, -10);
    }

    // // //check right side player's input
    if (IsKeyDown(KEY_W))
    {
        Move_Player(player_1, -10);
    }
    else if (IsKeyDown(KEY_S))
    {
        Move_Player(player_1, 10);
    }
}

int main()
{

    InitWindow(600, 700, "PONG");

    int height, width;
    height = GetMonitorHeight(0);
    width = GetMonitorWidth(0);

    int player_1 = height / 3, player_2 = height / 3;

    int ball_x = width / 2 ,ball_y = (height / 3) + 100;

    InitWindow(width, height, "PONG");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground({28, 28, 74});

        // // //func for make player move
        Check_Input_Movement(&player_1,&player_2);


        // // //for left side board
        DrawRectangle(100, player_1, 30, 200, WHITE);

        // // //for ball placement  "(height/3)+100"= to place same level as board position
        DrawCircle(ball_x,ball_y, 25, YELLOW);
        Ball(&ball_x,&ball_y);
        // ball_x+=10;     
        // ball_y+=10;
        // // //for right side board
        DrawRectangle(1800, player_2, 30, 200, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
