#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include <vector>

namespace VIDAL
{
	namespace Button
	{
		
	}
	namespace Text
	{
		enum TextStyle
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

		struct Color
		{
			uint8_t r, b, g, alpha = 255;
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

		class Text
		{
		public:
			std::string text;
			unsigned int size;
			float line_spacing = 1.5;
			float letter_spacing = 1;

			TextStyle style = Regular;
			Color color;
			Color outline_color = { 0, 0, 0, 0 };
			float outline_thickness = 0;
			Pos pos;
			float angle = 0;
			Scale scale = { 1, 1 };
			Origin origin = { 0, 0 };
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
		static void Initialize(const Window& window, const std::vector<Text::Text>& texts, Text::Color windowColor);
		
		Window window;
		Text::Color window_color;
		std::vector<sf::Text> sf_texts;
	
	private:
		static void Main_Loop(VIDAL::Application application);
	};
}
