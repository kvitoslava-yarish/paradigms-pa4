#include "CaesarCipher.h"
#include <windows.h>
#include "iostream"

CaesarCipher::CaesarCipher()
{
    handle = LoadLibrary(TEXT("C:\\Users\\kvita\\CLionProjects\\paradigms-pa-3\\cryptography.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
    {
        FreeLibrary(handle);
        throw std::runtime_error("Library not found");
    }

    encryptPtr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
    if (encryptPtr == nullptr)
    {
        FreeLibrary(handle);
        throw std::runtime_error("Encrypt function not found");
    }

    decryptPtr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
    if (decryptPtr == nullptr)
    {
        FreeLibrary(handle);
        throw std::runtime_error("Decrypt function not found");

    }

}
encrypt_ptr_t CaesarCipher:: getEncryptFunc()
{
    return encryptPtr;
}

decrypt_ptr_t CaesarCipher:: getDecryptFunc()
{
    return decryptPtr;
}

CaesarCipher ::~CaesarCipher() {
    FreeLibrary(handle);
}