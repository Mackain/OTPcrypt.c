#pragma once
#if !defined(OTPCRYPT_H)
#define OTPCRYPT_H

/*functions can be void cuz pointers lol*/

void encrypt(char* encryptionKey, char* input);

void decrypt(char* decryptionKey, char* input, char* salt);

int otpRand();

void addSalt(char* unsaltedString);

void removeSalt(char* saltedString);

#endif
