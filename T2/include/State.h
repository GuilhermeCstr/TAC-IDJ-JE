#pragma once


#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "GameObject.h"

#include <vector>
#include <memory>



class State{
    public:
        State();
        ~State();
        void LoadAssets();
        void Update(float dt);
        void Render();
        bool QuitRequested();

    private:
        Sprite bg;
        Music music;
        bool quitRequested;
        void Input();
        void AddObject(int mouseX, int mouseY);
        std::vector<std::shared_ptr<GameObject>> objectArray;
};