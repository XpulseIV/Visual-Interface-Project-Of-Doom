#pragma once
#include <cstdint>
#include <string>

namespace VIDAL
{
	struct Color
	{
		uint8_t r{}, b{}, g{}, alpha = 255;
	};

	struct Pos
	{
		float x, y;
	};

	struct Scale
	{
		float factor_x, factor_y;
	};

	struct Origin
	{
		float x, y;
	};

	struct Texture
	{
		std::string name, path;
	};

	struct TextureRect : Texture
	{
		unsigned int left;
		unsigned int top;
		unsigned int width;
		unsigned int height;
	};

	struct Points : Pos
	{
		unsigned int index;
	};

	struct RectSize
	{
		unsigned int width, height;
	};
}