// #include "SDL_image.h"
// #include "SDL_mixer.h"

#include "string"
#include "iostream"
#include "../include/SDL_include.h"
#include "../include/Game.h"

std::string title = "Guilherme de Castro Ribeiro - 14/0142151";
int width = 1024;
int height = 600;

Game *Game::instance = nullptr;

Game& Game::GetInstance(){

    if(instance != nullptr){
        return *instance;
    }
    else{
		instance = new Game(title,width,height);
        return *instance;
    }
}

Game::Game(std::string title, int width, int height){
    
	if(instance == nullptr){
        instance = this;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
    	SDL_Log("SDL cannot initalize: %s", SDL_GetError());
    	exit(1);
	}

	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
    	SDL_Log("SDL cannot initalize IMG: %s", IMG_GetError());
    	exit(1);
	}

	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if(window == 0) {
    	SDL_Log("SDL cannot initalize window: %s", SDL_GetError());
    	exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == 0) {
    	SDL_Log("Unable to initialize renderer: %s", SDL_GetError());
    	exit(1);
	}

    state = new State;

}

Game::~Game(){

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
	return(renderer);
}

void Game::Run(){
	while (state->QuitRequested()!=true) {
		state->Update(33);
		state->Render();
		SDL_RenderPresent(Game::GetInstance().GetRenderer());
	}
}

