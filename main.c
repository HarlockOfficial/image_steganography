#include <stdio.h>

#include "steganography.h"


//TODO check for file format
//TODO add stdin for encrypt text input
//TODO add file possibility for decrypt output
int main(int argc, char **argv) {
    if(argc < 2){
        printf("Usage %s [OPTION] [PATHS]\nAvailable options are:\n", argv[0]);
        printf("\t1\t\tEncrypt the content of file inside an image, the ordered required [PATHS] are image file in bmp format, text file in txt format, output file name without extension\n");
        printf("\t2\t\tDecrypt the content of file and retrieve the text, the ordered required [PATHS] are image file in bmp format\n");
        return 1;
    }
    long choice = strtol(argv[1],NULL,10);
    if (choice == 1) {
        if(argc != 5){
            printf("Usage %s [OPTION] [PATHS]\nAvailable options are:\n", argv[0]);
            printf("\t1\t\tEncrypt the content of file inside an image, the ordered required [PATHS] are image file in bmp format, text file in txt format, output file name without extension\n");
            printf("\t2\t\tDecrypt the content of file and retrieve the text, the ordered required [PATHS] are image file in bmp format\n");
            return 3;
        }
        encrypt(argv[2], argv[3], argv[4]);
    } else if (choice == 2) {
        if(argc != 3){
            printf("Usage %s [OPTION] [PATHS]\nAvailable options are:\n", argv[0]);
            printf("\t1\t\tEncrypt the content of file inside an image, the ordered required [PATHS] are image file in bmp format, text file in txt format, output file name without extension\n");
            printf("\t2\t\tDecrypt the content of file and retrieve the text, the ordered required [PATHS] are image file in bmp format\n");
            return 3;
        }
        decrypt(argv[2]);
    } else{
        printf("Invalid option %ld used, try %s with no parameters to see the available options", choice, argv[0]);
        return 2;
    }
    return 0;
}
