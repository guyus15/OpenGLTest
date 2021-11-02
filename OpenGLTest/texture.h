#pragma once

#include "libs.h"

class Texture
{
public:
	unsigned int ID;
	const char* texturePath;

	Texture(const char* textureImagePath);

	void use();
	void setParameter(int target, int value);
	void generate();
};

