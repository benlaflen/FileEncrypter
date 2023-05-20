#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char password, const char fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Unable to open file: %s\n", fileName);
        return;
    }

    // Get the file name (without extension) as the seed for the random number generator
    char seed = strdup(password);
    char dot = strrchr(seed, '.');
    if (dot != NULL) {
        dot = '\0';
    }

    // Seed the random number generator
    srand(hash(seed));
    fclose(file);
    file = fopen(fileName, "wb");
    // Create an output file with ".encrypted" extension
    /* char outputFileName[256]; */
    /* snprintf(outputFileName, sizeof(outputFileName), "%s.encrypted", fileName); */
    /* FILEoutputFile = fopen(outputFileName, "wb"); */
    /* if (outputFile == NULL) { */
    /*     printf("Unable to create output file: %s\n", outputFileName); */
    /*     fclose(file); */
    /*     return; */
    /* } */

    // Read and encrypt the content byte by byte
    int byte;
    while ((byte = fgetc(fileName)) != EOF) {
        // Generate a random key between 1 and 255
        int key = rand() % 255 + 1;

        // XOR the byte with the key to encrypt
        byte = byte ^ key;

        // Write the encrypted byte to the output file
        fputc(byte, file);
    }

    printf("File encrypted successfully. Output file: %s\n", fileName);

    fclose(file);
    free(seed);
}

/*int main() {
    const char *fileName = "file.txt";
    encryptFile(fileName);

    return 0;
}*/
