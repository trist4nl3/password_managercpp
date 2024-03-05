#include <string>

bool aesEncrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *ciphertext);
bool aesDecrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *plaintext);
