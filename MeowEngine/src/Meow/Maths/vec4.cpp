#include "MeowPCH.h"
#include "vec4.h"

namespace Meow {
	namespace Maths {
		vec4::vec4() :x(0), y(0), z(0), w(0) {}

		vec4::vec4(const vec2& vec) : x(vec.x), y(vec.y), z(0), w(0) {}

		vec4::vec4(const vec2& vec, const float& z, const float& w) : x(vec.x), y(vec.y), z(z), w(w) {}

		vec4::vec4(const vec2& vecA, const vec2 vecB) : x(vecA.x), y(vecA.y), z(vecB.x), w(vecB.y) {}

		vec4::vec4(const vec3& vec) : x(vec.x), y(vec.y), z(vec.z), w(0) {}

		vec4::vec4(const vec3& vec, float w) : x(vec.x), y(vec.y), z(vec.z), w(w) {}
		
		vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		
		vec4& vec4::add(const vec4& vec)
		{
			x += vec.x;
			y += vec.y;
			z += vec.z;
			w += vec.w;
			return *this;
		}

		vec4& vec4::sub(const vec4& vec)
		{
			z -= vec.z;
			x -= vec.x;
			y -= vec.y;
			w -= vec.w;
			return *this;
		}

		vec4& vec4::mul(const float& num)
		{
			x *= num;
			y *= num;
			z *= num;
			w *= num;
			return *this;
		}

		vec4& vec4::div(const float& num)
		{
			x /= num;
			y /= num;
			z /= num;
			w /= num;
			return *this;
		}

		vec4& vec4::operator+=(const vec4& vec)
		{
			return add(vec);
		}
		
		vec4& vec4::operator-=(const vec4& vec)
		{
			return sub(vec);
		}

		vec4& vec4::operator*=(const float& num)
		{
			return mul(num);
		}

		vec4& vec4::operator/=(const float& num)
		{
			return div(num);
		}

		bool vec4::operator==(const vec4& vec) const
		{
			return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
		}

		bool vec4::operator!=(const vec4& vec) const
		{
			return x != vec.x || y != vec.y || z != vec.z || w != vec.w;
		}
		
		vec4& operator+(vec4 a, const vec4& b)
		{
			return a.add(b);
		}
		
		vec4& operator-(vec4 a, const vec4& b)
		{
			return a.sub(b);
		}
		
		vec4& operator*(vec4 a, const float& num)
		{
			return a.mul(num);
		}

		vec4& operator/(vec4 a, const float& num)
		{
			return a.div(num);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vec)
		{
			stream << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
			return stream;
		}
	}
}