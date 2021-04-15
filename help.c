#include "help.h"

void help(char *executable_name){
    printf("Usage %s [OPTION] [PATHS]\nAvailable options are:\n", executable_name);
    printf("\t1\t\tEncrypt the content of file inside an image, the ordered required [PATHS] is image file in bmp format, then the following NOT mandatory file can be specified output file name without extension and text file in txt format\n");
    printf("\t2\t\tDecrypt the content of file and retrieve the text, the ordered required [PATHS] is the image file in bmp format and the NOT mandatory name of the output file\n");
}