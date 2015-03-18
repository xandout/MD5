#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "md5.h"


void parseFile(const char *path){

    unsigned char buffer[13];
    FILE *ptr = fopen(path,"rb");
    if(ptr == NULL){
        printf("The error is - %s\n", strerror(errno));
    }
    fseek(ptr, 0, SEEK_END);
    long fsize = ftell(ptr);
    fseek(ptr, 0, SEEK_SET);
    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, ptr);
    fclose(ptr);

    string[fsize] = 0;

    char md5string[33];
    md5_state_t state;
    md5_byte_t digest[16];
    md5_init(&state);
    md5_append(&state, string, strlen(string));
    md5_finish(&state, digest);
    md5_string(digest, md5string);
    puts(md5string);

}


int main(int argc, char* argv[])
{
    //parseFile("MCPR.exe");
    if(argc < 2)
    {
        printf("\nUsage: %s [string] [-file 'path_to_file']\n", argv[0]);
        return 0;
    }
    else if(!strcmp(argv[1], "-file"))
    {
        parseFile(argv[2]);
    }
    else
    {

        char md5string[33];
        md5_state_t state;
        md5_byte_t digest[16];
        md5_init(&state);
        md5_append(&state, (md5_byte_t *)argv[1], strlen(argv[1]));
        md5_finish(&state, digest);
        md5_string(digest, md5string);
        puts(md5string);

        // Test from Zed
        return 0;

    }

}
