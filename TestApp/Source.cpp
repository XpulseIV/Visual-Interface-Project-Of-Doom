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

	const VIDAL::Text::Text lol{
		.text = "lol", .size = 48, .style = VIDAL::Text::Style::Regular, .color = {0, 0, 255, 255}
	};
	
	// Vectors
	std::vector<VIDAL::Text::Text> texts = {lol};
	std::vector<VIDAL::Shape::Rectangle> rectangle_shapes;
	std::vector<VIDAL::Shape::RegularPolygon> normal_polygon_shapes;
	std::vector<VIDAL::Shape::ConvexShape> convex_shapes;

	
	
	VIDAL::Application::Initialize(window, texts, windowColor, rectangle_shapes, normal_polygon_shapes, convex_shapes);
	return 0;
}