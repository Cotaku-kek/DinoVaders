#pragma once

#include <vector>
#include <memory>

#include "raylib.h"

#include "Screen.h"
#include "Sprite.h"

namespace Game {
    class GameScreen : public Screen {
    public:
        std::vector<std::unique_ptr<Sprite>> sprites;
        std::vector<std::unique_ptr<Sprite>> player;
        std::vector<std::unique_ptr<Sprite>> bullet;
        std::vector<std::unique_ptr<Sprite>> fireright;
        std::vector<std::unique_ptr<Sprite>> fireleft;
        std::vector<std::unique_ptr<Sprite>> base;
        std::vector<std::unique_ptr<Sprite>> boss;
        std::vector<std::unique_ptr<Sprite>> life;
        std::vector<std::unique_ptr<Sprite>> dinoschuss;

        Texture2D background = LoadTexture("assets/graphics/background.png");

        /* static Screen* getInstance() {
            static GameScreen instance;
            return &instance;
        } */

        GameScreen() {};

        GameScreen(GameScreen const&) = delete;

        void operator=(GameScreen const&) = delete;

        ~GameScreen();

        void Start();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
