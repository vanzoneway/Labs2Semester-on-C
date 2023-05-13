#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 200

typedef struct stack{
    char expression[LEN];
    char operand;
    struct stack* next;
}STACK;

void push(STACK** head,char string[]){
    STACK* n = (STACK*)malloc(sizeof(STACK));
    n->next = NULL;
    strcpy(n->expression, string);
    if (*head == NULL)
        *head = n;
    else
    {
        n->next = *head;
        *head = n;
    }



}

//int isOperator(char x){
//    char operators[] ="()/%+-*" ;
//    for(int i = 0 ; i < 7; i++){
//        if (x == operators[i]){
//            return 1;
//        }
//    }
//    return 0;
//}

//void pref_to_infix(char* string[]){
//    STACK* head;
//    char operators[] ="()/%+-*" ;
//    int len = (int)strlen(*string);
//    for(int i = len - 1; i >= 0; i--){
//        if (isOperator((*string)[i]) == 1){
//
//        }else{
//
//        }
//    }
//}

