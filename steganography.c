#include "steganography.h"

void encrypt(char *image_file, char *text_file, char *output_image_file){
    FILE *image = fopen(image_file, "rb"),
        *text = fopen(text_file, "rb");
    if(image == NULL || text == NULL){
        printf("One of the specified input files is not present");
        return;
    }
    int i;
    long int image_length, text_length;

    //reach byte 10
    fseek(image, 10, SEEK_CUR);
    //read position where image starts
    fread(&i, 1, sizeof(int), image);
    fseek(image, 2, SEEK_SET);
    fread(&image_length, 1, sizeof(int), image);
    image_length -= i;
    fseek(text, 0, SEEK_END);
    text_length = ftell(text);

    if((text_length+text_length/4)*8>image_length){
        perror("Text too long for the image to be hidden");
        return;
    }
    strcat(output_image_file, ".bmp");
    FILE *output = fopen(output_image_file, "wb");

    fseek(text, 0, SEEK_SET);
    fseek(image, 0, SEEK_SET);

    for(int j=0;j<i;++j){
        byte b;
        fread(&b, 1, sizeof(byte), image);
        fwrite(&b, 1, sizeof(byte), output);
    }

    while(!feof(image)){
        byte img, txt;
        if(!feof(text)) {
            fread(&txt, 1, sizeof(byte), text);
            byte x = 0x01;
            for(int j=0;j<8;++j){
                fread(&img, 1, sizeof(byte), image);
                img = ((img>>1)<<1) | ((txt & x)>>j);
                x<<=1;
                fwrite(&img, 1, sizeof(byte), output);
                if((j+1)%4==0){
                    fread(&img, 1, sizeof(byte), image);
                    fwrite(&img, 1, sizeof(byte), output);
                }
            }
            fread(&img, 1, sizeof(byte), image);
            fwrite(&img, 1, sizeof(byte), output);
        }else{
            fread(&img, 1, sizeof(byte), image);
            img &= 0xFE;
            fwrite(&img, 1, sizeof(byte), output);
        }
    }
}

void decrypt(char *image_file){
    FILE *encrypted = fopen(image_file, "rb");
    int i;

    //reach byte 10
    fseek(encrypted, 10, SEEK_CUR);
    //read position where image starts
    fread(&i, 1, sizeof(int), encrypted);
    //move to first byte of the image
    fseek(encrypted, i, SEEK_SET);

    //i used to move inside the bits of the byte
    byte output;
    i=0;
    while(!feof(encrypted)) {
        byte b;
        output = 0x00;
        for(int j=0;j<8;++j) {
            fread(&b, 1, sizeof(byte), encrypted);
            output = output | ((b & 0x01) << j);
            if((j+1)%4==0){
                fread(&b, 1, sizeof(byte), encrypted);
            }
        }
        fread(&b, 1, sizeof(byte), encrypted);
        printf("%c", output);
        if(output==0){
            break;
        }
    }
}
