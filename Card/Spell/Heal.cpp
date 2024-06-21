#include "Heal.hpp"
#include <allegro5/color.h>

#include "Helper/Helper.hpp"
#include "Entity/Spell/Spell.hpp"

Heal::Heal(bool selected, float x, float y): 
    Card(selected, 11, x, y, "Heal", "Heal your troops to keep them in the fight!", 75, 3.5, 2, 0.5, 0, 1) {
        fontDesc = Engine::Resources::GetInstance().GetFont("recharge.otf", 16);
        fontDescH = Engine::Resources::GetInstance().GetFont("recharge.otf", 17);
    }
Heal::Heal(float x, float y): 
    Card(11, x, y, "Heal", 75, 3.5, 2, 0.5, 0, 1) {
    }

void Heal::Draw() const {
    Card::Draw();
    if (!inPlay) {
        if (!hovered) {
            al_draw_text(fontDesc.get(), White, Position.x+200-10, Position.y+90, 0,  ("Atk: "+std::to_string(pt)).c_str());
            al_draw_text(fontDesc.get(), White, Position.x+200-10, Position.y+125, 0, ("Radius: "+floatToStr(radius)).c_str());
            al_draw_text(fontDesc.get(), White, Position.x+200-10, Position.y+160, 0, ("Duration: "+floatToStr(duration)).c_str());
            al_draw_text(fontDesc.get(), White, Position.x+200-10, Position.y+195, 0, ("Interval: "+floatToStr(interval)).c_str());
        } else {
            Engine::Point nP(Position); nP.x-=diff; nP.y-=diff;
            al_draw_text(fontDescH.get(), White, nP.x+200-10, nP.y+90, 0,  ("Atk: "+std::to_string(pt)).c_str());
            al_draw_text(fontDescH.get(), White, nP.x+200-10, nP.y+125+2, 0, ("Radius: "+floatToStr(radius)).c_str());
            al_draw_text(fontDescH.get(), White, nP.x+200-10, nP.y+160+4, 0, ("Duration: "+floatToStr(duration)).c_str());
            al_draw_text(fontDescH.get(), White, nP.x+200-10, nP.y+195+6, 0, ("Interval: "+floatToStr(interval)).c_str());
        }
    } else {
        if (!hovered) {
            al_draw_text(fontDesc.get(), White, Position.x+220, Position.y+90, 0,  ("Atk: "+std::to_string(pt)).c_str());
            al_draw_text(fontDesc.get(), White, Position.x+220, Position.y+130, 0, ("Radius: "+floatToStr(radius)).c_str());
            al_draw_text(fontDesc.get(), White, Position.x+220, Position.y+170, 0, ("Duration: "+floatToStr(duration)).c_str());
            al_draw_text(fontDesc.get(), White, Position.x+220, Position.y+210, 0, ("Interval: "+floatToStr(interval)).c_str());
        } else {
            Engine::Point nP(Position); nP.x-=diff; nP.y-=diff;
            al_draw_text(fontDescH.get(), White, nP.x+220, nP.y+90, 0,  ("Atk: "+std::to_string(pt)).c_str());
            al_draw_text(fontDescH.get(), White, nP.x+220, nP.y+130+2, 0, ("Rad.: "+floatToStr(radius)).c_str());
            al_draw_text(fontDescH.get(), White, nP.x+220, nP.y+170+4, 0, ("Dur.: "+floatToStr(duration)).c_str());
            al_draw_text(fontDescH.get(), White, nP.x+220, nP.y+210+6, 0, ("Int.: "+floatToStr(interval)).c_str());
        }

    }
}

Spell* Heal::placeSpell(int instanceID, float xB, float yB) {
    return new Spell(ID, instanceID, xB, yB, Name, pt, radius, duration, interval, atkTower, al_map_rgb(255, 220, 0));
}