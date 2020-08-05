#pragma once

#include <Meow/Core.h>
#include <ostream>

namespace Meow {
	namespace Maths {
		struct MEOW_API vec3
		{
			// Members
			float x, y, z;
		
			// Constructors
			vec3();
			vec3(float x, float y, float z);

			// Functions
			vec3& add(const vec3& vec);
			vec3& sub(const vec3& vec);
			vec3& mul(const float& num);
			vec3& div(const float& num);

			MEOW_API friend vec3& operator+(vec3 a, const vec3& b);
			MEOW_API friend vec3& operator-(vec3 a, const vec3& b);
			MEOW_API friend vec3& operator*(vec3 a, const float& num);
			MEOW_API friend vec3& operator/(vec3 a, const float& num);

			vec3& operator+=(const vec3& vec);
			vec3& operator-=(const vec3& vec);
			vec3& operator*=(const float& num);
			vec3& operator/=(const float& num);

			bool operator==(const vec3& vec);
			bool operator!=(const vec3& vec);

			#ifdef DEBUG
			MEOW_API friend std::ostream& operator<<(std::ostream& stream, const vec3& vec);
			#endif
		};
	}
}