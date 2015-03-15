#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "md5.h"

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
   //     parseFile(argv[2]);
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
