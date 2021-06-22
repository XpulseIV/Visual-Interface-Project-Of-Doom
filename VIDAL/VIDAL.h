#pragma once

#include "SFML/Window.hpp"

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

	class Font
	{
	public:
		std::string name, file_path;
	};

	class Text
	{
		std::string text;
		Font font;
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
	
	private:
		static void Main_Loop(VIDAL::Application application);
	};
}
