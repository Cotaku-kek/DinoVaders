#pragma once

#include "Screen.h"

namespace Game {
    class MenuScreen : public Screen {

    public:
       /* static Screen* getInstance() {

            static MenuScreen instance;
            return &instance;
        } */ 

        Texture2D backgroundmenu = LoadTexture("assets/graphics/background.png");

        MenuScreen();

        MenuScreen(MenuScreen const&) = delete;

        void operator=(MenuScreen const&) = delete;

        ~MenuScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
