#include "MeowPCH.h"
#include <Meow/Maths/Maths.h>
#include <Meow/Maths/vec2.h>

namespace Meow {
	namespace Maths {
		vec2::vec2() :x(0.0f), y(0.0f) {}

		vec2::vec2(float x, float y) :x(x), y(y) {}

		vec2::vec2(const vec2& other)
			:x(other.x), y(other.y) {}

		vec2::vec2(vec2&& other)
			:x(other.x), y(other.y) {}
		
		vec2& vec2::add(const vec2& vec)
		{
			x += vec.x;
			y += vec.y;
			return *this;
		}
		
		vec2& vec2::sub(const vec2& vec)
		{
			x -= vec.x;
			y -= vec.y;
			return *this;
		}
		
		vec2& vec2::mul(const float& num)
		{
			x *= num;
			y *= num;
			return *this;
		}
		
		vec2& vec2::div(const float& num)
		{
			x /= num;
			y /= num;
			return *this;
		}

		float vec2::length() const
		{
			return sqrt(x * x + y * y);
		}

		float vec2::lengthSqr() const
		{
			return x * x + y * y;
		}

		vec2 vec2::unit() const
		{
			return vec2(*this) * Maths::qrSqrt(x * x + y * y);
		}
		
		vec2& vec2::operator=(const vec2& other)
		{
			return *this;
		}

		vec2& vec2::operator+=(const vec2& vec)
		{
			return add(vec);
		}
		
		vec2& vec2::operator-=(const vec2& vec)
		{
			return sub(vec);
		}

		vec2& vec2::operator*=(const float& num)
		{
			return mul(num);
		}

		vec2& vec2::operator/=(const float& num)
		{
			return div(num);
		}
		
		bool vec2::operator==(const vec2& vec) const
		{
			return x == vec.x && y == vec.y;
		}

		bool vec2::operator!=(const vec2& vec) const
		{
			return x != vec.x || y != vec.y;
		}

		vec2 operator+(vec2 a, const vec2& b)
		{
			return a.add(b);
		}
		
		vec2 operator-(vec2 a, const vec2& b)
		{
			return a.sub(b);
		}
		
		vec2 operator*(vec2 a, const float& num)
		{
			return a.mul(num);
		}

		vec2 operator/(vec2 a, const float& num)
		{
			return a.div(num);
		}
		
		std::ostream& operator<<(std::ostream& stream, const vec2& vec)
		{
			stream << vec.x << " " << vec.y;
			return stream;
		}
	}
}