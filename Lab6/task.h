//
// Created by PC on 10.04.2023.
//

#ifndef LAB6_TASK_H
#define LAB6_TASK_H
typedef struct queue{
    int x;
    struct queue* next;
}FIFO;

void add(FIFO** head, FIFO** tail, int number);
FIFO* pop(FIFO** head);
void copy_list_to_FIFO(int* array,int size_of_array, FIFO** head, FIFO** tail);
void remove_negative_numbers_from_FIFO(FIFO** head);
void print_FIFO(FIFO* head);
#endif //LAB6_TASK_H
