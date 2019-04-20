#ifndef BST_H
#define BST_H


//define bst which holds customer
//bst will be ordered using bst algorithm
struct bst;
typedef struct bst *bst;

//structure of a bst (customer)
struct bst
{
    int id;
    struct list *list;
    struct bst *right;
    struct left *left;
};


#endif