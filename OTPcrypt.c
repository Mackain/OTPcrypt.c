#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char* encryptionKey, char* input) {

}

void decrypt(char* decryptionKey, char* input, char* salt) {

}

void addSalt(char* unsaltedString) {
	strcpy(unsaltedString, "lol new  value");

	// Totaly unnessessary as usual, but hey, I did malloc and free!
	size_t len = strlen(unsaltedString);

	char *tempSaltedString = malloc(len + 2);
	strcpy(tempSaltedString, unsaltedString);
	tempSaltedString[len] = 'q';
	tempSaltedString[len + 1] = '\0';
	strcpy(unsaltedString, tempSaltedString);
	free(tempSaltedString);

	// time to add some salt! (yum)
	// add random(ish) char c from the alphabet array tp the end of the input.

	// add n number of random(ish) characters at the start of the input.
	// where n is the index of c in the alphabet array.
}

void removeSalt(char* saltedString) {
	strcpy(saltedString, "lol doesnt work yet");
	// time too remove some salt (thats a lot of sodium)
	// find integer n at the end of the input

	//remove n number of characters at the start of the input

	// unsalted output may get a lenght of 0 if an invalid c is used... impostor detected!
	// if so, just return the garbled output and pretend like it works as intended...
}
