#pragma once

#include <Meow/Core.h>

#include <ostream>

namespace Meow {
	namespace Maths {
		struct MEOW_API vec2
		{
			// Members
			union 
			{
				float x;
				float u;
				float width;
			};
			union
			{
				float y;
				float v;
				float height;
			};
		
			// Constructor
			vec2();
			vec2(float x, float y);

			// Functions
			vec2& add(const vec2& vec);
			vec2& sub(const vec2& vec);
			vec2& mul(const float& num);
			vec2& div(const float& num);

			float length() const;
			float lengthSqr() const;
			vec2 unit() const;

			MEOW_API friend vec2 operator+(vec2 a, const vec2& b);
			MEOW_API friend vec2 operator-(vec2 a, const vec2& b);
			MEOW_API friend vec2 operator*(vec2 a, const float& num);
			MEOW_API friend vec2 operator/(vec2 a, const float& num);

			vec2& operator+=(const vec2& vec);
			vec2& operator-=(const vec2& vec);
			vec2& operator*=(const float& num);
			vec2& operator/=(const float& num);
			
			bool operator==(const vec2& vec) const;
			bool operator!=(const vec2& vec) const;

			MEOW_API friend std::ostream& operator<<(std::ostream& stream, const vec2& vec);
		};
	}
}