#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "OTPcrypt.h"


const char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890";
const int numberOfLetters = 63;

void encrypt(char* encryptionKey, char* input)
{
	addSalt(input);
	printf("got this back: %s\n", input);
	char* encryptedStr = (char*) malloc(sizeof(input) * sizeof(char));

    // for (var i = 0; i < input.length; ++i) {
	for (int i = 0; i < strlen(input); i++)
	{
	//     // special characters not part of the alphabet array are not encrypted.
    //     // So to maker sure the rest of the encryption does not break they are simply passed trough to the output unencrypted.
    //     if (alpha.indexOf(input[i]) == -1) {
    //         output += input[i];
		char* pPosition = strchr(alpha, input[i]);
		if (!pPosition)
		{
			encryptedStr[i] = input[i];
		}
		else
		{
			char curKey = encryptionKey[i % strlen(encryptionKey)];
			char* keyIndex = strchr(alpha, curKey);
			int curCharIndex = (int)(keyIndex - alpha);
			char* strIndex = strchr(alpha, input[i]);
			int curStrIndex = (int)(strIndex - alpha);
			encryptedStr[i] = alpha[(curCharIndex + curStrIndex) % strlen(alpha)];
		}
	}
	strcpy(input, encryptedStr);
}

void decrypt(char* decryptionKey, char* input)
{
	char decryptedStr[10000]; //(char*) malloc(sizeof(input) * sizeof(char));
	for (int i = 0; i < strlen(input); i++)
	{
		char* pPosition = strchr(alpha, input[i]);
		if(!pPosition)
		{
			decryptedStr[i] = input[i];
		}
		else
		{
			char curKey = decryptionKey[i % strlen(decryptionKey)];
			int curCharIndex = strchr(alpha, input[i]) - strchr(alpha, curKey);
			curCharIndex = curCharIndex < 0 ? curCharIndex + strlen(alpha) : curCharIndex;
			decryptedStr[i] = alpha[curCharIndex];
			//printf("haha it is %c \n", alpha[curCharIndex]);
		}
	}
	// remove salt here lol
	removeSalt(decryptedStr);
	printf("haha it done: %s\n", decryptedStr);
	strcpy(input, decryptedStr);
}

int otpRand()
{
	// use this to generate random numbers.
	// it is not perfect, but this way we only have to refactor in one place in the future :)
   	time_t t;

	// getpid gets the process ID and getppid gets the parent process ID
	int seed = (unsigned) time(&t) + (unsigned) clock() + (unsigned) getpid() + (unsigned) getppid() + 414 + 1337;

	srand(seed);

	int r = rand();
	return r;
}

char* addSalt(char* unsaltedString)
{
	// time to add some salt! (yum)
	// find a random character c to start salting.
	int n = otpRand() % numberOfLetters-1;
	char c = alpha[n];
	int unsaltedLen = strlen(unsaltedString);
	int saltedLen = unsaltedLen + n + 2;
	char *saltedString = malloc(saltedLen*sizeof(char)); 

	// add n number of random(ish) characters at the start of the string.
	// where n is the index of c in the alphabet string.
	int i;
	for (i = 0; i < n; i++)
	{
		saltedString[i] = alpha[otpRand() % numberOfLetters];
	}

	strcat(saltedString, unsaltedString);

	// add c to the end of the string
	int penultimateIndex = saltedLen -2;
	saltedString[saltedLen-2] = c;
	saltedString[saltedLen-1] = '\0';
	return saltedString;
}

char* removeSalt(char* saltedString)
{
	// time too remove some salt (thats a lot of sodium)
	// find char c at the end of the string.
	char c = saltedString[(strlen(saltedString)-1)];
	//char* orgStrCpy = (char *) malloc(strlen(saltedString) * sizeof(char));
	//strcpy(orgStrCpy, saltedString);

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
	saltedString[(strlen(saltedString)-1)] = '\0';
	printf("there is %i much salt here\n", n);

	//strcpy(saltedString, &saltedString[n]);
	return &saltedString[n];

	//char unsaltedString[strlen(saltedString)]; //(char*) malloc(strlen(saltedString) * sizeof(char));
	//memcpy(unsaltedString, saltedString, strlen(saltedString)-1);
	//strncpy(unsaltedString, saltedString, strlen(saltedString)-1);

	// remove n number of chars from the start of the string.
	//strcpy(saltedString, &unsaltedString[n]);


	// unsalted output may get a lenght of 0 if an invalid c is used... impostor detected!
	// if so, just return the garbled input and pretend like it works as intended...
	//if(saltedString[0] == '\0')
	//{
	//	strcpy(saltedString, orgStrCpy);
	//}
}

void fetPrint(char* string)
{
	printf("+-------------FETPRINT-----------+\n");
	printf("%s\n", string);
	printf("+--------------------------------+\n");
	printf("length: %lu\n", strlen(string));
	printf("size: %lu bytes\n", sizeof(string));
	printf("+--------------------------------+\n");
	int n = 0;
	for (n; n<strlen(string); n++)
	{
		printf("[%c]", string[n]);
	}
	printf("\n");
	printf("+--------------------------------+\n");
}
