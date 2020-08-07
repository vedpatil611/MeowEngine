#pragma once

#include "vec3.h"

#include <Meow/Core.h>
#include <ostream>

namespace Meow { 
	namespace Maths {

		struct MEOW_API vec4 {
		
			// Member
			float x, y, z, w;
		
			// Constructor
			vec4();
			vec4(const vec3& vec);
			vec4(const vec3& vec, float w);
			vec4(float x, float y, float z, float w);

			// Functions
			vec4& add(const vec4& vec);
			vec4& sub(const vec4& vec);
			vec4& mul(const float& num);
			vec4& div(const float& num);

			MEOW_API friend vec4& operator+(vec4 a, const vec4& b);
			MEOW_API friend vec4& operator-(vec4 a, const vec4& b);
			MEOW_API friend vec4& operator*(vec4 a, const float& num);
			MEOW_API friend vec4& operator/(vec4 a, const float& num);

			vec4& operator+=(const vec4& vec);
			vec4& operator-=(const vec4& vec);
			vec4& operator*=(const float& num);
			vec4& operator/=(const float& num);

			bool operator==(const vec4& vec);
			bool operator!=(const vec4& vec);

			#ifdef DEBUG
			MEOW_API friend std::ostream& operator<<(std::ostream& stream, const vec4& vec);
			#endif
		};
	}
}