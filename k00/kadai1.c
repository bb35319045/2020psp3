#include <stdio.h>

int main(void){
    int *p;
    int a = 100;

    printf("a=%d\n", a);
    p = &a;
    *p = 10;
    printf("a=%d, *p=%d\n", a, *p);
    printf("adress of a = %x, value of p = %x\n", &a, p);

    return 0;
}