#include "raylib.h"
#include "MenuScreen.h"
#include "GameScreen.h"
// #include "CreditScreen.h"
#include "GameOverScreen.h"
#include "WinScreen.h"
#include "Screen.h"
#include "game.h"

Game::WinScreen::WinScreen() {
    // Your screen initialization code here...
}

Game::WinScreen::~WinScreen() {
    // Your screen cleanup code here...
}


void Game::WinScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = &menuScreen;

}

void Game::WinScreen::Update() {
    // Your update game code here...
}

void Game::WinScreen::Draw() {
    // Your drawing code here...

    DrawTexture(backgroundwin, 0, 0, RAYWHITE);

    ClearBackground(RAYWHITE);

    DrawText("CONGRATULATIONS! \n\n\n\n", 75, 195, 80, DARKGREEN);
    DrawText("CONGRATULATIONS! \n\n\n\n", 70, 190, 80, GREEN);
   //DrawText("You saved the earth and the humanity!\n\n\n\n", 300, 700, 60, RAYWHITE);
    //DrawText("Your courageous action will never be forgotten! \n\n\n\n", 400, 650, 60, RAYWHITE);
    DrawText("Press ENTER to go back to the menu!\n\n\n\n", 180, 300, 30, LIGHTGRAY);

}