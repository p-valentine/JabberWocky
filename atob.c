#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* atob(char s)
{
	char *binary = malloc(9); // each char is one byte (8 bits) and + 1 at the end for null terminator
	binary[0] = '\0';
		
	for(int j = 7; j >= 0; --j){
		if(s & (1 << j)) {
			strcat(binary,"1");
		} else {
			strcat(binary,"0");
		}
	}	
	return binary;
}



int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;

	if (argc < 3) {
		fprintf(stderr,"Not enough arguments\n");
		exit(1);
	}
	if (!(ifp = fopen(argv[1],"r"))) {
		fprintf(stderr,"Cannot open file %s\n",argv[1]);
		exit(1);
	}
	if (!(ofp = fopen(argv[2],"w"))) {
		fprintf(stderr,"Cannot open file %s\n",argv[2]);
		exit(1);
	}



	int *one;

	fseek(ifp, 0, SEEK_END);
	size_t file_len = ftell(ifp);
	rewind(ifp);
	char *string = (char *)calloc(file_len+1, sizeof(char));
	fread(string, sizeof(char), file_len, ifp);
	string[file_len] = '\0';

	for(int i = 0; i< file_len; i++){
//		char ch;
//		ch = string[i]; 
//		int charValue = ch - '0';
		//	atob(ifp, ofp, string);
		fprintf(ofp, "%s", atob(string[i]));
	}


	//	printf("\n The ASCII value of given character = %d",ch);
	//	printf("\n Binary Value: ");	  
	//	fscanf(ifp)
	//	atob(ifp, ofp, charValue, one);
	fprintf(ofp,"%s", "\n");
	fclose(ifp);
	fclose(ofp);
	return 0;

}
