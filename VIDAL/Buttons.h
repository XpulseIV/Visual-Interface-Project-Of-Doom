#pragma once
#include "Structs.h"
#include "Buttons.h"
#include "VIDAL.h"

namespace VIDAL
{
	class Button
	{
	public:
		sf::RectangleShape shape;
		void (*on_click) (void*);
		void (*on_held) (void*);
		void (*on_hover) (void*);
		void Draw(sf::RenderWindow* window) const;

		bool is_clicked, is_hovered;
	};
}
