#include "stdlib.h"
#include "stdio.h"
void clear_static_array(char* array, int size){
    for(int i = 0; i < size; i++){
        array[i] = '\0';
    }
}

void parser(char* name){
    char mail[100];
    clear_static_array(mail,100);
    int i;
    char symbol, tmp;
    FILE* fp;
    if ((fp = fopen(name, "r")) == NULL){
        printf("Cannot open the file\n");
        exit(1);
    }
    while(!feof(fp)){
        fread(&symbol,sizeof(char),1,fp);
        if(symbol == '{'){
            fread(&tmp,sizeof(char),1,fp);
            i = 0;
            while(tmp != '}' && i < 100){
                mail[i] = tmp;
                i++;
                fread(&tmp,sizeof(char),1,fp);

            }
            puts(mail);
            clear_static_array(mail,100);
        }
    }

    fclose(fp);
};