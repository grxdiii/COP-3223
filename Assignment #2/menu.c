//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #2 - Problem C: Menu
//  Feb 19 2022

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// given information
#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main() {
    
    // declaring all variables
    // controls menu
    int choice;
    
    // Print the menu and read in the user's choice.
    printf("1.coaster2, 2.lastnames, 3.quit\n");
    scanf("%d", &choice);
    
    // variables for option #1
    
    // the first three variables store the user input
    // the rest will be used in the for loop
    int lenTrack, lenTrain, maxTrain;
    int TL, i, Total_cars, Cumul_car_len, Peop;
    int N_cars = 0, N_trains = 0, mostPeople = 0, mostCars = 0;
    
    // variables that will be used to calculate the AVG ratio
    float Ratio, averageRatio, ratioSum = 0, ratio_array[N_cars+1];
    
    // Keep on going until the user quits.
    while(choice != 3){
        
        if(choice == 1){
            // prompts the user
            printf("\nWhat is the total length of the track, in feet?\n");
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
            printf("\n");
            
        }else if(choice == 2){
            
            // var for: for loop, number of entries, check
            int i, n, isRepeated = 0;
              
            // prompts the user
            printf("\nEnter n, followed by n Last names (each last name must be a single word) : \n");
            scanf("%d", &n);
              
            // array with n spaces for strings; strings can only be 20 characters long
            char lastNames[n][20];
              
            // saves the last names in array
            for(i=0; i<n; i++){
                scanf("%s", lastNames[i]);
            }
              
            // compares the first last name to the rest; checks to see if the first last name is repeated
            for(i=1; i<n; i++){
                if(strcmp(lastNames[0], lastNames[i]) == 0){
                    isRepeated = 1;
                }
            }
              
            // prints out the result
            if(isRepeated == 1){
                printf("First name in list is repeated. \n");
                printf("\n");
            }
            else{
                printf("First name in list is not repeated. \n");
                printf("\n");
            }

        }else if(choice != 3){
            
            printf("Sorry that was invalid.\n");
            printf("\n");
        }
        // Reprompt the menu.
        printf("1.coaster2, 2.lastnames, 3.quit\n");
        scanf("%d", &choice);
    } // end while loop
          
    printf("\nAll done!\n");
    system("PAUSE");
    return 0;
}
