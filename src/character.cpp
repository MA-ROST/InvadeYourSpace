﻿// ReSharper disable All
#include "character.h"

Character::Character (const float& x, const float& y)
{
	setCoords(x, y, true);
}


void Character::setCoords (const float& x, const float& y, bool applyResize)
{
	coordinate_.x = applyResize ? x * resizeFactor_ : x;
	coordinate_.y = applyResize ? y * resizeFactor_ : y;
}

void Character::setCoords (const float& y, bool applyResize)
{
	coordinate_.y = applyResize ? y * resizeFactor_ : y;
}

int Character::getSpriteValue() const
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}
