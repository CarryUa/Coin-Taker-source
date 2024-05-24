#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <user/structs.h>
void processScene(App app, RGBA bgColor) {
    SDL_SetRenderDrawColor(app.renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a); //sets background color
    SDL_RenderClear(app.renderer);
}
void presentScene(App app) {
    SDL_RenderPresent(app.renderer);
}
SDL_Texture* loadTexture(const char* filePath, App app) {
    return IMG_LoadTexture(app.renderer, filePath);
}
void draw(Entity entity, App app) {
    SDL_Rect dest;
    dest.w = entity.getSize().w;
    dest.h = entity.getSize().h;
    dest.x = entity.getPossition().x - entity.getSize().w / 2;
    dest.y = entity.getPossition().y - entity.getSize().h / 2;
    SDL_QueryTexture(entity.getTexture(), NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app.renderer, entity.getTexture(), NULL, &dest);
}
void drawText(Size size, Possition pos, App app) {
    SDL_Rect dest;
    dest.w = size.w;
    dest.h = size.h;
    dest.x = pos.x - size.w / 2;
    dest.y = pos.y - size.h / 2;
    SDL_QueryTexture(app.textTexture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app.renderer, app.textTexture, NULL, &dest);
}
void drawTextBox(Size size, Possition pos, RGBA bgcolor, App app) {
    SDL_Rect dest;
    dest.w = size.w;
    dest.h = size.h;
    dest.x = pos.x - size.w / 2;
    dest.y = pos.y - size.h / 2;
    SDL_SetRenderDrawColor(app.renderer, bgcolor.r, bgcolor.g, bgcolor.b, bgcolor.a);
    SDL_RenderFillRect(app.renderer, &dest);
    SDL_QueryTexture(app.textTexture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app.renderer, app.textTexture, NULL, &dest);
}