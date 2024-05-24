#include<SDL2/SDL.h>
#include<SDL2/SDL_main.h>
#include<SDL2/SDL_ttf.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
#include<user/draw.h>
#include<user/funcs.h>
int main(int argc, char* argv[]) {
    srand(time(NULL));
    RGBA backgroundColor = { 0, 226, 255, 255 };
    int score = 0;
    App app = Init(app);
    Coin coin({ 0,0 }, { 32,32 }, { false, false, false, false }, 0, { loadTexture("src/textures/coin.png", app), 32, 32 });
    Enemy enemy({ 0,0 }, { 64,64 }, { false, false, false, false }, 2, { loadTexture("src/textures/enemy.png", app), 32, 32 });
    Player player({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, { 64,64 }, { false, false, false, false }, 4, 4, { loadTexture("src/textures/hero.png", app), 32, 32 });
    coin.randomizePossition();
    while (player.getHP() != 0)
    {
        processScene(app, backgroundColor);
        SDL_Delay(16);
        draw(player, app);
        draw(coin, app);
        draw(enemy, app);
        player.getInput();
        player.processMovement();
        enemy.processDirection(player);
        enemy.processMovement();
        if (isTouching(player, coin))
        {
            coin.randomizePossition();
            score++;
        }
        if (isTouching(player, enemy))
        {
            player.setHP(player.getHP() - 1);
            SDL_Delay(1000);
            enemy.setPossition({ 0,0 });
            player.setPossition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
            coin.randomizePossition();
        }
        app = setText(intToChar(score), app);
        drawTextBox({ 100,60 }, { 50, 60 }, { 128, 128, 128, 255 }, app);
        app = setText(intToChar(player.getHP()), app);
        drawText({ 100,24 }, { 50, 82 }, app);
        presentScene(app);
    }
    //main loop
    backgroundColor = { 255,0,0,255 };
    processScene(app, backgroundColor);
    app = setText("YOU LOOSE", app);
    drawTextBox({ 0,0 }, { SCREEN_WIDTH / 2 - 20,SCREEN_HEIGHT / 2 }, { 128, 128, 128, 255 }, app);
    presentScene(app);
    SDL_Delay(5000);
    SDL_Quit();
    return 0;

}
