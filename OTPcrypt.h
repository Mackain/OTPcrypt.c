#pragma once
#include <stdio.h>
#include <string.h>


#if !defined(OTPCRYPT_H)
#define OTPCRYPT_H

const char alpha[63] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

/*functions can be void cuz pointers lol*/

/*void encrypt(char* encryptionKey, char* input);

void decrypt(char* decryptionKey, char* input, char* salt);*/

void addSalt(char* unsaltedString);

void removeSalt(char* saltedString);

/*void generatePseudoRandomKey(char* key);

void generateKeyFromSeed(char* key, char* seed);*/

#endif
