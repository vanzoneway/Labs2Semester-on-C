#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME 40
#define EDITION 40

typedef struct ring{
    int data;
    struct ring* next;
}RING;

void push_before(RING** p, int x){
    RING* temp = (RING*)malloc(sizeof(RING));
    if(*p != NULL){
        RING* p2 = *p;
        while(p2->next != *p){
            p2 = p2->next;
        }

    }
}


int main(){

    return 0;
}