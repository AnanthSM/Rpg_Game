
#include "cGame.h"


cGame::cGame() {

}
cGame::~cGame() {

}

bool cGame::Init(int lvl) {

	bool res = true;
	level = lvl;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();



	return res;

}
bool cGame::loop() {

	return false;

}
void cGame::Finilize() {

}

//inputs 
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press) {

}
void cGame::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) {

}
void cGame::ReadMouse(int button, int state, int x, int y) {

}
//porc 
bool cGame::process() {

	return false;

}
void cGame::Reshape(int w, int h) {

}
//output
void cGame::Render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glLoadIdentity();

}