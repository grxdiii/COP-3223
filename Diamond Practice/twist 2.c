//
//  main.c
//  Diamond Practice
//
//  Created by Gradi LeRoi on 4/19/22.
//

#include <stdio.h>
#define TOTAL_ROWS 15

int main() {
    int row, col, rate = 1, numstars = 1;
    int half = TOTAL_ROWS / 2;
    
    for(row = 1; row <= TOTAL_ROWS; row++){
        half = TOTAL_ROWS / 2;
        
        for(col = 1; col <= half + 1 - numstars; col++){
            printf(" ");
        }
        
        for(col = 1; col <= 2*numstars - 1; col++){
            printf("*");
        }
        
        if(row == half+1){
            printf("\n");
        }
        
        if(numstars == half+1){
            rate = -rate;
        }
        
        numstars += rate;
        printf("\n");
        
    }
    return 0;
}
