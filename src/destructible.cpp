﻿#include "destructible.h"
#include "ofGraphics.h"


Destructible::Destructible(const float& x, const float& y)
{
	shootSFX_.load("shoot.mp3");
	shootSFX_.setLoop(false);
	shootSFX_.setVolume(0.5f);
	setCoords(x, y, true);
}

void Destructible::kill()
{
	shootSFX_.play();
	isLive_ = false;
}

bool Destructible::isLiving()
{
	return isLive_;
}

void Destructible::draw(const int& spriteIndex)
{
	ofSetColor(drawColor_);
	sprite_.drawSprite(spriteIndex, collider_.x, collider_.y);
	setCollision();
}

void Destructible::setCoords(const float& x, const float& y, const bool applyResize)
{
	collider_.x = applyResize ? x * Sprite::getResize() : x;
	collider_.y = applyResize ? y * Sprite::getResize() : y;
}

void Destructible::setCoords(const float& y, bool applyResize)
{
	collider_.y = applyResize ? y * Sprite::getResize() : y;
}

float Destructible::applyResize(float value)
{
	return value * Sprite::getResize();
}

Point<float> Destructible::applyResize(Point<float> value)
{
	return {applyResize(value.x), applyResize(value.y)};
}

int Destructible::getSpriteValue()
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}

Rect<float> Destructible::getCollider() const
{
	return collider_;
}

void Destructible::setCollision()
{
	setCollision(collider_.x, collider_.y, sprite_.getSize().x, sprite_.getSize().y);
}

void Destructible::setCollision(const float& x, const float& y, const float& w, const float& h)
{
	setCollision({x, y}, {w, h});
}

void Destructible::setCollision(Point<float> xy, Point<float> wh)
{
	collider_.setXY(xy);
	collider_.setWH(wh);
}
