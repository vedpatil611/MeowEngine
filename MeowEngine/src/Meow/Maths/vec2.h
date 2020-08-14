#pragma once

#include <Meow/Core.h>
#include <Meow/Log.h>

#include <ostream>

namespace Meow {
	namespace Maths {
		struct MEOW_API vec2
		{
			// Members
			float x, y;
		
			// Constructor
			vec2();
			vec2(float x, float y);

			// Functions
			vec2& add(const vec2& vec);
			vec2& sub(const vec2& vec);
			vec2& mul(const float& num);
			vec2& div(const float& num);

			MEOW_API friend vec2& operator+(vec2 a, const vec2& b);
			MEOW_API friend vec2& operator-(vec2 a, const vec2& b);
			MEOW_API friend vec2& operator*(vec2 a, const float& num);
			MEOW_API friend vec2& operator/(vec2 a, const float& num);

			vec2& operator+=(const vec2& vec);
			vec2& operator-=(const vec2& vec);
			vec2& operator*=(const float& num);
			vec2& operator/=(const float& num);
			
			bool operator==(const vec2& vec) const;
			bool operator!=(const vec2& vec) const;

			#ifdef DEBUG
			MEOW_API friend std::ostream& operator<<(std::ostream& stream, const vec2& vec);
			#endif
		};
	}
}