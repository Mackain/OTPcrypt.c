#include "OTPcrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

	// if arg1 == -e ? encryp : decrypt


	// this string must always have enough memory for its lenght + the alphabetstrings lenght +1
	char* str = " BABUCHKA YAYA ";
	str = decrypt("BABUCHKA", str);
	printf("A\n");



	//char* str2 = (char*) malloc(strlen(str) * sizeof(char));
	//sprintf(str2, "%s", str);
	//str2 = decrypt("BABUCHKA", str2);
	//printf("B\n");
	//fetPrint(str2);

	return 0;
}
