#include "OTPcrypt.h"

int main(){
	char str[] = "old value";
	printf("\n%s\n", str);
	addSalt(str);
	printf("%s\n", str);
	removeSalt(str);
	printf("%s\n", str);
	return 0;
}
