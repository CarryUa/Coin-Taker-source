#include <SDL2/SDL.h>
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} App;
typedef struct {
    int r;
    int g;
    int b;
    int a;
} RGBA;
typedef struct {
    int x;
    int y;
} Possition;
typedef struct {
    int w;
    int h;
} Size;
class Entity {
protected:
    Possition possition;
    Size size;
    int direction;
    bool isMove = false;
    SDL_Texture* texture;
    void doKeyDown(SDL_KeyboardEvent* event) {
        switch (event->keysym.scancode) {
        case SDL_SCANCODE_A:
            isMove = true;
            direction = 1;
        case SDL_SCANCODE_W:
            isMove = true;
            direction = 2;
        case SDL_SCANCODE_D:
            isMove = true;
            direction = 3;
        case SDL_SCANCODE_S:
            isMove = true;
            direction = 4;
        }
    }
    void doKeyUp(SDL_KeyboardEvent* event) {
        if (event->repeat == 0)
        {
            switch (event->keysym.scancode) {
            case SDL_SCANCODE_A:
                isMove = false;
            case SDL_SCANCODE_W:
                isMove = false;
            case SDL_SCANCODE_D:
                isMove = false;
            case SDL_SCANCODE_S:
                isMove = false;
            }
        }
    }
public:
    Entity(Possition _pos, Size _size, int _direction, SDL_Texture* _texture)
    {
        possition = _pos;
        size = _size;
        direction = _direction;
        texture = _texture;
    }
    Possition getPossition() {
        return possition;
    }
    Size getSize() {
        return size;
    }
    int getDirection() {
        return direction;
    }
    SDL_Texture* getTexture() {
        return texture;
    }
    bool getIsMove() {
        return isMove;
    }
    void setIsMove(bool state) {
        isMove = state;
    }
    void setPossition(Possition _possition) {
        possition = _possition;
    }
    void setSize(Size _size) {
        size = _size;
    }
    void setDirection(int _direction) {
        direction = _direction;
    }
    void changeTexture(SDL_Texture* _texture) {
        texture = _texture;
    }
    void getInput() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                doKeyDown(&event.key);
                break;
            case SDL_KEYUP:
                doKeyUp(&event.key);
            }
        }
    }
};