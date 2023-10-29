#include<stdio.h>
#include<math.h>

typedef float(*function)(float);

int sign(float x);
float rootFindDiv2(float xl, float xr, float eps, function f);
float calcIntegralSimpson(float xl, float xr, size_t n, function f);