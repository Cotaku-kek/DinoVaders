#pragma once
#include "Screen.h"

namespace Game {
    class GameOverScreen : public Screen {

    public:

        Texture2D gameoverscreen = LoadTexture("assets/graphics/gameoverscreen.png");

        /* static Screen* getInstance() {
            static GameOverScreen instance;
            return &instance;
        } */

        GameOverScreen();

        GameOverScreen(GameOverScreen const&) = delete;

        void operator=(GameOverScreen const&) = delete;

        ~GameOverScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
