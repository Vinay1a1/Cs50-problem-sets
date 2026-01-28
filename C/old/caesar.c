#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int index[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12,
//                13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    };
    int valid = strlen(argv[1]);

    for (int j = 0; j < valid; j++)
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string input1 = get_string("plaintext: ");

    // Loop to convert it into index //////
    int n = strlen(input1);
    char x[n];
    char c[n];
    int k = atoi(argv[1]);

    for (int i = 0; i < n; i++)
    {
        if (isupper(input1[i]))
        {
            x[i] = input1[i] - 'A';
            c[i] = (x[i] + k) % 26;
            c[i] += 'A';
        }
        else if (islower(input1[i]))
        {
            x[i] = input1[i] - 'a';
            c[i] = (x[i] + k) % 26;
            c[i] += 'a';
        }
        else
        {
            c[i] = input1[i];
        };
    };
    //  Why need three separate loops when it's better to handle everything in 1.

    // //  Loop to add the key
    //     for (int i= 0; i < n; i++ )
    //     {
    //         c[i] = (x[i] + k) % 26;
    //     };

    // //  Loop to convert back into letters //////

    //     for (int i= 0; i < n; i++ )
    //     {
    //         if (c[i]+'A' <= 90)
    //         {
    //             c[i]+='A';
    //         } else if (c[i] + 'A' > 90)
    //         {
    //             c[i]+='a';
    //         };
    //     }
    printf("ciphertext: ");
    for (int l = 0; l < n; l++)
    {
        printf("%c", c[l]);
    }
    printf("\n");
}
