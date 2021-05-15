#pragma once

#include "Screen.h"
#include "MenuScreen.h"
#include "GameScreen.h"
#include "GameOverScreen.h"
#include "PauseScreen.h"
#include "WinScreen.h"

extern Game::GameOverScreen gameOverScreen;
extern Game::MenuScreen menuScreen;
extern Game::PauseScreen pauseScreen;
extern Game::WinScreen winScreen;
extern Game::GameScreen gameScreen;

extern Game::Screen* currentScreen;