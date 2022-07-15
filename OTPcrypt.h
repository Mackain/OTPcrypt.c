#pragma once
#if !defined(OTPCRYPT_H)
#define OTPCRYPT_H

/*functions can be void cuz pointers lol*/

char* encrypt(char* encryptionKey, char* input);

char* decrypt(char* decryptionKey, char* input);

int otpRand();

char* addSalt(char* unsaltedString);

char* removeSalt(char* saltedString);

#endif
