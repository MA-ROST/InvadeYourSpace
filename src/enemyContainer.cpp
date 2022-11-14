﻿#include "enemyContainer.h"

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

void EnemyContainer::isMovingRight ()
{
	//std::cout << wholeCoordinate_.x << ", " << wholeCoordinate_.x + wholeSize_.x << std::endl;
	if (wholeCoordinate_.x + wholeSize_.x >= glb::DRAW_RESTRICTIONS.y) {
		isForwardMove_ = false;
		wholeCoordinate_.y += 3;
	}
	if (wholeCoordinate_.x <= glb::DRAW_RESTRICTIONS.x) isForwardMove_ = true;
}

void EnemyContainer::setWholeSize (int rowSize, int columnSize)
{
	wholeSize_.x += 10.7;
	wholeSize_.y += 4.4;

	//std::cout << wholeSize_.x << ", " << wholeSize_.y << std::endl;
}

void EnemyContainer::setWholeCoordinate (const Point<float> coordinate)
{
	wholeCoordinate_ = coordinate;
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
	int a = static_cast<int>(round(ofRandom(10)));
	int b = static_cast<int>(round(ofRandom(4)));

	enemyTest_[a][b].canShoot() ? enemyTest_[a][b].fire() : makeShoot();
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
