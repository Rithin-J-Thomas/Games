#include <iostream>
#include "other.hpp"

// // //render background Image
void Other::loadBackgroundImage()
{
int screenWidth = GetMonitorWidth(0);
int screenHeight = GetMonitorHeight(0);
        // // //get screenWidth & screenHeight from main.cpp and make it float also get values of screenWidth & screenHeight before calling loadBackgroundImage() in  main.cpp do something for that so it wont be outdated value
        backgroundImage = LoadTexture("assets/Scene_Overview.png");
        backgroundSource = {0.0f, 0.0f, (float)backgroundImage.width, (float)backgroundImage.height};



        backgroundDestination = { 0.0f, 0.0f,(float)screenWidth,(float)screenHeight};

        backgroundOrigin = { 0.0f, 0.0f };
        backgroundImageRotation = 0.0f;

        //std::cout<<screenWidth<<" \nfro";
}

void Other::renderBackgroundImage()
{        
        DrawTexturePro(backgroundImage, backgroundSource, backgroundDestination, backgroundOrigin, backgroundImageRotation, WHITE);

}

void Other::unloadPlayerImage()
{
        UnloadTexture(backgroundImage);
}