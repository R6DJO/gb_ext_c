# gb_ext_c

## ex1

1. Опишите функцию void array2struct(int ar[], struct pack_array *ps), которая
упаковывает массив из 32-ух элементов, содержащий только 0 и 1, в структуру
вида

struct pack_array {
    uint32_t array; // массив из 0 и 1
    uint32_t count0 : 8; // количество 0 в массиве
    uint32_t count1 : 8; // количество 1 в массиве
}
void array2struct(int ar[], struct pack_array *ps);

2. Опишите функцию void struct2array(int ar[], struct pack_array *ps), которая
распаковывает структуру в массив из 32-ух элементов, в структуру вида

3. Опишите функцию, которой на вход передаётся вещественное число в типе
float, она возвращает порядок в виде десятичного целого числа.
int extractExp(float f).

int extractExp(float f) 
{
    union {
        float f;
        struct {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;
    return fl.field.exp;
}