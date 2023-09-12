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

int extractExp(float f)
{
    union
    {
        float f;
        struct
        {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;
    return fl.field.exp - 127;
}

float extractMant(float f)
{
    union
    {
        float f;
        struct
        {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;

    float fraction = 1, div = 2;
    for (int i = 22; i >= 0; i--)
    {
        int bitValue = ((1 << i) & fl.field.mantissa) >> i;
        fraction += bitValue / div;
        div *= 2;
    }

    return fraction;
}

char extractSign(float f)
{
    union
    {
        float f;
        struct
        {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;

    return fl.field.s ? '-' : '+';
}

int main()
{
    float x = 0.4125;

    char sign = extractSign(x);
    float mant = extractMant(x);
    int exp = extractExp(x);

    printf("   x: %f\n", x);
    printf("sign: %c\n", sign);
    printf("mant: %f\n", mant);
    printf(" exp: %d 0b" BYTE_TO_BIN_PATTERN "\n", exp, BYTE_TO_BIN(exp));
    printf("   x: %c%f * 2^%d\n", sign, mant, exp);
}