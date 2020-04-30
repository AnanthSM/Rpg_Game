
#include "cGame.h"


cGame::cGame() {

}
cGame::~cGame() {

}

bool cGame::Init(int lvl) {

	int tex_w, tex_h;
	bool res = true;
	level = lvl;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	visible_area.left = TILE_SIZE;
	visible_area.right = TILE_SIZE + GAME_WIDTH;
	visible_area.bottom = TILE_SIZE;
	visible_area.top = TILE_SIZE + GAME_HEIGHT;
	glOrtho(visible_area.left, visible_area.right, visible_area.bottom, visible_area.top, 3, -SCENE_HEIGHT * TILE_SIZE - 2 - 1);
	//last 2 values ​​are znear and zfar, 3 is for the bar / life overlays, interface and menu, -2 is for the terrain z, range: [-3, (SCENE_HEIGHT * TILE_SIZE) +2]
	glMatrixMode(GL_MODELVIEW); //Applies subsequent matrix operations to the modelview matrix stack.
	glAlphaFunc(GL_GREATER, 0.05f);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_DEPTH_TEST);

	Data.Load();

	Data.GetSize(IMG_TILESET, &tex_w, &tex_h);
	res = Scene.LoadLevel(level, tex_w, tex_h);

	if (!res)
		return false;






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

	int tex_w, tex_h;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Data.GetSize(IMG_TILESET, &tex_h, &tex_w);
	Scene.Draw(Data.GetID(IMG_TILESET), tex_w, tex_h, true);

	
	glutSwapBuffers();

}