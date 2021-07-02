#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Structs.h"
#include "Buttons.h"

#include <vector>

namespace VIDAL
{
	bool IsWithin(const sf::Vector2i mouse_pos, const sf::RectangleShape& object);
	
	class Window
	{
	public:
		std::string title;
		unsigned int width = 800, height = 600;
	};
	
	class Application
	{
	public:
		Window window;
		Color window_color;

		std::vector<void(*)(void*)> button_events;
		
		std::vector<sf::Text> sf_texts;
		std::vector<sf::RectangleShape> sf_rect_shapes;
		std::vector<sf::RectangleShape> button_shapes;
		std::vector<sf::CircleShape> sf_circle_shapes;
		std::vector<sf::ConvexShape> sf_convex_shapes;
	
	private:
		static void ReInit(Application* application, void (*function)(void*));
		static void Main_Loop(VIDAL::Application application);
	};
}