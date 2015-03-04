#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("\nUsage: %s <string to hash>", argv[0]);
        return 0;
    }
    else
    {

        char md5string[33];
        md5_state_t state;
        md5_byte_t digest[16];
        char hex_output[16*2 + 1];
        md5_init(&state);
        md5_append(&state, (md5_byte_t *)argv[1], strlen(argv[1]));
        md5_finish(&state, digest);
        md5_string(digest, md5string);
        puts(md5string);


        return 0;

    }

}
