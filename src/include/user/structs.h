#include <SDL2/SDL.h>
#include <ctime>
#include <cstdlib>
#include <user/defines.h>
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
typedef struct {
    bool up;
    bool down;
    bool left;
    bool right;
} Direction;
class Entity {
protected:
    Possition possition;
    Size size;
    Direction direction;
    bool isMove = false;
    SDL_Texture* texture;
public:
    Entity(Possition _pos, Size _size, Direction _direction, SDL_Texture* _texture)
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
    Direction getDirection() {
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
    void setDirection(Direction _direction) {
        direction = _direction;
    }
    void changeTexture(SDL_Texture* _texture) {
        texture = _texture;
    }
    void processMovement() {
        if (isMove) {
            if (direction.left)
                possition.x -= 4;
            if (direction.up)
                possition.y -= 4;
            if (direction.right)
                possition.x += 4;
            if (direction.down)
                possition.y += 4;
        }
    }
};
class Player : public Entity {
protected:
    void doKeyDown(SDL_KeyboardEvent* event) {
        if (event->keysym.scancode == SDL_SCANCODE_A) {
            isMove = direction.left = true;
        }
        if (event->keysym.scancode == SDL_SCANCODE_W) {
            isMove = direction.up = true;
        }
        if (event->keysym.scancode == SDL_SCANCODE_D) {
            isMove = direction.right = true;
        }
        if (event->keysym.scancode == SDL_SCANCODE_S) {
            isMove = direction.down = true;

        }
    }
    void doKeyUp(SDL_KeyboardEvent* event) {

        if (event->keysym.scancode == SDL_SCANCODE_A) {
            isMove = direction.left = false;
        }
        if (event->keysym.scancode == SDL_SCANCODE_W) {
            isMove = direction.up = false;
        }
        if (event->keysym.scancode == SDL_SCANCODE_D) {
            isMove = direction.right = false;
        }
        if (event->keysym.scancode == SDL_SCANCODE_S) {
            isMove = direction.down = false;
        }

    }
public:
    Player(Possition _pos, Size _size, Direction _direction, SDL_Texture* _texture) : Entity(_pos, _size, _direction, _texture)
    {
        possition = _pos;
        size = _size;
        direction = _direction;
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
class Coin : public Entity {
public:
    Coin(Possition _pos, Size _size, Direction _direction, SDL_Texture* _texture) : Entity(_pos, _size, _direction, _texture) {
        possition = _pos;
        size = _size;
        direction = _direction;
        texture = _texture;
    }
    void randomizePossition() {
        srand(time(NULL));
        possition.x = rand() % SCREEN_WIDTH;
        possition.y = rand() % SCREEN_HEIGHT;
    }
};