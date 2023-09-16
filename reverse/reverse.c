#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc < 1 || argc > 3)
    {
        printf("Usage ./reverse input.wav output.wav\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file for reading
    // TODO #2
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER head;
    fread(&head, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(head))
    {
        printf("Input is not a WAV file.\n");
        fclose(inptr);
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outptr = fopen(outfile, "wb");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&head, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(head);

    // Write reversed audio to file
    // TODO #8
    uint32_t buffer;
    int a = ftell(inptr);
    int n = 1;
    fseek(inptr, 0, SEEK_END);
    while (ftell(inptr) > a + block_size)
    {
        int x = n * block_size;
        fseek(inptr, -x, SEEK_END);
        fread(&buffer, block_size, 1, inptr);
        fwrite(&buffer, block_size, 1, outptr);
        n++;
    }

    fclose(inptr);
    fclose(outptr);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    int format[4] = {'W', 'A', 'V', 'E'};
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != format[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
}