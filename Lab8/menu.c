#include "task.h"
#include <stdio.h>
#include "goodinputs.h"
#include "stdbool.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void print_menu(){
    printf("----------------------\n");
    printf("|1.Load next N strings|\n");
    printf("|2.  Add string       |\n");
    printf("|3.  Remove string    |\n");
    printf("|4.  Find IP by string|\n");
    printf("|5.  Print hash_table|\n");
    printf("|6.  Exit             |\n");
    printf("----------------------\n>");

}

bool check_variant(int variant){
    if(variant > 0 && variant < 7)
        return true;
    return false;
}
void load_n_strings(FILE* fp, int n, person* hash_table[]){
    double time_spent = 0.0;
    clock_t begin = clock();
    int i = 0;
    char tmp_name[MAX_NAME];
    while(i < n && !feof(fp)){
        person* tmp = (person*)malloc(sizeof(person));
        tmp->next = NULL;
        fgets(tmp_name,MAX_NAME,fp);
        strcpy(tmp->name, tmp_name);
        char* ip = generate_random_ip();
        strcpy(tmp->ip, ip);
        hash_table_insert(hash_table, tmp);
        i++;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f \n", time_spent);
}

void insert_string(person* hash_table[]){
    char tmp_name[MAX_NAME];
    printf("Input a name to add\n>");
    scanf_s("%s",tmp_name, MAX_NAME);
    strcat(tmp_name, "\n");
    person* tmp_p = (person*)malloc(sizeof(person));
    strcpy(tmp_p->name, tmp_name);
    strcpy(tmp_p->ip, generate_random_ip());
    tmp_p->next = NULL;
    hash_table_insert(hash_table, tmp_p);
    free(tmp_p);
}


void remove_string(person* hash_table[]){
    char tmp_name[MAX_NAME];
    printf("Input a name to remove\n>");
    scanf_s("%s",tmp_name, MAX_NAME);
    strcat(tmp_name, "\n");
    if(hash_table_delete(hash_table, tmp_name) == NULL){
        printf("Nothing was deleted\n");
    }else{
        printf("Successfully!\n");
    }
}

void find_ip(person* hash_table[]){
    char tmp_name[MAX_NAME];
    printf("Input a name to find\n>");
    scanf_s("%s",tmp_name, MAX_NAME);
    strcat(tmp_name, "\n");
    person* tmp_p = hash_table_find(hash_table, tmp_name);
    if(tmp_p == NULL){
        printf("There is no such name as this one!\n");
    }else{
        printf("%s has ip: %s", tmp_p->name, tmp_p->ip);
    }

}


void menu(){
    srand(time(NULL));
    FILE* fp;
    srand(time(NULL));
    person* hash_table[TABLE_SIZE];
    init_hash_table(hash_table);
    if ((fp = fopen("english_words.txt", "rt")) == NULL){
        printf("Cannot open file!\n");
        exit(1);
    }
    print_menu();
    int var = goodScanfInt();
    while(check_variant(var) != true){
        printf("You wrote an incorrect variant! Try again!\n>");
        var = goodScanfInt();
    }

    do{
        switch(var){
            case 1:
                printf("Input how many strings do you wanna load:\n>");
                int n = goodScanfInt();
                load_n_strings(fp, n, hash_table);
                print_menu();
                var = goodScanfInt();
                while(check_variant(var) != true){
                    printf("You wrote an incorrect variant! Try again!\n>");
                    var = goodScanfInt();
                }
                break;
            case 2:
                insert_string(hash_table);
                print_menu();
                var = goodScanfInt();
                while(check_variant(var) != true){
                    printf("You wrote an incorrect variant! Try again!\n>");
                    var = goodScanfInt();
                }
                break;
            case 3:
                remove_string(hash_table);
                print_menu();
                var = goodScanfInt();
                while(check_variant(var) != true){
                    printf("You wrote an incorrect variant! Try again!\n>");
                    var = goodScanfInt();
                }

                break;
            case 4:
                find_ip(hash_table);
                print_menu();
                var = goodScanfInt();
                while(check_variant(var) != true){
                    printf("You wrote an incorrect variant! Try again!\n>");
                    var = goodScanfInt();
                }

                break;
            case 5:
                print_hash_table(hash_table);
                print_menu();
                var = goodScanfInt();
                while(check_variant(var) != true){
                    printf("You wrote an incorrect variant! Try again!\n>");
                    var = goodScanfInt();
                }
                break;
            default:
                break;
        }

    }while(var != 6);
    fclose(fp);
}
