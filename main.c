#include <stdio.h>
#include <inttypes.h>

struct point{
    int x:16;
    int y:16;
};

void plus(int* a){
    *a+=1;
}




void print_data(struct point* pt){
    printf("x = %d\n", pt->x);
    printf("y = %d\n", pt->y);

}

int main() {
/*//    int8_t a = -13;                                    // 00111000
//    int8_t b = 10;                                   // 00001010
//    int8_t resultand = a & b;                                         // 00000010
//    int8_t resultor = a | b;                                          // 00001111
//    int8_t resultxor = a ^ b;                                         // 00001101      13
//    int8_t resultinva = ~a;                           // 11111000          248 - 256 = -8
//    int8_t resultinvb = ~b;                           // 11111000          248 - 256 = -8

//    printf("%d\n", resultinva);
//    printf("%x\n", resultinva);          //
//
//    printf("%d\n", resultinvb);          // 00000000 00000000 00000000 00001010
//    printf("%x\n", resultinvb);          // 11111111 11111111 11111111 11110101   245 - 256 = -11
//    printf("%x\n", a);
//    int8_t shift_a = a >> 2;               // 11111001 ->    11111110   254 - 256 = -2
//    printf("%d\n", shift_a);        // 00000111 ->    00000001

//    int8_t result = !(a^b);
//    printf("%d\n", result);
//

//    int a = 8;              // 11111111 11111111 11111111 00001000
//    printf("%x\n", a);
//    int sign = 0;
//
//    sign = a >> 31;          // 11111111 11111111 11111111 11111111
//    printf("sign = %x\n", sign);
//    a = a^sign;              // 00000000 00000000 00000000 11111000           248
//    printf("a = %x\n", a);                                              // 255-248 = 7
//                             // 00000000 00000000 00000000 00000000
//    a = a + (sign & 0x1);
//
//    printf("%x\n", a);
//    printf("%d\n", a);
//
//    int b = -11;
//    int8_t inv_b = ~b + 1;
//    printf("%d\n", inv_b);


//    printf("a = %d\n", a);                  // 00000000 00000000 00000000 00000111
//    printf("size a = %d\n", sizeof(a));     // 11111111 11111111 11111111 11111000
//
//
//
//    float c = 123.1f;
//    printf("c = %f\n", c);*/

//    struct point a = {35,68};                     // 100011    1000100
//    printf("size a = %d\n", sizeof(a));
//    printf("x = %d\n", a.x);
//    printf("y = %d\n", a.y);
//    printf("%p", a);

//    int i = 123;
//    int* p_i = &i;
//    printf("pointer = %p\n", p_i);
//
//    printf("value = %d\n", *p_i);
//    plus(p_i);
//    printf("value = %d\n", *p_i);
//
//    struct point b = {39, -5};
//    struct point* p_b = &b;
//
//    print_data(p_b);


    int i = 123;
    int* p_i = &i;

    void (*p_function)(int*);

    p_function = plus;
    p_function(p_i);
    printf("value = %d\n", *p_i);



    return 0;
}
