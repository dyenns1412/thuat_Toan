#include <iostream>
#include <SDL.h>
#include <time.h>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BLOCK_SIZE = 20;
const int MAP_WIDTH = SCREEN_WIDTH / BLOCK_SIZE;
const int MAP_HEIGHT = SCREEN_HEIGHT / BLOCK_SIZE;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int snakeX[100];
int snakeY[100];
int snakeLength = 3;
int appleX;
int appleY;

void spawnApple()
{
    appleX = rand() % MAP_WIDTH;
    appleY = rand() % MAP_HEIGHT;
}

void init()
{
    srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Snake Game",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    spawnApple();
}

void drawBlock(int x, int y)
{
    SDL_Rect blockRect = { x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };
    SDL_RenderFillRect(renderer, &blockRect);
}

void drawSnake()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int i = 0; i < snakeLength; i++)
    {
        drawBlock(snakeX[i], snakeY[i]);
    }
}

void drawApple()
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    drawBlock(appleX, appleY);
}

void moveSnake(int dx, int dy)
{
    for (int i = snakeLength - 1; i > 0; i--)
    {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    snakeX[0] += dx;
    snakeY[0] += dy;

    if (snakeX[0] < 0 || snakeX[0] >= MAP_WIDTH ||
        snakeY[0] < 0 || snakeY[0] >= MAP_HEIGHT)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game Over", "You hit the wall!", window);
        exit(0);
    }

    for (int i = 1; i < snakeLength; i++)
    {
        if (snakeX[i] == snakeX[0] && snakeY[i] == snakeY[0])
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game Over", "You hit yourself!", window);
            exit(0);
        }
    }

    if (snakeX[0] == appleX && snakeY[0] == appleY)
    {
        snakeLength++;
        spawnApple();
    }
}

void gameLoop()
{
    bool quit = false;
    int dx = 1, dy = 0;

    while (!quit)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
                        if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    dx = 0;
                    dy = -1;
                    break;

                case SDLK_DOWN:
                    dx = 0;
                    dy = 1;
                    break;

                case SDLK_LEFT:
                    dx = -1;
                    dy = 0;
                    break;

                case SDLK_RIGHT:
                    dx = 1;
                    dy = 0;
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        moveSnake(dx, dy);

        drawSnake();
        drawApple();

        SDL_RenderPresent(renderer);

        SDL_Delay(100);
    }
}

void cleanUp()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* args[])
{
    init();

    gameLoop();

    cleanUp();

    return 0;
}

