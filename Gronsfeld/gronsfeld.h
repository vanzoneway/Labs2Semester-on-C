//
// Created by PC on 20.05.2023.
//

#ifndef GRONSFELD_GRONSFELD_H
#define GRONSFELD_GRONSFELD_H
#include <stdbool.h>
char* decrypt(char word[],const int key[], int size_of_key);
char* encrypt(char word[],const int key[], int size_of_key);
void write_pointer_in_file(char** string, FILE* fp);
int get_file_in_pointer(char** string, FILE* fp);
int get_key_from_file(FILE* fk, int** key);
#endif //GRONSFELD_GRONSFELD_H
