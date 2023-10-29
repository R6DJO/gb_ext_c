#include "square.h"

float rootFindDiv2(float xl, float xr, float eps, function f)
{
  int stepcount = 0;
  float xm;
  while (fabs(xr - xl) > eps)
  {
    stepcount++;
    xm = (xl + xr) / 2;
    if (f(xr) == 0)
    {
      printf("Find root for %d steps\n", stepcount);
      return xr;
    }
    if (f(xl) == 0)
    {
      printf("Find root for %d steps\n", stepcount);
      return xl;
    }

    if (sign(f(xl)) != sign(f(xm)))
      xr = xm;
    else
      xl = xm;
  }
  printf("Find root for %d steps\n", stepcount);
  return (xl + xr) / 2.0;
}

int sign(float x)
{
  if (x >= 0)
  {
    return 1;
  }
  return 0;
}

float calcIntegralSimpson(float xl, float xr, size_t n, function f)
{
  float sum = 0;
  float h = (xr - xl) / n;
  for (float x = xl + h; x < xr - h; x += h)
  {
    sum += h / 6.0 * (f(x) + 4.0 * f(0.5 * (x + x + h)) + f(x + h));
  }
  return sum;
}
