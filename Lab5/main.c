#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int gets_customised(char** string){
    int len = 0;
    *string = (char*)malloc(sizeof(char));
    char c;
    while((c = getchar()) != '\n'){
        (*string)[len++] = c;
        *string = (char*)realloc(*string, len);
    }
    (*string)[len] = '\0';
    return len;

}

bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}


char* preToInfix(char* pre_exp) {
    int length = (int)strlen(pre_exp);
    char** stack = (char**)malloc(length * sizeof(char*));
    int top = -1;
    int breckets = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            char* op1 = stack[top--];
            char* op2 = stack[top--];
            char* temp = (char*)malloc((strlen(op1) + strlen(op2) + 3) * sizeof(char));
            sprintf(temp, "(%s%c%s)", op1, pre_exp[i], op2);
            stack[++top] = temp;
            free(op1);
            free(op2);
            breckets += 2;
        }

        else {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = pre_exp[i];
            operand[1] = '\0';
            stack[++top] = operand;
        }
    }
    char* infix = stack[top--];
    free(stack);
    if (strlen(infix) != strlen(pre_exp) + breckets)
        return false;
    return infix;
}


int main() {
    char* pre_exp;
    printf("Write an expression in infix form:\n>");
    gets_customised(&pre_exp);

    char* infix = preToInfix(pre_exp);
    if(infix == false){
        printf("Something went wrong! Reload a programm!\n");
        getchar();
    }else{
        printf("Infix : %s\n", infix);
        getchar();
        free(infix);
    }

    return 0;
}





