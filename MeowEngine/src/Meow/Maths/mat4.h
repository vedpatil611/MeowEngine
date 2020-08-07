#pragma once

#include <Meow/Core.h>
#include <ostream>

#include "vec3.h"
#include "vec4.h"

namespace Meow {
	namespace Maths {
		struct MEOW_API mat4 {
			// Memeber
			union 
			{
				// row + col * 4
				float elements[16];
				vec4 cols[4];
			};
		
			//Constructor
			mat4();
			mat4(float diagonal);

			//Functions
			mat4& add(const mat4& matrix);
			mat4& sub(const mat4& matrix);
			mat4& mul(const mat4& matrix);
			mat4& mul(const float& value);
			mat4& div(const float& value);

			friend mat4& operator+(mat4 matA, const mat4& matB);
			friend mat4& operator-(mat4 matA, const mat4& matB);
			friend mat4& operator*(mat4 matA, const mat4& matB);
			friend mat4& operator*(mat4 matA, const float& value);
			friend mat4& operator*(const float& value, mat4 matA);
			friend mat4& operator/(mat4 matA, const float& value);

			mat4& operator+=(const mat4& matrix);
			mat4& operator-=(const mat4& matrix);
			mat4& operator*=(const mat4& matrix);
			mat4& operator*=(const float& value);
			mat4& operator/=(const float& value);

			bool operator==(const mat4& matrix) const;
			bool operator!=(const mat4& matrix) const;

			#ifdef DEBUG
			friend std::ostream& operator<<(std::ostream& stream, const mat4& matrix);
			#endif 

			float& operator[](int i);
			float operator[](int i) const;

			static mat4 inverse(const mat4& matrix);
			static float mod(const mat4& matrix);
			static mat4 traspose(const mat4& matrix);

			static mat4 identity();

			static mat4 orthographic(const float& left, const float& right, const float& top, const float& bottom, const float& near, const float& far);
			static mat4 perspective(const float& fov, const float& aspectratio,  const float& near, const float& far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(const float& angle, const vec3& axis);
			static mat4 scaling(const vec3& scale);
		};
	}
}