
#include <stdio.h>
#include <stdlib.h>

int checkingOneError(int error){
    if(error!=1){
        return error;
    }
    char temp = getchar();
    if(temp!='\n'){
        if (temp > '9' || temp < '0') {
            return -2;
        }
    }
    return 1;
}
int goodScanfInt(){
    int num = 0;
    rewind(stdin);
    while(checkingOneError(scanf("%d",&num))!=1){
        printf("You wrote an incorrect symbol. Try again!\n>");
        rewind(stdin);
    }
    return num;
}
float goodScanfFloat(){
    float num = 0;
    rewind(stdin);
    while(checkingOneError(scanf("%f",&num))!=1){
        printf("You wrote an incorrect symbol. Try again!\n>");
        rewind(stdin);
    }
    return num;
}

typedef struct info{
    int size;
    int flag;
} info_t;
//return size of string from console
info_t get_string_with_errors(char** str){
    char c;
    int size_of_str = 1;
    info_t info;
    info.flag = 1;
    *str = (char*)calloc(1,1);
    while((c = getchar())!= '\n'){
        (*str) = (char*)realloc(*str,size_of_str+1);
        (*str)[size_of_str-1] = c;
        size_of_str++;
        if( (c>='a' && c<='z') || ( c >='A' && c<='Z') || c == ' ' ){
            continue;
        }else{
            info.flag = 0;
            *str =(char*)realloc(*str,1);
            rewind(stdin);
            break;
        }
    }


    (*str)[size_of_str-1] = '\n';
    info.size = size_of_str;
    return info;
}

int get_clear_string(char** str){
    info_t info;
    while((info = get_string_with_errors(str)).flag == 0) {
        printf("You wrote an incorrect symbol! Try again!\n");
    }
    return info.size;

}