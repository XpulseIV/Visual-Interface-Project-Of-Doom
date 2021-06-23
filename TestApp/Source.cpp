#include "VIDAL.h"
#include <vector>

int main()
{
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "LOL";

	const VIDAL::Text lol = {
		"lol", 48, 10, 10
	};
	
	std::vector<VIDAL::Text> texts = {lol};
	
	VIDAL::Application::Initialize(window, texts);
	return 0;
}