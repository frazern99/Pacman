#pragma once
#include "ofMain.h"
#define N_MAX 2000
class Map
{
public:
	
	int n, i;
	ofRectangle hit;
	int wall[25][25];
	ofPoint center;
	Map();
	void set(ofRectangle rectangle,int n_in); 
	 
	void draw();
	void setWall(int dir, int p1, int p2, int pos);
	void mapGrid(ofRectangle grid[][N_MAX],int n);









};