#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Structs.h"

#include <vector>

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
			Color outlineColor = {0, 0, 0, 0,};
			float outlineThickness = 0;
			Pos pos;
			float angle = 0;
			Scale scale = {1, 1};
			Origin origin = {0, 0};
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
	
	namespace Text
	{
		enum Style
		{
			Regular,
			Bold,
			ItalicRegular,
			ItalicBold,
			UnderLinedRegular,
			UnderLinedBold,
			UnderLinedItalicRegular,
			UnderLinedItalicBold,
			StrikeThroughRegular,
			StrikeThroughBold,
			StrikeThroughItalicRegular,
			StrikeThroughItalicBold,
			StrikeThroughUnderLinedRegular,
			StrikeThroughUnderLinedBold,
			StrikeThroughUnderLinedItalicRegular,
			StrikeThroughUnderLinedItalicBold
		};

		class Text
		{
		public:
			std::string text;
			unsigned int size;
			float line_spacing = 1.5;
			float letter_spacing = 1;

			Style style = Regular;
			Color color;
			Color outline_color = { 0, 0, 0, 0 };
			float outline_thickness = 0;
			Pos pos;
			float angle = 0;
			Scale scale = { 1, 1 };
			Origin origin = { 0, 0 };
		};
	}

	namespace Button
	{
		class Button
		{
		public:
			Shape::Rectangle shape;
		};
	}
	
	class Window
	{
	public:
		std::string title;
		unsigned int width = 800, height = 600;
	};
	
	class Application
	{
	public:
		static void Initialize(const Window& window, const std::vector<Text::Text>& texts, const Color windowColor, std::vector<VIDAL::Shape::Rectangle> rectangle_shapes, std::vector<VIDAL::Shape::RegularPolygon> normal_polygon_shapes, std::vector<VIDAL::Shape::ConvexShape> convex_shapes);
		
		Window window;
		Color window_color;
		std::vector<sf::Text> sf_texts;
		std::vector<sf::RectangleShape> sf_rect_shapes;
		std::vector<sf::CircleShape> sf_circle_shapes;
		std::vector<sf::ConvexShape> sf_convex_shapes;
	
	private:
		static void Main_Loop(VIDAL::Application application);
	};
}
