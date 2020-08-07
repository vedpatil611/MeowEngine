#include "mat4.h"

#include "Maths.h"

namespace Meow {
	namespace Maths {
		mat4::mat4() {
			for (int i = 0; i < 16; ++i) elements[i] = 0;
		}
		
		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 16; ++i) elements[i] = 0;
			elements[0 + 0 * 4] = elements[1 + 1 * 4] = elements[2 + 2 * 4] = elements[3 + 3 * 4] = diagonal;
		}
		
		mat4& mat4::add(const mat4& matrix)
		{
			for (int i = 0; i < 16; ++i) 
				elements[i] += matrix[i];
			return *this;
		}
		
		mat4& mat4::sub(const mat4& matrix)
		{
			for (int i = 0; i < 16; ++i)
				elements[i] -= matrix[i];
			return *this;
		}

		mat4& mat4::mul(const mat4& matrix)
		{
			mat4 result;
			float sum = 0;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					for (int k = 0; k < 4; ++k)
						result[i + j * 4] += elements[i + k * 4] * elements[k + j * 4];

			return result;
		}
		
		mat4& mat4::mul(const float& value)
		{
			for (int i = 0; i < 16; ++i)
				elements[i] *= value;
			return *this;
		}
		
		mat4& mat4::div(const float& value)
		{
			for (int i = 0; i < 16; ++i)
				elements[i] /= value;
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
		
		bool mat4::operator==(const mat4& matrix) const
		{
			for (int i = 0; i < 16; ++i)
				if (elements[i] != matrix.elements[i])
					return false;
			return true;
		}

		bool mat4::operator!=(const mat4& matrix) const
		{
			for (int i = 0; i < 16; ++i)
				if (elements[i] == matrix.elements[i])
					return true;
			return false;
		}

		float& mat4::operator[](int i)
		{
			return elements[i];
		}

		float mat4::operator[](int i) const
		{
			return elements[i];
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		mat4 mat4::orthographic(const float& left, const float& right, const float& top, const float& bottom, const float& near, const float& far)
		{
			mat4 mat(1.0f);
			mat[0 + 0 * 4] = 2 / (right - left);
			mat[1 + 1 * 4] = 2 / (top - bottom);
			mat[2 + 2 * 4] = -2 / (far - near);
			
			mat[0 + 3 * 4] = -(right + left) / (right - left);
			mat[1 + 3 * 4] = -(top + bottom) / (top - bottom);
			mat[2 + 3 * 4] = -(far + near) / (far - near);
			return mat;
		}

		mat4 mat4::perspective(const float& fov, const float& aspectratio, const float& near, const float& far)
		{
			mat4 mat;
			mat[0 + 0 * 4] = 1 / (aspectratio * tan(toRad(fov / 2)));
			mat[1 + 1 * 4] = 1 / (tan(toRad(fov / 2)));
			mat[2 + 2 * 4] = (near + far) / (near - far);
			mat[2 + 3 * 4] = (2 * far * near) / (near - far);
			mat[3 + 2 * 4] = -1;
			return mat;
		}

		mat4 mat4::translation(const vec3& translation)
		{
			mat4 result(1.0f);
			result.cols[3] = translation;
			return result;
		}

		mat4 mat4::scaling(const vec3& scale)
		{
			mat4 result;
			result[0 + 0 * 4] = scale.x;
			result[1 + 2 * 4] = scale.y;
			result[1 + 2 * 4] = scale.z;
			return result;
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

		mat4& operator*(const float& value, mat4 matA)
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
				stream << matrix[i] << " ";
			}
			return stream;
		}
	}
}
