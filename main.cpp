#include "globals.h"
#include "cGame.h"

cGame Game;
void AppRender() {

	Game.Render();

}

int main(int argc, char** argv) {

	int res_x, res_y, pos_x, pos_y;
	glutInit(&argc, argv);

	//alpha for the alpha control of colors 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA | GLUT_DEPTH);

	//Create centered window
	res_x = glutGet(GLUT_SCREEN_WIDTH);
	res_y = glutGet(GLUT_SCREEN_HEIGHT);
	pos_x = (res_x >> 1) - (GAME_WIDTH >> 1);
	pos_y = (res_y >> 1) - (GAME_HEIGHT >> 1);

	glutInitWindowPosition(pos_x, pos_y);
	glutInitWindowSize(GAME_WIDTH, GAME_HEIGHT);;
	glutCreateWindow("Game");
	
	//glutInitWindowSize(500, 500);//////////need change !! 
	glutDisplayFunc(AppRender);
	glutMainLoop();

	return 1;
}

