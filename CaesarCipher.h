#ifndef PARADIGMS_PA4_CAESARCIPHER_H
#define PARADIGMS_PA4_CAESARCIPHER_H
#include <windows.h>

typedef char* (*encrypt_ptr_t)(char*, int);
typedef char* (*decrypt_ptr_t)(char*, int);

class CaesarCipher {
public:
    CaesarCipher();
    ~CaesarCipher();
    encrypt_ptr_t getEncryptFunc();
    decrypt_ptr_t getDecryptFunc();
private:
    encrypt_ptr_t encryptPtr;
    decrypt_ptr_t decryptPtr;
    HINSTANCE handle;
};


#endif //PARADIGMS_PA4_CAESARCIPHER_H
