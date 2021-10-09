#pragma once

#include "vec2.h"

#include <Meow/Core.h>
#include <ostream>

namespace Meow {
	namespace Maths {
		struct MEOW_API vec3
		{
			// Members
			union
			{
				float x;
				float width;
				float r;
			};
			union
			{
				float y;
				float height;
				float g;
			};
			union
			{
				float z;
				float depth;
				float b;
			};
		
			// Constructors
			vec3();
			vec3(const vec2& vec);
			vec3(const vec2& vec, const float& z);
			vec3(float x, float y, float z);
			vec3(const vec3& other);
			vec3(const vec3&& other);

			// Functions
			vec3& add(const vec3& vec);
			vec3& sub(const vec3& vec);
			vec3& mul(const float& num);
			vec3& div(const float& num);

			float length() const;
			float lengthSqr() const;
			vec3 unit() const;

			MEOW_API friend vec3 operator+(vec3 a, const vec3& b);
			MEOW_API friend vec3 operator-(vec3 a, const vec3& b);
			MEOW_API friend vec3 operator*(vec3 a, const float& num);
			MEOW_API friend vec3 operator/(vec3 a, const float& num);

			vec3& operator+=(const vec3& vec);
			vec3& operator-=(const vec3& vec);
			vec3& operator*=(const float& num);
			vec3& operator/=(const float& num);

			bool operator==(const vec3& vec) const;
			bool operator!=(const vec3& vec) const;

			MEOW_API friend std::ostream& operator<<(std::ostream& stream, const vec3& vec);
		};
	}
}