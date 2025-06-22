#ifndef MY_OTHER_HPP
#define MY_OTHER_HPP

#include <raylib.h>


void printArrayInDecipher(char *lettersArr, int elementStart, int elementEnd, int *nextLineFromYpos,Color fontColor);
void decipherGameInfo();


class MiniGame
{
public:
        void GameDecipher(Player *playerobj, bool *game, int screenSize[2]);


};

class Box
{
public:
        Texture2D ClosedMissionBoxImage, OpenedMissionBoxImage;
        Rectangle ClosedMissionBoxImageSource, ClosedMissionBoxImageDestination_1, ClosedMissionBoxImageDestination_2;

        Vector2 ClosedMissionBoxOrigin;

        float ClosedMissionBoxImageRotation;
        float destination_1_and_2PositionY, destination_2PositionX; // // // calculations of X & Y  axis to make code less complicated

        void loadMissioBoxImage();
        void renderMissioBoxImage();
        void unloadMissioBoxImage();
};

class Other
{

public:
        Texture2D backgroundImage;
        Rectangle backgroundSource, backgroundDestination;
        Vector2 backgroundOrigin;

        float backgroundImageRotation;
        // float floatScreenWidth = screenWidth, floatScreenHeight = screenHeight;         // // //  converts for Rectangle's data type

        void loadBackgroundImage();
        void renderBackgroundImage();
        void unloadBackgroundImage();

        void playerTouchMiniGame(Player &playerObj, Box &minigameObj, int screenSize[2]);
};

#endif
