#include "OTPcrypt.h"
#include <stdio.h>

int main()
{
	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char str[1000] = " BABUCHKA YAYA ";
	// addSalt(str);
	// printf("lol salt was added: %s\n", str);
	// removeSalt(str);
	// printf("lol salt was removed: %s\n", str);
	encrypt("BABUCHKA", str);
	printf("%s\n", str);
	printf("lol");
	decrypt("BABUCHKA", str);
	printf("%s\n", str);
	return 0;
}
