// twist 2: isolate the third week and isolate the Wednseday of that week. Make that date blank.

#include <stdio.h>

int main() {
    
    int i, entry, days =  31, start = 3, week = 1, wednesday = 0;
    
    for(i = 1; i < start; i++){
        printf("   ");
    }
    
    for(i = 1; i <= days; i++){
        entry = start - 1 + i;
        if(week == 3 && wednesday == 4){
            printf("   ");
        }else{
            printf("%3d", i);
        }
        
        wednesday++;
        
        if(entry % 7 == 0){
            printf("\n");
            week++;
            wednesday = 1;
        }
    }
    
    return 0;
}
