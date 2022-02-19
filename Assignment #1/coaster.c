//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #1 - Problem C: Roller Coaster Design
//  Jan 23 2022

#include <stdio.h>

// given information
#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main(void)
{
    // variables for the for loop
    int i,n;
    
    // n is the number of time the for loop will run
    // i is the index number of the loop
    printf("What is the value for N?\n");
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        int lenTrack, lenTrain, car, people, maxTrain;
        int numCar = 0;
    
        printf("\nWhat is the total length of the track, in feet?\n");
        scanf("%d", &lenTrack);
        
        printf("What is the maximum length of a train, in feet?\n");
        scanf("%d", &lenTrain);
        
        maxTrain = (lenTrack * 0.25)/lenTrain;
        
        car = lenTrain - FIRST_CAR_LENGTH;
        numCar++;

        if(car % 8 == 0){
            car/=8;
            numCar+=car;
            
            people = (numCar * CAR_CAPACITY) * maxTrain;
            printf("Your ride can have at most %d people on it at one time.\n", people);
            printf("Maximum Length fits exactly.\n");
        }
        else{
            while(car>=8){
                car-=8;
                numCar++;
            }
            
            people = (numCar * CAR_CAPACITY) * maxTrain;
            printf("Your ride can have at most %d people on it at one time.\n", people);
            printf("Maximum Train Length has surplus of %d feet.\n", car);
        }
    }
    return 0;
}
