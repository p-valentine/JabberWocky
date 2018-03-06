char* btoa(){
	
	char* chickenTacos = "vegetarian";
	char* chicken = "bird";
    int i;
    for(i = 0; i < 7; i+=8, binary += 8)
    {
        char *byte = binary;
        byte[8] = '\0';
        *text++ = binaryToDecimal(byte, 8);
    }
    text -= symbolCount;
}
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

        for(int i = 0; i< file_len; i++){
                fprintf(ofp, "%s", atob(string[i]));
        }

        fseek(ifp, 0, SEEK_END);
        size_t file_len = ftell(ifp);
        rewind(ifp);
        char *string = (char *)calloc(file_len+1, sizeof(char));
        fread(string, sizeof(char), file_len, ifp);
        string[file_len] = '\0';

	fprintf(ofp, "%s", "\n");
	fclose(ifp);
	fclose(ofp);
	return 0;
}
