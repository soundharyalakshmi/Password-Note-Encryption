

typedef enum
{
	ENCRYPT,
	DECRYPT
}EMode;

struct COMMAND_INFO
{
	char input_file[100];
	char output_file[100];
	char password[9];
	EMode mode;
};

unsigned int password_hash(const char *password);
