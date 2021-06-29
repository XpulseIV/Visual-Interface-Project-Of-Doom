#include "pch.h"
#include "framework.h"
#include "VIDAL.h"
#include "Structs.h"
#include "Shapes.h"
#include "Texts.h"
#include "Buttons.h"

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <map>

// If mouse is within a object, return true. Otherwise, return false



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
	
	// Application Methods
	//void Application::Initialize(const Window& window,
	//							 const std::vector<Text::Text>& texts,
	//							 const Color windowColor,
	//							 const std::vector<VIDAL::Shape::Rectangle>& rectangle_shapes,
	//							 const std::vector<VIDAL::Shape::RegularPolygon>& normal_polygon_shapes,
	//							 const std::vector<VIDAL::Shape::ConvexShape>& convex_shapes,
	//							 const std::vector<VIDAL::Button>& buttons)
	//{
	//	Application application;
	//	application.window = window; // Having a window is required
	//	application.window_color = windowColor; // Color of the window BackGround
	//
	//	// Loads all texts from std::vector<Text> to std::vector<sf::text> to be rendered later
	//
	//	#pragma region Button handling
	//
	//	if (!buttons.empty())
	//	{
	//		std::vector<sf::RectangleShape> buttonShapes;
	//		std::vector<void(*)(void*)> buttonEvents;
	//		for (const VIDAL::Button::Button& button : buttons)
	//		{
	//			auto rS = button.shape;
	//			sf::RectangleShape rShape;
	//			rShape.setSize(sf::Vector2f(rS.size.width, rS.size.height));
	//			// Textures goes here
	//			rShape.setFillColor(sf::Color(rS.color.r, rS.color.g, rS.color.b, rS.color.alpha));
	//			rShape.setOutlineColor(sf::Color(rS.outlineColor.r, rS.outlineColor.g, rS.outlineColor.b, rS.outlineColor.alpha));
	//			rShape.setOutlineThickness(rS.outlineThickness);
	//			rShape.setPosition(rS.pos.x, rS.pos.y);
	//			rShape.setRotation(rS.angle);
	//			rShape.setScale(rS.scale.factor_x, rS.scale.factor_y);
	//			rShape.setOrigin(rS.origin.x, rS.origin.y);
	//
	//			buttonEvents.push_back(button.on_click);
	//
	//			buttonShapes.push_back(rShape);
	//		}
	//
	//		application.button_events = buttonEvents;
	//		application.button_shapes = buttonShapes;
	//	}
	//	
	//	#pragma endregion 
	//
	//	#pragma region textHandling
	//	
	//	#pragma region FontLoading
	//	sf::Font font;
    //
	//	if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
	//	{
	//		std::cout << "Failed to load font file\n";
	//		exit(EXIT_FAILURE);
	//	}
	//
	//	#pragma endregion
	//	
	//	if (!texts.empty())
	//	{
	//		#pragma region loadTextObjects
	//
	//		std::vector<sf::Text> sfTexts;
	//
	//		for (const VIDAL::Text::Text& t : texts)
	//		{
	//			sf::Text text;
	//			text.setFont(font);
	//			text.setString(t.text);
	//			text.setCharacterSize(t.size);
	//			text.setLineSpacing(t.line_spacing);
	//			text.setLetterSpacing(t.letter_spacing);
	//			text.setStyle(t.style);
	//
	//			text.setFillColor(sf::Color(t.color.r, t.color.g, t.color.b, t.color.alpha));
	//
	//			text.setOutlineColor(sf::Color(t.outline_color.r, t.outline_color.g, t.outline_color.b, t.outline_color.alpha));
	//			text.setOutlineThickness(t.outline_thickness);
	//			text.setPosition(t.pos.x, t.pos.y);
	//			text.rotate(t.angle);
	//			text.setScale(t.scale.factor_x, t.scale.factor_y);
	//			text.setOrigin(t.origin.x, t.origin.y);
	//			sfTexts.push_back(text);
	//		}
	//
	//		application.sf_texts = sfTexts;
	//		#pragma endregion
	//	}
	//	#pragma endregion
	//	
	//	#pragma region loadShapeObjects
	//
	//	if (!rectangle_shapes.empty())
	//	{
	//		std::vector<sf::RectangleShape> rectangle_shapesLoL;
	//		for (const VIDAL::Shape::Rectangle& rS : rectangle_shapes)
	//		{
	//			sf::RectangleShape rShape;
	//			rShape.setSize(sf::Vector2f(rS.size.width, rS.size.height));
	//			// Textures goes here
	//			rShape.setFillColor(sf::Color(rS.color.r, rS.color.g, rS.color.b, rS.color.alpha));
	//			rShape.setOutlineColor(sf::Color(rS.outlineColor.r, rS.outlineColor.g, rS.outlineColor.b, rS.outlineColor.alpha));
	//			rShape.setOutlineThickness(rS.outlineThickness);
	//			rShape.setPosition(rS.pos.x, rS.pos.y);
	//			rShape.setRotation(rS.angle);
	//			rShape.setScale(rS.scale.factor_x, rS.scale.factor_y);
	//			rShape.setOrigin(rS.origin.x, rS.origin.y);
	//
	//			rectangle_shapesLoL.push_back(rShape);
	//		}
	//		
	//		application.sf_rect_shapes = rectangle_shapesLoL;
	//	}
	//
	//	if (!normal_polygon_shapes.empty())
	//	{
	//		std::vector<sf::CircleShape> normal_polygon_shapesLOL;
	//		for (const VIDAL::Shape::RegularPolygon& rPS : normal_polygon_shapes)
	//		{
	//			sf::CircleShape regularPolygonShape;
	//
	//			regularPolygonShape.setRadius(rPS.radius);
	//			regularPolygonShape.setPointCount(rPS.pointCount);
	//			// Textures goes here
	//			regularPolygonShape.setFillColor(sf::Color(rPS.color.r, rPS.color.g, rPS.color.b, rPS.color.alpha));
	//			regularPolygonShape.setOutlineColor(sf::Color(rPS.outlineColor.r, rPS.outlineColor.g, rPS.outlineColor.b, rPS.outlineColor.alpha));
	//			regularPolygonShape.setOutlineThickness(rPS.outlineThickness);
	//			regularPolygonShape.setPosition(rPS.pos.x, rPS.pos.y);
	//			regularPolygonShape.setRotation(rPS.angle);
	//			regularPolygonShape.setScale(rPS.scale.factor_x, rPS.scale.factor_y);
	//			regularPolygonShape.setOrigin(rPS.origin.x, rPS.origin.y);
	//			
	//			normal_polygon_shapesLOL.push_back(regularPolygonShape);
	//		}
	//
	//		application.sf_circle_shapes = normal_polygon_shapesLOL;
	//	}
	//
	//	if (!convex_shapes.empty())
	//	{
	//		std::vector<sf::ConvexShape> convex_shapesLOL;
	//		for (VIDAL::Shape::ConvexShape cS : convex_shapes)
	//		{
	//			sf::ConvexShape convexShape;
	//
	//			convexShape.setPointCount(cS.pointCount);
	//
	//			for (int i = 0; i < cS.pointCount - 1; i++)
	//			{
	//				convexShape.setPoint(cS.points[i].index, (sf::Vector2f(cS.points[i].x, cS.points[i].y)));
	//			}
	//
	//			// Textures goes here
	//			convexShape.setFillColor(sf::Color(cS.color.r, cS.color.g, cS.color.b, cS.color.alpha));
	//			convexShape.setOutlineColor(sf::Color(cS.outlineColor.r, cS.outlineColor.g, cS.outlineColor.b, cS.outlineColor.alpha));
	//			convexShape.setOutlineThickness(cS.outlineThickness);
	//			convexShape.setPosition(cS.pos.x, cS.pos.y);
	//			convexShape.setRotation(cS.angle);
	//			convexShape.setScale(cS.scale.factor_x, cS.scale.factor_y);
	//			convexShape.setOrigin(cS.origin.x, cS.origin.y);
	//
	//			convex_shapesLOL.push_back(convexShape);
	//		}
	//
	//		application.sf_convex_shapes = convex_shapesLOL;
	//	}
	//	
	//	#pragma endregion
	//	
	//	Main_Loop(application); // Main program
	//}

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