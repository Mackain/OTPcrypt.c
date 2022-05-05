#include "OTPcrypt.h"
#include <stdio.h>

int main(){
	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char str[100] = "old value";
	addSalt(str);
	printf("lol salt was added: %s\n", str);
	//removeSalt(str);
	return 0;
}
