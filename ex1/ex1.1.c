#include <stdio.h>
#include <inttypes.h>

#define BYTE_TO_BIN_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BIN(byte)            \
    ((byte) & 0x80 ? '1' : '0'),     \
        ((byte) & 0x40 ? '1' : '0'), \
        ((byte) & 0x20 ? '1' : '0'), \
        ((byte) & 0x10 ? '1' : '0'), \
        ((byte) & 0x08 ? '1' : '0'), \
        ((byte) & 0x04 ? '1' : '0'), \
        ((byte) & 0x02 ? '1' : '0'), \
        ((byte) & 0x01 ? '1' : '0')

struct pack_array
{
    uint32_t array;      // массив из 0 и 1
    uint32_t count0 : 8; // количество 0 в массиве
    uint32_t count1 : 8; // количество 1 в массиве
};

void array2struct(int ar[], struct pack_array *ps);

int main()
{
    int ar[32] = {0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    struct pack_array pa = {0, 0, 0};
    struct pack_array *ps = &pa;
    array2struct(ar, ps);
    printf("count 1:%" PRIu32 " count 0:%" PRIu32 "\n", ps->count1, ps->count0);
    printf("ar: 0x%08x\n", ps->array);
    printf("ar: " BYTE_TO_BIN_PATTERN " " BYTE_TO_BIN_PATTERN
           " " BYTE_TO_BIN_PATTERN " " BYTE_TO_BIN_PATTERN "\n",
           BYTE_TO_BIN((ps->array >> 24) & 255), BYTE_TO_BIN((ps->array >> 16) & 255),
           BYTE_TO_BIN((ps->array >> 8) & 255), BYTE_TO_BIN(ps->array & 255));
    return 0;
}

void array2struct(int ar[], struct pack_array *ps)
{
    ps->array = 0;
    ps->count0 = 0;
    ps->count1 = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (ar[i])
        {
            ps->count1++;
        }
        else
        {
            ps->count0++;
        }
        ps->array = (ps->array << 1) + ar[i];
    }
}