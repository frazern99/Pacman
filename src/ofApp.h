#pragma once
#define N_MAX 2000
#include "ofMain.h"
#include "../Map.h"
#include"../Enemy.h"
#include"../Player.h"
class ofApp : public ofBaseApp{

	public:
		ofRectangle ghost2;
		
		int score;
		int lives;
		int show;
		int play;
		int eaten[25][25];
		int direction1;
		int direction2;
		int direction3;
		int direction4;
		
		float shortest1;
		float shortest2;
		float shortest3;
		float shortest4;
		float distance1[4];
		float distance2[4];
		float distance3[4];
		float distance4[4];
		ofPoint ghostCenter;
		bool vup, vdown, vleft, vright;
		int step;
		Map mapM[N_MAX];
		int vx, vy;
		ofRectangle grid[25][N_MAX];
		ofRectangle hit[25][N_MAX];
		ofRectangle ball[25][N_MAX];
		bool colision;
		ofRectangle map[N_MAX];
		ofRectangle pHBox;
		Map wallC;
		int wall[25][25];
		ofRectangle ghost1;
		ofPoint target1;
		ofPoint target2;
		ofPoint target3;
		ofPoint target4;
		float sho;
		int s;
		ofRectangle bubble;
		ofRectangle ghost3;
		ofPoint gridCenters[25][25];
		ofTrueTypeFont title;
		ofTrueTypeFont controls;
		ofTrueTypeFont scoreString;
		char scoreC[255];
		void setup();
		void update();
		void draw();




		ofPoint getCenter(int x, int y, int width, int height);
		ofPoint getCenter(ofRectangle rectangle);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
