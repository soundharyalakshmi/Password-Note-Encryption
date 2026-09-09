



#include<stdio.h>
#include "connect.h"


void decrypt_file(struct COMMAND_INFO info)
{
	FILE *fptr1;
	FILE *fptr2;
	char ch;
	char key;
	unsigned int stored_hash;
	unsigned int entered_hash;

	fptr1=fopen(info.input_file,"rb");
	
	if(fptr1 == NULL)
	{
		printf("Error: Unable to open the input file\n");
		return ;
	}


	fptr2=fopen(info.output_file,"w");

	if(fptr2 == NULL)
	{
		printf("Error: Unable to open the output file\n");
		fclose(fptr1);
		return ;
	}

	if(fread(&stored_hash,sizeof(stored_hash),1,fptr1) !=1)
	{
		printf("Error: Invalid encryption file\n");
		fclose(fptr1);
		fclose(fptr2);
		return ;
	}

	entered_hash = password_hash(info.password);

	if(stored_hash != entered_hash)
	{
		printf("Invalid Password\n");
		fclose(fptr1);
		fclose(fptr2);
		return ;
	}

	printf("Password Verified\n");

	key=info.password[0];

	while(fscanf(fptr1,"%c",&ch) != EOF)
	{
		ch=ch^key;
		fprintf(fptr2,"%c",ch);
	}

	printf("Decryption Successful\n");
	fclose(fptr1);
	fclose(fptr2);

}

