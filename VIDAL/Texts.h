#pragma once
#include <string>

#include "Structs.h"

namespace VIDAL
{
	namespace Text
	{
		enum Style
		{
			Regular,
			Bold,
			ItalicRegular,
			ItalicBold,
			UnderLinedRegular,
			UnderLinedBold,
			UnderLinedItalicRegular,
			UnderLinedItalicBold,
			StrikeThroughRegular,
			StrikeThroughBold,
			StrikeThroughItalicRegular,
			StrikeThroughItalicBold,
			StrikeThroughUnderLinedRegular,
			StrikeThroughUnderLinedBold,
			StrikeThroughUnderLinedItalicRegular,
			StrikeThroughUnderLinedItalicBold
		};

		class Text
		{
		public:
			std::string text;
			unsigned int size;
			float line_spacing = 1.5;
			float letter_spacing = 1;

			Style style = Regular;
			Color color;
			Color outline_color = { 0, 0, 0, 0 };
			float outline_thickness = 0;
			Pos pos;
			float angle = 0;
			Scale scale = { 1, 1 };
			Origin origin = { 0, 0 };
		};
	}
}
