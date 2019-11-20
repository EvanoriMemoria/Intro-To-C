#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*Nicholas Rust
 *Lab 6, CSCI 112
 *March 13, 2019
 */ 

//finds one element subsets recursively
int one_ele_subs(char *arr, int i){
    if(i == 0){
	printf("one_ele_subs\n");
	printf("{\"%s\"}\n",arr);
    } else if(i == 4) {
	return 1;
    }
    printf("{%c}\n", arr[i]);
    one_ele_subs(arr, i+1);
    return 1;
}

//finds two element subsets recursively
int two_ele_subs(char *arr, int f, int l, int i){
    //01 02 03, 12 13, 23
    if(f == 0 && l == 1){
	printf("two_ele_subs\n");
	printf("{\"%s\"}\n",arr);
    }

    printf("{%c,%c}\n",arr[f],arr[l]);

    if(i < 2){
        two_ele_subs(arr, 0, l+1, i+1);
    } else if(i == 2) {
	two_ele_subs(arr, 1, 2, i+1);
    } else if(i == 3) {
	two_ele_subs(arr, 1, 3, i+1);
    } else if(i == 4) {
	two_ele_subs(arr, 2, 3, i+1);
    }
    return 1;
}

//finds three element subsets recursivly
int three_ele_subs(char *arr, int f, int m, int l, int i){
    //012,023,013,123
    
    if(i == 0){
	printf("three_ele_subs\n");
	printf("{\"%s\"}\n",arr);
        three_ele_subs(arr, 0,2,3,i+1);
    }

    printf("{%c,%c,%c}\n",arr[f],arr[m],arr[l]);

    if(i == 1){
	three_ele_subs(arr, 0,1,3,i+1);
    }
    if(i == 2){
	three_ele_subs(arr, 1,2,3,i+1);
    }
    return 1;
}

//main
//gathers input and starts the recursion chains
int main(int argc, char *argv[]) {
    if(argc != 2){
	printf("Sorry, that input is not correct.\n");
	return 1;
    }
    if(strlen(argv[1]) != 4){
	printf("Sorry, that input is not correct.\n");
    } else {
        one_ele_subs(argv[1], 0);
        two_ele_subs(argv[1], 0,1,0);
        three_ele_subs(argv[1], 0,1,2,0);
	printf("\n");
    }
    return 0;
}
