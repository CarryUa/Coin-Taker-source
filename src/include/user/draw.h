#ifndef draw_h
#define dtaw_h

void processScene(App app, RGBA bgColor);
void presentScene(App app);
SDL_Texture* loadTexture(const char* filePath, App app);
void draw(Entity entity, App app);
void drawText(Size size, Possition pos, App app);
void drawTextBox(Size size, Possition pos, RGBA bgcolor, App app);
void draw(Entity* entity, App app);
#endif