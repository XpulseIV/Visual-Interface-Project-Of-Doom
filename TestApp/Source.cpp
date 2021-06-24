#include "VIDAL.h"
#include <vector>
#include <iostream>

int main()
{
	// Window Settings
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "Test Window";
	const VIDAL::Color windowColor = {0, 0, 0, 255};

	// Window Contents
	const VIDAL::Text::Text lol1 = {
		.text = "lol", .size = 48, .style = VIDAL::Text::Style::Regular, .color = {0, 0, 255, 255}, .pos = {0, 0}
	};
	const VIDAL::Text::Text lol2 = {
		.text = "lol", .size = 48, .style = VIDAL::Text::Style::Bold, .color = {0, 0, 255, 255}, .pos = {0, 50}
	};
	
	const std::vector texts = {lol1, lol2};

	VIDAL::Button::Button button;
	
	VIDAL::Application::Initialize(window, texts, windowColor);
	return 0;
}