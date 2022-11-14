﻿#pragma once

#include "destructible.h"

class Bullet : public Destructible {
	const bool isPlayer_;
	bool isFired_{false};
	bool isActive_{ false };
	Point <float> bulletOrigin_;

	static constexpr float MOVE_SPEED{ 10 };

public:
	explicit Bullet();
	explicit Bullet (const bool& isPlayer);
	Bullet (const float& x, const float& y, const bool& isPlayer);

	void isBulletActive(const bool& isBottom);

	void move();
	void fire();
	bool isHitValid();

	void resetBullet();
	void setBulletOrigin(Point <float> bulletOrigin);

	Bullet& operator++ ();

	static float getMoveSpeed() { return MOVE_SPEED; }
};

inline Bullet& Bullet::operator++ ()
{
	isPlayer_ ? coordinate_.y -= MOVE_SPEED :
				coordinate_.y += MOVE_SPEED;
	return *this;
}
