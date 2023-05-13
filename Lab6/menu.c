#include <stdlib.h>
#include <stdio.h>
#include "goodinputs.h"
#include "task.h"


void task(){
    int* array;
    printf("Input an array:\n>");
    int size_of_array = init_array_from_keyboard(&array);
    FIFO* head = NULL;
    FIFO* tail = NULL;
    copy_list_to_FIFO(array, size_of_array, &head, &tail);
    print_FIFO(head);
    remove_negative_numbers_from_FIFO(&head);
    printf("|REMOVED|\n");
    print_FIFO(head);



}