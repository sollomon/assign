#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include"bst.c"
#include"bst.h"
#include"list.h"



//Loyalty programs are saved as list since they are an array and defined in list files

//Customers are save as bst and defined in bst files 



//Array of list
//Number of list is not expected to grow higher than a couple dozens

struct bst *root = NULL;
//Function declaration
void subscribe(void);
void unsubscribe(void);
void printsummary(void);
void printsubscriptions(void);
void printsubscribers(void);
void printarr(void);
int findstore(char *name);


//print array of list
void printarr()
{
    for(int i = 0;i<24;i++)
    {
        printf("%s-->\n",list[i]);
    }
}

//return number of customers of list of given name
void subscribers(char *name){
    int i = 0;
    int ctr = 1;
    struct bst *temp = root;
    while(temp->right != NULL){
        while (temp->list->link != NULL){
            if(strcmp(temp->list->name,name)==0){
                i++;
            }else
            {
                ctr++;

            }
            temp->list = temp->list->link;
        }
        temp = temp->right;
    }
    printf("%d",i);
    preorder(temp);
}

//Prompt customer for name odf list to return number of customers
void printsubscribers(){

    char name[100];
    printf("Enter name of program\n");
    fgets(name,100, stdin);
    subscribers(name);
}


//delete program from bst of programs in customer structure
void unsubscribe(){
    int id;
    char name[100];
    printf("Enter id:\n");
    scanf("%d",id);
    printf("Enter name of program'\n");
    fgets(name,100, stdin);

    struct bst *cust = searchcustomer(id);
      /* See if we are at end of bst. */
  if (cust == NULL)
    return NULL;

  /*
   * Check to see if current node is one
   * to be deleted.
   */
  if (cust->list->name == name) {
    struct bst  *tempNextP;

    /* Save the next pointer in the node. */
    tempNextP = cust->list->link;

    /* Deallocate the node. */
    free(cust);

    /*
     * Return the NEW pointer to where we
     * were called from.  I.e., the pointer
     * the previous call will use to "skip
     * over" the removed node.
     */
    return tempNextP;
  }

  /*
   * -------------- RECURSION-------------------
   * Check the rest of the bst, fixing the next
   * pointer in case the next node is the one
   * removed.
   */
  cust->list->link = ListDelete(cust->list->link, cust->list);


  /*
   * Return the pointer to where we were called
   * from.  Since we did not remove this node it
   * will be the same.
   */
  return cust;
}

//print subscription of customer
void printsubscriptions(){
    int id;
    printf("enter id\n");
    scanf("%d",id);
    struct bst *cust = searchcustomer(id);
    for(int i = 0;i<24; i++){
        printf("$s-->\n",cust->list[i]);
    }
}

//Creates  customer if ther is no customer
//adds a list to the bst of list in customers structure
void subscribe(){
    struct bst *new; 
    struct list *first = (struct list*)malloc(sizeof(struct list));

    struct list *roots = NULL;
    int id;
    char name[100];
    printf("Enter your id:\n");
    scanf("%d",id);
    new = getcustomer(id);
    printf("Enter name of program:\n");
    fgets(name,100, stdin);
    int found  = findstore(name);
    if(found == 1){
        new->list->link = NULL;
        new->list->name = name;
        if(roots == NULL){
            roots = new->list;
        }else{
            struct bst *p;
            p = roots;
            while(p->right != NULL){
                p=p->right;
            }
            p->right = new;
        }
    }else{
        printf("Store not found enter 3 to see list\n\n");
    }

}

int main(){
    int choice;
    while (1)
    {
        printf("1.Subscribe\n");
        printf("2.Unsubscribe\n");
        printf("3.Print Summary\n");
        printf("4.Print Subscribers\n");
        printf("5.Print Subscriptions\n");
        printf("0.Quit\n");
        printf("Enter your choice from above : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            subscribe();
            break;

        case 2:
            unsubscribe();
            break;

        case 3:
            printarr();
            break;

        case 5:
            printsubscriptions();
            break;

        case 4:
            printsubscribers();
            break;
        
        case 0:exit(1);

        default:
            printf("Invalid Choice");
        }
    }
    
}
