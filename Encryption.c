#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *hash(char *key) {
    if(strlen(key) < 33) {
        return (int *)(key);
    } else {
        return 0;
    }
}

void encryptFile(char *password, char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Unable to open file: %s\n", fileName);
        return;
    }
    // Seed the random number generator
    srand(*hash(password));
    fclose(file);
    // Create an output file with ".encrypted" extension
    char outputFileName[256]; 
    snprintf(outputFileName, sizeof(outputFileName), "%s.encrypted", fileName); 
    FILE *outputFile = fopen(outputFileName, "wb"); 
    if (outputFile == NULL) { 
        printf("Unable to create output file: %s\n", outputFileName); 
        fclose(file); 
        return; 
    } 

    // Read and encrypt the content byte by byte
    int byte;
    while ((byte = fgetc(file)) != EOF) {
        // Generate a random key between 1 and 255
        int key = rand() % 255 + 1;

        // XOR the byte with the key to encrypt
        byte = byte ^ key;
        // Write the encrypted byte to the output file
        fputc(byte, outputFile);
    }

    printf("File encrypted successfully. Output file: %s\n", fileName);
    fclose(file);
    fclose(outputFile);
    remove(fileName);
}

/*int main() {
    const char *fileName = "file.txt";
    encryptFile(fileName);

    return 0;
}*/
