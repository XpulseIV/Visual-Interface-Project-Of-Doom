#include "pch.h"
#include "framework.h"
#include "VIDAL.h"

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>

namespace VIDAL
{
	std::vector<sf::Text> Application::VidalTextToSfText(const std::vector<Text>& texts, sf::Font font)
	{
		std::vector<sf::Text> sfTexts;

		for (const VIDAL::Text& t : texts)
		{
			sf::Text text;
			text.setFont(font);
			text.setString(t.text);
			text.setCharacterSize(t.size);
			text.setFillColor(sf::Color::Blue);
			text.setPosition(t.x, t.y);

			sfTexts.push_back(text);
		}
		return sfTexts;
	}
	// Application Methods
	void Application::Initialize(const Window& window, const std::vector<Text>& texts)
	{
		Application application;
		application.window = window; // Having a window is required
		
		
		// Loads all texts from std::vector<Text> to std::vector<sf::text> to be rendered later
		if (!texts.empty())
		{
			sf::Font font;
			if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
			{
				std::cout << "Failed to load font file\n";
				exit(EXIT_FAILURE);
			}

			application.sfTexts = VidalTextToSfText(texts, font);
		}
		
		Main_Loop(application);
	}

	void Application::Main_Loop(VIDAL::Application application)
	{
		sf::RenderWindow render_window;
		render_window.create(sf::VideoMode(application.window.width, application.window.height), application.window.title);

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

			// Here Render Stuff
			
			// Render texts
			render_window.draw(application.sfTexts[0]);

			render_window.display();
		}
	}
}