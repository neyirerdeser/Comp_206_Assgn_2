#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	// in case there are no or more than one arguments entered
	if(argc != 2) {
		printf("ERROR: Wring number of arguments. One required.\n");
		return 0;
	}
	// now we know there's exactly one input argument
	// take the  argument and convert into an integer value
	// to be used to determine if the arguemnt is valid and later to size the diamond
	int H = atoi(argv[1]);

	// now we can check if the argument is valid
	// if the argument was not an integer, value of H will be the integer value of the number entered
	// if the argument was not a number to begin with, value of H will be 0
	if(H <= 0 || H%2 == 0) {
		printf("ERROR: Bad argument. Height must be positive odd integer.\n");
		return 0;
	}

	// if everything is fine, we can print the diamond
	// first the upper half

	// a triangle half the size of the diamond will be built first
	int half = ceil(H/2.0);
	
	// for each row there will be (half-row) spaces at the begining and the end
	// in between those spaces there will be [(2*row)-1] asterisks printed

	for(int row=1; row<=half; row++) {
		for(int i=0; i<(half-row); i++) printf(" ");
		for(int i=0; i<(2*row-1);  i++) printf("*");
		for(int i=0; i<(half-row); i++) printf(" ");
		printf("\n");
	}
	
	// now same thing reverse to build the lower half
	// as if going from half-1 th row to the first row
	for(int row=half-1; row>=1; row--) {
		for(int i=0; i<(half-row); i++) printf(" ");
		for(int i=0; i<(2*row-1);  i++) printf("*");
		for(int i=0; i<(half-row); i++) printf(" ");
		printf("\n");
	}
	
}