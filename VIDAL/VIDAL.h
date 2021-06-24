#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Structs.h"

#include <vector>

namespace VIDAL
{
	namespace Shape
	{
		class Shape
		{
			Color color = {};
			Texture texture;
			TextureRect textureRect;
			Color color;
			Color outlineColor;
			float outlineThickness;
			Pos pos;
			float angle;
			Scale scale;
			Origin origin;
		};
		
		class Rectangle : Shape
		{
			RectSize size;
		};
		
		class RegularPolygon : Shape
		{
			float radius;
			unsigned int pointCount;
		};
		
		class ConvexShape : Shape
		{
			unsigned int pointCount;
			Points points;
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
			Shape::Shape shape;
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
		static void Initialize(const Window& window, const std::vector<Text::Text>& texts, Color windowColor);
		
		Window window;
		Color window_color;
		std::vector<sf::Text> sf_texts;
	
	private:
		static void Main_Loop(VIDAL::Application application);
	};
}
