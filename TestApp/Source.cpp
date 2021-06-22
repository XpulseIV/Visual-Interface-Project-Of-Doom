#include "VIDAL.h"
#include <vector>

int main()
{
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "LOL";
	
	VIDAL::Application::Initialize(window, std::vector<VIDAL::Text> { });
	return 0;
}