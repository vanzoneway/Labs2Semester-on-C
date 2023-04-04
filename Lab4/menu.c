#include <stdio.h>
#include <stdlib.h>
#include "goodinputs.h"
#include "task.h"
#include <time.h>
#include <string.h>

enum menu {ADD = 1, SHOW_LIB=2, SORT=3, REMOVE=4, FIND=5, DELENIE=6};

void print_menu(){
    printf("________________________________\n");
    printf("|1.       ADD a game           |\n");
    printf("|2. SHOW a library with games  |\n");
    printf("|3. SORT a library with games  |\n");
    printf("|4. REMOVE a game from library |\n");
    printf("|5. FIND a game from library   |\n");
    printf("|6.          Exit              |\n");
    printf("________________________________\n");
}

int checking_variant(){
    int variant = goodScanfInt();
    while(variant < 1 || variant > 6){
        printf("There is no such variant as this. Try again!\n>");
        variant = goodScanfInt();
    }
    return variant;
}

//returns a number with variant how to open a file
int mode_to_file(){
    printf("_____________________\n");
    printf("|1. Rewrite old data|\n");
    printf("|2. Load old data   |\n");
    printf("_____________________\n>");
    int variant = goodScanfInt();
    while (variant < 1 || variant >2){
        printf("You wrote an incorrect variant!\nTry again!\n>");
        variant = goodScanfInt();
    }
    return variant;
}

//creates file with variant how to open him (DOESN'T close a file!)
FILE* create_file(int variant){
    FILE* fp;
    if (variant == 1){
        if((fp = fopen("data.bin","wb+")) == NULL){
            printf("Cannot open FILE\n");
            exit(1);
        }

    }else {
        if((fp = fopen("data.bin","rb+")) == NULL){
            printf("Cannot open FILE\n");
            exit(1);
        }
    }
    return fp;
}

//writes list in binary file
void write_list_in_file(LIST* head, FILE* fp){
    fclose(fp);
    if((fp = fopen("data.bin","wb+")) == NULL){
        printf("Cannot open FILE\n");
        exit(1);
    }
    LIST* tmp = head;
    while(tmp != NULL){
        fwrite(&(tmp->info_game),sizeof(GAME),1,fp);
        tmp = tmp->next;
    }
}

//reads list from file
void read_list_from_file(LIST** head, FILE* fp){
    GAME node;
    while(!feof(fp)){
        fread(&node, sizeof(GAME), 1, fp);
        LIST* tmp = (LIST *)malloc(sizeof(LIST));
        tmp->info_game = node;
        tmp->next = NULL;
        LIST* h = *head;
        if(*head == NULL){
            *head = tmp;
        }else{
            while(h->next != NULL){
                h = h->next;
            }
            if(!feof(fp))
                h->next = tmp;
        }
    }

}

void sort_based_min_age(LIST* head){
    LIST* ptr1 = head;
    LIST* ptr2 = head;

    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            if (ptr2->info_game.min_age < ptr1->info_game.min_age && ptr1->info_game.info_about_add_charasteristic == 1
            && ptr2->info_game.info_about_add_charasteristic == 1)
            {
                int temp = ptr2->info_game.min_age;
                ptr2->info_game.min_age = ptr1->info_game.min_age;
                ptr1->info_game.min_age = temp;
            }else if(strcmp(ptr1->info_game.sys_reqs, ptr2->info_game.sys_reqs) > 0 && ptr1->info_game.info_about_add_charasteristic != 1
                                                                                       && ptr2->info_game.info_about_add_charasteristic != 1){
                int temp = ptr2->info_game.min_age;
                ptr2->info_game.min_age = ptr1->info_game.min_age;
                ptr1->info_game.min_age = temp;
            }

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1;
    }



}
FILE* create_log_file(int variant){
    FILE* fp;
    if (variant == 1){
        if((fp = fopen("logs.log","w+")) == NULL){
            printf("Cannot open FILE\n");
            exit(1);
        }

    }else {
        if((fp = fopen("logs.log","a+")) == NULL){
            printf("Cannot open FILE\n");
            exit(1);
        }
    }
    return fp;

}

void menu(){
    time_t mytime = time(NULL);
    struct tm *now = localtime(&mytime);
    LIST *list_of_games = NULL;
    int variant = mode_to_file();
    FILE* fp = create_file(variant);
    FILE* fp_log = create_log_file(variant);
    if(variant == 2)
        read_list_from_file(&list_of_games, fp);
    print_menu();
    variant = checking_variant();
    do{
        switch(variant){
            case ADD:
                add_GAME(&list_of_games,create_struct_to_add());
                print_menu();
                variant = checking_variant();
                mytime = time(NULL);
                now = localtime(&mytime);
                fprintf(fp_log, "Date: %d.%d.%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
                fprintf(fp_log, "Time: %d:%d:%d\n", now->tm_hour, now->tm_min, now->tm_sec);
                fputs("Created a structure\n", fp_log);
                break;
            case SHOW_LIB:
                show_list(list_of_games);
                print_menu();
                variant = checking_variant();
                break;

            case SORT:
                sort_based_min_age(list_of_games);
                print_menu();
                variant = checking_variant();
                mytime = time(NULL);
                now = localtime(&mytime);
                fprintf(fp_log, "Date: %d.%d.%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
                fprintf(fp_log, "Time: %d:%d:%d\n", now->tm_hour, now->tm_min, now->tm_sec);
                fputs("Structs are sorted\n", fp_log);
                break;

            case REMOVE:
                remove_game_by_id(&list_of_games);
                print_menu();
                variant = checking_variant();
                mytime = time(NULL);
                now = localtime(&mytime);
                fprintf(fp_log, "Date: %d.%d.%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
                fprintf(fp_log, "Time: %d:%d:%d\n", now->tm_hour, now->tm_min, now->tm_sec);
                fputs("One/some structs were removed\n", fp_log);
                break;

            case FIND:
                find_game_by_name_or_rating_and_price(list_of_games);
                print_menu();
                variant = checking_variant();
                break;

        }
    }while(variant !=6);
    write_list_in_file(list_of_games, fp);
    fclose(fp);
    fclose(fp_log);
}