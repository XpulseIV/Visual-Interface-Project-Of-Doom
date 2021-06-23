#include "VIDAL.h"
#include <vector>

int main()
{
	// Window Settings
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "Test Window";
	const VIDAL::Color windowColor = {0, 0, 0, 255};

	// Window Contents
	const VIDAL::Text lol1 = {
		.text = "lol", .size = 48, .style = VIDAL::Regular, .color = {0, 0, 255, 255}, .pos = {0, 0}
	};
	
	const std::vector<VIDAL::Text> texts = {lol1};
	
	VIDAL::Application::Initialize(window, texts, windowColor);
	return 0;
}