#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Encryption.h"
#include "Decryption.h"

void Encrypt(char *name, char *pass) {

}
void Decrypt(char *name, char *pass) {

}

int main(int argc, char **argv) {
    if(argc != 4) {
        printf("Incorrect number of arguments\n\nCorrect Usage:\nEncryption: ./Encrypter encrypt [Filename] [Password]\nDecryption: ./Encrypter decrypt [Filename] [Password]\n");
    }
    if(strcmp(argv[1], "encrypt")) {
        char *filename = argv[2];
        char *password = argv[3];
        char resulter[20];
        printf("Verify the following is correct:\n\nFile Name: %s\nPassword: %s\n\nconfirm y/n\n", filename, password);
        scanf("%19s", resulter);
        printf("got '%s", resulter);
        fflush(stdout);
        if(strcmp(resulter, "y")) {
            Encrypt(filename, password);
        } else {
            printf("\nEncryption Terminated\n");
        }
    } else if(strcmp(argv[1], "decrypt")) {
        char *filename = argv[2];
        char *password = argv[3];
        char result;
        printf("Verify the following is correct:\n\nFile Name: %s\nPassword: %s\n\nconfirm y/n\n", filename, password);
        scanf("c", result);
        printf("got '%c'", result);
        fflush(stdout);
        if(result == 'y') {
            Decrypt(filename, password);
        } else {
            printf("\nEncryption Terminated\n");
        }
    } else {
        printf("Invalid use case\n\nCorrect Usage:\nEncryption: ./Encrypter encrypt [Filename] [Password]\nDecryption: ./Encrypter decrypt [Filename] [Password]\n");
    }
}