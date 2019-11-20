#include<stdio.h>
#include<math.h>

/*Nicholas Rust
 *Lab 2, CSCI 112
 *Feb 1, 2019
 */

//this computes BMI after getting weight and height.
int compute_BMI(){
  double h,w,BMI;
  printf("Enter your Height in inches: ");

  scanf("%lf",&h);

  printf("Enter your Weight in pounds: ");

  scanf("%lf",&w);

  BMI = (703*w)/pow(h,2);

  printf("Your BMI is %.1lf \n",BMI);

  return(BMI);
}

//categorize BMI
void categorize(int BMI){
  if(BMI < 0)
    printf("Not within range- less than 0.");
  else if(BMI < 18.5 && BMI >= 0)
    printf("Underweight");
  else if(BMI < 24.9 && BMI >= 18.5)
    printf("Normal");
  else if(BMI <= 29.9 && BMI >= 24.9)
    printf("Overweight");
  else if(BMI > 29.9)
    printf("Obese");
  else
    printf("try again");
  printf("\n");
}

int main(void){
  categorize(compute_BMI());
  return(0);
}
