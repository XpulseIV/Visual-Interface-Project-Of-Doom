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
	if (button->shape.getFillColor() != sf::Color(0, 200, 255))
		button->shape.setFillColor(sf::Color(0, 200, 255));
}
void Button0Hover(void* ptr)
{
	auto button = static_cast<VIDAL::Button*> (ptr);
	if (button->shape.getFillColor() != sf::Color(0, 255, 64) && !button->is_clicked)
		button->shape.setFillColor(sf::Color(0, 255, 64));
}

int main()
{

	sf::RenderWindow window;
	auto windowColor = sf::Color(0, 0, 0, 255);
	window.create(sf::VideoMode(800, 600), "Test Window");
	window.setFramerateLimit(60);

	#pragma region Font loading
	sf::Font font;
	if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
	{
		std::cout << "Failed to load font file\n";
		exit(EXIT_FAILURE);
	}
	#pragma endregion 
	
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

	bool holdLeftMouse = false;
	const int holdThreshold = 30;
	int holdTime = 0;

	while (window.isOpen())
	{
		sf::Keyboard::Key releasedKey;
		releasedKey = sf::Keyboard::Key::Unknown;
		sf::Keyboard::Key heldKey = sf::Keyboard::Key::Unknown;

		bool releasedLeftMouse = false, pressedLeftMouse = false;
		
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
				pressedLeftMouse = true;
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

		// Holding left mouse logic
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			holdTime++;
		if (releasedLeftMouse)
		{
			holdTime = 0;
			holdLeftMouse = false;
		}
		if (holdTime >= holdThreshold)
			holdLeftMouse = true;
		
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
		if(holdLeftMouse)
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