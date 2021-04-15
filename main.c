#include <stdio.h>

#include "steganography.h"
#include "help.h"


//TODO check for file format
int main(int argc, char **argv) {
    if(argc < 2){
        help(argv[0]);
        return 1;
    }
    long choice = strtol(argv[1],NULL,10);
    if (choice == 1) {
        if(argc == 5) {
            encrypt(argv[2], argv[3], argv[4]);
        }else if(argc == 4){
            encrypt(argv[2], argv[3], NULL);
        }else if(argc == 3){
            encrypt(argv[2], NULL, NULL);
        }else{
            help(argv[0]);
            return 3;
        }
    } else if (choice == 2) {
        if(argc == 3) {
            decrypt(argv[2], NULL);
        }else if(argc == 4){
            decrypt(argv[2], argv[3]);
        }else{
            help(argv[0]);
            return 3;
        }
    } else{
        printf("Invalid option %ld used, try %s with no parameters to see the available options", choice, argv[0]);
        return 2;
    }
    return 0;
}
