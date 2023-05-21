#include <stdio.h>
#include <stdbool.h>
#include "goodinputs.h"
#include <stdlib.h>
#include "gronsfeld.h"
#include <string.h>

void print_warning(){
    printf("--------------------------------------------------------------\n");
    printf("|To use this programme you have to write an key in 'key.txt' |\n");
    printf("|It can be a different combination of digits of any length   |\n");
    printf("|Also you have to write your text into 'file.txt'            |\n");
    printf("--------------------------------------------------------------\n");

}
void print_menu(){
    printf("--------------------\n");
    printf("|1.Encrypt a file  |\n");
    printf("|2.Decrypt a file  |\n");
    printf("|3.Exit            |\n");
    printf("--------------------\n>");
}

bool verify_option(int var){
    if (var < 1 || var > 3){
        printf("You wrote an incorrect option\n Try again!\n");
        return false;
    }
    return true;
}


void menu(){
    FILE* fp;
    FILE* fk;
    int* key;
    char* string;
    if(!(fk = fopen("key.txt", "r+t"))){
        printf("Cannot open file! Try again!\n");
        exit(1);
    }
    int size = get_key_from_file(fk, &key);
    fclose(fk);
    if(!(fp = fopen("file.txt", "r+t"))){
        printf("Cannot open file! Try again!\n");
        exit(1);
    }
    print_warning();
    print_menu();
    int var = goodScanfInt();
    while(!verify_option(var))
        var = goodScanfInt();
    do{
        switch (var) {
            case 1:
                get_file_in_pointer(&string, fp);
                strcpy(string, encrypt(string, key, size));
                write_pointer_in_file(&string, fp);
                print_menu();
                var = goodScanfInt();
                while(!verify_option(var))
                    var = goodScanfInt();
                break;
            case 2:
                get_file_in_pointer(&string, fp);
                strcpy(string, decrypt(string, key, size));
                write_pointer_in_file(&string, fp);
                print_menu();
                var = goodScanfInt();
                while(!verify_option(var))
                    var = goodScanfInt();
                break;
            default:
                exit(1);
        }
    }while(var != 3);

    fclose(fp);


}



