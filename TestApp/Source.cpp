#include "VIDAL.h"

int main()
{
	VIDAL::Window window;
	window.width = 800;
	window.height = 600;
	window.title = "LOL";

	VIDAL::Application application;
	application.window = window;
	
	VIDAL::Application::Initialize(application);
	return 0;
}