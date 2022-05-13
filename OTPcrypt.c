#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


const char alpha[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890\0";
const int numberOfLetters = 63;

void encrypt(char* encryptionKey, char* input)
{

}

void decrypt(char* decryptionKey, char* input, char* salt)
{

}

int otpRand()
{
	// use this to generate random numbers.
	// it is not perfect, but this way we only have to refactor in one place in the future :)
   	time_t t;

	int seed = (unsigned) time(&t) + (unsigned) clock();

	srand(seed);

	int r = rand();
	return r;
}

void addSalt(char* unsaltedString)
{
	// time to add some salt! (yum)
	// find a random character c to start salting.
	int n = otpRand() % (sizeof alpha / sizeof(alpha[0]));
	char c = alpha[n];
	int unsaltedSize = sizeof unsaltedString;
	int saltedSize = unsaltedSize + (n * sizeof(char) + (2 * sizeof(char)));
	char* saltedString = (char*) malloc(saltedSize);

	// add n number of random(ish) characters at the start of the string.
	// where n is the index of c in the alphabet string.
	int i;
	for (i = 0; i < n; i++)
	{
		saltedString[i] = alpha[otpRand() % numberOfLetters];
		// printf("lol adding: %c on index %i\n", saltedString[i], i);
	}
	strcat(saltedString, unsaltedString);

	// add c to the end of the string.
	int penultimateIndex = saltedSize / sizeof(char) -1;
	saltedString[penultimateIndex] = c;
	saltedString[penultimateIndex+1] = '\0';
	strcpy(unsaltedString, saltedString);
}

void removeSalt(char* saltedString)
{
	printf("trololo\n");
	// time too remove some salt (thats a lot of sodium)
	// find char c at the end of the string.
	char c = saltedString[(strlen(saltedString)-1)];
	char* orgStrCpy = malloc(strlen(saltedString) * sizeof(char));
	strcpy(orgStrCpy, saltedString);

	printf("THE KEY IS %c\n", c);
	// calculate n, the index of C in the alphabet string.
	int n = 0;
	for (n; n < numberOfLetters; n++)
	{
		if(alpha[n] == c)
		{
			break;
		}
	}

	// remove c from from the end of the string
	char* unsaltedString = (char*) malloc(strlen(saltedString) * sizeof(char));
	strncpy(unsaltedString, saltedString, strlen(saltedString)-1);

	// remove n number of chars from the start of the string.
	strcpy(saltedString, &unsaltedString[n]);
	// unsalted output may get a lenght of 0 if an invalid c is used... impostor detected!
	// if so, just return the garbled input and pretend like it works as intended...
	if(saltedString[0] == '\0')
	{
		strcpy(saltedString, orgStrCpy);
	}
}

