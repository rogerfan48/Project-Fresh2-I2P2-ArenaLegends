#include <cmath>
#include "Bullet.hpp"
#include "Engine/Collider.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/IObject.hpp"
#include "Engine/IScene.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/Sprite.hpp"
#include "Helper/Helper.hpp"

void Bullet::OnExplode(){
	//
}
Bullet::Bullet(std::string img, float speed, float damage, Engine::Point position, Army* target) :
	Sprite(img, position.x, position.y), speed(speed), damage(damage), target(target) {
	Rotation = findAngle(position, target->Position);
	Velocity.x = cos(Rotation) * speed, Velocity.y = sin(Rotation) * speed * (-1);
	CollisionRadius = 4;
}
void Bullet::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* PS = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
	if (!target) {
		static float tick = 255;
		tick -= deltaTime;
		if (tick > 0) {
			Tint = al_map_rgba(255, 255, 255, tick);
		} else {
			PS->WeaponGroup->RemoveObject(objectIterator);
		}
		return;
	}
	Rotation = findAngle(Position, target->Position);
	Velocity.x = cos(Rotation) * speed, Velocity.y = sin(Rotation) * speed * -1;
	if ((Position - target->Position).Magnitude() <= CollisionRadius) {
			OnExplode();
			target->hp -= damage;
			PS->WeaponGroup->RemoveObject(objectIterator);
			return;
		}
}