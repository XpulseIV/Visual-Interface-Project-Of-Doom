#include <vector>

#include "Structs.h"

#pragma once

namespace VIDAL
{
	namespace Shape
	{
		class Rectangle
		{
		public:
			RectSize size;

			Texture texture;
			TextureRect textureRect;
			Color color;
			Color outlineColor = { 0, 0, 0, 0, };
			float outlineThickness = 0;
			Pos pos;
			float angle = 0;
			Scale scale = { 1, 1 };
			Origin origin = { 0, 0 };
		};

		class RegularPolygon
		{
		public:
			float radius;
			unsigned int pointCount;

			Texture texture;
			TextureRect textureRect;
			Color color;
			Color outlineColor = { 0, 0, 0, 0, };
			float outlineThickness = 0;
			Pos pos;
			float angle = 0;
			Scale scale = { 1, 1 };
			Origin origin = { 0, 0 };
		};

		class ConvexShape
		{
		public:
			unsigned int pointCount;
			std::vector<Points> points;

			Texture texture;
			TextureRect textureRect;
			Color color;
			Color outlineColor = { 0, 0, 0, 0, };
			float outlineThickness = 0;
			Pos pos;
			float angle = 0;
			Scale scale = { 1, 1 };
			Origin origin = { 0, 0 };
		};
	}
}
