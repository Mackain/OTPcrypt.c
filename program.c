#include "OTPcrypt.h"
#include <stdio.h>

int main(){
	char str[20] = "old value";
	printf("\n%s\n", str);
	addSalt(str);
	printf("%s\n", str);
	// removeSalt(str);
	return 0;
}
