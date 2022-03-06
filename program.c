#include "OTPcrypt.h"

int main(){
	char str[] = "old value";
	printf("\n%s\n", str);
	addSalt(str);
	printf("\n%s\n", str);
	return 0;
}
