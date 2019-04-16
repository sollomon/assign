#include<stdio.h>
#include<stdlib.h>
#include"list.h"

struct list
{
    int id;
    struct store *store;
    struct list *link;
};

struct list *root = NULL;

struct store
{
    int name;
    struct store *link;
};

