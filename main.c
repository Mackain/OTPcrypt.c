#include "OTPcrypt.h"
#include <stdio.h>

int main()
{
	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char str[100] = "A";
	// addSalt(str);
	// printf("lol salt was added: %s\n", str);
	// removeSalt(str);
	// printf("lol salt was removed: %s\n", str);
	encrypt("A", str);
	printf("%s\n", str);
	return 0;
}
