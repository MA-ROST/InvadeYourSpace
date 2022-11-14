﻿#pragma once
#include "character.h"
#include <algorithm>

class Enemy : public Character {
	static std::vector<Enemy*> enemies_;
	static Point<float> wholeCoordinate_; // The coordinate of the first enemy
	static Point<float> wholeSize_; // The size of all of the enemies compiled into one
	int setupRows (int& sprite);
	Enemy* enemy_;
	static bool isForwardMove_;
	int points_{30};
	bool isBottomMost_;


	static constexpr float MOVE_SPEED {24};
public:
	
	Enemy (const float& x, const float& y, int& spriteSet);

	

	void draw ();
	void move();

	void getSprite (bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);

	static std::vector<Enemy*> getAllObjects() {
		return enemies_;
	}

	// THINGS TO DO /////
	// - Make enemies move down when hitting right side
	//		- only rightmost enemies slide down
	// - Only bottom most enemy has (Working) bullets
	//		- Hide bullets on enemies not bottommost 

	static void isMovingRight();

	static void setWholeSize(int rowSize, int columnSize);
	static void setWholeCoordinate(const Point<float> coordinate);
	static void drawDebugRange();

	static void moveWhole();
	static float getMoveSpeed() return MOVE_SPEED; }


	Enemy& operator ++ ()
	{
		std::cout << "ENEMY";
		wholeCoordinate_.x += Enemy::getMoveSpeed();
		return *this;
	}

	Enemy& operator-- ()
	{
		std::cout << "ENEMY";
		wholeCoordinate_.x -= Enemy::getMoveSpeed();
		return *this;
	}
};


