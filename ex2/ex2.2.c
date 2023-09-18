#include <stdio.h>
#include <stdlib.h>

int **get_parr(int *a, size_t count)
{
    int **p = malloc(sizeof(a) * count);
    for (size_t i = 0; i < count; i++)
    {
        *(p + i) = &(*(a + i));
    }
    return p;
}

void sort_parr(int **arr, size_t count)
{
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = 0; j < count - i - 1; j++)
        {
            if (*arr[i] > *arr[i + 1])
            {
                int *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int a[] = {3, 1, 2, 5, 6, 4, 7};
    size_t count = sizeof(a) / sizeof(a[0]);
    int **pa = get_parr(a, count);
    printf("origin:\n\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%d (%p)\n", *pa[i], pa[i]);
    }
    sort_parr(pa, count);
    printf("\nsorted:\n\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%d (%p)\n", *pa[i], pa[i]);
    }
    free(pa);
}
