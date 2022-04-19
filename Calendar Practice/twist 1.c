// twist 1: if date is divisiblw by 6, put an additional digit 6 to the immediate right of the actual date

#include <stdio.h>

int main() {
    
    int i, entry, days =  31, start = 3, week = 1;
    
    for(i = 1; i < start; i++){
        printf("    ");
    }
    
    for(i = 1; i <= days; i++){
        entry = start - 1 + i;
        if(i % 6 == 0){
            printf("%3d6", i);
        }else{
            printf("%3d ", i);
        }
        
        if(entry % 7 == 0){
            printf("\n");
            week++;
        }
    }
    
    return 0;
}
