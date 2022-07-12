#include "OTPcrypt.h"
#include <stdio.h>

int main()
{
	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char* str = " BABUCHKA YAYA ";

	str = addSalt(str);
	fetPrint(str);

	str = removeSalt(str);
	fetPrint(str);
	//encrypt("BABUCHKA", str);
	//printf("encrypted and salted: %s\n", str);
	//printf("lol");
	//decrypt("BABUCHKA", str);
	//printf("decrypted (still salted): %s\n", str);
	return 0;
}
