//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #5 - Linked List
//  04/29/2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining donaNode
struct donaNode {
    char donInvType[30];
    int donAmount;
    struct donaNode *link;
};

// functions used for searching, inserting, and printing a linked list
struct donaNode *search(struct donaNode *l, struct donaNode node1);
struct donaNode *insertatbackinlist(struct donaNode *l, struct donaNode node1);
void printlist(struct donaNode *l);

int main (){

    // var for menu
    int option;
    
    // var to store the linked list
    struct donaNode *head;
    struct donaNode node1;
    struct donaNode *found;

    head = NULL;

    // prompts the user
    printf("Welcome to the Food Bank Program\n");
    printf("1. Add a donation \n4. Print status report \n5. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    // while loop runs until user exit
    while (option != 5)
    {
        // store user data (input)
        if (option == 1)
        {
            // prompts for the inventory type
            printf("Enter inventory type: ");
            scanf("%s", node1.donInvType);
            
            // prompts for the amount/quantity of inventory
            printf("Enter the amount: ");
            scanf("%d", &node1.donAmount);

            // check if inventory type already exist
            found = search(head, node1);
            
            // inserts the donation in the list
            if (found == NULL){
                head = insertatbackinlist(head, node1);
            }else{
                found->donAmount += node1.donAmount;
            }
            
            // confirms that the donation has been addeed
            printf("\nDonation Added!\n");
        
        // prints donation table
        }else if(option == 4){
            printf("\nPrinting Donations Table...\n\n");
            printlist(head);
        
        // message is sent to user when they've inputed an invalid option
        }else if(option != 5){
            printf("\nSorry that is not a valid menu option.\n");
        
        }
        // prompts the user once again
        printf("\nPress any key to continue . . . \n\n");
        printf("Welcome to the Food Bank Program\n");
        printf("1. Add a donation \n4. Print status report \n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
    }
    // ends the program
    printf("\nThank You for using the softwaare. Bye for now.\n");
    return 0;
}

// definition of search function

struct donaNode *search(struct donaNode *l, struct donaNode node1)
{
    struct donaNode *temp;

    temp=NULL;
    
    while (l != NULL){
        if(strcmp(l->donInvType,node1.donInvType) == 0)
        {
            temp = l;
        }
        l = l->link;
    }

    return (temp);
}

// definition of insertion function

struct donaNode *insertatbackinlist(struct donaNode *l, struct donaNode node1)
{
    struct donaNode *temp, *temp2, *temp3;
    temp = (struct donaNode *) malloc(sizeof(struct donaNode));
    temp2 = NULL;
    temp3 = NULL;
    
    strcpy(temp->donInvType,node1.donInvType);
    
    temp->donAmount = node1.donAmount;

    temp->link = NULL;

    temp2 = l;
    if (l == NULL)
    {
        l = temp;
    }else{
        while (temp2 != NULL){
            temp3 = temp2;
            temp2 = temp2->link;
        }
        temp3->link = temp;
    }

  return (l);
}

// definition of printing function

void printlist(struct donaNode *l)
{
    if (l==NULL) printf("No Donations are present!\n");
    
    while (l != NULL)
    {
        printf("%s %d\n", l->donInvType, l->donAmount);
        l = l->link;
    }
}
