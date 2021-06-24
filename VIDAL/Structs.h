#pragma once
#include <cstdint>
#include <string>

namespace VIDAL
{
	struct Color
	{
		uint8_t r{}, g{}, b{}, alpha = 255;
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

	struct TextureRect
	{
		std::string name, path;
		unsigned int left;
		unsigned int top;
		unsigned int width;
		unsigned int height;
	};

	struct Points
	{
		unsigned int index;
		float x, y;
	};

	struct RectSize
	{
		float width, height;
	};
}