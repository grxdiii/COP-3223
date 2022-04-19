// twist 3: Print normal calendar, but while doing it, add up the numbers in the third row, and then at the end of program test if that sum is divisible by 7. If so, say so at the end of Calendar

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
    
    if(sum % 7 == 0){
        printf("The sum of the third row is divisible by 7");
    }
    
    return 0;
}
