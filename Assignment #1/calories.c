//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #1 - Problem B: Calorie Counter
//  Jan 15 2022

#include <stdio.h>

#define WALK_CAL 5
#define STAND_CAL 2
#define DRINK_CAL 20
#define FOOD_CAL 40
#define CALS_PER_POUND 3500

int main(void)
{
    // these var will store the user's input
    float walk, stand, drink, food, pounds;
    
    // ask user how many mins they were walking
    // stores input
    printf("How many minutes were you walking? \n");
    scanf("%f", &walk);
    
    // calculates and stores how many pounds the user burned walking
    walk *= WALK_CAL;
    
    // ask user how many mins they were standing
    // stores input
    printf("How many minutes were you standing? \n");
    scanf("%f", &stand);
    
    // calculates and stores how many pounds the user burned standing
    stand *= STAND_CAL;
    
    // ask user how many mins they were drinking
    // stores input
    printf("How many minutes were you drinking? \n");
    scanf("%f", &drink);
    
    // calculates and stores how many pounds the user ingested drinking
    drink *= DRINK_CAL;
    
    // ask user how many mins they were eating
    // stores input
    printf("How many minutes were you eating? \n");
    scanf("%f", &food);
    
    // calculates and store how many pounds the user ingested eating solid food
    food *= FOOD_CAL;
    
    // calculates the amount of weight lost by the user
    pounds = (walk + stand) - (drink + food);
    pounds /= CALS_PER_POUND;
    
    // outputs the result
    if(pounds > 0){
        printf("You lost %0.3f pounds today! \n", pounds);
    }else{
        printf("Weight lost is %0.3f pounds. \n", pounds);
    }
    
    return 0;
}
