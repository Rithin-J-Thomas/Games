#include "raylib.h"
#include <iostream>
#include <string>

int Point_System(int *player_point, bool *game_over, int turn)
{
	// std::cout<<player_point;
	if (*player_point == 3)
	{
		DrawText(TextFormat("Player %2i Wins", turn), (GetMonitorWidth(0) / 3) + 140, GetMonitorHeight(0) / 3, 50, RED);

		*game_over = true;
	}

	return *player_point += 1;
}

void Move_Player(int *player_Y_pos, int move_how_much)
{

	*player_Y_pos += move_how_much; // //player_Y_pos = 360 starting

	// // std::cout<<"\n player y ps = " <<*player_Y_pos;
	// // std::cout<<"\n player y ps ending = " <<*player_Y_pos+200;
}	

void Horizontal_motion(int *X, int ball_speed_X)
{

	*X += ball_speed_X; // X=960 starting
	// //  std::cout<<"\n ball x = " <<*X;
	// // std::cout<<"\n ball y = " <<*Y;

}

void Diagonal_motion(int* ball_y, int* ball_speed_Y)
{

	*ball_y += *ball_speed_Y;

}

void Ball_hit_paddle(int *player_1_pos, int *player_2_pos, int *ball_x,  int *ball_y, int *ball_speed_X, int*  ball_speed_Y )
{
	int player_2_pos_end = *player_2_pos + 200;
	int player_1_pos_end = *player_1_pos + 200;
	char direction;

	// // //checks if ball touched paddles ,why 100 because 30+25 =155 & 1775 is -25 ,25 is radius of ball
	if (*ball_x == 155 || *ball_x == 150)
	{
		// 360 560
		if ((*player_1_pos <= *ball_y) && (player_1_pos_end >= *ball_y))
		{
			
			// // //This is for dividing  player board into 7  parts 1,2,3	 , 	5,6,7 has 30 pixel and 4 has 20 pixel (4 is center to make ball go striaght )
			int player_1_pos_part1 = *player_1_pos + 30 ; 
			int player_1_pos_part2 = *player_1_pos + 60 ; 
			int player_1_pos_part3 = *player_1_pos + 90 ; 
			int player_1_pos_part4 = *player_1_pos + 110 ; 
			int player_1_pos_part5 = *player_1_pos + 140 ; 
			int player_1_pos_part6 = *player_1_pos + 170 ; 
			int player_1_pos_part7 = *player_1_pos + 200 ; 

			*ball_speed_X *= -1;

			if((*player_1_pos <= *ball_y) && (player_1_pos_part1 >= *ball_y))
			{
				std::cout<<"Hit  on 1\n";
				*ball_speed_Y = -5;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_1_pos <= *ball_y) && (player_1_pos_part2 >= *ball_y))
			{
				std::cout<<"Hit  on 2\n";
				*ball_speed_Y = -3;
				Diagonal_motion(ball_y,ball_speed_Y);


			}
			else if((*player_1_pos <= *ball_y) && (player_1_pos_part3 >= *ball_y))
			{
				std::cout<<"Hit  on 3\n";
				*ball_speed_Y = -1;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_1_pos <= *ball_y) && (player_1_pos_part4 >= *ball_y))
			{
				std::cout<<"Hit  on 4\n";
				*ball_speed_Y = 0;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_1_pos <= *ball_y) && (player_1_pos_part5 >= *ball_y))
			{
				std::cout<<"Hit  on 5\n";
				*ball_speed_Y = 1;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_1_pos <= *ball_y) && (player_1_pos_part6 >= *ball_y))
			{
				std::cout<<"Hit  on 6\n";
				*ball_speed_Y = 3;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_1_pos <= *ball_y) && (player_1_pos_part7 >= *ball_y))
			{
				std::cout<<"Hit  on 7\n";
				*ball_speed_Y = 5;
				Diagonal_motion(ball_y,ball_speed_Y);

			}

		}
   	}

	else if (*ball_x == 1775 || *ball_x == 1780)
	{
		if ((*player_2_pos <= *ball_y) && (player_2_pos_end >= *ball_y))
		{
			*ball_speed_X *= -1;

			int player_2_pos_part1 = *player_2_pos + 30;
			int player_2_pos_part2 = *player_2_pos + 60;
			int player_2_pos_part3 = *player_2_pos + 90;
			int player_2_pos_part4 = *player_2_pos + 110;
			int player_2_pos_part5 = *player_2_pos + 140;
			int player_2_pos_part6 = *player_2_pos + 170;
			int player_2_pos_part7 = *player_2_pos + 200;

			if((*player_2_pos <= *ball_y) && (player_2_pos_part1 >= *ball_y))
			{
				std::cout<<"Hit  on 1\n";
				*ball_speed_Y = -5;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_2_pos <= *ball_y) && (player_2_pos_part2 >= *ball_y))
			{
				std::cout<<"Hit  on 2\n";
				*ball_speed_Y = -3;
				Diagonal_motion(ball_y,ball_speed_Y);


			}
			else if((*player_2_pos <= *ball_y) && (player_2_pos_part3 >= *ball_y))
			{
				std::cout<<"Hit  on 3\n";
				*ball_speed_Y = -1;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_2_pos <= *ball_y) && (player_2_pos_part4 >= *ball_y))
			{
				std::cout<<"Hit  on 4\n";
				*ball_speed_Y = 0;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_2_pos <= *ball_y) && (player_2_pos_part5 >= *ball_y))
			{
				std::cout<<"Hit  on 5\n";
				*ball_speed_Y = 1;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_2_pos <= *ball_y) && (player_2_pos_part6 >= *ball_y))
			{
				std::cout<<"Hit  on 6\n";
				*ball_speed_Y = 3;
				Diagonal_motion(ball_y,ball_speed_Y);

			}
			else if((*player_2_pos <= *ball_y) && (player_2_pos_part7 >= *ball_y))
			{
				std::cout<<"Hit  on 7\n";
				*ball_speed_Y = 5;
				Diagonal_motion(ball_y,ball_speed_Y);

			}



		}
	}
}

