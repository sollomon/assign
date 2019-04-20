#include<stdio.h>
#include<stdlib.h>
#include"list.c"


//return customer with id of parameter
struct bst *searchcustomer(int *id){
    struct bst *new = (struct bst*)malloc(sizeof (struct bst));
    while(root != NULL){
        if(&root->id == id){
            return root;
        }else{
            return NULL;
        }
        root = root->right;
    }
    return new;
}

struct bst *getcustomer(int *id){
    struct bst *new = searchcustomer(id);

    if(new == NULL){
        new->right = NULL;
        new->id = (int)id;
        if(root == NULL){
            new = root;
        }else{
            struct bst *p;
            p = root;
            while(p->right != NULL){
                p=p->right;
            }
            p->right = new;
        }
    }
    return new;
}

void preorder(struct bst *one){
    if(one!=NULL){
        printf("%d", one->id);
        preorder(one->left);
        preorder(one->right);
    }
}