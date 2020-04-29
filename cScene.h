#pragma once

#include "globals.h"

#define SCENE_Xo		  0   
#define SCENE_Yo		  0
#define SCENE_WIDTH       20 // in number of tiles 
#define SCENE_HEIGHT      160

#define LEVEL_FILENAME	  "static_layer"
#define FILENAME_EXT	  ".txt"

#define TILE_FRAMES       4 //the number of frames the animated tile will have
#define TILE_DELAY        3 //what will make the tile move from one frame to another 
#define TILE_SIZE		  16   //the size in px of the side of an on - screen tile
#define TEXTURE_TILE_SIZE 16  

class cRect {
public:
	int top, left, right, bottom;
};

class cTile {
public:
	void SetX(int px) { x = px; }
	void SetY(int py) { y = py; }
	void  SetTexCoordX(float tex_x) { tex_coordx = tex_x; }
	void  SetTexCoordY(float tex_y) { tex_coordy = tex_y; }
	int   GetX() { return x; }
	int   GetY() { return y; }
	float GetTexCoordX() { return tex_coordx; }
	float GetTexCoordY() { return tex_coordy; }

private:
	int x, y;// postion of the tile 
	float tex_coordx, tex_coordy; //postion of the texture tile 
};

class cScene
{
public:
	cScene(void);
    ~cScene(void);

	bool LoadLevel(int level, int tex_w, int tex_h);
	void ComputeCollisionMaps();
	void Draw(int tex_id, int tex_w, int tex_h, bool run);
	void DrawAnimatedTiles(int tex_id, int tex_w, int tex_h);
	bool* GetCollisionMap();
	bool* GetProjCollisionMap();

private:

	//sets of tiles of different behaviors
	int terrain_flat[SCENE_WIDTH * SCENE_HEIGHT];
	int terrain_solid[SCENE_WIDTH * SCENE_HEIGHT];
	int solid_alpha[SCENE_WIDTH * SCENE_HEIGHT];
	std::vector<cTile> animated_tiles;
	std::vector<cTile> animated_tiles_up;
	int bridges[SCENE_WIDTH * SCENE_HEIGHT];
	int always_down[SCENE_WIDTH * SCENE_HEIGHT];
	int z_tileup[SCENE_WIDTH * SCENE_HEIGHT];
	int z_tiledown[SCENE_WIDTH * SCENE_HEIGHT];
	int always_up[SCENE_WIDTH * SCENE_HEIGHT];
	int always_up_alpha[SCENE_WIDTH * SCENE_HEIGHT];

	//display lists
	int id_TerrainFlat;
	int id_TerrainSolid;
	int id_SolidAlpha;
	int id_Bridges;
	int id_AlwaysDown;
	int id_ZtileUp;
	int id_ZtileDown;
	int id_AlwaysUp;
	int id_AlwaysUpAlpha;

	bool collision_map[SCENE_WIDTH * SCENE_HEIGHT];
	bool proj_collision_map[SCENE_WIDTH * SCENE_HEIGHT];
	int  seq, delay, frame_delay;
};

/*
******************
  ____
 |    |
x|____|  <= Tile
 y
******************
*/

/*
****************************
		tile_y=0
		  ______
 tile_x=0|    |
		 |____|  <= Texture
		 |
****************************
*/