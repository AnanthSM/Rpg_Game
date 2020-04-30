#include "cTexture.h"

cTexture::cTexture() {


}

cTexture::~cTexture() {


}

bool cTexture::Load(char const *filename, int type, int wraps, int wrapt, int magf, int minf, bool mipmap) {
	//refer https://open.gl/textures
	corona::Image* img;
	int comp;
	img = corona::OpenImage(filename);
	if (type == GL_RGB) {
		comp = 3;
	}
	else if (type == GL_RGBA)
	{
		comp = 4;
	}
	else
		return false;

	if (img == NULL)
		return false;

	height = img->getHeight();
	width = img->getWidth();

	glGenTextures(1, &id); //glGenTextures — generate texture names
	glBindTexture(GL_TEXTURE_2D, id); //glBindTexture — bind a named texture to a texturing target

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wraps); //wrapping of the image if it goes out of range 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapt); // here s,t = x,y 

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magf); //filtering the image if there are pixels missing ex: when a image is streched 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minf);

	if (!mipmap) {

		glTexImage2D(GL_TEXTURE_2D, 0, comp, width, height, 0, type,
			GL_UNSIGNED_BYTE, img->getPixels());
	}
	else {
		gluBuild2DMipmaps(GL_TEXTURE_2D, comp, width, height, type,
			GL_UNSIGNED_BYTE, img->getPixels());
	}

	return true;
}

int cTexture::GetId() {
	return id;
}

void cTexture::GetSize(int* w,int* h) {
	*w = width;
	*h = height;


}