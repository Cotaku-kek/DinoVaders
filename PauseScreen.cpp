#include "raylib.h"

#include "MenuScreen.h"
#include "GameScreen.h"
//#include "CreditScreen.h"
#include "GameOverScreen.h"
#include "PauseScreen.h"
#include "Screen.h"
#include "game.h"

Game::PauseScreen::PauseScreen() {
    // Your screen initialization code here...
}

Game::PauseScreen::~PauseScreen() {
    // Your screen cleanup code here...
}


void Game::PauseScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_BACKSPACE)) currentScreen = &menuScreen;
    if (IsKeyPressed(KEY_ENTER)) currentScreen = &gameScreen;
}

void Game::PauseScreen::Update() {
    // Your update game code here...
}

void Game::PauseScreen::Draw() {
    // Your drawing code here...

    DrawTexture(backgroundpause, 0, 0, RAYWHITE);

    ClearBackground(RAYWHITE);

    DrawText("PAUSE", 290, 150, 100, DARKBLUE);
    DrawText("PAUSE", 285, 145, 100, SKYBLUE);
    DrawText("Press ENTER to go back to the Game\n\n\n\n", 190, 300, 30, RAYWHITE);
    DrawText("Press BACKSPACE to go back to the Menu\n\n\n\n", 150, 350, 30, RAYWHITE);



}