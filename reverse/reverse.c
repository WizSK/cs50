#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

typedef u_int8_t BYTE;

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1],"r");
    if (input == NULL)
    {
        printf("Error: File %s not found\n", argv[1]);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header,sizeof(WAVHEADER), 1, input);


    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Error: input file is not a WAV file\n");
        return 1;
    }
    
    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Error: could not open file %s\n", argv[2]);
        // closing the open file
        fclose(input);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);


    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
    int size = get_block_size(header);
    
    // this is fa byte so 8 x 4 = ??
    BYTE buff[size];
    
    //seeking to the end and backing up 
    fseek(input, - (size * 8), SEEK_END);
    // printf("%ld\n", ftell(input));
    printf("%ld\n", ftell(output));

    while (ftell(input) - (8 * size) > 44)
    {
        fread(buff, sizeof(BYTE), size, input);
        printf("%ld ", buff[0]);
        // printf("%ld\n", ftell(input));
        fwrite(buff, sizeof(BYTE), size, output);
        fseek(input, -(size * 8 * 2), SEEK_CUR);
        // printf("%ld\n", ftell(input));
    }
    // fseek(input, -(size * 8), SEEK_CUR);
    printf("%ld\n", ftell(input));
    // while (ftell(input) - size < 44)
    // {
    //     fread(buff, size, 1, input);
    //     fwrite(buff, size, 1, output);
    //     fseek(input, - size, SEEK_CUR);
    // }
    // closing files 
    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    char frmt[] = "WAVE";
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != frmt[i])
            return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
}
