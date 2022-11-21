﻿#include "bullet.h"
#include "character.h"
#include "ofGraphics.h"

Bullet::Bullet():
	Bullet (4, 5, true)
{
}

Bullet::Bullet(const bool& isPlayer):
	Bullet (4, 5, isPlayer)
{
}

Bullet::Bullet(const float& x, const float& y, const bool& isPlayer):
	Destructible (x, y), isPlayer_ (isPlayer)
{
	sprite_.clearCoords();
	sprite_.setSize ({3, 7});
	sprite_.newCoords ({41, 21}); // Default
	sprite_.newCoords ({16, 21}); // Death
}


void Bullet::setIsActive(const bool& isBottom) { isActive_ = isBottom; }

void Bullet::move()
{
	if (!isFired_) { resetBullet(); }
	else {
		isFired_ = isHitValid();
		++*this;
	}

	if (collider_.addYH() > glb::DRAW_RESTRICTIONS.h + glb::DRAW_RESTRICTIONS.y || collider_.y < glb::DRAW_RESTRICTIONS.y) {
		resetBullet();
	}

	draw (isLive_ ? 0 : 1);
}

void Bullet::fire()
{
	if (!isFired_) {
		isFired_ = true;
		//drawColor_ = ofColor::white;
	}
}

bool Bullet::isHitValid()
{
	if (collider_.y < 1 || collider_.y > ofGetViewportHeight()) { return false; }
	return true;
}

void Bullet::resetBullet()
{
	//drawColor_ = ofColor::red;
	setCoords (bulletOrigin_.x, bulletOrigin_.y, false);
	isFired_ = false;
}

void Bullet::setBulletOrigin(const Point <float> bulletOrigin)
{
	bulletOrigin_ = bulletOrigin;
}

bool Bullet::hasHitOppos(Rect<float> col, const bool isLive)
{
	col.drawRect();
	/*ofDrawBitmapString(std::to_string(static_cast<int>(col.x)) + " " + std::to_string(static_cast<int>(col.y)), 20, 685);
	ofDrawBitmapString(std::to_string(static_cast<int>(col.addXW())) + " " + std::to_string(static_cast<int>(col.addYH())), 20, 700);*/

	if (isFired_) {
		/*ofDrawBitmapString(std::to_string(static_cast<int>(collider_.x)) + " " + std::to_string(static_cast<int>(collider_.y)), 20, 585);
		ofDrawBitmapString(std::to_string(static_cast<int>(collider_.addXW())) + " " + std::to_string(static_cast<int>(collider_.addYH())), 20, 600);*/

		//std::cout << "Run for " << memoryAddress_ << "\n";

		if (collider_.checkBounds(col) && isLive) {
			resetBullet();
			return true;
		}
		return false;
	}
}
