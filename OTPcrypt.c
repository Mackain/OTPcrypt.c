#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


const char alpha[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890\0";

void encrypt(char* encryptionKey, char* input) {

}

void decrypt(char* decryptionKey, char* input, char* salt) {

}

int otpRand() {
	// use this to generate random numbers.
	// it is not perfect, but this way we only have to refactor in one place in the future :)

	srand(time(NULL));
	int r = rand();
	return r;
}

void addSalt(char* unsaltedString) {
	// initialize random thingy.
	//srand(time(NULL));

	// time to add some salt! (yum)
	// find a random character c to start salting.
	int n = otpRand() % (sizeof alpha / sizeof(alpha[0]));
	char c = alpha[n];

	int unsaltedSize = sizeof unsaltedString * sizeof(char);
	int saltedSize = unsaltedSize + n + 1;
	char* saltedString = (char*) malloc(saltedSize);

	// add n number of random(ish) characters at the start of the string.
	// where n is the index of c in the alphabet string.
	int i;
	for (i = 0; i < n; i++)
	{
		saltedString[i] = alpha[otpRand() % (sizeof alpha / sizeof(char))];
	}
	//printf("\n------------------\n%s", saltedString);
	//printf("\n------------------\n");
	strcat(saltedString, unsaltedString);
	// add c to the end of the string.
	saltedString[saltedSize] = c;
	strcpy(unsaltedString, saltedString);
}

void removeSalt(char* saltedString) {
	// time too remove some salt (thats a lot of sodium)
	// find char c at the end of the string.
	char c = saltedString[(strlen(saltedString)-1)];
	char* orgStrCpy = (char*) malloc(sizeof saltedString * sizeof(char));
	strcpy(orgStrCpy, saltedString);

	printf("\n%c\n", c);
	// calculate n, the index of C in the alphabet string.
	int i;
	char* e;
	e = strchr(alpha, c);

	printf("\n%s\n", e);

	i = e - alpha;

	printf("\n%i\n", i);

	// remove n number of characters at the start of the input

	char* unsaltedString = (char*) malloc(sizeof saltedString * sizeof(char));
	strcpy( unsaltedString, &saltedString[i]);
	//printf("\n%s\n", &saltedString[i]);
	printf("\n%s\n", unsaltedString);
	// remove c from the end of the string.

	// unsalted output may get a lenght of 0 if an invalid c is used... impostor detected!
	// if so, just return the garbled input and pretend like it works as intended...
	if(saltedString[0] == '\0')
	{
		strcpy(saltedString, orgStrCpy);
	}
}

