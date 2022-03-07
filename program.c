#include "OTPcrypt.h"

int main(){
	char str[] = "old value";
	printf("\n%s\n", str);
	addSalt(str);
	printf("%s\n", str);
	removeSalt(str);

	/*print last char in array defined in header file*/
	printf("%c\n", alpha[62]);
	return 0;
}
