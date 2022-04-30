//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #4 - Payroll - W2 Forms
//  04/29/2022

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
    
    // declaring and opening files
    FILE *f_input;
    FILE *f_output;
    
    f_input = fopen("clock.txt", "r");
    f_output = fopen("w2.txt", "w");
    
    // scans for the num of employees
    fscanf(f_input, "%d", &n);
    for(i = 0; i < n; i++){
        fscanf(f_input, "%s %s %lf", staff[i].first, staff[i].last, &staff[i].payperhr);
    }
    
    // scans for the num of weeks
    fscanf(f_input, "%d", &numweeks);
    
    // scans data for each week
    for(i = 0; i < numweeks; i++){
        fscanf(f_input, "%d", &numentry);
        // scans data for each entry
        for(j = 0; j < numentry; j++){
            fscanf(f_input, "%s %s %d %d %d %d", LastName, FirstName, &HrIn, &MinIn, &HrOut, &MinOut);
            // calculate data of the "entry" employee
            for(k = 0; k < n; k++){
                if(strcmp(LastName, staff[k].last)==0 && strcmp(FirstName, staff[k].first)==0){
                    a = HrIn * 60 + MinIn;
                    b = HrOut * 60 + MinOut;
                    
                    c = b - a;
                    c = (double) c / 60;
                    
                    staff[k].hours_in_week += c;
                }
            }
        }
        
        // save data of the "entry" employee
        for(j = 0; j < n; j++){
            if(staff[j].hours_in_week <= 40.0){
                temp_gross = staff[j].hours_in_week * staff[j].payperhr;
                
                staff[j].gross += temp_gross;
                staff[j].taxes += temp_gross * 0.10;
            }else{
                staff[j].hours_in_week -= 40.0;
                temp_gross = staff[j].hours_in_week * 1.5 * staff[j].payperhr;
                
                staff[j].taxes += temp_gross * 0.20;
                temp_gross += 40.0 * staff[j].payperhr;
                
                staff[j].taxes += 40.0 * staff[j].payperhr * 0.10;
                
                staff[j].gross += temp_gross;
            }
        }
        
        // end of entry
        for(j = 0; j < n; j++){
            staff[j].hours_in_week = 0;
        }
    }
        
    
    // for the output file
    fprintf(f_output, "\nNumber of employee: %d \n\n", n);
    
    for(i = 0; i < n; i++){
        fprintf(f_output, "W2 Form \n");
        fprintf(f_output, "------- \n");
        fprintf(f_output, "Name: %s %s \n", staff[i].first, staff[i].last);
        fprintf(f_output, "Gross Pay: %.2lf \n", staff[i].gross);
        fprintf(f_output, "Taxes Withheld: %.2lf \n", staff[i].taxes);
        fprintf(f_output, "Net pay: %.2lf \n\n", staff[i].gross - staff[i].taxes);
    }
    
    //close files & end program
    fclose(f_input);
    fclose(f_output);
    
    return 0;
}
