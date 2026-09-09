


#include "connect.h"

unsigned int password_hash(const char *password)
{

	unsigned int hash = 2765;
	int i;

	for(i=0;password[i] != '\0';i++)
		hash =((hash << 5)+ hash) ^ password[i];

	return hash;
}
