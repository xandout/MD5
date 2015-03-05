#include <stdio.h>
#include <stdlib.h>
#include "md5.h"
#include <errno.h>


void parseFile(const char *path){

    unsigned char buffer[13];
    FILE *ptr = fopen(path,"rb");
    if(ptr == NULL){
        printf("The error is - %s\n", strerror(errno));
    }

//    char md5string[33];
//        md5_state_t state;
//        md5_byte_t digest[16];
//        md5_init(&state);
//        md5_append(&state, (md5_byte_t *)buffer, strlen(buffer));
//        md5_finish(&state, digest);
//        md5_string(digest, md5string);
//        puts(md5string);

}

int main(int argc, char* argv[])
{
    //parseFile("MCPR.exe");
    if(argc < 2)
    {
        printf("\nUsage: %s <string to hash>", argv[0]);
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


        return 0;

    }

}
