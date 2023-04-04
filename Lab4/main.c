#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include "goodinputs.h"
#include <conio.h>

typedef union bit {
    unsigned int num;
    unsigned int bit2 : 1;
    unsigned int bit4 : 2;
    unsigned int bit8 : 3;
    unsigned int bit16 : 4;
    unsigned int bit32 : 5;
    unsigned int bit64 : 6;
    unsigned int bit128 : 7;
    unsigned int bit256 : 8;
} BIT;

enum t_bit{
        BIT2 = 2,
        BIT4 = 4,
        BIT8 = 8,
        BIT16 = 16,
        BIT32 = 32,
        BIT64 = 64,
        BIT128 = 128,
        BIT256 = 256
};

void ost_ot_del(int num){

    BIT number;
    number.num = num;
    printf("Input x:\n>");
    int x = goodScanfInt();

    switch(x){
        case BIT2:
            printf("%i %% %i = %i\n", number.num, x, number.bit2);
            break;
        case BIT4:
            printf("%i %% %i = %i\n", number.num, x, number.bit4);
            break;
        case BIT8:
            printf("%i %% %i = %i\n", number.num, x, number.bit8);
            break;
        case BIT16:
            printf("%i %% %i = %i\n", number.num, x, number.bit16);
            break;
        case BIT32:
            printf("%i %% %i = %i\n", number.num, x, number.bit32);
            break;
        case BIT64:
            printf("%i %% %i = %i\n", number.num, x, number.bit64);
            break;
        case BIT128:
            printf("%i %% %i = %i\n", number.num, x, number.bit128);
            break;
        case BIT256:
            printf("%i %% %i = %i\n", number.num, x, number.bit256);
            break;
        default:
            printf("Don't write a number more then 256 or don't write negative operands!\n");
    }
}

int main(int argc, char* argv[]) {
    ost_ot_del(atoi(argv[1]));
    menu();

    return 0;
}
