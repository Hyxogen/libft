#include <ft/math.h>
#include <stdint.h>

int ft___signbit(double x)
{
	union {
		double d;
		uint64_t i;
	} y = { x };
	return y.i >> 63;
}

int ft___signbitf(float x)
{
	union {
		float f;
		uint32_t i;
	} y = { x };
	return y.i >> 31;
}

float ft_fminf(float x, float y)
{
	if (ft_isnan(x))
		return y;
	if (ft_isnan(y))
		return x;
	if (ft_signbit(x) != ft_signbit(y))
		return ft_signbit(x) ? x : y;
	return x < y ? x : y;
}
