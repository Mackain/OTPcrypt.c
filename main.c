#include "OTPcrypt.h"
#include <stdio.h>

int main()
{
	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char* str = " BABUCHKA YAYA \0";
	fetPrint(str);
	addSalt(str);
	printf("lol salt");
	fetPrint(str);
	// removeSalt(str);
	// printf("lol salt was removed: %s\n", str);

	//encrypt("BABUCHKA", str);
	//printf("encrypted and salted: %s\n", str);
	//printf("lol");
	//decrypt("BABUCHKA", str);
	//printf("decrypted (still salted): %s\n", str);
	return 0;
}
