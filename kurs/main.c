#include <stdio.h>

#include "func.h"
#include "square.h"

float f(float x)
{
    return f1(x);
}

int main()
{
    printf("Hello...\n");

    float xl = -5.0;
    float xr = -0.244;
    float eps = 0.001;

    float root = rootFindDiv2(xl, xr, eps, f);
    printf("root for f1 - f2: %.03f\n", root);

    printf("f1()=%.04f\n", f1(root));
    printf("f2()=%.04f\n", f3(root));

    size_t n = (xr - xl) / eps;

    float s = calcIntegralSimpson(xl, xr, n, f1);
    printf("S(f1())=%.04f\n", s);
    
    s = calcIntegralSimpson(xl, xr, n, f3);
    printf("S(f1())=%.04f\n", s);
    return 0;
}
