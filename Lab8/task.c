#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "goodinputs.h"

#define TABLE_SIZE 100
#define IP_SIZE 22
#define MAX_NAME 30

//generates random ip + port and return memory for char with 22 elements
//you should do a static array and use memcpy to use this ip+port
char* generate_random_ip() {

    char* ip = (char*) malloc(sizeof(char) * 22);
    int a = rand() % 256;
    int b = rand() % 256;
    int c = rand() % 256;
    int d = rand() % 256;
    int e = rand() % 65535;
    sprintf(ip, "%d.%d.%d.%d:%d", a, b, c, d, e);
    return ip;
}
//структура-односвязный список с инфой нужной нам
typedef struct person{
    char name[MAX_NAME];
    char ip[IP_SIZE];
    struct person* next;

}person;


//иницилизируем наш массив указателей на структуру person нулями
void init_hash_table(person* hash_table[]){
    for(int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}


//печатает хэш таблицу( в лабе не нужно, но удобнее дебажить )
void print_hash_table(person* hash_table[]){
    person* p = NULL;
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        }else{
            p = hash_table[i];
            printf("\t%i\t", i);
            while(p != NULL){
                printf("%s : %s ===>  ", p->name, p->ip);
                p = p->next;
            }
            printf("\n");

        }
    }
}
//функции хэша через ASCII и процент от размера таблицы
unsigned int hash(char* name){
    int length =  strlen(name);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}


//получить последний узел в списке
person* getLast(person* head) {
    if (head == NULL)
        return NULL;
    while (head->next)
        head = head->next;
    return head;
}
//запушить в конец односвзяного списка( p.s без проверки на null )
void push_back(person* head, person* what_to_add){
    person *last = getLast(head);
    person *tmp = (person*) malloc(sizeof(person));
    strcpy(tmp->name, what_to_add->name);
    strcpy(tmp->ip,what_to_add->ip);
    tmp->next = NULL;
    last->next = tmp;
}

//записать элемент в хэш-таблицу
bool hash_table_insert(person* hash_table[], person* p){
    if(p == NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL)
    {
        push_back(hash_table[index], p);
    }
    else
        hash_table[index] = p;
    return true;
}


//найти нужную структуру по имени, или вернет
//NULL если такого имени нет
person* hash_table_find(person* hash_table[],char* name){
    int index = hash(name);
    if(hash_table[index] == NULL)
        return NULL;

    person* tmp = hash_table[index]->next;
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, MAX_NAME) == 0)
    {
        return hash_table[index];
    }
    else if(hash_table[index] != NULL && strncmp(hash_table[index]->name, name, MAX_NAME) != 0)
    {
        while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0 )
            tmp = tmp->next;
        return tmp;
    }
    return NULL;
}

//удаляет элемент их хэш-таблицы по имени
person* hash_table_delete(person* hash_table[], char* name){
    int index = hash(name);
    if (hash_table[index] == NULL){
        return NULL;
    }
    person* tmp = hash_table[index];
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, MAX_NAME) == 0){
        tmp = hash_table[index];
        hash_table[index] = hash_table[index]->next;
        return tmp;
    }else if(hash_table[index] != NULL && strncmp(hash_table[index]->name, name, MAX_NAME) != 0){
        while(tmp->next != NULL && strncmp(tmp->next->name, name, MAX_NAME) != 0 )
            tmp = tmp->next;


        if(tmp->next != NULL && strncmp(tmp->next->name, name, MAX_NAME) == 0 ){
            person* tmp_two = tmp->next;
            tmp->next = tmp->next->next;
            return tmp_two;
        }
    }
    return NULL;
}




