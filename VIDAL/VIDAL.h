#pragma once

#include "SFML/Window.hpp"

namespace VIDAL
{
	class Window
	{
	public:
		unsigned int width, height;
		std::string title;
	};
	
	class Application
	{
	public:
		static void Initialize(VIDAL::Application application);
		Window window;
	private:
		static void Main_Loop(VIDAL::Window window);
	};
}
