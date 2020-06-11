/*
Design, develop and implement a C/C++/Java program to implement page replacement algorithms LRU and FIFO. 
Assume suitable input required to demonstrate the results.
*/

#include<stdio.h>
#include<stdlib.h>

//FIFO
void FIFO(char str[], int len, int frames) {
    int i=0, j=0, k=0, flag=0, count=0;
    
    // Initialize the queue
    char fqueue[10];
    for(i=0; i<frames; i++)
        fqueue[i] = -1;
    
    printf("\nPAGE\tFRAMES\tFAULTS");
    
    // Loop through string
    for(i=0; i<len; i++) {
    	
        // Print page
        printf("\n%c\t", str[i]);
        
        // Check if page is present in frames
        for(k=0; k<frames; k++) {
            if(fqueue[k] == str[i])
                flag = 1;
        }

        // Page fault
        if(flag == 0) {
        	
            // Replace oldest element with page
            fqueue[j] = str[i];
            j++;

            for(k=0; k<frames; k++)
                printf("%c ", fqueue[k]);
            printf("\tPage fault %d", count+1);
            count++;
        } else { // Page Hit
        
            // Reset flag and print queue
            flag = 0;            
            for(k=0; k<frames; k++)
                printf("%c ", fqueue[k]);
            printf("\tHit");
        }

        // Reset j if reached last element
        if(j == frames)
            j = 0;
    }
}

//LRU
void LRU(char str[], int len, int frames) {

    int i=0, j=0, k=0, m=0, flag=0, count=0, top=0;
    
    char fqueue[10];
    for(i=0; i<frames; i++)
        fqueue[i] = -1;
    
    printf("\nPAGE\tFRAMES\tFAULTS");
    for(i=0; i<len; i++) {
        printf("\n%c\t", str[i]);
        
        // Check if page is present in frames
        for(k=0; k<frames; k++) {
            if(fqueue[k] == str[i]) {
                flag=1;
                break;
            }
        }

        // If queue has empty frames with no page hit
        if(j!=frames && flag == 0) {
        	
            // Place page at end of queue
            fqueue[top] = str[i];
            j++;
            if(j != frames) top++;
        } else {
        	
            // Page Fault
            if(flag == 0) {
            	
                // Shift all characters left
                for(k=0; k<top; k++)
                    fqueue[k] = fqueue[k+1];
                    
                // Place page at end of queue
                fqueue[top] = str[i];
            }

            // page hit
            if(flag == 1) {
            	
                // Shift all elements after the hit frame
                for(m=k; m<top; m++) {
                    fqueue[m] = fqueue[m+1];
                }
                
                // Place the hit page at end of queue
                fqueue[top] = str[i];
            }
        }

        // Print results
        for(k=0; k<frames; k++)
            printf("%c ", fqueue[k]);
        if(flag == 0) {
            printf("\tPage Fault %d", count+1);
            count++;
        } else
            printf("\tHit");
            
        // Reset flag
        flag = 0;
    }
}

int main() {
    int ch, repeat=1, i, len, frames;
    char str[25];
    printf("Enter the number of empty frames: ");
    scanf("%d", &frames);
    printf("Enter the length of the string: ");
    scanf("%d", &len);
    printf("Enter the string:\t");
    scanf("%s", str);
    do {
        printf("\n1: FIFO\n2: LRU\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                FIFO(str, len, frames);
                break;
            case 2:
                LRU(str, len, frames);
                break;
            default:
                exit(0);
        }
        printf("\n\nEnter 1 to continue, 0 to finish: ");
        scanf("%d", &repeat);
    } while(repeat == 1);
    return 0;
}
