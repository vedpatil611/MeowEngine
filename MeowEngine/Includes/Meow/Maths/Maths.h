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

		float qrSqrt(float number);
	}
}