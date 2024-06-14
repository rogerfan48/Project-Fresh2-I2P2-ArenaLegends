#include "LoadScene.hpp"
#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/RectangleButton.hpp"
#include "UI/Component/Label.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Slider.hpp"

void LoadScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    int diff[3] = {120, 250, 380};
    int lD = 50; // labelDiff

    AddNewObject(new Engine::Label("Tower Defense", "pirulen.ttf", 120, halfW, halfH / 3 + 50, 10, 255, 255, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 250, halfH / 2 + diff[0] , 500, 100);
    btn->SetOnClickCallback(std::bind(&LoadScene::PlayOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Play", "pirulen.ttf", 48, halfW, halfH / 2 + diff[0] + lD, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 250, halfH / 2 + diff[1] , 500, 100);
    btn->SetOnClickCallback(std::bind(&LoadScene::ScoreboardOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Scoreboard", "pirulen.ttf", 48, halfW, halfH / 2 + diff[1] + lD, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 250, halfH / 2 + diff[2], 500, 100);
    btn->SetOnClickCallback(std::bind(&LoadScene::SettingsOnClick, this, 3));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Settings", "pirulen.ttf", 48, halfW, halfH / 2 + diff[2] + lD, 0, 0, 0, 255, 0.5, 0.5));

    AddNewControlObject(new Engine::RectangleButton(0,0,50,50,50,50,50));
}
void LoadScene::Terminate() {
    IScene::Terminate();
}
void LoadScene::PlayOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("load");
}
void LoadScene::SettingsOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("load");
}
void LoadScene::ScoreboardOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("load");
}