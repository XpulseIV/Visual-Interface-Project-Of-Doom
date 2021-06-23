#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include <vector>

namespace VIDAL
{
	struct Color
	{
		uint8_t R, B, G, ALPHA = 255;
	};

	struct Pos
	{
		uint8_t x, y;
	};

	struct Scale
	{
		float factorX, factorY;
	};

	struct Origin
	{
		float originX, originY;
	};
	
	class Window
	{
	public:
		std::string title;
		unsigned int width, height;
	};

	class Text
	{
	public:
		std::string text;
		unsigned int size;
		float lineSpacing;
		float letterSpacing;
		sf::Uint32 style;
		Color color;
		Color outlineColor;
		float outlineThickness;
		Pos pos;
		float angle;
		Scale scale;
		Origin origin;
	};
	
	class Application
	{
	public:
		static void Initialize(const Window& window, const std::vector<Text>& texts);
		
		Window window;
		std::vector<Text> texts;
		std::vector<sf::Text> sfTexts;
	
	private:
		static void Main_Loop(VIDAL::Application application);
	};
}
