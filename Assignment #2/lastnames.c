//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #2 - Problem B: Lastnames
//  Feb 19 2022

#include <stdio.h>
#include <string.h>

#define TOTAL_ROWS 15
int main(void) {

    // var for: for loop, number of entries, check
    int i, n, isRepeated = 0;
    
    // prompts the user
    printf("Enter n, followed by n Last names (each last name must be a single word) : \n");
    scanf("%d", &n);
    
    // array with n spaces for strings; strings can only be 20 characters long
    char lastNames[n][20];
    
    // saves the last names in array
    for(i=0; i<n; i++){
        scanf("%s", lastNames[i]);
    }
    
    // compares the first last name to the rest; checks to see if the first last name is repeated
    for(i=1; i<n; i++){
        if(strcmp(lastNames[0], lastNames[i]) == 0){
            isRepeated = 1;
        }
    }
    
    // prints out the result
    if(isRepeated == 1){
        printf("First name in list is repeated. \n");
    }
    else{
        printf("First name in list is not repeated. \n");
    }
    
    return 0;
}
