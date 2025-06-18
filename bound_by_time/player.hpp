#ifndef MY_PLAYER_HPP
#define MY_PLAYER_HPP

#include <raylib.h>



class Player
{
public:

        Texture2D playerImageFull;
        Rectangle playerSource ,playerDestination;
        Vector2 playerPosition ,playerOrigin;


        float playerRotation ;

        void LoadPlayerImage();

        void renderPlayerImg();

        void unloadPlayerImage();

        void movePlayer();

};

#endif