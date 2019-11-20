#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*Nicholas Rust
 *Lab 5, CSCI 112
 *March 5, 2019
 */ 

void clearArray(char *arr){
    for(int i = 0;i<80;i++){
        arr[i] = 0;
    }
}

//calculates factorial of num and modifies the fact and stars character arrays
//to produce the output.
void fact_calc(char *fact, char *stars,  int num){
    char tempFact[80] = "*";
    char smallerTempFact[80];
    char tempStars[80] = "";
    char smallerTempStars[80];
    int factorial = 1;
    if(num == 0){
        sprintf(smallerTempFact, "\n*0! = 1*\n*");
        sprintf(smallerTempStars,"*******");
	strcat(tempFact, smallerTempFact);
        strcat(tempStars, smallerTempStars);
    }
    if(num > 9){
            printf("Please enter a valid number.");
    } else {
        for(int i = num; i>0; i--){
	    factorial = factorial * i;
	    if(i == num){
	        sprintf(smallerTempFact, " %d! = %d x ", num, num);
	        sprintf(smallerTempStars, "***********");
	    } else if(i == 1){
	        sprintf(smallerTempFact, "1 = %d*\n",factorial);
	        sprintf(smallerTempStars, "********\n");
	    } else {
	        sprintf(smallerTempFact, "%d x ", i);
	        sprintf(smallerTempStars, "****");
	    }
	    strcat(tempFact, smallerTempFact);
            strcat(tempStars, smallerTempStars);
	    if(i > 9 && i < 100){
	        sprintf(smallerTempStars, "*");
	        strcat(tempStars, smallerTempStars);
	    }
       	    if(i > 99 && i < 1000){
	        sprintf(smallerTempStars, "**");
	        strcat(tempStars, smallerTempStars);
	    }
    	}
    }
    strcat(fact,tempFact);
    strcat(stars, tempStars);
    clearArray(tempStars);
    clearArray(tempFact);
    clearArray(smallerTempStars);
    clearArray(smallerTempFact);

}

//takes input and passes is to fact_calc. 
//Prints arrays after fact_calc has modified them.
int main (void) {
    char *fact = (char *) malloc(80);
    char stars[80] = "";
    int scanResult;
    do{
	clearArray(fact);
	clearArray(stars);
	printf("Input a number between 0 and 9, -1 to exit:  ");

        scanf("%d",&scanResult);

        fact_calc(fact,stars,scanResult);
        printf(stars);
        printf(fact);
        printf(stars);
        printf("\n");
    }while(scanResult > -1);
    return 0;
}
