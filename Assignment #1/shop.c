//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #1 - Problem A: A Gift Shop Purchase
//  Jan 15 2022

#include <stdio.h>
#define TAX_RATE 0.065

int main(void)
{
    // user data will be stored in these variables
    float cost, totalCost;
    int item, isTaxed;
    
    // asks user the cost of the item
    printf("What is the cost of the item to be purchased (in dollars)? \n");
    scanf("%f", &cost);
    
    // asks user how many of the item they're purchasing
    printf("How many of the item are you purchasing? \n");
    scanf("%d", &item);
    
    // asks users if the item is taxed
    printf("Is the item a taxed item (1 = yes, 0 = no)? \n");
    scanf("%d", &isTaxed);
    
    // isTaxed is an int
    // tax is a float
    // this part of the program takes the int input and place it in a float var
    float tax = isTaxed;
    
    // multiply user input to the tax rate
    tax *= TAX_RATE;
    
    // gets the total cost of all the items
    totalCost = cost * item;
    
    // multiply the tax to the total cost
    tax *= totalCost;
    
    // adds the tax amount to total cost
    totalCost += tax;
    
    // outputs the total cost
    printf("Your total purchase will cost $%0.2f \n", totalCost);
    return 0;
}
