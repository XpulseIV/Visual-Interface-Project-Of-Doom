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
		
		// Loads all texts from std::vector<Text> to std::vector<sf::text> to be rendered later
		
		if (!texts.empty())
			#pragma region loadTextObjects
			application.texts = texts;

			std::vector<sf::Text> sfTexts;

			sf::Font font;
			if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
			{
				std::cout << "Failed to load font file\n";
				exit(EXIT_FAILURE);
			}

			for (const VIDAL::Text& t : application.texts)
			{
				sf::Text text;
				text.setFont(font);
				text.setString(t.text);
				text.setCharacterSize(t.size);
				text.setLineSpacing(t.lineSpacing);
				text.setLetterSpacing(t.letterSpacing);
				text.setStyle(t.style);
				
				text.setFillColor(sf::Color(t.color.R, t.color.G, t.color.B, t.color.ALPHA));
				
				text.setOutlineColor(sf::Color(t.outlineColor.R, t.outlineColor.G, t.outlineColor.B, t.outlineColor.ALPHA));
				text.setOutlineThickness(t.outlineThickness);
				text.setPosition(t.pos.x, t.pos.y);
				text.rotate(t.angle);
				text.setScale(t.scale.factorX, t.scale.factorY);
				text.setOrigin(t.origin.originX, t.origin.originY);

				sfTexts.push_back(text);
			}
			application.sfTexts = sfTexts;
			#pragma endregion
		
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
			for (auto t : application.sfTexts) render_window.draw(t);

			render_window.display();
		}
	}
}