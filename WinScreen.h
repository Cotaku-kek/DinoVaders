#pragma once
#include "Screen.h"

namespace Game {
    class WinScreen : public Screen {

    public:
      /*  static Screen* getInstance() {
            static WinScreen instance;
            return &instance;
        } */

        Texture2D backgroundwin = LoadTexture("assets/graphics/background.png");

        WinScreen();

        WinScreen(WinScreen const&) = delete;

        void operator=(WinScreen const&) = delete;

        ~WinScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}