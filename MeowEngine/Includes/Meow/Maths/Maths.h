#pragma once

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

#include "mat4.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Meow {
	namespace Maths {
		float toRad(float degree);

		/// <summary>
		///  Fast inverse sqaure root function
		/// </summary>
		/// <param name="float number"></param>
		/// <returns>float</returns>
		float qrSqrt(float number);
	}
}