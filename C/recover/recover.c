#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Take only 1 command line argument
    if (argc != 2)
        {printf("Usage: ./recover filename\n");
        return 1;}
    // Open a file
    FILE *input = fopen(argv[1], "r");
    // Return 1 if the file can't be opened
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    // Read from the file and store it in an array
    // Check if the first four bytes are 0xff 0xd8 0xff. Fourth can be 0xe0...0xef
    FILE *output = NULL;
    uint8_t arr[512];
    int counter = 0;
    while (fread(arr, 512, 1, input))
    {
        if ((arr[0] == 0xff) && (arr[1] == 0xd8) && (arr[2] == 0xff) && (arr[3] & 0xf0)  == 0xe0)
        {
    // Check if file is already opened. Close it
             if (output != NULL)
              fclose(output);
            // Create an array filename and store the filename there. 8 are needed because
            // 3 digits + . + jpg + terminator = 8)
            char filename[8];
            // print the filename to string and open the file. Increment the counter for next file.
            sprintf(filename, "%03i.jpg", counter);
            output = fopen(filename, "w");
            counter++;
        }
        // Write to a file if it's opened
        if(output != NULL)
        fwrite(arr, 512, 1, output);
        // This loop repeats till it finds a header at which point the first if block becomes active
        // again
    }
    if (output != NULL)
    {
    fclose(output);
    }
    fclose(input);
    // Close the output and input.
}
