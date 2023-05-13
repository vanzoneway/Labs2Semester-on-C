

#ifndef LAB8_TASK_H
#define LAB8_TASK_H

#include <stdbool.h>

#define TABLE_SIZE 100
#define IP_SIZE 22
#define MAX_NAME 30
typedef struct person{
    char name[MAX_NAME];
    char ip[IP_SIZE];
    struct person* next;

}person;
char* generate_random_ip();
void print_hash_table(person* hash_table[]);
void init_hash_table(person* hash_table[]);
person* hash_table_find(person* hash_table[],char* name);
person* hash_table_delete(person* hash_table[], char* name);
bool hash_table_insert(person* hash_table[], person* p);
unsigned int hash(char* name);
#endif //LAB8_TASK_H
