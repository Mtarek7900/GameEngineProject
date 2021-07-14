#include "Sprite.h"
#include "pch.h"
#include "stb_image.h"

namespace Hunter
{
	Sprite::Sprite(const std::string& spriteFile)
	{
		if (!Load(spriteFile))
		{ 
			HLOG("ERROR LOADING SPRITE!");
		}
			
	}

	bool Sprite::Load(const std::string& spriteFile)
	{
		//flips image since it gets inverted, opengl reads from bottemleft corner
		stbi_set_flip_vertically_on_load(1);
		mImage = stbi_load(spriteFile.c_str(), &mWidth, &mHeight, &mNumChannels, 0);

		if (mImage)
			return true;
		else
			return false;
	}

	int Sprite::GetWidth() const
	{
		return mWidth;
	}
	
	
	int Sprite::GetHeight() const
	{
		return mHeight;
	}

	const unsigned char* Sprite::GetImagePointer() const
	{
		return mImage;
	}

	Sprite::~Sprite()
	{
		stbi_image_free(mImage);
	}
}
