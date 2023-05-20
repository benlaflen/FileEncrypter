#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Encryption.h"

void Decrypt(char *name, char *pass) {

}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Incorrect number of arguments\n\nCorrect Usage:\n./Encrypter [Filename] [Password]\n");
        return 1;
    }
    char resulter[2];
    char *filename = argv[1];
    char *password = argv[2];
    printf("Verify the following is correct:\n\nFile Name: %s\nPassword: %s\n\nconfirm y/n\n", filename, password);
    scanf("%1s", resulter);
    fflush(stdout);
    if(!strcmp(resulter, "y")) {
        encryptFile(password, filename);
    } else {
        printf("\nEncryption Terminated\n");
    }
}