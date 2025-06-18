#include <iostream>
#include "player.hpp"

        // // // std::cout<<;
void Player::LoadPlayerImage()
{

        playerImageFull = LoadTexture("assets/player/SteamMan/SteamMan_idle.png"); // // // Load full Sprite image
        playerSource = {0.f, 0.f, (float)playerImageFull.width / 4.0f, (float)playerImageFull.height};
        playerPosition = {400.0f, 700.0f};

        playerDestination = {playerPosition.x, playerPosition.y, playerSource.width * 2.0f, playerSource.height * 2.0f}; // 2x scale size for character

        playerOrigin = {playerDestination.width / 2.0f, playerDestination.height / 2.0f};
        playerRotation = 0.0f;
}

void Player::renderPlayerImg()
{
        DrawTexturePro(playerImageFull, playerSource, playerDestination, playerOrigin, playerRotation, WHITE);
}

void Player::unloadPlayerImage()
{
        UnloadTexture(playerImageFull);
}

void Player::movePlayer()
{
        if ((IsKeyDown(KEY_W) && IsKeyDown(KEY_A)) || IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) // // // Moves diagonally
        {
                playerDestination.x -= 5.0f;
                playerDestination.y -= 5.0f;
        }

        else if ((IsKeyDown(KEY_W) && IsKeyDown(KEY_D)) || IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) // // // Moves diagonally
        {
                playerDestination.x += 5.0f;
                playerDestination.y -= 5.0f;
        }
        else if ((IsKeyDown(KEY_D) && IsKeyDown(KEY_S)) || IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN)) // // // Moves diagonally
        {
                playerDestination.x += 5.0f;
                playerDestination.y += 5.0f;
        }
        else if ((IsKeyDown(KEY_A) && IsKeyDown(KEY_S)) || IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN)) // // // Moves diagonally
        {
                playerDestination.x -= 5.0f;
                playerDestination.y += 5.0f;
        }
        else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))// // // Moves UP
        {
                playerDestination.y -= 5;
        }
        else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))// // // Moves DOWN
        {
                playerDestination.y += 5.0f;
                playerRotation = 0.f;
        }
        else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))// // // Moves LEFT
        {
                playerDestination.x -= 5;
        }
        else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))// // // Moves RIGHT
        {
                playerDestination.x += 5;
        }
        playerRotation = 0.f;
}

