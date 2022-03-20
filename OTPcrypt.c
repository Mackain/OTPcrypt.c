#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


const char alpha[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890";

void encrypt(char* encryptionKey, char* input) {

}

void decrypt(char* decryptionKey, char* input, char* salt) {

}

void addSalt(char* unsaltedString) {

	// initialize random thingy.
	srand(time(NULL));

	// time to add some salt! (yum)
	// find a random character c to start salting.
	int n = rand() % (sizeof alpha / sizeof(alpha[0]));
	char c = alpha[n];

	int unsaltedSize = sizeof unsaltedString * sizeof(char);
	int saltedSize = unsaltedSize + n + 1;
	char* saltedString = (char*) malloc(saltedSize);

	// add n number of random(ish) characters at the start of the string.
	// where n is the index of c in the alphabet string.
	int i;
	for (i = 0; i < n; i++)
	{
		saltedString[i] = alpha[rand() % (sizeof alpha / sizeof(char))];
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
	
	printf("\n%c\n", c);
	// calculate n, the index of C in the alphabet string.
	int i;
	char* e;
	printf("\n%s\n", alpha);
	e = strchr(alpha, c);
	printf("-----------------------------------\n");
	printf("\n%s\n", e);
	printf("-----------------------------------\n");
	// i = (int)(e - alpha);
	// printf("\n%i\n", i);

	// remove n number of characters at the start of the input

	// remove c from the end of the string.

	// unsalted output may get a lenght of 0 if an invalid c is used... impostor detected!
	// if so, just return the garbled output and pretend like it works as intended...
}
