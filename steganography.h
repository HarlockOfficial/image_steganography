#ifndef STEGANOGRAFIA_STEGANOGRAPHY_H
#define STEGANOGRAFIA_STEGANOGRAPHY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char byte;
void encrypt(char *image_file, char *output_image_file, char *text_file);
void decrypt(char *image_file, char *output_file);
#endif //STEGANOGRAFIA_STEGANOGRAPHY_H
