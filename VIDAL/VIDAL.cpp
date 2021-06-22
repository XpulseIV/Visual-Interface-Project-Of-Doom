#include "pch.h"
#include "framework.h"
#include "VIDAL.h"

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>

namespace VIDAL
{
	// Application Methods
	void Application::Initialize(const Window& window, const std::vector<Text>& texts)
	{
		Application application;
		application.window = window; // Having a window is required
		
		if(!texts.empty())
			application.texts = texts;
		
		Main_Loop(application);
	}

	void Application::Main_Loop(VIDAL::Application application)
	{
		sf::RenderWindow render_window;
		render_window.create(sf::VideoMode(application.window.width, application.window.height), application.window.title);

		sf::Font font;
		if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
		{
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
					application.window.width = event.size.width;
					application.window.height = event.size.height;

					sf::FloatRect visibleArea(0, 0, application.window.width, application.window.height);
					render_window.setView(sf::View(visibleArea));
				}
			}

			render_window.clear(sf::Color::Black);

			render_window.draw(text);

			render_window.display();
		}
	}
}