//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #4 -
//  Date

#include <stdio.h>
#include <stdlib.h>

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
    int i, n, numweeks, numentry;
    
    char LastName[MAX_LEN], FirstName[MAX_LEN];
    
    // var for converting time
    int HrIn, MinIn, HrOut, MinOut;
    double a, b, c;
    
    FILE *f_input = fopen("clock.txt", "r");
    FILE *f_output = fopen("w2.txt", "w");
    
    fscanf(f_input, "%d", &n);
    
    for(i = 0; i < n; i++){
        fscanf(f_input, "%s %s %lf", staff[i].first, staff[i].last, &staff[i].payperhr);
        
        staff[i].hours_in_week = 0;
        staff[i].gross = 0;
        staff[i].taxes = 0;
    }
    
    fscanf(f_input, "%d", &numweeks);
    
    for(i = 0; i < numweeks; i++){
        fscanf(f_input, "%d", &numentry);
        
        for(i = 0; i < numentry; i++){
            fscanf(f_input, "%s %s %d %d %d %d", LastName, FirstName, &HrIn, &MinIn, &HrOut, &MinOut);
            
            for(i = 0; i < n; i++){
                if(LastName == staff[i].last){
                    a = HrIn * 60 + MinIn;
                    b = HrOut * 60 + MinOut;
                    
                    c = b - a;
                    c /= 60;
                    
                    staff[i].hours_in_week += c;
                }
            }
        }
        
        for(i = 0; i < n; i++){
            if(staff[i].hours_in_week <= 40){
                staff[i].gross += staff[i].hours_in_week * staff[i].payperhr;
                staff[i].taxes += staff[i].gross * 0.10;
            }else{
                staff[i].hours_in_week -= 40;
                    
                staff[i].gross += staff[i].hours_in_week * 1.5 * staff[i].payperhr;
                staff[i].taxes += staff[i].gross * 0.20;
                
                staff[i].gross += 40 * staff[i].payperhr;
                staff[i].taxes += 40 * staff[i].payperhr * 0.10;
            }
            
            staff[i].hours_in_week = 0;
        }
    }
        
    
    // for the output file
    
    fprintf(f_output, "Number of employee: %d \n\n", n);
    
    for(i = 0; i < n; i++){
        fprintf(f_output, "W2 Form \n");
        fprintf(f_output, "------- \n");
        fprintf(f_output, "Name: %s %s \n", staff[i].first, staff[i].last);
        fprintf(f_output, "Gross Pay: %.2lf \n", staff[i].gross);
        fprintf(f_output, "Taxes Withheld: %.2lf \n", staff[i].taxes);
        fprintf(f_output, "Net pay: %.2lf \n\n", staff[i].gross - staff[i].taxes);
    }
    
    fclose(f_input);
    fclose(f_output);
    
    return 0;
}
