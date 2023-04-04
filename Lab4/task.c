#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "goodinputs.h"
#define NAME 40
#define EDITION 40
#define OS_LEN 10
#define SYS_REQS 40



//struct which contains name, id, edition, year, rate and price
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

// creates a struct with all info
GAME create_struct_to_add(){
    GAME game;
    printf("Input an ID of game:\n>");
    game.id = goodScanfInt();
    printf("Input a name of game:\n>");
    fgets(game.name, NAME, stdin);
    printf("Input an edition:\n");
    fgets(game.edition, EDITION, stdin);
    printf("Input a date of relize of the game:\n>");
    game.year = goodScanfInt();
    printf("Input a price of the game (in dollars) :\n>");
    game.price = goodScanfFloat();
    printf("Input a rating of the game (from 1 to 5):\n>");
    int tmp = goodScanfInt();
    while(tmp < 1 || tmp > 5){
        printf("A rating must be from 1 to 5\n Write a correct rating!\n>");
        tmp = goodScanfInt();
    }
    game.rate = tmp;
    printf("Input 1 if you wanna add info about genre and min age"
           "\nInput something else if you wanna add info about System Requirements and Operating System\n>");
    tmp = goodScanfInt();
    if ( tmp == 1){
        printf("Input a genre of the game:\n>");
        fgets(game.genre, NAME, stdin);
        printf("Input a minimal age to play thos game:\n>");
        game.min_age = goodScanfInt();
        game.info_about_add_charasteristic = 1;
    }else{
        printf("Input system requirements:\n>");
        fgets(game.sys_reqs, SYS_REQS, stdin);
        printf("Input an OS:\n>");
        fgets(game.os, OS_LEN, stdin);

    }


    return game;
}
//struct with my list of games
typedef struct list{
    GAME info_game;
    struct list* next;
}LIST;

//creates first list
LIST* create_list(GAME struct_to_add){
    LIST* tmp = (LIST*)malloc(sizeof(LIST)*1);
    tmp->info_game = struct_to_add;
    return tmp;
}

// add game in a tail of list
void add_GAME(LIST** head, GAME data){
    LIST* tmp = (LIST *) malloc(sizeof(LIST)*1);
    tmp->info_game = data;
    tmp->next = NULL;
    LIST* h = *head;
    if(h == NULL){
        *head = tmp;
    }else{
        while (h->next != NULL)
            h = h->next;
        h->next = tmp;
    }
}
//prints one all info about game (gets a pointer to struct GAME as argument
void print_game(GAME* game){
    printf("________________________________\n");
    printf("A name of the game: %s", game->name);
    printf("Edition of the game: %s", game->edition);
    printf("ID: %d\n", game->id);
    printf("Price: %f\n", game->price);
    printf("Rating: %d\n", game->rate);
    printf("Year of the realize: %d\n", game->year);
    if (game->info_about_add_charasteristic == 1){
        printf("This game is %sMinimum age: %d+\n", game->genre, game->min_age);
    }else{
        printf("OS: %s System requirments:%s", game->os, game->sys_reqs);
    }
    printf("________________________________\n");

}
//show all list of games (gets a head of list as argument)
void show_list(LIST* head){
    LIST* tmp = head;

    while (tmp != NULL) {
        print_game(&(tmp->info_game));
        tmp = tmp->next;
    }

}

int get_string(char** str){
    int size_of_str = 0;
    char c;
    *str = (char*)calloc(1,1);
    while((c = getchar()) != '\n'){
        (*str) = (char*)realloc(*str,size_of_str+1);
        (*str)[size_of_str] = c;
        size_of_str++;
    }
    (*str) = (char*)realloc(*str,size_of_str+1);
    (*str)[size_of_str] = '\0';
    return size_of_str;
}

void find_game(LIST* head){
    char* substring;
    printf("Input a name of game:\n>");
    get_string(&substring);
    LIST* h = head;
    while(h != NULL){
        if(strstr(h->info_game.name,substring)){
            printf("%swith ID: %d\n",h->info_game.name, h->info_game.id);
        }
        h = h->next;
    }
}
//a part of void find_game_by_name_or_rating_and_price(LIST* head)
int variant_for_finding(){
    printf("_____________________\n");
    printf("|1. FIND a game by name |\n");
    printf("|2. FIND a game by price|\n");
    printf("_____________________\n>");
    int variant = goodScanfInt();
    while (variant < 1 || variant >2){
        printf("You wrote an incorrect variant!\nTry again!\n>");
        variant = goodScanfInt();
    }
    return variant;
}
//a part of void find_game_by_name_or_rating_and_price(LIST* head)
void change_prices_and_ratings(float* low_price, float* high_price, int* low_rate, int* high_rate){

    printf("Enter a lowest price\n>");
    *low_price = goodScanfFloat();
    printf("Enter a highest price\n>");
    *high_price = goodScanfFloat();
    printf("Enter a lowest rate\n>");
    *low_rate = goodScanfInt();
    while(*low_rate < 1 || *low_rate > 5){
        printf("A rating must be from 1 to 5\n Write a correct rating!\n>");
        *low_rate = goodScanfInt();
    }
    printf("Enter a highest rate\n>");
    *high_rate = goodScanfInt();
    while(*high_rate < 1 || *high_rate > 5){
        printf("A rating must be from 1 to 5\n Write a correct rating!\n>");
        *high_rate = goodScanfInt();
    }
}



void find_game_by_name_or_rating_and_price(LIST* head){
    int variant = variant_for_finding();
    if (variant == 1){
        find_game(head);
    }else{
        float low_price, high_price;
        int low_rate, high_rate;
        change_prices_and_ratings(&low_price, &high_price, &low_rate, &high_rate);
        LIST* h = head;
        while(h != NULL){
            float tmp_price = h->info_game.price;
            int tmp_rate = h->info_game.rate;
            if(tmp_price>=low_price && tmp_price<=high_price
               && tmp_rate>=low_rate && tmp_rate<=high_rate){
                printf("%swith ID: %d\n",h->info_game.name, h->info_game.id);
            }
            h = h->next;
        }
    }
}

void remove_game_by_id(LIST** head){
    find_game(*head);
    printf("Input an ID:\n");
    int id = goodScanfInt();
    LIST* prev = NULL;
    LIST* curr = *head;
    while (curr != NULL) {
        if (curr->info_game.id == id) {
            if (prev == NULL) { // node to delete is the head
                *head = curr->next;
            } else {
                prev->next = curr->next;
                curr = prev->next;
                continue;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}




