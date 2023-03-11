#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef u_int8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usages: ./recover IMAGE\n");
        return 1;
    }
    // open the IMAGE file or the raw file
    FILE *raw = fopen(argv[1], "r");
    // handle error
    if (raw == NULL)
    {
        printf("Error: couldn't open file %s\n", argv[1]);
        return 1;
    }


    BYTE buffer[BLOCK_SIZE];
    int idx = 0;
    char name_buff[8];
    FILE *write;
    while (fread(buffer, 1, BLOCK_SIZE, raw) == BLOCK_SIZE)
    {
        // printf("hi while\n");
        // printf("%i\n", buffer[0]);
        // printf("%p\n", buffer[3]);
        // printf("hi while\n");

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // if 1st pic is done then write it and
            // if the parent condition runs do
            // run it cause it is a new mail
            if (idx > 0) {
            fclose(write);
            }
            sprintf(name_buff, "%03i.jpg", idx++);
            write = fopen(name_buff, "w");
            if (write == NULL)
                    return -1;
            fwrite(buffer, 1, BLOCK_SIZE, write);

        }
        else 
        {

            if (idx == 0)
               continue;
            fwrite(buffer, 1, BLOCK_SIZE, write);
        }

    }
    printf("closing files\n");
    fclose(write);
    fclose(raw);
    return 0;
 
}
