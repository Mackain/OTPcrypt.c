#include <stdio.h>
#include <string.h>

void addSalt(char* unsaltedString) {
  strcpy(unsaltedString, "lol new  value");
}

void removeSalt(char* saltedString) {
  strcpy(saltedString, "lol doesnt work yet");
}
