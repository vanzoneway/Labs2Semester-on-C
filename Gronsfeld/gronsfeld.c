#include <string.h>
#include <stdio.h>
#include <stdlib.h>





char* encrypt(char word[], const int key[], int size_of_key){
    int len_of_word = (int)strlen(word);
    int counter = 0;
    for(int i = 0; i < len_of_word; i++)
    {
        if(word[i] == ' ' || word[i] == '\0' || word[i] == '\n' || word[i] == '\377')
            continue;
        if(counter == size_of_key)
            counter = 0;
        int tmp_ascii_letter = (int)word[i] + key[counter];
        counter++;
        word[i] = (char)tmp_ascii_letter;

    }
    return word;
}
char* decrypt(char word[],const int key[], int size_of_key){
    int len_of_word = (int)strlen(word);
    int counter = 0;
    for(int i = 0; i < len_of_word; i++)
    {
        if(word[i] == ' ' || word[i] == '\0' || word[i] == '\n' || word[i] == '\377')
            continue;
        if(counter == size_of_key)
            counter = 0;
        int tmp_ascii_letter = (int)word[i] - key[counter];
        counter++;

        word[i] = (char)tmp_ascii_letter;

    }
    return word;
}

int get_file_in_pointer(char** string, FILE* fp){
    fseek(fp, 0, SEEK_SET);
    int ch, i = 0;
    (*string) = malloc(1);
    while(!feof(fp))
    {
        (*string) = (char*) realloc(*string, i+1);
        ch = fgetc(fp);
        (*string)[i++] = (char)ch;
    }
    (*string)[i] = '\0';
    return i;
}

void write_pointer_in_file(char** string, FILE* fp){
    fseek(fp, 0, SEEK_SET);
    int i = 0;
    int size = (int)strlen(*string);
    while(i < size-2)
        fputc((*string)[i++], fp);
}

int get_key_from_file(FILE* fk, int** key){
    int i = 0;
    (*key) = (int*)malloc(sizeof(int));
    while(!feof(fk)) {
        *key = (int *) realloc(*key, (i + 1) * sizeof(int));
        (*key)[i++] = (int)fgetc(fk) - 48;
    }
    return i-1;
}

