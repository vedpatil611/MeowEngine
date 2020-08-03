#pragma once

#include <Meow/Core.h>
#include <ostream>

namespace Meow {
	namespace Maths {
		class MEOW_API vec2
		{
		public:
			float x, y;
		public:
			vec2();
			vec2(float x, float y);

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
			
			bool operator==(const vec2& vec);

			#ifdef DEBUG
			MEOW_API friend std::ostream& operator<<(std::ostream& stream, const vec2& vec);
			#endif
		};
	}
}