#include <stdio.h>
#include <stdlib.h>
#include <math.h>




void row_out(int row, int H, int L) {
	if(L==1) {
		for(int i=0; i<(H-row);   i++) printf(" ");
		for(int i=0; i<(2*row-1); i++) printf("*");
		for(int i=0; i<(H-row);   i++) printf(" ");
		return;
	}
	if(row<=H/2) {
		for(int space=1; space<=(H/2); space++) printf(" ");
		row_out(row, H/2, L-1);
		for(int space=1; space<=(H/2); space++) printf(" ");
	} else {
		row_out(row-H/2, H/2, L-1);
		printf(" ");
		row_out(row-H/2, H/2, L-1);
	}
	return;
}


int main(int argc, char *argv[]) {
	// ERROR CHECK
	if(argc != 3) {
		printf("ERROR: Wring number of arguments. Two required.\n");
		return 0;
	}
	int H = atoi(argv[1]);
	int L = atoi(argv[2]);
	if(H <= 0 || H%2 == 0) {
		printf("ERROR: Bad argument. Height must be positive odd integer.\n");
		return 0;
	}
	int tri_height = ceil(H/2.0);
	int exponent = 0;
	while(tri_height > 1) {
		if(tri_height % 2 != 0) {
			printf("ERROR: Height does not allow evenly dividing requested number of levels.\n");
			return 0;
		}
		exponent++;
		tri_height /= 2;
	}
	if(exponent < L-1) {
		printf("ERROR: Height does not allow evenly dividing requested number of levels.\n");
		return 0;
	}
	int T = ceil(H/2.0);
	// LOOP
	for(int row=1; row<=T; row++) {
		row_out(row,T,L);
		printf("\n");
	}
	for(int row=T-1; row>0; row--) {
		row_out(row,T,L);
		printf("\n");
	}
}