#include <stdbool.h>

#ifndef LAB7_ALLFORTREE_H
#define LAB7_ALLFORTREE_H
typedef struct tree{
    struct tree* left;
    struct tree* right;
    int data;
}TREE;

TREE* create_node(int item);
TREE* insert(TREE* root, int data);
void print_tree_sorted(TREE* root);
TREE* deleteNode(TREE* root, int value);
void print_spiral_order(TREE* root);


#endif //LAB7_ALLFORTREE_H
