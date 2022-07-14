#include "OTPcrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char* str = " BABUCHKA YAYA ";

	//str = addSalt(str);
	//fetPrint(str);

	//str = removeSalt(str);
	//fetPrint(str);
	//
	str = encrypt("BABUCHKA", str);
	printf("A\n");
	char* str2 = (char*) malloc(strlen(str) * sizeof(char));
	sprintf(str2, "%s", str);
	str2 = decrypt("BABUCHKA", str2);
	printf("B\n");
	fetPrint(str2);
	//printf("encrypted and salted: %s\n", str);
	//printf("lol");
	//decrypt("BABUCHKA", str);
	//printf("decrypted (still salted): %s\n", str);
	return 0;
}
