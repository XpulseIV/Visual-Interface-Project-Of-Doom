#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Structs.h"
#include "Shapes.h"
#include "Texts.h"
#include "Buttons.h"

#include <vector>

namespace VIDAL
{
	class Window
	{
	public:
		std::string title;
		unsigned int width = 800, height = 600;
	};
	
	class Application
	{
	public:
		static void Initialize(const Window& window, 
							   const std::vector<Text::Text>& texts, 
							   const Color windowColor, 
							   std::vector<VIDAL::Shape::Rectangle> rectangle_shapes, 
							   std::vector<VIDAL::Shape::RegularPolygon> normal_polygon_shapes, 
							   std::vector<VIDAL::Shape::ConvexShape> convex_shapes, 
							   std::vector<VIDAL::Button::Button> buttons);
		
		Window window;
		Color window_color;

		std::vector<void(*)()> button_events;
		
		std::vector<sf::Text> sf_texts;
		std::vector<sf::RectangleShape> sf_rect_shapes;
		std::vector<sf::RectangleShape> button_shapes;
		std::vector<sf::CircleShape> sf_circle_shapes;
		std::vector<sf::ConvexShape> sf_convex_shapes;
	
	private:
		static void Main_Loop(VIDAL::Application application);
	};
}