void Reset_Ball(int *ball_x,int* ball_y, int *ball_speed_X , int *ball_speed_Y , int height)
{

	*ball_x = 960;
	*ball_y = (height / 3) + 100;

}



void Lost_ball(int *ball_x,int* ball_y, int ball_speed_X, int ball_speed_Y, int *player_1_point, int *player_2_point, bool *game_over , int height)
{
	// std::cout<<*ball_x<<"\n";

	if (*ball_x >= 2000)
	{

		int playr_1_point = Point_System(player_1_point, game_over, 1);

		Reset_Ball(ball_x,ball_y, &ball_speed_X,&ball_speed_Y, height);

		// std::cout<<player_1_point<<"\n";
	}
	else if (*ball_x <= 0)
	{
		int playr_2_point = Point_System(player_2_point, game_over, 2);
		Reset_Ball(ball_x,ball_y, &ball_speed_X,&ball_speed_Y , height);
	}
}

void Check_Input_Movement(int *player_1_Y, int *player_2_Y)
{
	// // //check left side player's input
	if (IsKeyDown(KEY_DOWN))
	{
		Move_Player(player_2_Y, 5);
	}
	else if (IsKeyDown(KEY_UP))
	{
		Move_Player(player_2_Y, -5);
	}

	// // //check right side player's input
	if (IsKeyDown(KEY_W))
	{
		Move_Player(player_1_Y, -5);
	}
	else if (IsKeyDown(KEY_S))
	{
		Move_Player(player_1_Y, 5);
	}
}

int main()
{

	InitWindow(600, 700, "PONG");

	int height, width ;	// // //1080	1920

	height = GetMonitorHeight(0);
	width = GetMonitorWidth(0);

	bool game_over = false;

	int ball_speed_X = 10 , ball_speed_Y = 0;


	int player_1_Y = height / 3, player_2_Y = height / 3;
	int player_point_1 = 0, player_point_2 = 0;

	int ball_x = width / 2, ball_y = (height / 3) + 100;

	//int  curve =  0;	// // //460

	InitWindow(width, height - 95, "PONG");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{		

		BeginDrawing();

		if (game_over == false)
		{

		ClearBackground({28, 28, 74});

		// // //func for make player move
		Check_Input_Movement(&player_1_Y, &player_2_Y);

		// // //for left side board
		DrawRectangle(100, player_1_Y, 30, 200, WHITE);

		// // //for ball placement  "(height/3)+100"= to place same level as board position
		DrawCircle(ball_x, ball_y, 25, YELLOW);
		Horizontal_motion(&ball_x, ball_speed_X);


		Diagonal_motion(&ball_y,&ball_speed_Y);

		if(ball_y <= 25 || ball_y >= 960)
		{
			ball_speed_Y  *= -1;
		}

		// // //for right side board
		DrawRectangle(1800, player_2_Y, 30, 200, WHITE);

		Ball_hit_paddle(&player_1_Y, &player_2_Y, &ball_x, &ball_y, &ball_speed_X, &ball_speed_Y);

		Lost_ball(&ball_x,&ball_y, ball_speed_X , ball_speed_Y, &player_point_1, &player_point_2, &game_over , height);

		// // //scoreboard of both players
		DrawText(TextFormat("Score\t%02i", player_point_1), 100, 10, 50, WHITE);
		DrawText(TextFormat("Score\t%02i", player_point_2), width - 300, 10, 50, WHITE);


		}
		else
		{
			//std::cout<<"Game over";
		}            
		EndDrawing();
	}



	CloseWindow();
	return 0;
}	
