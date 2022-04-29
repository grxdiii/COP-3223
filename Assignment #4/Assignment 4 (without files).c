//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #4 -
//  Date

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPL 20
#define MAX_LEN 30

struct employee {
    char first[MAX_LEN];
    char last[MAX_LEN];
    double payperhr;
    double gross;
    double taxes;
    double hours_in_week;
};

int main() {
   
    // saves employee data
    struct employee staff[MAX_EMPL];
    
    // for-loop variables
    int i, j, k, n;
    
    int numweeks, numentry;
    
    char LastName[MAX_LEN], FirstName[MAX_LEN];
    
    // var for converting time
    int HrIn, MinIn, HrOut, MinOut;
    int a, b;
    double c, temp_gross;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%s %s %lf", staff[i].first, staff[i].last, &staff[i].payperhr);
    }
    
    scanf("%d", &numweeks);
    
    for(i = 0; i < numweeks; i++){
        scanf("%d", &numentry);
        
        for(j = 0; j < numentry; j++){
            scanf("%s %s %d %d %d %d", LastName, FirstName, &HrIn, &MinIn, &HrOut, &MinOut);
            
            for(k = 0; k < n; k++){
                if(strcmp(LastName, staff[k].last)==0){
                    a = HrIn * 60 + MinIn;
                    b = HrOut * 60 + MinOut;
                    
                    c = b - a;
                    c = (double) c / 60;
                    
                    staff[k].hours_in_week += c;
                }
            }
        }
        
        for(j = 0; j < n; j++){
            if(staff[j].hours_in_week <= 40.0){
                temp_gross = staff[j].hours_in_week * staff[j].payperhr;
                
                staff[j].gross += temp_gross;
                staff[j].taxes += temp_gross * 0.10;
            }else{
                staff[j].hours_in_week -= 40;
                temp_gross = staff[j].hours_in_week * 1.5 * staff[j].payperhr;
                
                staff[j].taxes += temp_gross * 0.20;
                temp_gross += 40 * staff[j].payperhr;
                
                staff[j].taxes += 40 * staff[j].payperhr * 0.10;
                
                staff[j].gross += temp_gross;
            }
        }
        
        for(j = 0; j < n; j++){
            staff[j].hours_in_week = 0;
        }
    }
        
    
    // for the output file
    
    printf("\nNumber of employee: %d \n\n", n);
    
    for(i = 0; i < n; i++){
        printf("W2 Form \n");
        printf("------- \n");
        printf("Name: %s %s \n", staff[i].first, staff[i].last);
        printf("Gross Pay: %.2lf \n", staff[i].gross);
        printf("Taxes Withheld: %.2lf \n", staff[i].taxes);
        printf("Net pay: %.2lf \n\n", staff[i].gross - staff[i].taxes);
    }
    return 0;
}
