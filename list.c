#include<stdio.h>
#include<stdlib.h>
#include"bst.h"



struct list
{
    int name;
    struct list *link;
};


const char *list[24] = {"one","two","three","four", "five", "six", "seven","eight","nine","ten","abc","def","ghi","jkl","mno","pqr","stu","vwx","yza","bcd","rfg","hij","klm"};

//find if store entered is in array of list
//params = name of store
int findstore(char *name){
    int i = 0;
    while (list[i])
    {
        if(strcmp(list[i],name)==0){
            return 1;
        }else{
            return 0;
        }
    }
    
}

