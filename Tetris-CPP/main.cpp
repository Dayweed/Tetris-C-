// Tetris-CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SDL_MAIN_USE_CALLBACKS 1
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#undef main
constexpr int mScreenWidth{ 640 };
constexpr int mScreenHeight{ 480 };
static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;


/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    if (!SDL_CreateWindowAndRenderer("Hello World", mScreenWidth, mScreenHeight, 0, &window, &renderer))
    {
        SDL_Log("Couldnt create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    return SDL_APP_CONTINUE;
}


/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult  SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if(event->type == SDL_EVENT_KEY_DOWN || event->type == SDL_EVENT_QUIT)
        return SDL_APP_SUCCESS;
    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void* appstate)
{
    const char* msg = "hello world\n";
    int w = 0, h = 0;
    float x, y;
    const float scale = 4.f;

    //center msg
    SDL_GetRenderOutputSize(renderer, &w, &h);
    SDL_SetRenderScale(renderer, scale, scale);
    x = ((w / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(msg)) / 2;
    y = ((h / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) / 2;

    //draw msg
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDebugText(renderer, x, y, msg);

    SDL_FRect rect;
    SDL_SetRenderDrawColor(renderer, 33, 33, 255, SDL_ALPHA_OPAQUE);
    rect.x = rect.y = 100;
    rect.w = 440;
    rect.h = 280;
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;

}

//function runs once at shutdown
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    return;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
