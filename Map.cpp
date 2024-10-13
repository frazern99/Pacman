#include "Map.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 Map::Map() {



}


 void Map::set(ofRectangle rectangle,int n_in) {
	 n = n_in;
	 
	 hit = rectangle;


 }



 void Map::draw() {
	 
	 ofDrawRectangle(hit);
	 

 }

 void Map::setWall(int dir, int p1, int p2, int pos) {
	 if (dir == 0) {
		 for (int i = p1; i < p2; i++) {
			 wall[i][pos] = 1;

		 }
		 for (int i = 25-p2; i < 25-p1; i++) {
			 wall[i][pos] = 1;

		 }
	 }
	 if (dir == 1) {
		 for (int i = p1; i < p2; i++) {
			 wall[pos][i] = 1;

		 }
		 for (int i = p1; i < p2; i++) {
			 wall[24 - pos][i] = 1;

		 }
	 }
	 if (dir == 2) {
		 for (int i = p1; i < p2; i++) {
			 wall[i][pos] = 2;

		 }
		 for (int i = 25 - p2; i < 25 - p1; i++) {
			 wall[i][pos] = 2;

		 }
	 }
	 if (dir == 3) {
		 for (int i = p1; i < p2; i++) {
			 wall[pos][i] = 2;

		 }
		 for (int i = p1; i < p2; i++) {
			 wall[24 - pos][i] = 2;

		 }
	 }

 }

 void Map::mapGrid(ofRectangle grid[][N_MAX],int n) {

	int step = 1000 / n;
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < 25; j++) {

			 grid[i][j].set(step*i, step*j, 1000 / n, 1000 / n);

		 }
	 }



 }