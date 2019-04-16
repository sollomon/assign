#include<stdio.h>
#include<stdlib.h>
#include"list.c"

const char *stores[24] = {"one","two","three","four"};


int findstore(char *name){
    int i = 0;
    while (stores[i])
    {
        if(strcmp(stores[i],name)==0){
            return 1;
        }else{
            return 0;
        }
    }
    
}