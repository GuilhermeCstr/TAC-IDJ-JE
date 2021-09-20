#pragma once

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL


#include "SDL_include.h"
#include "State.h"


class Game{

    private:
        static Game* instance;
        Game(std::string title, int width, int height);
        
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;

    public:
        ~Game();
        void Run();
        static Game& GetInstance();
        SDL_Renderer* GetRenderer();
        State& GetState();

};

