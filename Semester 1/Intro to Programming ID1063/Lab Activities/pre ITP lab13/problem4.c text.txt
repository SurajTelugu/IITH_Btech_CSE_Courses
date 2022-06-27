#include<stdio.h>
#include<stdlib.h>

int main()
{
	char inputFilename[30]="redSanta.bmp",outputFilename[30]="redSantaCopy.bmp";
	char headerInfo[55];
	unsigned char R,G,B;
	FILE *ptr,*opt;


	ptr=fopen(inputFilename,"rb");	

	if (ptr==NULL)
	{
		printf("\n Open Error");
		return 1;				
	}


	opt=fopen(outputFilename,"wb");
	if (opt==NULL){
        printf("Open Error");
        return 1;
	}

	fread(headerInfo,54,1,ptr);
	fwrite(headerInfo,54,1,opt);

	while(!feof(ptr))
	{
		B=fgetc(ptr);
		G=fgetc(ptr);
		R=fgetc(ptr);

		fputc(B,opt);
		fputc(G,opt);
		fputc(R,opt);

	}
	fclose(opt);
	fclose(ptr);

	printf("Success!");

	return EXIT_SUCCESS;
}
