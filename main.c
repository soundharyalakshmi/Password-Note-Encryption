//This is the main.c file which is used to choose encryption or decryption in command line arguments


#include<stdio.h>
#include<string.h>
#include "connect.h"  //connect main.c and encrypt.c and decrypt.c

void encrypt_file(struct COMMAND_INFO info);
void decrypt_file(struct COMMAND_INFO info);

int main(int argc, char *argv[])
{
	struct COMMAND_INFO info;
	if(argc == 5)		
	{
		if(strcmp(argv[1],"-e") == 0)
		{
			printf("Encryption selected\n");
			info.mode=ENCRYPT;
			//printf("%d\n",info.mode);
		}
		else if(strcmp(argv[1],"-d") == 0)
		{
			printf("Decryption selected\n");
			info.mode=DECRYPT;
			//printf("%d\n",info.mode);
		}
		else
		{
			printf("invalid option\n");
			return 1;
		}

		strcpy(info.input_file, argv[2]);
		//printf("%s\n",info.input_file);

		strcpy(info.output_file, argv[3]);
		//printf("%s\n",info.output_file);

		strcpy(info.password, argv[4]);
	//	printf("%s\n",info.password);

		if(strlen(info.password) !=8)
		{
			printf("Password must be exactly 8 characters\n");
			return 1;
		}

		if(info.mode == ENCRYPT)
		{
			encrypt_file(info);
		//	printf("Calling decryption function\n");
		}
		else if(info.mode == DECRYPT)
		{
			decrypt_file(info);
		//	printf("Calling decryption function\n");
		}
	}
	else
	{
		printf("Error in Argument(MISSING ARGUMENT)\n");
		return 1;
	}
	return 0;
}



