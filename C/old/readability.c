#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main (void) {
    // Prompt the user for some text
    string s = get_string("Text: ");


    // Count the number of letters, words, and sentences in the text
    // Letters     /////////////
    int letters = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
    }
    // printf("L = %d\n", letters);

    // Words     ////////////////
    int words = 0;
    for (int i =0; i < n; i++)
    {
        if (isspace(s[i]))
        {
            words++;
        }
    }
    words++;
    // printf("W = %d\n", words);


    // Sentences    //////////////
    int sentences = 0;
    for (int i =0; i < n; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences++;
        }
    }
    // printf("S = %d\n", sentences);
    // Compute the Coleman-Liau index
    // index = 0.0588 * L - 0.296 * S - 15.8
    //  L = letters, S = sentences
    float l = ((float)letters/words) * 100;
    float sen = ((float)sentences/words) * 100;
    float index = (0.0588 * l) - (0.296 * sen) - (15.8);
    // printf("%f\n", index);


    // Print the grade level after rounding
    int final = round(index);
    // printf("%d\n", final);

    if (final < 1)
    {
        printf("Before Grade 1\n");
    } else if ( final > 16)
    {
        printf("Grade 16+\n");
    } else
    {
        printf("Grade %d\n", final);
    }
}
