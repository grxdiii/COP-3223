// twist 4: calendar reads in two numbers (NumDays and Start) normally, and then also reads in an int ThisWeek. The purpose of ThisWeek is so that in that week, the dates that are divisible by ThisWeek have an asterik printed beside them.

#include <stdio.h>

int main() {
    
    int i, Start, NumDays, ThisWeek;
    
    printf("Start: ");
    scanf("%d", &Start);
    
    printf("NumDays: ");
    scanf("%d", &NumDays);
    
    printf("This Week: ");
    scanf("%d", %ThisWeeK);
    
    int entry, week = 1;
    
    for(i = 1; i < start; i++){
        printf("    ");
    }
    
    for(i = 1; i <= days; i++){
        entry = start - 1 + i;
        
        if(week == ThisWeek && i % ThisWeek == 0){
            printf("%3d*", i);
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
