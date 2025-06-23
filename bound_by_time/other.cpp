#include <iostream>
#include <random>
#include "player.hpp"
#include "other.hpp"
#include "string"

// // // std::cout<<" \n" ;

extern int screenWidth, screenHeight;

Color bgColor = {36, 43, 54, 255};
Color fontColor = {255, 36, 36, 255};

std::vector<char> userLettersVector, codeGeneratedVector , correctCode; // // // stores user's input , random code Generated , correct Code after shift
char lettersArr[52];

int score = 0 , shift;

void printArrayInDecipher(char *lettersArr, int elementStart, int elementEnd, int *nextLineFromXpos, Color fontColor)
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

        DrawText("HOW TO PLAY", screenWidth / 5, screenHeight / 10, 30, fontColor);

        std::string how = {
            " \nYou will be given a coded word and a shift number \nShift each letter forward in the alphabet by the given number\na becomes b or B becomes C and so on\nThe case (uppercase / lowercase) applies the same \nDecode all letters to find the solution \n"};

        DrawText(how.c_str(), screenWidth / 9, screenHeight / 10 + 20, 30, WHITE);
}

void MiniGame::GameDecipher(Player *playerobj, bool *game, int *screenSize)
{
        int index = 0;
        shift = GetRandomValue(1,5);

        for (char i = 'A'; i <= 'Z'; i++)
        {
                lettersArr[index++] = i;
        }
        for (char i = 'a'; i <= 'z'; i++)
        {
                lettersArr[index++] = i;
        }

        
        int i = 0;
        while (i < 8)
        {
                codeGeneratedVector.push_back(char(generateRandomCodes()));

                ++i;
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

                DrawText("LETTERS (HINT)", screenWidth / 2 + screenWidth / 6, screenHeight / 15, 30, fontColor);

                int nextLineFromXpos = 15;
                printArrayInDecipher(lettersArr, 0, 10, &nextLineFromXpos, fontColor);
                printArrayInDecipher(lettersArr, 11, 21, &nextLineFromXpos, fontColor);
                printArrayInDecipher(lettersArr, 22, 32, &nextLineFromXpos, fontColor);
                printArrayInDecipher(lettersArr, 33, 43, &nextLineFromXpos, fontColor);
                printArrayInDecipher(lettersArr, 44, 52, &nextLineFromXpos, fontColor);

                DrawText("EXAMPLE OF GAME", screenWidth / 2 + screenWidth / 6, screenHeight / 2 + screenHeight / 5, 30, fontColor);

                DrawText("Word = ABcDe  Shift = 1\n Solution = BCdEf \n\nWord = ZzaBcD Shift = 1\n Solution = AabCdE \n", screenWidth / 2 + screenWidth / 6, screenHeight / 2 + screenHeight / 4, 30, WHITE);

                decipherGameInfo();

                int drawTextXposOfCodeGenerated = screenWidth / 2 - screenWidth / 6, drawTextYposOfCodeGenerated = screenHeight / 2 + screenHeight / 6;
                for (int i = 0; i < codeGeneratedVector.size(); i++)
                {
                        char ch[2] = {codeGeneratedVector[i], '\0'};

                        DrawText(ch, drawTextXposOfCodeGenerated, drawTextYposOfCodeGenerated, 45, WHITE);
                        drawTextXposOfCodeGenerated += 50;
                }

                userInput();

                int userInputAnswerDisplayXpos = screenWidth / 10;

                for (int i = 0; i < userLettersVector.size(); ++i)
                {
                        std::string charToStringedLetter(1, userLettersVector[i]);
                        DrawText(charToStringedLetter.c_str(), userInputAnswerDisplayXpos, screenHeight / 3, 30, WHITE);
                        userInputAnswerDisplayXpos += 25;
                }

                checkCodeCraked(userLettersVector, codeGeneratedVector);

                EndDrawing();
        }
}

void MiniGame::userInput()
{
        int letterPressedIs = GetCharPressed();

        if ((letterPressedIs >= 65 && letterPressedIs <= 90) || (letterPressedIs >= 97 && letterPressedIs <= 122))
        {

                userLettersVector.push_back(char(letterPressedIs)); // // // a-z A-Z will pushed into Vector
        }
        else if (IsKeyPressed(KEY_BACKSPACE)) // // // delete letters like BACKSPACE
        {
                if (userLettersVector.size() != 0) // // // check if its empty Vector or not to avoid errors
                {
                        userLettersVector.pop_back();
                }
        }
}

char MiniGame::generateRandomCodes()
{
        std::random_device rd;
        std::mt19937 gen(rd());
        char randomChar;

        std::uniform_int_distribution<> distrib(0, sizeof(lettersArr) - 1);
        randomChar = lettersArr[distrib(gen)];
        std::cout << "\nRandom character: " << randomChar << "\n";

        return randomChar;
}

void MiniGame::checkCodeCraked(std::vector<char> codeGeneratedVector, std::vector<char> userLettersVector)
{
        if (codeGeneratedVector.size() >= userLettersVector.size())
        {
                for (int i = 0; i < codeGeneratedVector.size(); ++i)
                {
                        if (codeGeneratedVector[i] != userLettersVector[i])
                        {
                                DrawText("CODE WAS WRONG", 100, 100, 30, GREEN);
                        }
                        else
                        {
                                ++score;
                                std::string scoreDisplayStr = "SCORE = " + score;
                                DrawText(scoreDisplayStr.c_str(), 300, 300, 45, GOLD);
                        }
                }
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
