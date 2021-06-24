#include "pch.h"
#include "framework.h"
#include "VIDAL.h"

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <map>

namespace VIDAL
{
	// Application Methods
	void Application::Initialize(const Window& window, const std::vector<Text::Text>& texts, const Color windowColor)
	{
		Application application;
		application.window = window; // Having a window is required
		application.window_color = windowColor; // Color of the window BackGround

		// Loads all texts from std::vector<Text> to std::vector<sf::text> to be rendered later
		
		if (!texts.empty())
		{
			#pragma region loadTextObjects

			std::vector<sf::Text> sfTexts;

			// Loading the font from the file
			sf::Font font;
			if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
			{
				std::cout << "Failed to load font file\n";
				exit(EXIT_FAILURE);
			}

			for (const VIDAL::Text::Text& t : texts)
			{
				sf::Text text;
				text.setFont(font);
				text.setString(t.text);
				text.setCharacterSize(t.size);
				text.setLineSpacing(t.line_spacing);
				text.setLetterSpacing(t.letter_spacing);
				text.setStyle(t.style);

				text.setFillColor(sf::Color(t.color.r, t.color.g, t.color.b, t.color.alpha));

				text.setOutlineColor(sf::Color(t.outline_color.r, t.outline_color.g, t.outline_color.b, t.outline_color.alpha));
				text.setOutlineThickness(t.outline_thickness);
				text.setPosition(t.pos.x, t.pos.y);
				text.rotate(t.angle);
				text.setScale(t.scale.factor_x, t.scale.factor_y);
				text.setOrigin(t.origin.x, t.origin.y);
				sfTexts.push_back(text);
			}

			application.sf_texts = sfTexts;
			#pragma endregion
		}
		
		Main_Loop(application); // Main program
	}

	void Application::Main_Loop(VIDAL::Application application)
	{
		sf::RenderWindow render_window;
		render_window.create(sf::VideoMode(application.window.width, application.window.height), application.window.title);

		while (render_window.isOpen())
		{
			sf::Event event{};

			while (render_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					render_window.close();
				
				if (event.type == sf::Event::Resized)
				{
					application.window.width = event.size.width;
					application.window.height = event.size.height;

					sf::FloatRect visibleArea(0, 0, static_cast<float>(application.window.width), static_cast<float>(application.window.height));
					render_window.setView(sf::View(visibleArea));
				}
			}

			render_window.clear(sf::Color(application.window_color.r, application.window_color.g, application.window_color.b, application.window_color.alpha));

			// Here Render Stuff

			// TextRenderer
			for (auto t : application.sf_texts) render_window.draw(t);
			//

			
			render_window.display();
		}
	}
}