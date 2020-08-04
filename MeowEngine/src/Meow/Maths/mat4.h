#pragma once

#include <Meow/Core.h>
#include <ostream>

namespace Meow {
	namespace Maths {
		class MEOW_API mat4 {
		public:
			float mat[16];
		public:
			mat4();
			mat4(float value);

			mat4& add(const mat4& mat);
			mat4& sub(const mat4& mat);
			mat4& mul(const mat4& mat);
			mat4& mul(const float& value);
			mat4& div(const float& value);

			friend mat4& operator+(mat4 matA, const mat4& matB);
			friend mat4& operator-(mat4 matA, const mat4& matB);
			friend mat4& operator*(mat4 matA, const mat4& matB);
			friend mat4& operator*(mat4 matA, const float& value);
			friend mat4& operator/(mat4 matA, const float& value);

			mat4& operator+=(const mat4& mat);
			mat4& operator-=(const mat4& mat);
			mat4& operator*=(const mat4& mat);
			mat4& operator*=(const float& value);
			mat4& operator/=(const float& value);

			bool operator==(const mat4& mat);

			#ifdef DEBUG
			friend std::ostream operator<<(std::ostream& stream, const mat4& mat);
			#endif 
		};
	}
}