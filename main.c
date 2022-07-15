#include "OTPcrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

	// if arg1 == -e ? encryp : decrypt
	if (argc < 4)
	{
		printf("Too few arguments\n");
		return 1;
	}
	if (argc > 4)
	{
		printf("Too many arguments\n");
		return 1;
	}
	if (strcmp(argv[1], "-e") == 0)
	{
		printf("%s\n", encrypt(argv[2], argv[3]));
	}

	else if (strcmp(argv[1], "-d") == 0)
	{
		printf("%s\n", decrypt(argv[2], argv[3]));
	}
	else
	{
		printf("Invalid syntax\n");
		return 1;
	}

	return 0;
}
