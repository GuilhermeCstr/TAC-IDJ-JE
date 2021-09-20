#include <iostream>
#include "../include/Music.h"

Music::Music() {
    music = nullptr;
}

Music::Music(std::string file) {
    Open(file);
}

void Music::Play(int times) {
    if (music != nullptr) {
        Mix_PlayMusic(music, times);
    } else {
        std::cout << "Erro ao executar a música.";
    }
}

void Music::Open(std::string file) {
    music = Mix_LoadMUS(file.c_str());
    if (music == nullptr) {
        std::cout << "Erro ao carregar a música." << std::endl;
    } else {
        std::cout << "Música carregada com sucesso." << std::endl;
    }
}

void Music::Stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen() {
    if (music != nullptr) {
        return true;
    } else {
        return false;
    }
}

Music::~Music() {
    if (music != nullptr) {
        Stop(1500);
        Mix_FreeMusic(music);
    }
}