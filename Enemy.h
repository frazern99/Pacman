#pragma once
#include "ofMain.h"
#define N_MAX 2000
#include "Map.h"
class Enemy
{
public:
	ofPoint target;
	ofRectangle ghost;
	ofPoint ghostCenter;


	void setGhost(float x, float y, float width, float height);
	ofPoint getCenter(float x, float y, float width, float height);
	void setTarget(float x, float y);
	void setTarget(ofPoint point);
	int pickDirection(ofRectangle grid[][N_MAX], Map wallC);
	void drawEnemy();



};