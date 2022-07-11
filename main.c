#include "OTPcrypt.h"
#include <stdio.h>

int main()
{
	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char* str = " BABUCHKA YAYA \0";
	//fetPrint(str);

	//printf("%i\n",otpRand() % 63);

	//printf("lol salt");
	fetPrint(addSalt(str));

	//encrypt("BABUCHKA", str);
	//printf("encrypted and salted: %s\n", str);
	//printf("lol");
	//decrypt("BABUCHKA", str);
	//printf("decrypted (still salted): %s\n", str);
	return 0;
}
