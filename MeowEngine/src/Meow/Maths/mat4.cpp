#include "mat4.h"

namespace Meow {
	namespace Maths {
		mat4::mat4() {
			for (int i = 0; i < 16; ++i) elems[i] = 0;
		}
		
		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 16; ++i) elems[i] = 0;
			elems[0 + 0 * 4] = elems[1 + 1 * 4] = elems[2 + 2 * 4] = elems[3 + 3 * 4] = diagonal;
		}
		
		mat4& mat4::add(const mat4& matrix)
		{
			for (int i = 0; i < 16; ++i) 
				elems[i] += matrix.elems[i];
			return *this;
		}
		
		mat4& mat4::sub(const mat4& matrix)
		{
			for (int i = 0; i < 16; ++i)
				elems[i] -= matrix.elems[i];
			return *this;
		}

		mat4& mat4::mul(const mat4& matrix)
		{
			mat4 result;
			float sum = 0;
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					for (int k = 0; k < 4; ++k)
					{
						result.elems[i + j * 4] += elems[i + k * 4] * elems[k + j * 4];
					}
				}
			}
			return result;
		}
		
		mat4& mat4::mul(const float& value)
		{
			for (int i = 0; i < 16; ++i)
				elems[i] *= value;
			return *this;
		}
		
		mat4& mat4::div(const float& value)
		{
			for (int i = 0; i < 16; ++i)
				elems[i] /= value;
			return *this;
		}
		
		mat4& mat4::operator+=(const mat4& matrix)
		{
			return add(matrix);
		}
		
		mat4& mat4::operator-=(const mat4& matrix)
		{
			return sub(matrix);
		}

		mat4& mat4::operator*=(const mat4& matrix)
		{
			return mul(matrix);
		}
		
		mat4& mat4::operator*=(const float& value)
		{
			return mul(value);
		}
		
		mat4& mat4::operator/=(const float& value)
		{
			return div(value);
		}
		
		bool mat4::operator==(const mat4& matrix)
		{
			for (int i = 0; i < 16; ++i)
				if (elems[i] != matrix.elems[i])
					return false;
			return true;
		}

		bool mat4::operator!=(const mat4& matrix)
		{
			for (int i = 0; i < 16; ++i)
				if (elems[i] == matrix.elems[i])
					return true;
			return false;
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}
		
		mat4& operator+(mat4 matA, const mat4& matB)
		{
			return matA.add(matB);
		}
		
		mat4& operator-(mat4 matA, const mat4& matB)
		{
			return matA.sub(matB);
		}

		mat4& operator*(mat4 matA, const mat4& matB)
		{
			return matA.mul(matB);
		}
		
		mat4& operator*(mat4 matA, const float& value)
		{
			return matA.mul(value);
		}
		
		mat4& operator/(mat4 matA, const float& value)
		{
			return matA.div(value);
		}
		
		std::ostream& operator<<(std::ostream& stream, const mat4& matrix)
		{
			for (int i = 0; i < 16; ++i)
			{
				if (i & 0b100) stream << "\n";
				stream << matrix.elems[i] << " ";
			}
			return stream;
		}
	}
}
