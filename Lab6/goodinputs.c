#include <stdio.h>
#include <stdlib.h>

int checkingOneError(int error){
    if(error!=1){
        return error;
    }
    char temp = getchar();
    while(temp!='\n'){
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
int str_len(const char* str){
    int i = 0;
    while(str[i]!='\n'){
        i++;
    }
    return i;
}

// checking if number a character or a decimal number. returns 1
// if a decimal number; returns 0 if a character
int if_number(char s){
    if(s>= '0' && s<='9')
        return 1;
    return 0;
}

int find_quality_of_words(char* str) {
    int i = 0, n = str_len(str), cnt = 0;
    while (str[i] != '\n') {
        if ((i == 0 && if_number(str[i]) == 1) || (if_number(str[i - 1]) == 0 && if_number(str[i]) == 1)) {
            cnt++;
        }
        i++;


    }
    return cnt;
}

int beginning_of_k_word(char* str, int k){
    int b = 0, n = str_len(str), cnt = 0, j = 0;
    while(str[j]!='\n'){
        if( (j == 0 && if_number(str[j]) == 1) || (if_number(str[j-1]) == 0 && if_number(str[j]) == 1))
            cnt++;
        if(cnt == k)
            return j;
        j++;
    }
    return -1;
}

//converts a number from k index to int
int a_to_i_from_k(const char* s, int k){
    int n, znak;
    if( (s[k-1] == '+' || s[k-1] == ' ') || k == 0){
        znak = 1;
    } else{
        znak = -1;
    }

    for (n=0;s[k]>='0' && s[k]<='9';k++){
        n = 10*n +(s[k] - '0');
    }
    return n*znak;
}

//get string from command line with error checking; return 1
//if all good, returns 0 if something went wrong
int check_and_get_string(char** str){
    int w = 0, size_of_str = 1;
    char c;
    int flag = 1;

    while((c = getchar())!= '\n' && flag){


        size_of_str = w + 1;
        *str = (char *) realloc(*str, sizeof(char) * (size_of_str));
        (*str)[w] = c;
        w++;
        if((c>'9' || c< '0') && c != ' ' && c!= '-' && c!= '+'){
            printf("BAD! Try again!\n");
            *str = (char*)realloc(*str,sizeof(char));
            rewind(stdin);
            flag = 0;
            break;
        }
    }
    (*str)[w] = '\n';
    return flag;
}

int init_array_from_keyboard(int** arr){
    int w = 0, size_of_array;

    char* str = (char*)calloc(1,sizeof(char));
    int flag = 0;
    while(flag == 0){
        flag = check_and_get_string(&str);
    }
    size_of_array = find_quality_of_words(str);
    (*arr) = (int*)calloc(size_of_array,sizeof(int));
    for(int i = 0;i<size_of_array;i++){
        (*arr)[i] = a_to_i_from_k(str, beginning_of_k_word(str,i+1));
    }
    return size_of_array;

}