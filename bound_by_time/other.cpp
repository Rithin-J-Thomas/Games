#include <iostream>
#include "player.hpp"
#include "other.hpp"

extern int screenWidth, screenHeight;

Color bgColor = {36, 43, 54,255};
Color fontColor = {255, 36, 36,255};


void printArrayInDecipher(char *lettersArr, int elementStart, int elementEnd, int *nextLineFromXpos , Color fontColor)
{
        int drawTextAreaYpos = screenHeight / 10 + *nextLineFromXpos, drawTextAreaXpos = screenWidth / 2 + screenWidth / 6;

        for (int i = elementStart; i <= elementEnd; i++)
        {
                char ch[2] = {lettersArr[i], '\0'};
                DrawText(ch, drawTextAreaXpos, drawTextAreaYpos, 45, WHITE);
                drawTextAreaXpos += 40;
        }
        *nextLineFromXpos += 40;
}

void decipherGameInfo()
{

        DrawText("HOW TO PLAY",screenWidth/3,screenHeight/10,30,WHITE);

}



// // // std::cout<<" \n" ;
void MiniGame::GameDecipher(Player *playerobj, bool *game, int *screenSize)
{
        char lettersArr[52];
        int index = 0;
        for (char i = 'A'; i <= 'Z'; i++)
        {
                lettersArr[index++] = i;
        }
        for (char i = 'a'; i <= 'z'; i++)
        {
                lettersArr[index++] = i;
        }


        while (*game == true)
        {
                BeginDrawing();
                ClearBackground(bgColor);

                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                        *game = false; // //  Exit shortcut
                        playerobj->playerDestination.x = (float)screenSize[0] / 8.0f;
                        playerobj->playerDestination.y = (float)screenSize[1] / 2.0f;
                }

                DrawText("LETTERS (HINT)", screenWidth / 2 + screenWidth / 6 , screenHeight / 15 , 30, fontColor);

                int nextLineFromXpos = 15;
                printArrayInDecipher(lettersArr, 0, 10, &nextLineFromXpos,fontColor);
                printArrayInDecipher(lettersArr, 11, 21, &nextLineFromXpos,fontColor);
                printArrayInDecipher(lettersArr, 22, 32, &nextLineFromXpos,fontColor);
                printArrayInDecipher(lettersArr, 33, 43, &nextLineFromXpos,fontColor);
                printArrayInDecipher(lettersArr, 44, 52, &nextLineFromXpos,fontColor);


                DrawText("EXAMPLE OF GAME", screenWidth / 2 + screenWidth / 6 , screenHeight / 2 + screenHeight / 5  ,30, fontColor);

                
                DrawText("Word = ABcDe  Shift = 1\n Solution = BCdEf ", screenWidth / 2 + screenWidth / 6 , screenHeight / 2 + screenHeight / 4  ,30, fontColor);

                decipherGameInfo();
                


                EndDrawing();
        }
}





void Box::loadMissioBoxImage()
{
        int screenWidth = GetMonitorWidth(0);
        int screenHeight = GetMonitorHeight(0);

        ClosedMissionBoxImage = LoadTexture("assets/items/closedbox.png"); // // //Loads both boxes

        // OpenedMissionBoxImage = LoadTexture("assets/items/openedbox.png");

        ClosedMissionBoxImageSource = {0.0f, 0.0f, (float)ClosedMissionBoxImage.width, (float)ClosedMissionBoxImage.height};

        destination_1_and_2PositionY = (float)screenHeight / 2 + (float)screenHeight / 10; // // // Position of 1st box (only Y-axis)  eg=> 540 + 108 = 648
        ClosedMissionBoxImageDestination_1 = {(float)screenWidth / 1.8f, destination_1_and_2PositionY, (float)ClosedMissionBoxImage.width * 1.7f, (float)ClosedMissionBoxImage.height * 1.7f};

        destination_2PositionX = (float)screenWidth / 2 - (float)screenWidth / 10; // // // Position of 2nd (only X-axis)

        ClosedMissionBoxImageDestination_2 = {destination_2PositionX, destination_1_and_2PositionY, (float)ClosedMissionBoxImage.width * 1.7f, (float)ClosedMissionBoxImage.height * 1.7f};

        ClosedMissionBoxOrigin = {0.0f, 0.0f};
        ClosedMissionBoxImageRotation = 0.0f;
}

void Box::renderMissioBoxImage()
{
        DrawTexturePro(ClosedMissionBoxImage, ClosedMissionBoxImageSource, ClosedMissionBoxImageDestination_1, ClosedMissionBoxOrigin, ClosedMissionBoxImageRotation, WHITE);

        DrawTexturePro(ClosedMissionBoxImage, ClosedMissionBoxImageSource, ClosedMissionBoxImageDestination_2, ClosedMissionBoxOrigin, ClosedMissionBoxImageRotation, WHITE);
}

void Box::unloadMissioBoxImage()
{
        UnloadTexture(ClosedMissionBoxImage);
}

// // //render background Image
void Other::loadBackgroundImage()
{
        int screenWidth = GetMonitorWidth(0);
        int screenHeight = GetMonitorHeight(0);

        backgroundImage = LoadTexture("assets/items/Scene_Overview.png");
        backgroundSource = {0.0f, 0.0f, (float)backgroundImage.width, (float)backgroundImage.height};

        backgroundDestination = {0.0f, 0.0f, (float)screenWidth, (float)screenHeight};

        backgroundOrigin = {0.0f, 0.0f};
        backgroundImageRotation = 0.0f;
}

void Other::renderBackgroundImage()
{
        DrawTexturePro(backgroundImage, backgroundSource, backgroundDestination, backgroundOrigin, backgroundImageRotation, WHITE);
}

void Other::unloadBackgroundImage()
{
        UnloadTexture(backgroundImage);
}

void Other::playerTouchMiniGame(Player &playerObj, Box &BoxObj, int screenSize[2])
{
        bool game = true;

        if (CheckCollisionRecs(playerObj.playerDestination, BoxObj.ClosedMissionBoxImageDestination_1))
        {
                std::cout << "contacted         1\n";
                MiniGame minigameobj;
                minigameobj.GameDecipher(&playerObj, &game, screenSize);
        }
        else if (CheckCollisionRecs(playerObj.playerDestination, BoxObj.ClosedMissionBoxImageDestination_2))
        {
                std::cout << "contacted          2 \n";
        }
}
