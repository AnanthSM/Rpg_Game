#pragma once

#include "globals.h"
#include "corona.h"

class cTexture {
public:
	cTexture();
	~cTexture();

	int GetId();
	int GetSize(int* w, int* h);
	bool Load(const char* filename, int type = GL_RGBA, int wraps = GL_REPEAT, int wrapt = GL_REPEAT, 
		int magf = GL_NEAREST,int minf = GL_NEAREST, bool mipmap = false);

private:
	GLuint id;
	int width, height; 


};