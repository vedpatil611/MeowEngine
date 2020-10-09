#include "MeowPCH.h"
#include "Maths.h"

float Meow::Maths::toRad(float degree)
{
    return static_cast<float>(M_PI * degree / 180);
}
