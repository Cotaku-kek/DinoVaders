#include "raylib.h"
#include <iostream>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "WinScreen.h"
#include "PauseScreen.h"
#include "MenuScreen.h"
#include "Screen.h"
#include "CreditScreen.h"
#include "game.h"

float move = 0.5;
float boss_move = 3;

int cooldown = 10;
int lifes = 3;

Rectangle dinorec;
Rectangle playerrec;
Rectangle bossrec;
Rectangle dinoschussrec;
Rectangle bulletrec;

void Game::GameScreen::Start() {
    // Your screen initialization code here...


    //Dinos Position

    for (int x = 0; x <= 10; x++) {
        Vector2 vec = { 50.0f + 50 * x, 85.0f };
        this->sprites.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/dino_5.png"),
                vec,
                true));

    }

    for (int x = 0; x <= 10; x++) {
        Vector2 vec = { 50.0f + 50 * x, 125.0f };
        this->sprites.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/dino_6.png"),
                vec,
                true));

    }

    for (int x = 0; x <= 10; x++) {
        Vector2 vec = { 50.0f + 50 * x, 170.0f };
        this->sprites.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/dino_4.png"),
                vec,
                true));

    }

    for (int x = 0; x <= 10; x++) {
        Vector2 vec = { 50.0f + 50 * x, 210.0f };
        this->sprites.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/dino_7.png"),
                vec,
                true));

    }

    for (int x = 0; x <= 10; x++) {
        Vector2 vec = { 50.0f + 50 * x, 250.0f };
        this->sprites.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/dino_7.png"),
                vec,
                true));

    }


    //Boss Position:

    Vector2 vec_boss = {450.0f, 20.0f};
    this->boss.push_back(
        std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/boss.png"),
            vec_boss,
            true));



    //Player Position:

    Vector2 vec_player = { 450.0f, 480.0f };
    this->player.push_back(
        std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/ship.png"),
            vec_player,
            true));


    //Lifes Position

    for (int l = 0; l <= 2; l++) {
        Vector2 vec_life = { 830.0f + 40 * l, 20.0f };
        this->life.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/life.png"),
                vec_life,
                true));
    }



    //Base Position:

    for (int x = 0; x <= 3; x++) {
        Vector2 vec_base = { 130.0f + 200 * x, 390.0f };
        this->base.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/base.png"),
                vec_base,
                true));
    }



    /* 
    
    Fire Left Position:

    Vector2 vec_fireleft = { 400.0f, 480.0f };
    this->fireleft.push_back(
        std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/fireleft.png"),
            vec_fireleft,
            true));


    Fire Right Position:

    Vector2 vec_fireright = { 450.0f, 480.0f };
    this->fireright.push_back(
        std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/fireright.png"),
            vec_fireright,
            true)); 

    */
}



Game::GameScreen::~GameScreen() {
    // Your screen cleanup code here...
    //UnloadTexture(sprites[0]->texture);
}

void Game::GameScreen::ProcessInput() {
    // Your process input code here...

    if (IsKeyPressed(KEY_ENTER)) currentScreen = &pauseScreen;


   
    //Dinos Move:

    for (const auto& sprite : this->sprites) {

        sprite->pos.x += move;

        if (sprites.at(sprites.size() - 1)->pos.x == 900) {
            move = -0.5;
            sprite->pos.y += 2;
        }

        if (sprites.at(0)->pos.x == 10) {
            move = 0.5;
            sprite->pos.y += 2;
        }

    }


    //Player move:

    for (const auto& vec_player : this->player) {

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            if (vec_player->pos.x != 900) {
                vec_player->pos.x += 5;
            }

        }

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            if (vec_player->pos.x != 20) {
                vec_player->pos.x -= 5;

            }
        }

    }



    //Bullet move:

    if (IsKeyPressed(KEY_SPACE) && this->bullet.empty()) {

        Vector2 vec_bullet = { player.at(0)->pos.x, player.at(0)->pos.y };
        this->bullet.push_back(
            std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/player_bullet.png"),
                vec_bullet,
                true));
    }

    for (const auto& vec_bullet : this->bullet) {
        vec_bullet->pos.y -= 10;

        if (vec_bullet->pos.y < 0) {
            bullet.pop_back();
        }

    }



    //Boss move:

    for (const auto& vec_boss : this->boss) {
        
        if (vec_boss->pos.x < -1500) {
            boss_move = 3;
        }

        if (vec_boss->pos.x > 3000) {
            boss_move = -3;
        }

        vec_boss->pos.x += boss_move;
    }


  
   
   /*
   
       Fire Left:


    for (const auto& vec_fireleft : this->fireleft) {

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            if (vec_fireleft->pos.x != 900) {
                vec_fireleft->pos.x += 5;
            }

        }

    }


    Fire Right:

    for (const auto& vec_fireright : this->fireright) {
        
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            if (vec_fireright->pos.x != 20) {
                vec_fireright->pos.x -= 5;

            }
        }

    }
    */

}



