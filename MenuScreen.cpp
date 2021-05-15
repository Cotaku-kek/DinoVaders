#include "raylib.h"

#include "MenuScreen.h"
#include "Screen.h"
#include "CreditScreen.h"
#include "game.h"

Game::MenuScreen::MenuScreen() {
    // Your screen initialization code here...
}

Game::MenuScreen::~MenuScreen() {
    // Your screen cleanup code here...
}


void Game::MenuScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = &gameScreen;
}

void Game::MenuScreen::Update() {
    // Your update game code here...
}

void Game::MenuScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);
    DrawTexture(backgroundmenu, 0, 0, RAYWHITE);
    DrawText("DinoVaders\n\n\n\n", 200, 150, 100, DARKPURPLE);
    DrawText("DinoVaders\n\n\n\n", 195, 145, 100, PINK);
    DrawText("Press ENTER to start game", 260, 300, 30, LIGHTGRAY);
    
}
