#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


const char alpha[63] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void encrypt(char* encryptionKey, char* input) {

}

void decrypt(char* decryptionKey, char* input, char* salt) {

}

void addSalt(char* unsaltedString) {
	strcpy(unsaltedString, "lol new  value");

	// initialize random thingy.
	srand(time(NULL));

	// time to add some salt! (yum)
	// add random(ish) char c from the alphabet array to the end of the input.
	int n = rand() % sizeof alpha;
	char c = alpha[n];
	printf("\nwill add %c\n", c);

	// add n number of random(ish) characters at the start of the input.
	// where n is the index of c in the alphabet array.

	// TODO use malloc to make new string the size of unsaltedString + n + 1
	// then do all the magic stuff to it
	// then use strcpy to replace unsaltedString with the new string.
}

void removeSalt(char* saltedString) {
	strcpy(saltedString, "lol doesnt work yet");
	// time too remove some salt (thats a lot of sodium)
	// find integer n at the end of the input

	//remove n number of characters at the start of the input

	// unsalted output may get a lenght of 0 if an invalid c is used... impostor detected!
	// if so, just return the garbled output and pretend like it works as intended...
}
