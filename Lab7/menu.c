#include <stdlib.h>
#include <stdio.h>
#include "allForTree.h"
#include "goodscanfs.h"

void print_menu(){
    printf("-----------------------\n");
    printf("| 1.  ADD node        |\n");
    printf("| 2.  DELETE node     |\n");
    printf("| 3.Check sorted tree |\n");
    printf("| 4.Spiral traverse   |\n");
    printf("-----------------------\n>");

}

void do_one(TREE** root){
    printf("Input a value to add:\n>");
    int x = goodScanfInt();
    *root = insert(*root, x);
    print_menu();
}

void do_two(TREE** root){
    printf("Input a value to delete:\n>");
    int x = goodScanfInt();
    *root = deleteNode(*root, x);
    print_menu();
}



void menu(){
    TREE* root = NULL;
    print_menu();
    int var = goodScanfInt();

    do {
        switch(var){
            case 1:
                do_one(&root);
                var = goodScanfInt();
                break;
            case 2:
                do_two(&root);
                var = goodScanfInt();
                break;
            case 3:
                print_tree_sorted(root);
                printf("\n");
                print_menu();
                var = goodScanfInt();
                break;
            case 4:
                print_spiral_order(root);
                printf("\n");
                print_menu();
                var = goodScanfInt();
                break;
            default:
                continue;
        }
    }while(var >= 1 && var <= 4);

    free(root);
}
