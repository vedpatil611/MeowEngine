#include "MeowPCH.h"
#include "mat4.h"

#include "Maths.h"

namespace Meow {
	namespace Maths {
		mat4::mat4() {
			for (int i = 0; i < 16; ++i) elements[i] = 0;
		}
		
		mat4::mat4(const float& diagonal)
		{
			for (int i = 0; i < 16; ++i) elements[i] = 0;
			elements[0 + 0 * 4] = elements[1 + 1 * 4] = elements[2 + 2 * 4] = elements[3 + 3 * 4] = diagonal;
		}

		mat4::mat4(const mat4& mat)
		{
			memcpy(elements, mat.elements, sizeof(elements));
		}

		mat4::mat4(mat4&& mat)
		{
			memcpy(elements, mat.elements, sizeof(elements));
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

		mat4 mat4::mul(const mat4& matrix)
		{
			mat4 result;
			float sum = 0;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					for (int k = 0; k < 4; ++k)
						result[i + j * 4] += elements[i + k * 4] * matrix.elements[k + j * 4];

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

		void mat4::operator=(const mat4& mat)
		{
			memcpy(elements, mat.elements, 16 * sizeof(float));
		}

		mat4& mat4::operator+=(const mat4& matrix)
		{
			return add(matrix);
		}
		
		mat4& mat4::operator-=(const mat4& matrix)
		{
			return sub(matrix);
		}

		mat4 mat4::operator*=(const mat4& matrix)
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

		const float mat4::operator[](int i) const
		{
			return elements[i];
		}

		mat4 mat4::traspose(mat4& matrix)
		{
			mat4 result;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					result[i + j * 4] = matrix[j + i * 4];

			matrix = result;
			return matrix;
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
			mat[2 + 2 * 4] = 2 / (near - far);
			
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
			result.cols[3] += translation;
			result[15] = 1.0f;
			return result;
		}

		mat4 mat4::rotation(const float& angle, const vec3& axis)
		{
			mat4 result(1.0f);

			float r = toRad(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1 - c;

			const float &x = axis.x;
			const float &y = axis.y;
			const float &z = axis.z;

			result[0 + 0 * 4] = x * x * omc + c;
			result[1 + 0 * 4] = y * x * omc - z * s;
			result[2 + 0 * 4] = x * z * omc + y * s;
			
			result[0 + 1 * 4] = x * y*  omc + z * s;
			result[1 + 1 * 4] = y * y * omc + c;
			result[2 + 1 * 4] = y * z * omc - x * s;
			
			result[0 + 2 * 4] = x * z*  omc - y * s;
			result[1 + 2 * 4] = y * z * omc + x * s;
			result[2 + 2 * 4] = z * z * omc + c;

			return result;
		}

		mat4 mat4::scaling(const vec3& scale)
		{
			mat4 result;
			result[0 + 0 * 4] = scale.x;
			result[1 + 1 * 4] = scale.y;
			result[2 + 2 * 4] = scale.z;
			result[3 + 3 * 4] = 1.0f;
			return result;
		}

		void mat4::translate(const vec3& translation)
		{
			auto r = mat4::translation(translation);
			for (auto& i : elements)
			{
				i += r[i];
			}
		}

		mat4 operator+(mat4 matA, const mat4& matB)
		{
			return matA.add(matB);
		}
		
		mat4 operator-(mat4 matA, const mat4& matB)
		{
			return matA.sub(matB);
		}

		mat4 operator*(mat4 matA, const mat4& matB)
		{
			return matA.mul(matB);
		}
		
		mat4 operator*(mat4 matA, const float& value)
		{
			return matA.mul(value);
		}

		mat4 operator*(const float& value, mat4 matA)
		{
			return matA.mul(value);
		}
		
		mat4 operator/(mat4 matA, const float& value)
		{
			return matA.div(value);
		}
		
		std::ostream& operator<<(std::ostream& stream, const mat4& matrix)
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					stream << matrix[i + j * 4] << " ";
				}
				stream << "\n";
				//if (!(i & 0b100)) stream << "\n"1;
				//stream << matrix[i] << " ";
			}
			return stream;
		}
	}
}
