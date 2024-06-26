#include<SDL2/SDL.h>
#include<SDL2/SDL_main.h>
#include<SDL2/SDL_ttf.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
#include<user/draw.h>
#include<user/funcs.h>
#include<vector>
int main(int argc, char* argv[]) {
    srand(time(NULL));
    bool enemySpawned = true;
    std::vector<Enemy*> enemyVector;
    int i = 0;
    RGBA backgroundColor = { 0, 226, 255, 255 };
    int score = 0;
    App app = Init(app);
    Coin coin({ 0,0 }, { 32,32 }, { false, false, false, false }, 0, { loadTexture("src/textures/coin.png", app), 32, 32 });
    Player player({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, { 64,64 }, { false, false, false, false }, 4, 4, { loadTexture("src/textures/hero.png", app), 32, 32 });
    coin.randomizePossition();
    enemyVector.push_back(new Enemy({ 0,0 }, { 64,64 }, { false, false, false, false }, 2, { loadTexture("src/textures/enemy.png", app),  32, 32 }));
    while (player.getHP() > 0)
    {
        processScene(app, backgroundColor);
        draw(player, app);
        draw(coin, app);
        player.getInput();
        player.processMovement();
        if (isTouching(player, coin))
        {
            coin.randomizePossition();
            score++;
            enemySpawned = true;
        }
        app = setText(intToChar(score), app);
        drawTextBox({ 100,60 }, { 50, 60 }, { 128, 128, 128, 255 }, app);
        app = setText(intToChar(player.getHP()), app);
        drawText({ 100,24 }, { 50, 82 }, app);
        for (i = 0;i < enemyVector.size(); i++) {
            enemyVector[i] = processEnemyVector(enemyVector[i], player, coin, app);
            if (isTouching(player, enemyVector[i]))
            {
                for (i = 0;i < enemyVector.size(); i++) {
                    enemyVector[i]->setPossition({ 0 + i * (enemyVector[i]->getSize().w),0 });
                    player.setPossition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
                    coin.randomizePossition();
                }
                player.setHP(player.getHP() - 1);
                SDL_Delay(1000);
            }
        }
        presentScene(app);
        if (score % 10 == 0 && score != 0 && enemySpawned) {
            enemyVector.push_back(new Enemy({ 0,0 }, { 64,64 }, { false, false, false, false }, 2, { loadTexture("src/textures/enemy.png", app),  32, 32 }));
        }
        enemySpawned = false;
        SDL_Delay(16);
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
