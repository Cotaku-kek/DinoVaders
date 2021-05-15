#pragma once
#include "Screen.h"

namespace Game {
    class PauseScreen : public Screen {

    public:
      /*  static Screen* getInstance() {
            static PauseScreen instance;
            return &instance;
        } */

        Texture2D backgroundpause = LoadTexture("assets/graphics/background.png");

        PauseScreen();

        PauseScreen(PauseScreen const&) = delete;

        void operator=(PauseScreen const&) = delete;

        ~PauseScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
