#include <stdio.h>
#include <string.h>

// encryption 
char encryptChar(char ch, int key) {
    if (ch >= 'A' && ch <= 'Z') {
        return 'A' + (ch - 'A' + key) % 26;
    }
    return ch;
}

// decryption 
char decryptChar(char ch, int key) {
    if (ch >= 'A' && ch <= 'Z') {
        return 'A' + (ch - 'A' - key + 26) % 26;
    }
    return ch;
}

int main() {
    char fullName[100];
    int key, i;

    printf("Enter your full name(ALL IN UPPERCASE): ");
    fgets(fullName, sizeof(fullName), stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    printf("Original name: %s", fullName);

    // Encryption
    for (i = 0; i < strlen(fullName); i++) {
        fullName[i] = encryptChar(fullName[i], key);
    }
    printf("Encrypted name: %s", fullName);

    // Decryption
    for (i = 0; i < strlen(fullName); i++) {
        fullName[i] = decryptChar(fullName[i], key);
    }
    printf("Decrypted name: %s", fullName);

    return 0;
}
