#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "std_image.h"

Texture::Texture(const char* textureImagePath)
	: texturePath(textureImagePath)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::use()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::setParameter(int target, int value)
{
	glTexParameteri(GL_TEXTURE_2D, target, value);
}

void Texture::generate()
{
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}