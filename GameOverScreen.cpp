#include "raylib.h"

#include "CreditScreen.h"
#include "GameOverScreen.h"
#include "Screen.h"
#include "game.h"

Game::GameOverScreen::GameOverScreen() {
    // Your screen initialization code here...
}

Game::GameOverScreen::~GameOverScreen() {
    // Your screen cleanup code here...
}


void Game::GameOverScreen::ProcessInput() {
    // Your process input code here...
   // restart = true;

    if (IsKeyPressed(KEY_ENTER))
    {
        gameScreen.Start();
        currentScreen = &menuScreen;
    }
}


void Game::GameOverScreen::Update() {
    // Your update game code here...
}

void Game::GameOverScreen::Draw() {
    // Your drawing code here...

    DrawTexture(gameoverscreen, 0, 0, RAYWHITE);

    ClearBackground(RAYWHITE);

    DrawText("WASTED\n\n\n\n", 225, 185, 120, YELLOW);
    DrawText("WASTED\n\n\n\n", 220, 180, 120, RED);
    DrawText("Press ENTER to go back to the menu\n\n\n\n", 200, 320, 30, RAYWHITE);


}