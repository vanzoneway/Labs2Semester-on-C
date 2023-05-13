#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct tree{
    struct tree* left;
    struct tree* right;
    int data;
}TREE;

TREE* create_node(int item){
    TREE* temp = (TREE*)malloc(sizeof(TREE));
    temp->right = temp->left = NULL;
    temp->data = item;
    return temp;
}


TREE* insert(TREE* root, int data){
    if(root == NULL){
        root = create_node(data);
        return root;
    }

    if(root->data > data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}

void print_tree_sorted(TREE* root){
    if(root != NULL){
        print_tree_sorted(root->left);

        printf("(%d) ", root->data);

        print_tree_sorted(root->right);
    }

}


TREE* minValueNode(TREE* root) {
    TREE* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

TREE* deleteNode(TREE* root, int value){
    if(root == NULL) return root;
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }else if (value > root->data){
        root->right = deleteNode(root->right, value);
    }else{
        if(root->left == NULL){
            TREE* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            TREE* temp = root->left;
            free(root);
            return temp;
        }
        TREE* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);


    }

return root;

}

bool printLevelRightToLeft(TREE* root, int level){
    if(root == NULL)
        return false;
    if(level == 1) {
        printf("[%d] ", root->data);
        return true;
    }
    bool left = printLevelRightToLeft(root->left, level - 1);
    bool right = printLevelRightToLeft(root->right, level - 1);
    return (left || right);
}
bool printLevelLeftToRight(TREE* root, int level){
    if(root == NULL)
        return false;
    if(level == 1) {
        printf("[%d] ", root->data);
        return true;
    }
    bool right = printLevelLeftToRight(root->right, level - 1);
    bool left = printLevelLeftToRight(root->left, level - 1);
    return (left || right);
}

int find_tree_depth(TREE* root){
    if(root == NULL)
        return 0;
    int left = find_tree_depth(root->left);
    int right = find_tree_depth(root->right);
    return 1 + (left > right ? left: right);
}



void print_spiral_order(TREE* root){
    int i = 1, dp = find_tree_depth(root);
    while(i <= dp){
        printLevelRightToLeft(root, i);
        if(i != dp)
            printLevelLeftToRight(root, dp);
        i++;
        dp--;
    }
}