void Game::GameScreen::Update() {
    // Your update game code here...


    /* if (restart == true) {
        Init();
        restart = false;
    } */



    //Dino Schuss

    if (cooldown <= 0) {

        int dinoschussrandom = GetRandomValue(0, sprites.size() - 1);


        if (sprites.at(dinoschussrandom)->visible == true) {
            if (this->dinoschuss.empty()) {

                Vector2 vec_dinoschuss = { sprites.at(dinoschussrandom)->pos.x, sprites.at(dinoschussrandom)->pos.y };

                this->dinoschuss.push_back(
                    std::make_unique<Game::Sprite>(LoadTexture("assets/graphics/dino_bullet.png"), vec_dinoschuss, true));
            }

            for (const auto& vec_dinoschuss : this->dinoschuss) {
                vec_dinoschuss->pos.y += 7;

                if (vec_dinoschuss->pos.y > 1020) {
                    this->dinoschuss.pop_back();
                    cooldown = 10;
                }
            }
        }
    }

    else {
        cooldown--;
    }



    //Dino Kollision:

    for (int i = sprites.size() - 1; i >= 0 && !bullet.empty(); i--) {

        dinorec = { (float)sprites.at(i)->pos.x, (float)sprites.at(i)->pos.y, (float)sprites.at(i)->texture.width, (float)sprites.at(i)->texture.height };
        for (int j = bullet.size() - 1; j >= 0 && !bullet.empty(); j--) {
            bulletrec = { (float)bullet.at(j)->pos.x, (float)bullet.at(j)->pos.y, (float)bullet.at(j)->texture.width, (float)bullet.at(j)->texture.height };

            if (CheckCollisionRecs(dinorec, bulletrec)) {

               // sprites.pop_back();
                sprites.erase(sprites.begin() + i);
                bullet.pop_back();
            }
        }
    }

    if (sprites.empty()) currentScreen = &winScreen;



    //Boss Kollision:


    for (int i = boss.size() - 1; i >= 0 && !bullet.empty(); i--) {

        bossrec = { (float)boss.at(i)->pos.x, (float)boss.at(i)->pos.y, (float)boss.at(i)->texture.width, (float)boss.at(i)->texture.height };
        bulletrec = { (float)bullet.at(i)->pos.x, (float)bullet.at(i)->pos.y, (float)bullet.at(i)->texture.width, (float)bullet.at(i)->texture.height };

        if (CheckCollisionRecs(bossrec, bulletrec)) {

            boss.pop_back(); 
            bullet.pop_back();
        }
    }

    if (boss.empty()) {

        Vector2 vec_boss = { -800.0f, 20.0f };
        this->boss.push_back(
            std::make_unique < Game::Sprite >(LoadTexture("assets/graphics/boss.png"), vec_boss, true));
    }



    //Player Kollision

    for (int i = player.size() - 1; i >= 0 && !dinoschuss.empty(); i--) {

        playerrec = { (float)player.at(i)->pos.x, (float)player.at(i)->pos.y, (float)player.at(i)->texture.width, (float)player.at(i)->texture.height };
        dinoschussrec = { (float)dinoschuss.at(i)->pos.x, (float)dinoschuss.at(i)->pos.y, (float)dinoschuss.at(i)->texture.width, (float)dinoschuss.at(i)->texture.height };

        if (CheckCollisionRecs(playerrec, dinoschussrec)) {

            player.erase(player.begin() + i);
            dinoschuss.pop_back();

            Vector2 vec_player = { 450.0f, 480.0f };
            this->player.push_back(
                std::make_unique < Game::Sprite >(LoadTexture("assets/graphics/ship.png"), vec_player, true));

          lifes--;
          life.erase(life.begin());
           if (lifes == 0) currentScreen = &gameOverScreen;

        }
    }
   
}




void Game::GameScreen::Draw() {
    // Your drawing code here...

   ClearBackground(RAYWHITE); 

   DrawTexture(background, 0, 0, RAYWHITE);

   DrawText("Press ENTER for pause", 300, 10, 30, LIGHTGRAY);
    


    //Dinos:
    for (const auto& sprite : this->sprites) {
        if (sprite->visible)
            DrawTexture(sprite->texture, (int)sprite->pos.x, (int)sprite->pos.y, RAYWHITE);
    }

    //Boss:
    for (const auto& sprite_boss : this->boss) {
        if (sprite_boss->visible)
            DrawTexture(sprite_boss->texture, (int)sprite_boss->pos.x, (int)sprite_boss->pos.y, RAYWHITE);
    }

    //Player:
    for (const auto& sprite_player : this->player) {
        if (sprite_player->visible)
            DrawTexture(sprite_player->texture, (int)sprite_player->pos.x, (int)sprite_player->pos.y, RAYWHITE);
    }

    //Bullet:
    for (const auto& sprite_bullet : this->bullet) {
        if (sprite_bullet->visible)
            DrawTexture(sprite_bullet->texture, (int)sprite_bullet->pos.x, (int)sprite_bullet->pos.y, RAYWHITE);
    }

    //Base:
    for (const auto& sprite_base : this->base) {
        if (sprite_base->visible)
            DrawTexture(sprite_base->texture, (int)sprite_base->pos.x, (int)sprite_base->pos.y, RAYWHITE);
    }

    //Life
    for (const auto& sprite_life : this->life) {
        if (sprite_life->visible)
            DrawTexture(sprite_life->texture, (float)sprite_life->pos.x, (float)sprite_life->pos.y, RAYWHITE);
    }

    //Fireleft
    for (const auto& sprite_fireleft : this->fireleft) {
        if (sprite_fireleft->visible)
            DrawTexture(sprite_fireleft->texture, (int)sprite_fireleft->pos.x, (int)sprite_fireleft->pos.y, RAYWHITE);
    }

    //Fireright
    for (const auto& sprite_fireright : this->fireright) {
        if (sprite_fireright->visible)
            DrawTexture(sprite_fireright->texture, (int)sprite_fireright->pos.x, (int)sprite_fireright->pos.y, RAYWHITE);
    }

    //Dino Schuss
    for (const auto& sprite_dinoschuss : this->dinoschuss) {
        if (sprite_dinoschuss->visible)
            DrawTexture(sprite_dinoschuss->texture, (int)sprite_dinoschuss->pos.x, (int)sprite_dinoschuss->pos.y, RAYWHITE);
    }


}


