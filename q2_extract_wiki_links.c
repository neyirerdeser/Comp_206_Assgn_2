#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE * fPointer;
	fPointer = fopen(argv[1], "r");
	if(!fPointer) {
		printf("Error: unable to open file. Check file name and try again :)\n");
		return 1; // not sure if it matters wheter this is 1 or not (like 0, but I guess 0 is success, still?)
	}

	char line[10000];
	char start[16] = "<a href=\"/wiki/";
	char mid0[2]   = "\"";
	char mid1[8]   = "title=\"";
	char mid2[3]   = "\">";
	char end[5]    = "</a>";
	char *s, *m0, *m1, *m2, *e;
	// min lengths of strings needed after certain points
	int begin = 32;
	int after_start = begin - 15; 
	int after_mid0  = after_start - (1+1);
	int after_mid1  = after_mid0 - 7;
	int after_mid2  = after_mid1 - (2+1);


	/*
	 at first I was checking two points in the URL where the name would be and only printing if those two match,
	 but i realized that I get much less results than the examples in the assignmnet,
	 so now this is just for printing the first appereance of the page name
	 this way its "almost" identical, although for some reason not quite
	*/
	char name[100];

	char *ptr;
	char *sub;

	while((fgets(line,10000, fPointer)) != NULL) {
		ptr = line;
		sub = line;
		while(sub <= ptr+strlen(line)-1) {
			memset(name, 0, 100);

			if(strlen(sub)<begin) break; 
			if(strstr(sub,start)==NULL) break; 
			s  = strstr(sub,start);

			if(strlen(sub)<after_start) break;
			if(strstr(s, mid0)==NULL) break; 
			m0 = strstr(s+15, mid0);

			if(strlen(sub)<after_mid0) break; 
			if(strstr(m0+1, mid1)==NULL) break; 
			m1 = strstr(m0+1, mid1);

			if(strlen(sub)<after_mid1) break; 
			if(strstr(m1+7, mid2)==NULL) break; 
			m2 = strstr(m1+7, mid2);

			if(strlen(sub)<after_mid2) break;
			if(strstr(m2+2, end)==NULL) break;
			e  = strstr(m2+2, end);

			if(m0-(s+15+1)>0) {
				strncpy(name,s+15,m0-(s+15));
				printf("%s\n",name);
			}
			sub = (e+4);
		}
   }
	fclose(fPointer);
}