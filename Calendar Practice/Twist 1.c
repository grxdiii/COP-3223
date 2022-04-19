// Twist 1: 
// if date is divisible by 6 put an additional digit 6 to the immediate right of the actual date.

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
