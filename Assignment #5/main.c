//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #5 - Linked List
//  04/29/2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct donaNode {
    char donInvType[30];
    float donAmount;
    struct donaNode *link;
};

struct donaNode *search(struct donaNode *l, struct donaNode node1);
struct donaNode *insertatbackinlist(struct donaNode *l, struct donaNode node1);
void printlist(struct donaNode *l);

int main (){

    int option;

    struct donaNode *head;
    struct donaNode node1;
    struct donaNode *found;

    head = NULL;

    printf("Welcome to the Food Bank Program\n");
    printf("1. Add a donation \n4. Print status report \n5. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
     
    while (option != 5)
    {
        if (option == 1)
        {
            // prompt for word, don_quant
            scanf("%s", node1.donInvType);
            scanf("%f", &node1.donAmount);

            found = search (head, node1);
            
            if (found == NULL){
                head = insertatbackinlist(head, node1);
            }else{
                found->donAmount += node1.donAmount;
            }
        }else if(option == 4){
            printlist(head);
        }else if(option != 5){
            printf("\n Sorry that is not a valid menu option.\n\n");
        }
        printf("Press any key to continue . . . \n\n");
        printf("Welcome to the Food Bank Program\n");
        printf("1. Add a donation \n4. Print status report \n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
    }
    printf("\nThank You for using the softwaare. Bye for now.\n");
    return 0;
}

// define search function here

struct donaNode *search(struct donaNode *l, struct donaNode node1)
{
    struct donaNode   *temp;

    temp=NULL;

    if(l==NULL) printf("while searching, list began Empty\n");
    
    while (l != NULL)
    if(strcmp(l->donInvType,node1.donInvType) == 0)
    {
        temp = l;
    }

    return (temp);
}



struct donaNode *insertatbackinlist(struct donaNode *l, struct donaNode node1)
{
    struct donaNode *temp, *temp2, *temp3;
    temp = (struct donaNode *) malloc(sizeof(struct node));
    
    strcpy(temp->donInvType,node1.donInvType);

    temp->link = NULL;

    temp2 = l;
    if (l == NULL)
    {
        l = temp;
    }else{
        while (temp2 != NULL){
            temp3= temp2;
            temp2 = temp2->link;
        }
        temp3->link = temp;
    }

  return (l);
}


void printlist(struct donaNode *l)
{
    if (l==NULL) printf("Empty\n");
    while (l != NULL)
    {
        printf("Name=%s \n", l->donInvType);
        l = l->link;
    }
}
