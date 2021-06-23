#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include <vector>

namespace VIDAL
{
	struct Color
	{
		uint8_t r, b, g, ALPHA = 255;
	};

	struct Pos
	{
		float pos_x, pos_x;
	};

	struct Scale
	{
		float factor_x, factor_y;
	};

	struct Origin
	{
		float origin_x, origin_y;
	};
	
	class Window
	{
	public:
		std::string title;
		unsigned int width = 800, height = 600;
	};

	class Text
	{
	public:
		std::string text;
		unsigned int size;
		float line_spacing = 1.5;
		float letter_spacing = 1;
		
		/* Styles
		* 0 = Regular
		* 1 = Bold
		* 2 = Italic Regular
		* 3 = Italic Bold
		* 4 = UnderLined Regular
		* 5 = UnderLined Bold
		* 6 = UnderLined Italic Regular
		* 7 = UnderLined Italic Bold
		* 8 = StrikeThrough Regular
		* 9 = StrikeThrough Bold
		* 10 = StrikeThrough Italic Regular
		* 11 = StrikeThrough Italic Bold
		* 12 = StrikeThrough UnderLined Regular
		* 13 = StrikeThrough UnderLined Bold
		* 14 = StrikeThrough UnderLined Italic Regular
		* 15 = StrikeThrough UnderLined Italic Bold
		*/
		
		int style = 0;
		Color color;
		Color outline_color = {0, 0, 0, 0};
		float outline_thickness = 0;
		Pos pos;
		float angle = 0;
		Scale scale = {1, 1};
		Origin origin = {0, 0};
	};
	
	class Application
	{
	public:
		static void Initialize(const Window& window, const std::vector<Text>& texts, Color windowColor);
		
		Window window;
		Color window_color;
		std::vector<Text> texts;
		std::vector<sf::Text> sf_texts;
	
	private:
		static void Main_Loop(VIDAL::Application application);
	};
}
