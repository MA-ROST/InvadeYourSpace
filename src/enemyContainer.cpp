﻿#include "enemyContainer.h"

#include <array>

#include "ofGraphics.h"


// Static variables must be declared in the .cpp file
bool EnemyContainer::isForwardMove_;

EnemyContainer::EnemyContainer ()
{
	
	for (int x = 0; x < 11; ++x) {
		for (int y = 0; y < 5; ++y) {
			enemyTest_[x].emplace_back(x * 18, y * 18, y);
			setWholeSize(x, y);
		}
	}

	setWholeCoordinate({ glb::DRAW_RESTRICTIONS.x, 10 });
	
}

void EnemyContainer::draw ()
{
	drawDebugRange();
	drawEnemies();
}



void EnemyContainer::setWholeSize (int rowSize, int columnSize)
{
	wholeCollision_.w += 10.7;
	wholeCollision_.h += 4.4;

	//std::cout << wholeSize_.x << ", " << wholeSize_.y << std::endl;
}

void EnemyContainer::setWholeCoordinate (const Point<float> coordinate)
{
	wholeCollision_.x = coordinate.x;
	wholeCollision_.y = coordinate.y;
}

void EnemyContainer::drawDebugRange () const
{
	ofSetColor(ofColor::lavender);
	ofDrawRectangle(wholeCoordinate_.x, wholeCoordinate_.y, wholeSize_.x, wholeSize_.y);
}

void EnemyContainer::drawEnemies ()
{
	for (auto& enemyRow : enemyTest_) {
		for (auto& enemy : enemyRow) {
			enemy.move(wholeCoordinate_);
		}
	}
}

void EnemyContainer::makeShoot ()
{
	const int a = static_cast<int>(round(ofRandom(10)));
	const int b = static_cast<int>(round(ofRandom(4)));
	
	if (enemyTest_[a][b].canShoot()) enemyTest_[a][b].fire();
	else makeShoot ();
}

void EnemyContainer::moveWhole ()
{
	if (ofGetFrameNum() % 30 == 0) {
		isMovingRight();
		isForwardMove_ ? wholeCoordinate_.x += MOVE_SPEED : wholeCoordinate_.x -= MOVE_SPEED;
	}
	drawDebugRange();
	drawEnemies ();

	if (ofGetFrameNum() % 60 == 0) {
		makeShoot();
	}
}

void EnemyContainer::isMovingRight()
{
	if (wholeCoordinate_.x + wholeSize_.x >= glb::DRAW_RESTRICTIONS.y) {
		isForwardMove_ = false;
		wholeCoordinate_.y += 3;
	}
	if (wholeCoordinate_.x <= glb::DRAW_RESTRICTIONS.x) isForwardMove_ = true;
}
