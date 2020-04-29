#pragma once

#include "cScene.h"
#include "cData.h"

//dimensiones of the game 
#define GAME_WIDTH	((SCENE_WIDTH-2)*TILE_SIZE + SCENE_Xo*2) //compound values ​​of #define always enclosed in parentheses
#define GAME_HEIGHT int((SCENE_WIDTH-2)*TILE_SIZE*1.5f + SCENE_Yo*2)

#define STATE_GAMEOVER    0
#define STATE_RUN         1
#define STATE_PAUSE       2
#define STATE_MAINMENU    3
#define STATE_LEVELCHANGE 4
#define STATE_ENDGAME	  5

#define TOTAL_LEVELS	  2
#define DYNAMIC_FILENAME  "dynamic_layer"

//controls
#define P1_UP		'w'
#define P1_DOWN		's'
#define P1_LEFT		'a'
#define P1_RIGHT	'd'
#define P1_ATTACK	'f'
#define P1_SKILL	'e'

class cGame {
public:
	cGame();
	~cGame();

	bool Init(int level);
	bool loop();
	void Finilize();

	//inputs 
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state, int x, int y);
	//porc 
	bool process();
	void Reshape(int w, int h);
	//output
	void Render();

private:
	int level, state;
	cScene Scene;
	cData Data;


};