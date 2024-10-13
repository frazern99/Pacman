#include "ofApp.h"
#include "../Map.h"
//--------------------------------------------------------------

ofPoint ofApp::getCenter(int x, int y, int width, int height) {
	int p1, p2;
	ofPoint center;
	p1 = x + width * 0.5;
	p2 = y + height * 0.5;
	center.set(p1, p2);
	return center;
}
ofPoint ofApp::getCenter(ofRectangle rectangle) {

	float p1, p2,x,y,width,height;
	x = rectangle.x;
	y = rectangle.y;
	width = rectangle.width;
	height = rectangle.height;

	ofPoint center;
	p1 = x + width * 0.5;
	p2 = y + height * 0.5;
	center.set(p1, p2);
	return center;


}


void ofApp::setup() {
	step = 1000 / 25;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {

			grid[i][j].set(step*i, step*j, 1000 / 25, 1000 / 25);
			gridCenters[i][j] = getCenter(grid[i][j]);
			ball[i][j].set(getCenter(grid[i][j]).x, getCenter(grid[i][j]).y, 10, 10);
		}
	}

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			wall[i][j] = 0;
			eaten[i][j] == 0;
		}
	}

	title.load("arial", 32);
	controls.load("arial", 32);
	scoreString.load("arial", 10);
	show = 0;
	
	
	s = 5;
	lives = 3;
	pHBox.set(step*12, step*16, 20, 20);
	ghost1.set(step * 6, step * 4, 40, 40);
	ghost2.set(step * 1, step * 23, 40, 40);
	ghost3.set(step * 23, step * 23,40,40);
	
	wallC.setWall(2, 0, 5, 0);
	wallC.setWall(2, 0, 5, 1);
	wallC.setWall(2, 0, 5, 2);
	wallC.setWall(2, 0, 5, 3);
	wallC.setWall(2, 0, 5, 4);
	wallC.setWall(2, 8, 18, 21);
	wallC.setWall(2, 8, 18, 22);
	wallC.setWall(2, 8, 18, 23);
	wallC.setWall(2, 8, 18, 24);
	wallC.setWall(2, 10, 15, 10);
	wallC.setWall(1, 5, 25, 0);
	wallC.setWall(1, 20, 25, 7);
	wallC.setWall(1, 20, 23, 4);
	wallC.setWall(1, 15, 21, 1);
	wallC.setWall(1, 10, 14, 2);
	wallC.setWall(1, 10, 14, 2);
	wallC.setWall(1, 0, 6, 5);
	wallC.setWall(1, 10, 14, 4);
	wallC.setWall(1, 10, 14, 5);
	wallC.setWall(1, 17, 21, 2);
	wallC.setWall(1, 13, 16, 12);
	wallC.setWall(1, 9, 12, 9);
	wallC.setWall(1, 15, 19, 4);
	wallC.setWall(1, 12, 16, 7);
	wallC.setWall(0, 0, 5, 5);
	wallC.setWall(0, 6, 19, 20);
	wallC.setWall(0, 6, 12, 17);
	wallC.setWall(0, 6, 12, 18);
	wallC.setWall(0, 0, 8, 24);
	wallC.setWall(0, 6, 13, 0);
	wallC.setWall(0, 7, 12, 2);
	wallC.setWall(0, 7, 12, 3);
	wallC.setWall(0, 7, 9, 5);
	wallC.setWall(0, 2, 8, 7);
	wallC.setWall(0, 2, 8, 8);
	wallC.setWall(0, 9, 16, 9);
	wallC.setWall(0, 9, 16, 11);
	wallC.setWall(0, 3, 6, 15);
	wallC.setWall(0, 2, 6, 22);
	wallC.setWall(0, 7, 11, 15);
	wallC.setWall(0, 9, 16, 13);
	wallC.setWall(0, 6, 8, 10);
	wallC.setWall(0, 9, 16, 7);
	wallC.setWall(0, 10, 15, 6);
	wallC.setWall(0, 10, 15, 5);
	

	direction1=5;
	shortest1 = 10000;
	direction2 = 5;
	shortest2 = 10000;
	direction3 = 5;
	shortest3 = 10000;
	direction4 = 5;
	shortest4 = 10000;


	play = 0;
	ofSetBackgroundColor(0, 0, 0);
}
//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(60);
	pHBox.set(pHBox.x + vx, pHBox.y+vy, 20, 20);
	ghostCenter = getCenter(ghost1);
	target1.set(pHBox.x, pHBox.y);

	if (vx == s) {

		target2.set(pHBox.x+100, pHBox.y);

	}
	if (vx == -1*s) {

		target2.set(pHBox.x - 100, pHBox.y);

	}
	if (vy == s) {

		target2.set(pHBox.x, pHBox.y+100);

	}
	if (vy == -1*s) {

		target2.set(pHBox.x, pHBox.y - 100);

	}

	bubble.set(pHBox.x - 100, pHBox.y -100, 200, 200);

	if (ghost3.intersects(bubble) == true) {

		target3.set(step * 23, step * 23);
	}
	else target3.set(pHBox.x, pHBox.y);




	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (wallC.wall[i][j] == 1) {
				hit[i][j] = grid[i][j];

			}

		}
	}
	
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {

			colision = pHBox.intersects(hit[i][j]);



			if (colision == true)
			{
				if (vy == -1*s)
				{
					vy = 0;
					pHBox.y = pHBox.y + s;
				}
				if (vy == s)
				{
					vy = 0;
					pHBox.y = pHBox.y - s;
				}
				if (vx == s)
				{
					vy = 0;
					pHBox.x = pHBox.x - s;
				}
				if (vx == -1*s)
				{
					vy = 0;
					pHBox.x = pHBox.x + s;
				}

			}
		}
		
	}



	
	if (play == 1) {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (ghost1.x == grid[i][j].x) {
					if (ghost1.y == grid[i][j].y) {
						if (wallC.wall[i][j - 1] == 0) {
							if (direction1 != 2) {

								distance1[0] = sqrt(pow(grid[i][j - 1].x - target1.x, 2) + pow(grid[i - 1][j].y - target1.y, 2));


							}
							else {
								distance1[0] = 1000;
							}

						}
						else {
							distance1[0] = 1000;
						}

						if (wallC.wall[i + 1][j] == 0) {
							if (direction1 != 3) {

								distance1[1] = sqrt(pow(grid[i + 1][j].x - target1.x, 2) + pow(grid[i + 1][j].y - target1.y, 2));


							}
							else {
								distance1[1] = 1000;
							}
						}
						else {
							distance1[1] = 1000;
						}
						if (wallC.wall[i][j + 1] == 0) {
							if (direction1 != 0) {

								distance1[2] = sqrt(pow(grid[i][j + 1].x - target1.x, 2) + pow(grid[i][j + 1].y - target1.y, 2));


							}
							else {
								distance1[2] = 1000;
							}
						}
						else {
							distance1[2] = 1000;
						}
						if (wallC.wall[i - 1][j] == 0) {
							if (direction1 != 1) {

								distance1[3] = sqrt(pow(grid[i - 1][j].x - target1.x, 2) + pow(grid[i - 1][j].y - target1.y, 2));


							}
							else {
								distance1[3] = 1000;
							}
						}
						else {
							distance1[3] = 1000;
						}
					}

				}
			}
		}

		for (int i = 0; i < 4; i++) {
			if (distance1[i] < shortest1) {

				shortest1 = distance1[i];
				direction1 = i;

			}

		}
		shortest1 = 10000;



		if (direction1 == 0) {
			ghost1.y = ghost1.y - 5;

		}

		if (direction1 == 1) {
			ghost1.x = ghost1.x + 5;

		}
		if (direction1 == 2) {
			ghost1.y = ghost1.y + 5;

		}
		if (direction1 == 3) {
			ghost1.x = ghost1.x - 5;

		}

		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (ghost2.x == grid[i][j].x) {
					if (ghost2.y == grid[i][j].y) {
						if (wallC.wall[i][j - 1] == 0) {
							if (direction2 != 2) {

								distance2[0] = sqrt(pow(grid[i][j - 1].x - target2.x, 2) + pow(grid[i - 1][j].y - target2.y, 2));


							}
							else {
								distance2[0] = 1000;
							}

						}
						else {
							distance2[0] = 1000;
						}

						if (wallC.wall[i + 1][j] == 0) {
							if (direction2 != 3) {

								distance2[1] = sqrt(pow(grid[i + 1][j].x - target2.x, 2) + pow(grid[i + 1][j].y - target2.y, 2));


							}
							else {
								distance2[1] = 1000;
							}
						}
						else {
							distance2[1] = 1000;
						}
						if (wallC.wall[i][j + 1] == 0) {
							if (direction2 != 0) {

								distance2[2] = sqrt(pow(grid[i][j + 1].x - target2.x, 2) + pow(grid[i][j + 1].y - target2.y, 2));


							}
							else {
								distance2[2] = 1000;
							}
						}
						else {
							distance2[2] = 1000;
						}
						if (wallC.wall[i - 1][j] == 0) {
							if (direction2 != 1) {

								distance2[3] = sqrt(pow(grid[i - 1][j].x - target2.x, 2) + pow(grid[i - 1][j].y - target2.y, 2));


							}
							else {
								distance2[3] = 1000;
							}
						}
						else {
							distance2[3] = 1000;
						}
					}

				}
			}
		}

		for (int i = 0; i < 4; i++) {
			if (distance2[i] < shortest2) {

				shortest2 = distance2[i];
				direction2 = i;

			}

		}
		shortest2 = 10000;



		if (direction2 == 0) {
			ghost2.y = ghost2.y - 5;

		}

		if (direction2 == 1) {
			ghost2.x = ghost2.x + 5;

		}
		if (direction2 == 2) {
			ghost2.y = ghost2.y + 5;

		}
		if (direction2 == 3) {
			ghost2.x = ghost2.x - 5;

		}

		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (ghost3.x == grid[i][j].x) {
					if (ghost3.y == grid[i][j].y) {
						if (wallC.wall[i][j - 1] == 0) {
							if (direction3 != 2) {

								distance3[0] = sqrt(pow(grid[i][j - 1].x - target3.x, 2) + pow(grid[i - 1][j].y - target3.y, 2));


							}
							else {
								distance3[0] = 10000;
							}

						}
						else {
							distance3[0] = 10000;
						}

						if (wallC.wall[i + 1][j] == 0) {
							if (direction3 != 3) {

								distance3[1] = sqrt(pow(grid[i + 1][j].x - target3.x, 2) + pow(grid[i + 1][j].y - target3.y, 2));


							}
							else {
								distance3[1] = 10000;
							}
						}
						else {
							distance3[1] = 10000;
						}
						if (wallC.wall[i][j + 1] == 0) {
							if (direction3 != 0) {

								distance3[2] = sqrt(pow(grid[i][j + 1].x - target3.x, 2) + pow(grid[i][j + 1].y - target3.y, 2));


							}
							else {
								distance3[2] = 10000;
							}
						}
						else {
							distance3[2] = 10000;
						}
						if (wallC.wall[i - 1][j] == 0) {
							if (direction3 != 1) {

								distance3[3] = sqrt(pow(grid[i - 1][j].x - target3.x, 2) + pow(grid[i - 1][j].y - target3.y, 2));


							}
							else {
								distance3[3] = 10000;
							}
						}
						else {
							distance3[3] = 10000;
						}
					}

				}
			}
		}

		for (int i = 0; i < 4; i++) {
			if (distance3[i] < shortest3) {

				shortest3 = distance3[i];
				direction3 = i;

			}

		}
		shortest3 = 10000;



		if (direction3 == 0) {
			ghost3.y = ghost3.y - 5;

		}

		if (direction3 == 1) {
			ghost3.x = ghost3.x + 5;

		}
		if (direction3 == 2) {
			ghost3.y = ghost3.y + 5;

		}
		if (direction3 == 3) {
			ghost3.x = ghost3.x - 5;

		}


		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (pHBox.intersects(ball[i][j]) == 1) {
					ball[i][j].set(0, 0, 1, 1);
					eaten[i][j] = 1;
					score = score + 100;
				}

			}
		}
		sprintf(scoreC, "SCORE: %d", score);
		
		if (ghost1.intersects(pHBox) == true) {
			lives = lives - 1;
			pHBox.set(step*12, step*16 + vy, 20, 20);
			ghost1.set(step * 6, step * 4, 40, 40);
			ghost2.set(step * 6, step * 17, 40, 40);
			ghost3.set(step * 23, step * 23, 40, 40);
		}
		if (ghost2.intersects(pHBox) == true) {
			lives = lives - 1;
			pHBox.set(step * 12, step * 16 + vy, 20, 20);
			ghost1.set(step * 6, step * 4, 40, 40);
			ghost2.set(step * 6, step * 17, 40, 40);
			ghost3.set(step * 23, step * 23, 40, 40);
		}
		if (ghost3.intersects(pHBox) == true) {
			lives = lives - 1;
			pHBox.set(step * 12, step * 16 + vy, 20, 20);
			ghost1.set(step * 6, step * 4, 40, 40);
			ghost2.set(step * 6, step * 17, 40, 40);
			ghost3.set(step * 23, step * 23, 40, 40);
		}
		if (lives == 0) play = 2;
		if (score > 21000)play = 2;


	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (play == 0) {
		ofSetColor(255, 0, 0);
		title.drawString("PACMAN", 500, 500);
		controls.drawString("Up:w \nDown:s \nLeft:a \nRight:d \nSTART:g",500,550);


	}

	
	
	if (play == 1) {
		
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (wallC.wall[i][j] == 0) {
					if (eaten[i][j] == 0) {

						ofSetColor(255, 255, 255);
						ofDrawCircle(gridCenters[i][j], 10);
					}

				}
				
			}
		}
		ofSetColor(255, 0, 0);
		scoreString.drawString(scoreC, 500, 900);



		ofNoFill();
		ofSetColor(0, 0, 0);
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (wallC.wall[i][j] == 1) {
					ofFill();
					ofSetColor(0, 0, 255);
					ofDrawRectangle(grid[i][j]);
				}
				else {
					ofNoFill();
					ofSetColor(0, 0, 0);
					ofDrawRectangle(grid[i][j]);
				}

			}

		}



		//ofSetColor(0, 0, 255);
		//for (int i = 0; i < 4; i++) {
		//	ofDrawRectangle(map[i]);
		//}
		ofSetColor(255, 255, 0);
		ofDrawRectangle(pHBox);
		ofSetColor(255, 0, 0);
		ofDrawRectangle(ghost1);
		ofSetColor(255, 20, 147);
		ofDrawRectangle(ghost2);
		ofSetColor(255, 127, 80);
		ofDrawRectangle(ghost3);

		//ofDrawCircle(target1, 10);
		//ofDrawCircle(target2, 10);
		//ofDrawCircle(target3, 5);
		//ofNoFill();
		//ofDrawRectangle(bubble);

		if (show == 1) {
			ofDrawBitmapString("X: " + ofToString(ghost1.x), 20, 20);
			ofDrawBitmapString("dist 0: " + ofToString(distance2[0]), 20, 25);
			ofDrawBitmapString("dist 1: " + ofToString(distance2[1]), 20, 35);
			ofDrawBitmapString("dist 2: " + ofToString(distance2[2]), 20, 45);
			ofDrawBitmapString("dist 3: " + ofToString(distance2[3]), 20, 55);
			ofDrawBitmapString("shortest: " + ofToString(sho), 20, 65);
			ofDrawBitmapString("direction: " + ofToString(direction2), 20, 75);
		}
	}
	if (play == 2) {
		if (lives == 0) {
			title.drawString("GAME OVER", 500, 500);
			controls.drawString(scoreC, 500, 600);
		
		}
		else {
			title.drawString("YOU WIN", 500, 500);
			controls.drawString(scoreC, 500, 600);
		}
	}

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (play == 0) {

		if (key == 'g') play = 1;

	}


	
	
	if (play == 1) {


		if (key == 's') {
			vy = s;
			
		}
		if (key == 'w') {
			vy = -1*s;
			
		}
		if (key == 'a') {
			vx = -1*s;
			
		}
		if (key == 'd') {
			vx = s;
			
		}
		if (key == 't') {
			if (show == 0) {
				show = 1;
			}
			else show = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (play == 1) {


		if (key == 's') {
			vy = 0;
			
		}
		if (key == 'w') {
			vy = 0;
			
		}
		if (key == 'a') {
			vx = 0;
			
		}
		if (key == 'd') {
			vx = 0;
			
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
