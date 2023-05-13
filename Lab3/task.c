#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "goodscanfs.h"
#define NAME 40
#define EDITION 40


//struct which contains name, id, edition, year, rate and price
typedef struct Game{
    int id;
    char name[NAME];
    char edition[EDITION];
    int year;
    float price;
    int rate;
}GAME;

//it's add a struct into in an array of structs and realloc a memory for the array
void add_struct(GAME** array_of_structs, GAME struct_to_add, int size){
    *array_of_structs = realloc(*array_of_structs, sizeof(GAME)*(size+1));
    (*array_of_structs)[size] = struct_to_add;
}

enum menu {ADD = 1, SHOW_LIB, SORT, REMOVE, CHANGE, FIND};

\
][-p0o987654321`qw2]

//this function create a struct, which will be added into in an array
//it returns a struct
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
    return game;
}


//prints menu and returns nothing
void print_menu(){
    printf("1.ADD A GAME into collection\n");
    printf("2.SHOW your LIBRARY of games\n");
    printf("3.SORT all your GAMES, based on diffrent variables\n");
    printf("4.REMOVE A GAME from your library, according it's name\n");
    printf("5.CHANGE AN INFORMATION about the game, according it's name\n>");
    printf("6.FIND A GAME:\n");
    printf("7.Exit:\n>");
}

//checking variant, if it is from 1 to 7 returns one of this number, else you will write variant
//till you will choose correct one
int checking_variant(){
    int variant = goodScanfInt();
    while(variant < 1 || variant > 7){
        printf("There is no such variant as this. Try again!\n>");
        variant = goodScanfInt();
    }
    return variant;
}


// prints your current library from array with structs
void print_library(GAME* array_of_structs, int size){
    for(int i = 0; i < size; i++){
        printf("%sfrom %sThis game has an ID: %d\nPrice of this game is %.2f$\n"
               "Rating of this game is %d\nAn year of the realize is %d",array_of_structs[i].name, array_of_structs[i].edition,
               array_of_structs[i].id, array_of_structs[i].price, array_of_structs[i].rate, array_of_structs[i].year);
        printf("\n\n");
    }

}


//get string without \0 at the end till you will enter \n
int get_string(char** str){
    int size_of_str = 0;
    char c;
    *str = (char*)calloc(1,1);
    while((c = 3getchar()) != '\n'){
        (*str) = (char*)realloc(*str,size_of_str+1);
        (*str)[size_of_str] = c;
        size_of_str++;
    }
    (*str) = (char*)realloc(*str,size_of_str+1);
    (*str)[size_of_str] = '\0';
    return size_of_str;
}


// finds game which begins from symbols what you will write
void find_game(GAME* array_of_structs, int size){
    char* substring;
    printf("Input a name of game:\n>");
    get_string(&substring);
    for(int i = 0; i < size; i++){
        if(strstr(array_of_structs[i].name,substring)){
            printf("%s with ID: %d\n",array_of_structs[i].name, array_of_structs[i].id);
        }
    }
}

void find_game_by_rating_and_price(GAME* array_of_structs, int size){
    float low_price, high_price;
    int low_rate, high_rate;
    printf("Enter a lowest price\n>");
    low_price = goodScanfFloat();
    printf("Enter a highest price\n>");
    high_price = goodScanfFloat();
    printf("Enter a lowest rate\n>");
    low_rate = goodScanfInt();
    while(low_rate < 1 || low_rate > 5){
        printf("A rating must be from 1 to 5\n Write a correct rating!\n>");
        low_rate = goodScanfInt();
    }
    printf("Enter a highest rate\n>");
    high_rate = goodScanfInt();
    while(high_rate < 1 || high_rate > 5){
        printf("A rating must be from 1 to 5\n Write a correct rating!\n>");
        high_rate = goodScanfInt();
    }

    for(int i = 0; i < size; i++){
        if(array_of_structs[i].price>=low_price && array_of_structs[i].price<=high_price
        && array_of_structs[i].rate>=low_rate && array_of_structs[i].rate<=high_rate){
            printf("%sfrom %sThis game has an ID: %d\nPrice of this game is %.2f$\n"
                   "Rating of this game is %d\nAn year of the realize is %d",array_of_structs[i].name, array_of_structs[i].edition,
                   array_of_structs[i].id, array_of_structs[i].price, array_of_structs[i].rate, array_of_structs[i].year);
            printf("\n\n");
        }
    }

}


//removes a game when you enter an ID, from list which shows you
// when you find a name of a game
int remove_game_by_ID(GAME* array_of_structs, int size){
    int counter = 0;
    find_game(array_of_structs,size);
    printf("Write an ID of game which you wanna delete:\n>");
    int id = goodScanfInt();
    for(int i = 0; i < size; i++){
        if(array_of_structs[i].id == id){
            counter++;
            for(int j = i+1; j < size; j++){
                array_of_structs[j-1] = array_of_structs[j];
            }
        }
    }
    return counter;
}


//changes all information of struct except of ID
void change_information(GAME* array_of_structs, int size){
    find_game(array_of_structs, size);
    printf("Input an ID of game, which you wanna to change");
    int id = goodScanfInt();
    for(int i = 0; i < size; i++){
        if(array_of_structs[i].id == id){
            printf("Input a name of game:\n>");
            fgets(array_of_structs[i].name, NAME, stdin);
            printf("Input an edition:\n");
            fgets(array_of_structs[i].edition, EDITION, stdin);
            printf("Input a date of relize of the game:\n>");
            array_of_structs[i].year = goodScanfInt();
            printf("Input a price of the game (in dollars) :\n>");
            array_of_structs[i].price = goodScanfFloat();
            printf("Input a rating of the game (from 1 to 5):\n>");
            int tmp = goodScanfInt();
            while(tmp < 1 || tmp > 5){
                printf("A rating must be from 1 to 5\n Write a correct rating!\n>");
                tmp = goodScanfInt();
            }
            array_of_structs[i].rate = tmp;
        }
    }
}


void write_structure_in_file(GAME struct_to_add, char name[]){
    FILE* fp;
    if((fp = fopen(name,"ab")) == NULL){
        printf("Cannot open file!\n");
        exit(1);
    }
    fwrite(&struct_to_add,sizeof(GAME),1,fp);
    fclose(fp);
}

void read_file_in_buf(GAME* array, int size, char name[]){
    FILE* fp;
    if((fp = fopen(name,"rb")) == NULL){
        printf("Cannot open file!\n");
        exit(1);
    }
    fread(array,sizeof(GAME),size,fp);
    fclose(fp);
}

void rewrite_file(GAME* array, int size, char name[]){
    FILE* fp;
    if((fp = fopen(name,"wb")) == NULL){
        printf("Cannot open file!\n");
        exit(1);
    }
    fwrite(array,sizeof(GAME),size,fp);
    fclose(fp);
}

int determinate_quanity_of_structs(char name[]){
    FILE* fp;
    int size = 0;
    GAME tmp_struct;
    if((fp = fopen(name,"a+b")) == NULL){
        printf("Cannot open file!\n");
        exit(1);
    }
    fseek(fp,0,SEEK_CUR);
    while(!feof(fp)){
        fread(&tmp_struct,sizeof(GAME),1,fp);
        size++;
    }
    fclose(fp);
    return size-1;
}

void sort(GAME* array, int size){
    int i,j,step;
    GAME tmp;
    for(step = size/2;step>0;step/=2){
        for(i = step; i<size; i++){
            tmp = array[i];
            for(j = i; j >= step; j-= step){
                if(tmp.year < array[j-step].year && tmp.year != array[j-step].year){
                    array[j] = array[j-step];
                } else if(tmp.year == array[j-step].year && tmp.id < array[j-step].id){
                    array[j] = array[j-step];
                }else
                    break;
            }
            array[j] = tmp;
        }
    }
}


void menu_with_switch(int size, char name_of_file[]){
    GAME tmp_struct;
    print_menu();
    int variant = checking_variant();
    GAME* array_of_structs = calloc(size,sizeof(GAME));
    do{

        switch(variant){
            case ADD:
                tmp_struct = create_struct_to_add();
                add_struct(&array_of_structs,tmp_struct, size++);
                write_structure_in_file(tmp_struct,name_of_file);
                print_menu();
                variant = checking_variant();
                break;
            case SHOW_LIB:
                read_file_in_buf(array_of_structs, size, name_of_file);
                print_library(array_of_structs, size);
                print_menu();
                variant = checking_variant();
                break;

            case SORT:
                sort(array_of_structs, size);
                rewrite_file(array_of_structs, size, name_of_file);
                print_menu();
                variant = checking_variant();
                break;

            case REMOVE:
                size = size - remove_game_by_ID(array_of_structs, size);
                rewrite_file(array_of_structs,size,name_of_file);
                print_menu();
                variant = goodScanfInt();
                break;

            case CHANGE:
                change_information(array_of_structs, size);
                rewrite_file(array_of_structs,size,name_of_file);
                print_menu();
                variant = goodScanfInt();
                break;
            case FIND:
                read_file_in_buf(array_of_structs, size, name_of_file);
                printf("1.To find a game by name\n2.To find a game by diapason on price and rating\n>");
                int var = goodScanfInt();
                while(var < 1 || var > 2){
                    var = goodScanfInt();
                }
                if(var == 1){
                    find_game(array_of_structs, size);
                    print_menu();
                    variant = goodScanfInt();
                    break;
                }
                if (var == 2){
                    find_game_by_rating_and_price(array_of_structs, size);
                    print_menu();
                    variant = goodScanfInt();
                    break;
                }
                break;
        }
    }while(variant !=7);

}

//in switch construction don't forget to change a size of array's struct
void task(){
    int i;
    char* string;
    printf("Input a name of file (without .bin at the end)\n>");
    int size_of_string = get_string(&string);
    char name_of_file[size_of_string+5];
    for(i = 0; i < size_of_string; i++){
        name_of_file[i] = string[i];
    }
    name_of_file[i++] = '.';
    name_of_file[i++] = 'b';
    name_of_file[i++] = 'i';
    name_of_file[i++] = 'n';
    name_of_file[i++] = '\0';
    int size = determinate_quanity_of_structs(name_of_file);
    menu_with_switch(size,name_of_file);

}