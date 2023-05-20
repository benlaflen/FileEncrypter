#include <stdlib.h>
#include "Encryption.h"
#include "Decryption.h"

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Incorrect number of arguments\n\nCorrect Usage:\nEncryption: ./Encrypter encrypt [Filename] [Password]\nDecryption: ./Encrypter decrypt [Filename] [Password]");
    }
    if(argv[1] == "encrypt") {
        char *filename = argv[2];
        char *password = argv[3];
        char result;
        printf("Verify the following is correct:\n\n")
    } else if(argv[1] == "decrypt") {

    } else {
        printf("Invalid use case\n\nCorrect Usage:\nEncryption: ./Encrypter encrypt [Filename] [Password]\nDecryption: ./Encrypter decrypt [Filename] [Password]");
    }
}