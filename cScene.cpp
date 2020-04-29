#include "cScene.h"

cScene::cScene() {
	seq = 0;
	delay = 0;
	frame_delay = 0;
}

cScene::~cScene() {

}

bool cScene::LoadLevel(int level, int tex_w, int tex_h) {

	bool res;
	FILE *fd;
	char file[32];
	int i, j, px, py, id, tiles_w;
	char c;
	float coordx_tile, coordy_tile;
	float tex_offset_x, tex_offset_y; 

	animated_tiles.clear();
	animated_tiles_up.clear();
	//refer https://www.opengl.org/archives/resources/code/samples/advanced/advanced97/notes/node20.html

	tex_offset_x = 1.0f / float(tex_w / TEXTURE_TILE_SIZE);
	tex_offset_y = 1.0f / float(tex_h / TEXTURE_TILE_SIZE);
	tiles_w = (tex_w / TEXTURE_TILE_SIZE);

	res = true;

	if (level < 10)
		sprintf_s(file, "Levels/%s0%d%s", (char*)LEVEL_FILENAME, level, (char*)FILENAME_EXT);
	else 
		sprintf_s(file, "Levels/%s%d%s", (char*)LEVEL_FILENAME, level, (char*)FILENAME_EXT);

	fopen_s(&fd,file, "r");

	if (fd == NULL)
		return false;

	id_TerrainFlat = glGenLists(1); //glGenLists — generate a contiguous set of empty display lists
	glNewList(id_TerrainFlat, GL_COMPILE); //glNewList — create or replace a display list and mearly compile them and not execute them
	glBegin(GL_QUADS);

	for (j = SCENE_HEIGHT - 1; j >= 0; j--)
	{
		px = SCENE_Xo;
		py = SCENE_Yo + (j * TILE_SIZE);

		for (i = 0; i < SCENE_WIDTH; i++)
		{
			fscanf_s(fd, "%i", &id);

			terrain_flat[(i * SCENE_WIDTH) + i] = id;
			coordx_tile = tex_offset_x * ((id - 1) % tiles_w);
			coordy_tile = tex_offset_y * ((id - 1) / tiles_w);
		}
		if (id) {
			//texture coords to be taken by the vertex; where the vertex will be drawn;
			glTexCoord2f(coordx_tile, coordy_tile + tex_offset_y);
			glVertex3i(px, py, (SCENE_HEIGHT * TILE_SIZE) + 2);
			glTexCoord2f(coordx_tile + tex_offset_x, coordy_tile + tex_offset_y);
			glVertex3i(px + TILE_SIZE, py, (SCENE_HEIGHT * TILE_SIZE) + 2);
			glTexCoord2f(coordx_tile + tex_offset_x, coordy_tile);
			glVertex3i(px + TILE_SIZE, py + TILE_SIZE, (SCENE_HEIGHT * TILE_SIZE) + 2);
			glTexCoord2f(coordx_tile, coordy_tile);
			glVertex3i(px, py + TILE_SIZE, (SCENE_HEIGHT * TILE_SIZE) + 2);

		}
		px += TILE_SIZE;
		fscanf_s(fd,"%c",&c); //for passing comma's and . 



	}

	glEnd();
	glEndList();

	return res;





}
void cScene::ComputeCollisionMaps() {


}

void cScene::Draw(int tex_id, int tex_w, int tex_h, bool run) {

	glEnable(GL_TEXTURE_2D);
	glCallList(id_TerrainFlat);
	glDisable(GL_TEXTURE_2D);




}

void cScene::DrawAnimatedTiles(int tex_id, int tex_w, int tex_h) {


}

bool* cScene::GetCollisionMap() {
	return collision_map;

}

bool* cScene::GetProjCollisionMap() {

	return proj_collision_map;


}