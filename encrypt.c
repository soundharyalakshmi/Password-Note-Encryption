



#include<stdio.h>
#include "connect.h"

void encrypt_file(struct COMMAND_INFO info)
{
	FILE *fptr1;
	FILE *fptr2;
	unsigned int hash;
	char ch;
	char key;

	fptr1=fopen(info.input_file,"r");

	if(fptr1 ==NULL)
	{
		printf("Error: Unable to open input file\n");
		return ;
	}

		
	fptr2=fopen(info.output_file,"wb");
	
	if(fptr2 == NULL)
	{
		printf("Error: Unable to open output file\n");
		fclose(fptr1);
		return ;
	}
	
	hash = password_hash(info.password);

	fwrite(&hash,sizeof(hash),1,fptr2);

	key=info.password[0];
	
	
	while(fscanf(fptr1,"%c",&ch) != EOF)
	{
		ch=ch^key;
		fprintf(fptr2,"%c",ch);
	}

	printf("Encryption Successful\n");


	fclose(fptr1);
	fclose(fptr2);
}





