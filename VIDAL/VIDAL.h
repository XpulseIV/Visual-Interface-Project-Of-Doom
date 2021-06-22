#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include <vector>

namespace VIDAL
{
	struct Color
	{
		uint8_t r, g, b, a = 255;
	};
	
	class Window
	{
	public:
		unsigned int width, height;
		std::string title;
	};

	class Text
	{
	public:
		std::string text;
		int size;
		Color color;
		int x, y;
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
