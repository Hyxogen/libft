#ifndef FT_MATH_H
#define FT_MATH_H

#include <math.h> // for __STDC_IEC_559__

#ifndef __STDC_IEC_559__
#error "Only IEEE 754 floating point is supported"
#endif
#define ft_isnan(arg) ((arg) != (arg))
#define ft_signbit(arg)                     \
	_Generic((arg),                     \
		double: ft___signbit,       \
		float: ft___signbitf)(arg)

int ft___signbit(double x);
int ft___signbitf(float x);

float ft_fminf(float x, float y);
float ft_fmaxf(float x, float y);

#endif
