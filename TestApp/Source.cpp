#include "VIDAL.h"
#include <vector>
#include <iostream>

void ButtonClick()
{
	std::cout << "Clicked" << std::endl;
}

int main()
{
	// Window Settings
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "Test Window";
	const VIDAL::Color windowColor = {0, 0, 0, 255};

	const VIDAL::Text::Text lol{
		.text = "lol", .size = 48, .style = VIDAL::Text::Style::Regular, .color = {0, 255, 0, 255}
	};

	const VIDAL::Shape::Rectangle buttonShape{
		.size = {50, 50}, .color = {0,255, 0, 255}, .pos = {100, 100}
	};


	const VIDAL::Shape::RegularPolygon lolPolygon = {
		.radius = 50, .pointCount = 3, .color = {0,255, 245, 255}
	};

	VIDAL::Button::Button button = { .shape = buttonShape, .on_click = &ButtonClick };
	
	// Vectors
	std::vector<VIDAL::Text::Text> texts;
	std::vector<VIDAL::Shape::Rectangle> rectangle_shapes;
	std::vector<VIDAL::Shape::RegularPolygon> normal_polygon_shapes;
	std::vector<VIDAL::Shape::ConvexShape> convex_shapes;
	std::vector<VIDAL::Button::Button> buttons = { button };

	
	
	VIDAL::Application::Initialize(window, texts, windowColor, rectangle_shapes, normal_polygon_shapes, convex_shapes, buttons);
	return 0;
}