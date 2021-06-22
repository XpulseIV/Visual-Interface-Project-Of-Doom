#include "VIDAL.h"
#include <vector>

int main()
{
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "LOL";

	std::vector<VIDAL::Text> texts;

	const VIDAL::Text lel = {
		"lel", 48, 0, 0, 255, 255, 0, 0
	};

	const VIDAL::Text lol{
		"lol", 50, 0, 255, 0, 255, 50, 50
	};
	
	texts.push_back(lel);
	texts.push_back(lol);
	
	VIDAL::Application::Initialize(window, texts);
	return 0;
}