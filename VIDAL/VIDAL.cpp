#include "pch.h"
#include "framework.h"
#include "VIDAL.h"
#include "Buttons.h"

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <map>

namespace VIDAL
{
	bool IsWithin(const sf::Vector2i mouse_pos, const sf::RectangleShape& object)
	{
		const auto low = object.getPosition();
		const auto high = low + object.getSize();
		const bool withinOnX = low.x < mouse_pos.x&& high.x > mouse_pos.x;
		const bool withinOnY = low.y < mouse_pos.y&& high.y > mouse_pos.y;

		if (withinOnX && withinOnY)
			return true;
		return false;
	}
	
	void Button::Draw(sf::RenderWindow* window) const
	{
		window->draw(this->shape);
	}

	void Application::ReInit(Application* application, void(*function)(void*))
	{
		function(application);
	}

	void Application::Main_Loop(VIDAL::Application application)
	{
		sf::RenderWindow render_window;
		render_window.create(sf::VideoMode(application.window.width, application.window.height), application.window.title);

		while (render_window.isOpen())
		{
			bool leftMouseReleased = false;

			#pragma region Events
			
			sf::Event event{};

			while (render_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					render_window.close();
				
				if (event.type == sf::Event::Resized)
				{
					application.window.width = event.size.width;
					application.window.height = event.size.height;

					sf::FloatRect visibleArea(0, 0, (application.window.width), (application.window.height));
					render_window.setView(sf::View(visibleArea));
				}
				if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Left)
				{
					leftMouseReleased = true;
				}
			}

			#pragma endregion

			#pragma region Input

			auto mouse_pos = sf::Mouse::getPosition(render_window);

			if(leftMouseReleased)
			{
				for (int i = 0; i < application.button_shapes.capacity(); i++)
				{
					if (IsWithin(mouse_pos, application.button_shapes[i]))
					{
						ReInit(&application, application.button_events[i]);
					}
				}
			}
			
			#pragma endregion 

			#pragma region Rendering
			render_window.clear(sf::Color(application.window_color.r, application.window_color.g, application.window_color.b, application.window_color.alpha));

			// Here Render Stuff
			// ShapeRenderer shapes
			for (const auto& rShape : application.sf_rect_shapes) render_window.draw(rShape);
			for (const auto& nPShape : application.sf_circle_shapes) render_window.draw(nPShape);
			for (const auto& cShape : application.sf_convex_shapes) render_window.draw(cShape);
			for (const auto& bShape : application.button_shapes) render_window.draw(bShape);
			
			// TextRenderer
			for (const auto& t : application.sf_texts) render_window.draw(t);

			
			render_window.display();
			#pragma endregion 
		}
	}
}