#include <stdio.h>

int main(void){
   double start,end,r,dist;

   //Get the start milage
   printf("MILEAGE REIMBURSEMENT CALCULATOR \n Enter beinning odometer reading=> ");
   scanf("%lf", &start);
   printf("Enter endng odometer reading=> ");
   scanf("%lf", &end);

   //distance traveled
   dist = end-start;

   //find the reimbursement
   r =dist*.35;

   //display reimbursement
   printf("You traveled %.1lf miles. At $0.35 per mile, your reimbursement is %.1lf\n",dist,r);
   
   return(0);
}
