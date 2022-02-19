//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #2 - Problem A: Roller Coaster Redesign
//  Feb 10 2022

#include <stdio.h>

// given information
#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main(void)
{
    // declaring all my variables
    
    // the first three variables store the user input
    int lenTrack, lenTrain, maxTrain;
    
    // variables that will be used in the for loop
    int TL, i, Total_cars, Cumul_car_len, Peop;

    int N_cars = 0;
    int N_trains = 0;
    int mostPeople = 0;
    int mostCars = 0;
    
    // variables that will be used to calculate the AVG ratio
    float ratioSum = 0;
    float Ratio, averageRatio;
    float ratio_array[N_cars+1];

    // prompts the user
    printf("What is the total length of the track, in feet?\n");
    scanf("%d", &lenTrack);
        
    printf("What is the maximum length of a train, in feet?\n");
    scanf("%d", &lenTrain);
    
    // 25% of the track can be used
    maxTrain = lenTrack * 0.25;
    
    // produces Dr. Lobo's table
    for(TL=FIRST_CAR_LENGTH; TL<= lenTrain; TL+=NORMAL_CAR_LENGTH){
        N_cars++;
        N_trains = maxTrain / TL;
        Total_cars = N_cars * N_trains;
        Cumul_car_len = TL * N_trains;
        Peop = CAR_CAPACITY * Total_cars;
        Ratio = (float) Peop / Cumul_car_len;
        ratio_array[N_cars-1] = Ratio;
        
        // finds the maximum amount of people that can be supported
        if(Peop > mostPeople){
            mostPeople = Peop;
            mostCars = N_cars;
        }
    }
    
    // sums all the ratio
    for(i=0; i<N_cars; i++){
        ratioSum += ratio_array[i];
    }
    
    // finds the average ratio
    averageRatio = ratioSum / N_cars;
    
    // outputs
    printf("Your ride can have at most %d people on it at one time. \n", mostPeople);
    printf("This can be achieved wirth trains of %d cars. \n", mostCars);
    printf("AVG Ratio: %.3f\n", averageRatio);
    
    return 0;
}
