#include "Enemy.h"



void Enemy::setGhost(float x, float y, float width, float height) {

	ghost.x = x;
	ghost.y = y;
	ghost.width = width;
	ghost.height = height;

}
ofPoint Enemy::getCenter(float x, float y, float width, float height) {
	float p1, p2;
	ofPoint center;
	p1=x + width * 0.5;
	p2=y + height * 0.5;
	center.set(p1, p2);
	return center;
}
void Enemy::setTarget(float x, float y) {

	target.x = x;
	target.y = y;


}
void Enemy::setTarget(ofPoint point) {

	target = point;


}

int Enemy::pickDirection(ofRectangle grid[][N_MAX],Map wallC) {
	float shortest=10000;
	float distance[4];
	int direction=5;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (ghost.x == grid[i][j].x) {
				if (ghost.y == grid[i][j].y) {
					if (wallC.wall[i][j - 1] == 0) {
						if (direction != 2) {

							distance[0] = sqrt(pow(grid[i][j - 1].x - target.x, 2) + pow(grid[i - 1][j].y - target.y, 2));


						}
						else {
							distance[0] = 1000;
						}

					}
					else {
						distance[0] = 1000;
					}

					if (wallC.wall[i + 1][j] == 0) {
						if (direction != 3) {

							distance[1] = sqrt(pow(grid[i + 1][j].x - target.x, 2) + pow(grid[i + 1][j].y - target.y, 2));


						}
						else {
							distance[1] = 1000;
						}
					}
					else {
						distance[1] = 1000;
					}
					if (wallC.wall[i][j + 1] == 0) {
						if (direction != 0) {

							distance[2] = sqrt(pow(grid[i][j + 1].x - target.x, 2) + pow(grid[i][j + 1].y - target.y, 2));


						}
						else {
							distance[2] = 1000;
						}
					}
					else {
						distance[2] = 1000;
					}
					if (wallC.wall[i - 1][j] == 0) {
						if (direction != 1) {

							distance[3] = sqrt(pow(grid[i - 1][j].x - target.x, 2) + pow(grid[i - 1][j].y - target.y, 2));


						}
						else {
							distance[3] = 1000;
						}
					}
					else {
						distance[3] = 1000;
					}
				}

			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (distance[i] < shortest) {
			
			shortest = distance[i];
			direction = i;

		}

	}
	shortest = 10000;
	return direction;
}
void Enemy::drawEnemy() {

	ofDrawRectangle(ghost);


}