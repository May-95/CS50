#include <stdio.h>
#include <stdlib.h>

int BLOCK_SIZE = 512;
int main(int argc, char *argv[])
{
    // Check correct number of arguments have been passed
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // File that will be opened
    FILE *file = fopen(argv[1], "r");
    // Where data will be read into
    unsigned char buffer[BLOCK_SIZE];
    // Count number of images processed
    int count = 0;
    // File image will be written into
    FILE *img = NULL;
    // Loop through the file
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Checks if we are at the beginning of a new image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // If image file is not empty, we close it so we can start a new file
            if (img != NULL)
            {
                fclose(img);
            }

            // New file name is created from count
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            // Open a new file to write into
            img = fopen(filename, "w");
            // Update image count
            count++;
        }

        // If we are not at the top of the file, we write to the image if it is not null
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    fclose(img);
    fclose(file);
}