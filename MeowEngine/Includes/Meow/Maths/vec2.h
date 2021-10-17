#pragma once

#include <Meow/Core.h>

#include <ostream>

namespace Meow {
	namespace Maths {
		/// <summary>
		/// 2d vector class
		/// </summary>
		struct MEOW_API vec2
		{
			// Members
			union 
			{
				float x;
				float u;
				float width;
			};
			union
			{
				float y;
				float v;
				float height;
			};
		
			// Constructors

			/// <summary>
			/// Default construtor. Intialize all values to zero
			/// </summary>
			vec2();

			/// <summary>
			/// Constructor
			/// ### Example
			/// vec2 vec = vec2(1.0f, 3.0f);
			/// </summary>
			/// <param name="x">Initialize x with given value</param>
			/// <param name="y">Initilaize y with given value</param>
			vec2(float x, float y);

			/// <summary>
			/// Copy constructor
			/// </summary>
			vec2(const vec2& other);

			/// <summary>
			/// Move constructor
			/// </summary>
			vec2(vec2&& other);

			// Basic math functions

			/// <summary>
			/// Add given vec2 with self
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(1.0f, 4.0f);
			/// vec2 b = vec2(2.0f, -1.4f);
			/// vec2 c = a.add(b);
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <param name="vec">Other vector to add with</param>
			/// <returns>Reference to self</returns>
			vec2& add(const vec2& vec);

			/// <summary>
			/// Subtract given vec2 with self
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(1.0f, 4.0f);
			/// vec2 b = vec2(2.0f, -1.4f);
			/// vec2 c = a.sub(b);
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <param name="vec">Other vector to subtract with</param>
			/// <returns>Reference to self</returns>
			vec2& sub(const vec2& vec);

			/// <summary>
			/// Scalar multiplication of vector with given number
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(1.0f, 4.0f);
			/// vec2 b = a.mul(3.14f);
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <param name="num">Number to multiple with</param>
			/// <returns>Reference to self</returns>
			vec2& mul(const float& num);

			/// <summary>
			/// Scalar division of vector with given number
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(1.0f, 4.0f);
			/// vec2 b = a.div(3.14f);
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <param name="num">Number to divide with</param>
			/// <returns>Reference to self</returns>
			vec2& div(const float& num);

			/// <summary>
			/// Length of vector
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(4.5f, 1.3f);
			/// float length = a.length();
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <returns>Lenght of vector</returns>
			float length() const;

			/// <summary>
			/// Square of lenght of vector.
			/// 
			/// Function is often useful as calculation sqaure root is computationally heavy
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(4.5f, 1.3f);
			/// float length = a.lengthSqr();
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <returns>Length sqaured of vector</returns>
			float lengthSqr() const;

			/// <summary>
			/// Unit vector of self
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 vec = vec2(2.0f, 1.3f);
			/// vec2 unit = vec.unit();
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <returns>Normalized vector between zero and one with length = 1.0f</returns>
			vec2 unit() const;

			/// <summary>
			/// operator+ overload to add two vec2
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(4.5f, 2.5f);
			/// vec2 b = vec2(2.5f, 1.4f);
			/// vec c = a + b;
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <returns>result of addition of two vectors</returns>
			MEOW_API friend vec2 operator+(vec2 a, const vec2& b);

			/// <summary>
			/// operator- overload to add two vec2
			/// ### Example
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(4.5f, 2.5f);
			/// vec2 b = vec2(2.5f, 1.4f);
			/// vec c = a - b;
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// </summary>
			/// <returns>result of subtraction of two vectors</returns>
			MEOW_API friend vec2 operator-(vec2 a, const vec2& b);

			/// <summary>
			/// operator* overload for scalar multiplication of vector with a float
			/// </summary>
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(4.5f, 2.5f);
			/// vec b = a * 2.4;
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// <returns>Result of scalar multiplation of vector with number</returns>
			MEOW_API friend vec2 operator*(vec2 a, const float& num);

			/// <summary>
			/// operator* overload for scalar division of vector with a float
			/// </summary>
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
			/// vec2 a = vec2(4.5f, 2.5f);
			/// vec b = a / 2.0f;
			/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			/// <returns>Result of scalar division of vector with number</returns>
			MEOW_API friend vec2 operator/(vec2 a, const float& num);

			/// <summary>
			/// Assignment opertator overload
			/// </summary>
			vec2& operator=(const vec2& other);

			/// <summary>
			/// operator += overload to add vec2 to self
			/// </summary>
			vec2& operator+=(const vec2& vec);
			
			/// <summary>
			/// operator -= overload to subtract vec2 from self
			/// </summary>
			vec2& operator-=(const vec2& vec);

			/// <summary>
			/// operator *= overload to add multiply self with scalar
			/// </summary>
			vec2& operator*=(const float& num);
			
			/// <summary>
			/// operator *= overload to add divide self with scalar
			/// </summary>
			vec2& operator/=(const float& num);
			
			/// <summary>
			/// operator== overload to check if two given vec2 are equal
			/// </summary>
			bool operator==(const vec2& vec) const;
			
			/// <summary>
			/// operator!= overload to check if two given vec2 are not equal
			/// </summary>
			bool operator!=(const vec2& vec) const;

			MEOW_API friend std::ostream& operator<<(std::ostream& stream, const vec2& vec);
		};
	}
}