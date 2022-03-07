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
}

void removeSalt(char* saltedString) {
  strcpy(saltedString, "lol doesnt work yet");
}
