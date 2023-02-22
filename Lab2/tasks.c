#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "goodscanfs.h"

void input_file_data(const char* name){
    FILE* fp;
    if((fp = fopen(name,"w")) == NULL){
        printf("Cannot open this file!\n");
        exit(1);
    }
    int some_char;
    while((some_char = getchar()) != '$')
        fputc(some_char,fp);
    fclose(fp);


}

void print_file(const char* name){
    FILE* fp;
    if((fp = fopen(name,"r")) == NULL){
        printf("Cannot open this file!\n");
        exit(1);
    }
    while(!feof(fp)){
        int some_char = fgetc(fp);
        printf("%c",some_char);
    }
    fclose(fp);
}


int count_words_with_n_length(const char* name, int n){
    FILE* fp;
    if((fp = fopen(name,"r")) == NULL){
        printf("Cannot open file!\n");
        exit(1);
    }
    char a;
    int counter = 0, counter_of_words = 0;
    while(!feof(fp)){
        fread(&a,sizeof(char),1,fp);
        if(counter == n && (a == ' ' || a == '\n'))
            counter_of_words++;
        counter++;
        if(a == ' ')
            counter = 0;
    }
    fclose(fp);
    return counter_of_words;
}


void replace_word_with_spaces(const char* name, char x) {
    FILE* fp;
    fopen_s(&fp, name, "r+");

    char space = ' ';
    char a;
    fpos_t pos1, pos2;
    while (fgetc(fp) && !feof(fp)) {
        fgetpos(fp, &pos1);
        pos1--;
        fsetpos(fp, &pos1);
        a = fgetc(fp);

        if (a == x)
        {
            fsetpos(fp, &pos1);
            pos2 = pos1;
            while (fgetc(fp) != ' ' && !feof(fp))
            {
                pos1++;
            }
            fsetpos(fp, &pos2);
            while (pos2 != pos1)
            {
                fprintf(fp, "%c", space);
                fgetpos(fp, &pos2);
            }
        }
    }

    fclose(fp);

}


void AllTask(const char* name){
    printf("Write words, what will be in your file: \n");
    input_file_data(name);
    printf("Words in file: \n");
    print_file(name);
    printf("Enter something to continue: \n");
    getchar();
    fflush(stdin);
    printf("Input a n (a length of words, to count how many words with this length in file)\n>");
    int n = goodScanfInt();
    printf("Here is %d words with length %d \n", count_words_with_n_length(name,n), n);
    printf("Enter something to continue: \n");
    getchar();
    fflush(stdin);
    printf("Write a char-symbol to replace all words, which begins from this symbol by spaces \n");
    char x = getchar();
    fflush(stdin);
    replace_word_with_spaces(name, x);
    print_file(name);
}