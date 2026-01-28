#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  Code copied from caesar.c. I will edit the logic as basic outline should be the same.
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    };
    int valid = strlen(argv[1]);

    for (int j = 0; j < valid; j++)
    {
        if (!isalpha(argv[1][j]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    if (valid != 26)
    {
        printf("Key must be 26 characters\n");
        return 1;
    };
    string k = argv[1];
    string k1 = k;
    for (int m = 0; m < valid; m++)
    {
        for (int dupcheck = m +1; dupcheck < valid; dupcheck++)
        {
            if (toupper(k1[m]) == toupper(k1[dupcheck]))
            {
                printf("No duplicates allowed\n");
                return 1;
            }
        }
    }
        string input1 = get_string("plaintext: ");

    // Loop to convert it into index //////
    int n = strlen(input1);
    char x[n];
    char c[n];



//  I will figure this out later

    for (int i = 0; i < n; i++)
    {
        if (isupper(input1[i]))
        {
            // we need to replace A with 1st letter of key and so forth

            c[i] = toupper(k[input1[i] - 'A']);
        }
        else if (islower(input1[i]))
        {
            c[i] = tolower(k[input1[i] - 'a']);
        }
        else
        {
            c[i] = input1[i];
        };
    };


    printf("ciphertext: ");
    for (int l = 0; l < n; l++)
    {
        printf("%c", c[l]);
    }
    printf("\n");
}
