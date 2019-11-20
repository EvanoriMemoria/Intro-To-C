#include<stdio.h>
#include<math.h>

/*Nicholas Rust
 *Lab 3, CSCI 112
 *Feb 8, 2019
 */

//pages 167 and 305

//computes the monthly payments
void compute_payments(){
  double secLastPrinc,principal,interestRate,numPayment,monthlyPay,interest,finalPayment, fakePrincipal;

  printf("Enter principal amount, annual interest rate, and number of payments: ");

  //get user input from command line
  if(scanf("%lf%lf%lf",&principal,&interestRate,&numPayment) == 3){
    monthlyPay = (interestRate/12*principal)/(1-pow(1+(interestRate/12),-numPayment));
  }
  else //if there are not three values that are all numbers
    printf("you failed to enter all the values");

  //prints what user entered
  printf("Principal: $%.2lf              Payment: $%.2lf\n",principal,monthlyPay);
  printf("Annual Interest: %.1lf%%       Term: %.0lf months\n\n",interestRate*100,numPayment);
  printf("Payment Balance     Interest     Principal     Principal\n");

  //calculate monthly amounts
  for(int i = 0;i<numPayment;i++){
    interest = principal*interestRate/12;
    principal = principal + interest - monthlyPay;
    fakePrincipal = monthlyPay - interest;
    printf("      %d              %.2lf         %.2lf        %.2lf\n",i+1,interest,fakePrincipal,principal);

    if(i==numPayment-2){
      secLastPrinc = principal;
    }

    if(i==numPayment-1){
      finalPayment = roundf(interest*100)/100+roundf(secLastPrinc*100)/100;
      printf("\nFinal payment: $%.2lf\n\n",finalPayment);
    }

  }
}

int main(void){
  compute_payments();
  return(0);
}

