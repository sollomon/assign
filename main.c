#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include"list.c"
#include"list.h"
#include"bst.c"


//Array of store
//Number of stores is not expected to grow higher than a couple dozens
const char *stores[24] = {"one","two","three","four", "five", "six", "seven","eight","nine","ten","abc","def","ghi","jkl","mno","pqr","stu","vwx","yza","bcd","rfg","hij","klm"};

struct list *root = NULL;
//Function declaration
void subscribe(void);
void unsubscribe(void);
void printsummary(void);
void printsubscriptions(void);
void printsubscribers(void);
void printarr(void);
int findstore(char *name);

struct list *getcustomer(int *id){
    struct list *new = searchcustomer(id);

    if(new == NULL){
        new->link = NULL;
        new->id = (int)id;
        if(root == NULL){
            new = root;
        }else{
            struct list *p;
            p = root;
            while(p->link != NULL){
                p=p->link;
            }
            p->link = new;
        }
    }
    return new;
}


//return customer with id of parameter
struct list *searchcustomer(int *id){
    struct list *new = (struct list*)malloc(sizeof (struct list));
    while(root != NULL){
        if(&root->id == id){
            return root;
        }else{
            return NULL;
        }
        root = root->link;
    }
    return new;
}


//print array of stores
void printarr()
{
    for(int i = 0;i<24;i++)
    {
        printf("%s-->\n",stores[i]);
    }
}

//return number of customers of store of given name
void subscribers(char *name){
    int i = 0;
    int ctr = 1;
    struct list *temp = root;
    while(temp->link != NULL){
        while (temp->store->link != NULL){
            if(strcmp(temp->store->name,name)==0){
                i++;
            }else
            {
                ctr++;

            }
            temp->store = temp->store->link;
        }
        temp = temp->link;
    }
    printf("%d",i);
}

//Prompt customer for name odf store to return number of customers
void printsubscribers(){

    char name[100];
    printf("Enter name of program\n");
    fgets(name,100, stdin);
    subscribers(name);
}


//delete program from list of programs in customer structure
void unsubscribe(){
    int id;
    char name[100];
    printf("Enter id:\n");
    scanf("%d",id);
    printf("Enter name of program'\n");
    fgets(name,100, stdin);

    struct list *cust = searchcustomer(id);
      /* See if we are at end of list. */
  if (cust == NULL)
    return NULL;

  /*
   * Check to see if current node is one
   * to be deleted.
   */
  if (cust->store->name == name) {
    struct list  *tempNextP;

    /* Save the next pointer in the node. */
    tempNextP = cust->store->link;

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
   * Check the rest of the list, fixing the next
   * pointer in case the next node is the one
   * removed.
   */
  cust->store->link = ListDelete(cust->store->link, cust->store);


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
    struct list *cust = searchcustomer(id);
    for(int i = 0;i<24; i++){
        printf("$s-->\n",cust->store[i]);
    }
}

//Creates  customer if ther is no customer
//adds a store to the list of stores in customers structure
void subscribe(){
    struct list *new; 
    struct store *first = (struct store*)malloc(sizeof(struct store));

    struct store *roots = NULL;
    int id;
    char name[100];
    printf("Enter your id:\n");
    scanf("%d",id);
    new = getcustomer(id);
    printf("Enter name of program:\n");
    fgets(name,100, stdin);
    int found  = findstore(name);
    if(found == 1){
        new->store->link = NULL;
        new->store->name = name;
        if(roots == NULL){
            roots = new->store;
        }else{
            struct list *p;
            p = roots;
            while(p->link != NULL){
                p=p->link;
            }
            p->link = new;
        }
    }else{
        printf("Store not found enter 3 to see stores\n\n");
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
