#include "VIDAL.h"
#include <vector>
#include <iostream>

void Button0Click(void* ptr)
{
	auto button = static_cast<VIDAL::Button*> (ptr);
	if (!button->is_clicked)
	{
		button->shape.setFillColor(sf::Color(0, 255, 255, 255));
		button->is_clicked = true;
	}
	else 
	{
		button->shape.setFillColor(sf::Color(0, 255, 0, 255));
		button->is_clicked = false;
	}
}
void Button0Hold(void* ptr)
{
	auto button = static_cast<VIDAL::Button*> (ptr);
	if (button->shape.getFillColor() != sf::Color(0, 200, 255) && !button->is_clicked)
		button->shape.setFillColor(sf::Color(0, 200, 255));
}

int main()
{
	//// Window Settings
	//VIDAL::Window window;
	//window.width = 800;
	//window.height = 600;
	//window.title = "Test Window";
	//const VIDAL::Color windowColor = {0, 0, 0, 255};
	//
	//const VIDAL::Text::Text lol{
	//	.text = "lol", .size = 48, .style = VIDAL::Text::Style::Regular, .color = {0, 255, 0, 255}
	//};
	//
	//const VIDAL::Shape::Rectangle buttonShape{
	//	.size = {50, 50}, .color = {0,255, 0, 255}, .pos = {100, 100}
	//};
	//
	//
	//const VIDAL::Shape::RegularPolygon lolPolygon = {
	//	.radius = 50, .pointCount = 3, .color = {0,255, 245, 255}
	//};
	//
	//VIDAL::Button::Button button = { .shape = buttonShape, .on_click = &Button0Click };
	//
	//// Vectors
	//std::vector<VIDAL::Text::Text> texts ={ lol };
	//std::vector<VIDAL::Shape::Rectangle> rectangle_shapes;
	//std::vector<VIDAL::Shape::RegularPolygon> normal_polygon_shapes = { lolPolygon };
	//std::vector<VIDAL::Shape::ConvexShape> convex_shapes;
	//std::vector<VIDAL::Button::Button> buttons = { button };
	//
	//
	//
	//VIDAL::Application::Initialize(window, texts, windowColor, rectangle_shapes, normal_polygon_shapes, convex_shapes, buttons);

	sf::RenderWindow window;
	auto windowColor = sf::Color(255, 255, 255, 255);
	window.create(sf::VideoMode(800, 600), "Test Window");

	sf::Font font;

	if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
	{
		std::cout << "Failed to load font file\n";
		exit(EXIT_FAILURE);
	}

	sf::Text text0;
	text0.setString("LOL");
	text0.setFillColor(sf::Color(0, 255, 0));
	text0.setFont(font);
	text0.setCharacterSize(48);

	VIDAL::Button button0;
	button0.shape.setSize(sf::Vector2f(50, 50));
	button0.shape.setFillColor(sf::Color(0, 255, 0));
	button0.shape.setPosition(sf::Vector2f(100, 100));
	button0.on_click = &Button0Click;
	button0.on_held	= &Button0Hold;

	std::vector texts { text0 };
	std::vector buttons { button0 };

	while (window.isOpen())
	{
		sf::Keyboard::Key releasedKey;
		releasedKey = sf::Keyboard::Key::Unknown;
		sf::Keyboard::Key heldKey = sf::Keyboard::Key::Unknown;

		bool releasedLeftMouse = false, heldLeftMouse = false;
		
		#pragma region Events

		sf::Event event{};
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
			{
				sf::FloatRect visibleArea(0, 0, (event.size.width), (event.size.height));
				window.setView(sf::View(visibleArea));
					break;
			}
			case sf::Event::LostFocus: 
				break;
			case sf::Event::GainedFocus: 
				break;
			case sf::Event::TextEntered: 
				break;
			case sf::Event::KeyPressed:
				heldKey = event.key.code;
				break;
			case sf::Event::KeyReleased:
				releasedKey = event.key.code;
				break;
			case sf::Event::MouseWheelMoved: 
				break;
			case sf::Event::MouseWheelScrolled: 
				break;
			case sf::Event::MouseButtonPressed:
				heldLeftMouse = true;
				break;
			case sf::Event::MouseButtonReleased:
				releasedLeftMouse = true;
				break;
			case sf::Event::MouseMoved: 
				break;
			case sf::Event::MouseEntered: 
				break;
			case sf::Event::MouseLeft: 
				break;
			case sf::Event::JoystickButtonPressed: 
				break;
			case sf::Event::JoystickButtonReleased: 
				break;
			case sf::Event::JoystickMoved: 
				break;
			case sf::Event::JoystickConnected: 
				break;
			case sf::Event::JoystickDisconnected: 
				break;
			case sf::Event::TouchBegan: 
				break;
			case sf::Event::TouchMoved: 
				break;
			case sf::Event::TouchEnded: 
				break;
			case sf::Event::SensorChanged: 
				break;
			case sf::Event::Count: 
				break;
			}
		}
		
		#pragma endregion
		
		#pragma region Changes

		if(heldKey == sf::Keyboard::A)
			texts[0].setCharacterSize(300);
		if (releasedKey == sf::Keyboard::A)
			texts[0].setCharacterSize(48);

		if (releasedLeftMouse)
		{
			for (int i = 0; i < buttons.size(); i++)  // Can't use range-based for loop because it copies        NOLINT(modernize-loop-convert)
			{
				if (VIDAL::IsWithin(sf::Mouse::getPosition(window), buttons[i].shape))
				{
					buttons[i].on_click(&buttons[i]); 
				}
			}
		}
		if(heldLeftMouse)
		{
			for (int i = 0; i < buttons.size(); i++)  // Can't use range-based for loop because it copies        NOLINT(modernize-loop-convert)
			{
				if (VIDAL::IsWithin(sf::Mouse::getPosition(window), buttons[i].shape))
				{
					buttons[i].on_held(&buttons[i]);
				}
			}
		}
		
		#pragma endregion
		
		#pragma region Rendering

		window.clear(windowColor);

		for (const auto& text : texts) window.draw(text);
		for (const auto& button : buttons) button.Draw(&window);
		
		window.display();
		
		#pragma endregion 
	}
	
	return 0;
}