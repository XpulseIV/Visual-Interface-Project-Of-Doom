#include "VIDAL.h"
#include <vector>

int main()
{
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "LOL";

	const VIDAL::Text lol = {
		"lel", 48, 0, 0, 255, 255, 0, 0
	};
	const VIDAL::Text lol2 = {
		"lol", 48, 0, 0, 255, 255, 50, 50
	};
	const VIDAL::Text lol3 = {
		"lel", 48, 0, 0, 255, 255, 100, 100
	};
	const VIDAL::Text lol4 = {
		"lol", 48, 0, 0, 255, 255, 150, 150
	};
	const VIDAL::Text lol5 = {
		"lel", 48, 0, 0, 255, 255, 200, 200
	};
	const VIDAL::Text lol6 = {
		"lol", 48, 0, 0, 255, 255, 250, 250
	};

	std::vector<VIDAL::Text> texts = {lol, lol2, lol3, lol4, lol5, lol6};
	
	VIDAL::Application::Initialize(window, texts);
	return 0;
}