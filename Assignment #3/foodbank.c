//  Gradi Tshielekeja Mbuyi
//  COP 3223C Section 2
//  Assignment #2 - Foodbank
//  March 27 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    // declaring all my variables
    int i, option, found, don_quant, don_count = 0, req_count = 0, don_amt[100], req_amt[100];
    char don_inv_type[100][20], req_inv_type[100][20], word[20];
    
    // menu screen
    printf("Welcome to the Food Bank Program\n\n");
    printf("1. Add a donation \n2. Add a request \n3. Fulfill a request \n4. Print status report \n5. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    // fills two arrays with the value 0 in each position
    for(i = 0; i < 100; i++){
        don_amt[i] = 0;
        req_amt[i] = 0;
    }
    
    // the program will run at least 1 time
    // the program will continue to run as long as the user does not input 5
    while(option != 5){
        
        // adds a donation
        if(option == 1){
            
            // prompts the user for the donation type and amount
            printf("\nEnter inventory type: ");
            scanf("%s", word);
            printf("Enter the amount: ");
            scanf("%d", &don_quant);
            
            found = -99;
            
            // check if the donation type exist
            for(i = 0; i < don_count; i++){
                if(strcmp(don_inv_type[i], word)==0){
                    found = i;
                }
            }
            
            // adds donation to the array
            if(found == -99){
                strcpy(don_inv_type[i], word);
                don_amt[i] = don_quant;
                don_count++;
                
            }else{
                
                // adds the amount to an already existing donation type
                don_amt[found] += don_quant;
            }
            
            // informs the user that the donation has been added
            printf("\nDonation Added!\n\n");
        
        // adds a request
        }else if(option == 2){
            
            // prompts the user for the inventory type and amount
            // adds in the request
            for(i = req_count; i < req_count + 1; i++){
                printf("\nEnter inventory type: ");
                scanf("%s", word);
                printf("Enter the amount: ");
                scanf("%d", &don_quant);
                
                strcpy(req_inv_type[i], word);
                req_amt[i] = don_quant;
                
                printf("\nRequest Added!\n\n");
            }
            
            // counter variable for request
            req_count++;
        
        // fulfills a request
        }else if(option == 3){
            
            printf("\n-------- Fulfilling Requests --------\n");
            
            // checks if there are any requests or donations
            if(req_count == 0){
                printf("\nNo Requests have been made.\n\n");
            }else if(don_count == 0){
                printf("\nNo Donations have been made.\n\n");
            }else{
                
                found = -99;
                
                // runs if the request count is > 1
                // checks the inventory
                for(i = 0; i < don_count; i++){
                    if(strcmp(don_inv_type[i], req_inv_type[0])==0){
                        found = i;
                    }
                }
                
                if(found == -99){
                    printf("\nRequest Cannot Be Fulfilled\n");
                }else{
                    
                    if(don_amt[found]==req_amt[0]){
                        printf("\nRequest Fulfilled\n\n");
                        
                        // deletes the request
                        // moves list
                        for(i = 1; i < req_count; i++){
                            strcpy(req_inv_type[i-1], req_inv_type[i]);
                            req_amt[i-1] = req_amt[i];
                        }
                        
                        // lowers num request
                        req_count--;
                        
                        // deletes the donation
                        // moves list
                        for(i = found; i < don_count; i++){
                            strcpy(don_inv_type[i], don_inv_type[i+1]);
                            don_amt[i] = don_amt[i+1];
                        }
                        
                        // lowers num donation
                        don_count--;
                        
                    }else if(don_amt[found]>req_amt[0]){
                        
                        don_amt[found] -= req_amt[0];
                        
                        for(i = 1; i < req_count; i++){
                            strcpy(req_inv_type[i-1], req_inv_type[i]);
                            req_amt[i-1] = req_amt[i];
                        }
                        
                        req_count--;
                        printf("\nRequest Fulfilled\n\n");
                        
                    }else{
                        
                        req_amt[0] -= don_amt[found];
                        
                        for(i = found; i < don_count - 1; i++){
                            strcpy(don_inv_type[i], don_inv_type[i+1]);
                            don_amt[i] = don_amt[i+1];
                        }
                        
                        printf("\nReuqest Partially Fulfilled\n\n");
                        don_count--;
                    }
                }
            }
        }else if(option == 4){
            
            // prints the donation table
            printf("\nPrinting the Donations Table\n\n");
            for(i = 0; i < don_count; i++){
                printf("%s %d \n", don_inv_type[i], don_amt[i]);
            }
            
            // prints the request table
            printf("\nPrinting the Requests Table\n\n");
            for(i = 0; i < req_count; i++){
                printf("%s %d \n", req_inv_type[i], req_amt[i]);
            }
            
            printf("\n");
            
        }else if(option != 5){
            // error message
            printf("\n Sorry that is not a valid menu option.\n\n");
        }
        
        // menu screen appears once again
        printf("Press any key to continue . . . \n\n");
        printf("Welcome to the Food Bank Program\n\n");
        printf("1. Add a donation \n2. Add a request \n3. Fulfill a request \n4. Print status report \n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
    }
    
    // ends program
    printf("\nThank You for using the software. Bye for now.\n");
    return 0;
}
