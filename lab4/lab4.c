#include<stdio.h>
#include<math.h>

/*Nicholas Rust
 *Lab 4, CSCI 112
 *February 22, 2019
 */ 

//I do want to note, for this lab I did not have access to the book, but completed it based on observations and information gained through class and the assignment posted.

//one great big disgusting function to calculate and print everything.
void get_corners(){
    int i = 0;
    int k = 0;
    double corner[20];
    double X[10];
    double Y[10];
    int lineRead = 0;
    int isEnd = 0;
    int scanResult = 0;

    printf("    X       Y\n");
    printf("    -       -\n");
    //get the coordinates from the redirected file
    do{
        scanResult = scanf("%lf ",&corner[i]);
	//split into two separate arrays
	if(i % 2 == 0){
	    X[i/2] = corner[i];
	}
	else{
	    Y[i/2] = corner[i];
	}

	lineRead++;
	i++;
    }while(scanResult >= 0);

    //put an ending value into the array
    corner[i] = -1; 

    //print coordinates
    while(isEnd == 0){
	if(corner[k] < 0 || corner[k+1] < 0){
            isEnd = 1;
	    break;
        }
	printf("   %.1f     %.1f \n",corner[k],corner[k+1]);
	k+=2;
    }

    double area = 0.0;
    int n = (lineRead-1)/2;

    // Calculate area
    int j = n - 1;
    for (int p = 1; p < n; p++)
    {
        area += (X[j]*Y[p]- Y[j]*X[p]);
        j = p;  // j is previous vertex to p
    }

    // print absolute value
    printf("\nArea is: %.2f\n",fabs(area/2));
}

//main
int main (void) {
    get_corners();
    return 0;
}
