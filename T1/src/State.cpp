#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "../include/SDL_include.h"
#include "../include/State.h"


#define spritePath "recursos/img/ocean.jpg"
#define musicPath "recursos/audio/stageState.ogg"

// -1 for infinite loop
#define musicLoopTime -1    


State::State(){
    quitRequested = false;
    LoadAssets();
    music.Play(musicLoopTime);
}

void State::LoadAssets(){
    //Carrega musicas, imagens e qualquer outra feature
    bg.Open(spritePath);
    music.Open(musicPath);
}

void State::Update(float dt){
    //Verifica comando para sair do jogo
    if(SDL_QuitRequested() == true){
        quitRequested = true;
    }
    SDL_Delay(dt);
}

void State::Render(){
    //Renderizar entidades, cenários, HUD e etc
    bg.Render(0, 0);
}

bool State::QuitRequested(){
    return quitRequested;

}

