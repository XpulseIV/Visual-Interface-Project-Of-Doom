#pragma once
#include "Structs.h"
#include "Shapes.h"
#include "Texts.h"
#include "Buttons.h"

namespace VIDAL
{
	namespace Button
	{
		class Button
		{
		public:
			Shape::Rectangle shape;
			void (*on_click) ();
		private:
			void OnClick();
		};
	}
}
