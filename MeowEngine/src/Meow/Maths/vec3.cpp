#include "MeowPCH.h"
#include "vec3.h"

namespace Meow {
	namespace Maths {
		vec3::vec3() :x(0.0f), y(0.0f), z(0.0f) {}

		vec3::vec3(const vec2& vec) : x(vec.x), y(vec.y), z(1.0f) {}

		vec3::vec3(const vec2& vec, const float& z) : x(vec.x), y(vec.y), z(z) {}

		vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

		vec3& vec3::add(const vec3& vec)
		{
			x += vec.x;
			y += vec.y;
			z += vec.z;
			return *this;
		}

		vec3& vec3::sub(const vec3& vec)
		{
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			return *this;
		}

		vec3& vec3::mul(const float& num)
		{
			x *= num;
			y *= num;
			z *= num;
			return *this;
		}

		vec3& vec3::div(const float& num)
		{
			x /= num;
			y /= num;
			z /= num;
			return *this;
		}

		vec3& vec3::operator+=(const vec3& vec)
		{
			return add(vec);
		}

		vec3& vec3::operator-=(const vec3& vec)
		{
			return sub(vec);
		}

		vec3& vec3::operator*=(const float& num)
		{
			return mul(num);
		}

		vec3& vec3::operator/=(const float& num)
		{
			return div(num);
		}

		bool vec3::operator==(const vec3& vec) const
		{
			return x == vec.x && y == vec.y && z == vec.z;
		}

		bool vec3::operator!=(const vec3& vec) const
		{
			return x != vec.x || y != vec.y || z != vec.z;
		}

		vec3 operator+(vec3 a, const vec3& b)
		{
			return a.add(b);
		}

		vec3 operator-(vec3 a, const vec3& b)
		{
			return a.sub(b);
		}

		vec3 operator*(vec3 a, const float& num)
		{
			return a.mul(num);
		}

		vec3 operator/(vec3 a, const float& num)
		{
			return a.div(num);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vec)
		{
			stream << vec.x << " " << vec.y << " " << vec.z;
			return stream;
		}
	}
}