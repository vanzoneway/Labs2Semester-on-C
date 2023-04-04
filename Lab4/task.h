//
// Created by PC on 19.03.2023.
//

#ifndef LAB4_TASK_H
#define LAB4_TASK_H

#endif //LAB4_TASK_H
#define NAME 40
#define EDITION 40
#define OS_LEN 10
#define SYS_REQS 40

typedef struct Game{
    int id;
    char name[NAME];
    char edition[EDITION];
    int year;
    float price;
    int rate;
    union{
        struct{
            char genre[NAME];
            int min_age;
        };
        struct {
            char sys_reqs[SYS_REQS];
            char os[OS_LEN];
        };
    };
    int info_about_add_charasteristic;

}GAME;

typedef struct list{
    GAME info_game;
    struct list* next;
}LIST;

GAME create_struct_to_add();

LIST* create_list(GAME struct_to_add);

void add_GAME(LIST** head, GAME data);

void show_list(LIST* head);

void find_game_by_name_or_rating_and_price(LIST* head);

void remove_game_by_id(LIST** head);
