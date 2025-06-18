#ifndef MY_OTHER_HPP
#define MY_OTHER_HPP

#include <raylib.h>

//int screenWidth = GetMonitorWidth(0), screenHeight = GetMonitorHeight(0);



class Other
{

public:
        Texture2D backgroundImage;
        Rectangle backgroundSource, backgroundDestination;
        Vector2 backgroundImagePosition, backgroundOrigin;

        float backgroundImageRotation;
        //float floatScreenWidth = screenWidth, floatScreenHeight = screenHeight;         // // //  converts for Rectangle's data type

        void loadBackgroundImage();
        void renderBackgroundImage();
        void unloadPlayerImage();
};

#endif




