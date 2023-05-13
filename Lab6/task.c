#include <stdlib.h>
#include <stdio.h>


typedef struct queue{
    int x;
    struct queue* next;
}FIFO;

void add(FIFO** head, FIFO** tail, int number){
    FIFO* tmp = (FIFO*)malloc(sizeof(FIFO));
    tmp->x = number;
    tmp->next = NULL;
    if (*head == NULL)
    {
        (*head) = tmp;
        (*tail) = tmp;
    }else
    {
        (*tail)->next = tmp;
        (*tail) = tmp;
    }
}

FIFO* pop(FIFO** head){
    if(*head == NULL)
    {
        return NULL;
    }else
    {
       *head = (*head)->next;
       return *head;
    };
}

void remove_from_middle_after(FIFO** pointer){
    FIFO* tmp_pointer = NULL;
    tmp_pointer = *pointer;
    if(tmp_pointer != NULL && tmp_pointer->next != NULL)
    {
        tmp_pointer->next = tmp_pointer->next->next;
    }
}

void copy_list_to_FIFO(int* array,int size_of_array, FIFO** head, FIFO** tail){
    for(int i = 0; i < size_of_array; i++){
        add(head, tail, array[i]);
    }
}

void remove_negative_numbers_from_FIFO(FIFO** head){
    FIFO* tmp = (FIFO*)malloc(sizeof(FIFO));
    while((*head) != NULL && (*head)->x < 0){
        pop(head);
    }
    tmp = *head;
    while((tmp) != NULL)
    {
        if(tmp->next != NULL && tmp->next->x < 0){
            while(tmp->next != NULL && tmp->next->x < 0)
                remove_from_middle_after(&tmp);
        }else if (tmp == NULL){
            break;
        }else {
            tmp = tmp->next;
        }

    }
}

void print_FIFO(FIFO* head){
    FIFO* tmp_head = NULL;
    tmp_head = head;
    while(tmp_head != NULL){
        printf("[%d] ", tmp_head->x);
        tmp_head = tmp_head->next;
    }
    printf("\n");
}
