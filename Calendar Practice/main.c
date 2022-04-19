//
//  main.c
//  Test
//
//  Created by Gradi LeRoi on 4/19/22.
//

#include <stdio.h>

int main() {
    
    int i, entry, days =  31, start = 3, week = 1, sum = 0;
    
    for(i = 1; i < start; i++){
        printf("...");
    }
    
    for(i = 1; i <= days; i++){
        entry = start - 1 + i;
        if(week == 3){
            sum+=i;
        }
        
        printf("%3d", i);
        
        if(entry % 7 == 0){
            printf("\n");
            week++;
        }
    }
    
    printf("\nSum: %d", sum);
    return 0;
}
