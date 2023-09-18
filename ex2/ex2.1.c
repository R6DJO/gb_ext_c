#include <stdio.h>

void swap(void **a, void **b)
{
    void *tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    long int a = 12;
    long int b = 21;
    long int *pa = &a;
    long int *pb = &b;

    printf("    var: %ld %ld\n", a, b);
    printf("pointer: %ld %ld\n", *pa, *pb);
    swap((void **)&pa, (void **)&pb);

    printf("    var: %ld %ld\n", a, b);
    printf("pointer: %ld %ld\n", *pa, *pb);

    float x = 12.0;
    float y = 21.0;
    float *px = &x;
    float *py = &y;

    printf("    var: %.1f %.1f\n", x, y);
    printf("pointer: %.1f %.1f\n", *px, *py);
    swap((void **)&px, (void **)&py);

    printf("    var: %.1f %.1f\n", x, y);
    printf("pointer: %.1f %.1f\n", *px, *py);
}