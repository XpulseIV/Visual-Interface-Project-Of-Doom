#include "pch.h"
#include "framework.h"
#include "VIDAL.h"

#include "SFML/Graphics.hpp"

#include <string>
#include <iostream>
#include <utility>

namespace VIDAL
{
	// Application Methods
	void Application::Initialize(VIDAL::Application application)
	{
		
		Main_Loop(application.window);
	}

	void Application::Main_Loop(VIDAL::Window window)
	{
		sf::RenderWindow render_window;
		render_window.create(sf::VideoMode(window.width, window.height), window.title);

		sf::CircleShape shape(50.0f, 50);
		shape.setPosition(window.width / 2 - 50, window.height / 2 - 50);
		shape.setFillColor(sf::Color::Green);

		sf::Font font;
		if(!font.loadFromFile( "JetBrainsMono-Medium.ttf" ))
		{
			// TODO error handling
			std::cout << "Failed to load font file\n";
			exit(EXIT_FAILURE);
		}

		sf::Text text;
		text.setFont(font);
		text.setString("LEL");
		text.setCharacterSize(48);
		text.setFillColor(sf::Color::Blue);
		text.setPosition(0, 0);

		while (render_window.isOpen())
		{
			sf::Event event;

			while (render_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					render_window.close();
				if (event.type == sf::Event::Resized)
				{
					window.width = event.size.width;
					window.height = event.size.height;
					
					sf::FloatRect visibleArea(0, 0, window.width, window.height);
					render_window.setView(sf::View(visibleArea));

					shape.setPosition(window.width / 2 - 50, window.height / 2 - 50);
				}
			}

			render_window.clear(sf::Color::Black);

			render_window.draw(shape);
			render_window.draw(text);

			render_window.display();
		}
	}
}