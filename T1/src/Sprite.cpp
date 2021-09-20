#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(std::string file) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    };
}

void Sprite::Open(std::string file) {
    if (texture != nullptr) {
       SDL_DestroyTexture(texture);
    };
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if (texture == nullptr)
    {
        std::cout << "Erro ao carregar a textura" << std::endl;
    } else {
        std::cout << "Textura carregada com sucesso" << std::endl;
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    }
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y) {
    int errorStatus;
    SDL_Rect dstLoc = {x, y, GetWidth(), GetHeight()};

    errorStatus = SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstLoc);
    if (errorStatus != 0) {
        std::cout << "Erro ao renderizar a textura: " << SDL_GetError() << std::endl;
    }
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
}

bool Sprite::IsOpen() {
    std::cout << texture << std::endl;
    if (texture == nullptr) {
        return false;
    } else {
        return true;
    }
}
