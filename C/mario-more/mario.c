#include <stdio.h>
#include <cs50.h>
// Make the less comfortable mario game as described in cs50
//  Declare the main function
int main() {
    int height = 0;
    do {
        printf("Enter your height:");
        scanf("%d", &height);
    }
    while(height < 1 || height > 8);

// This will take the input and store it in a variable height. Now, time to implement the bricks logic
// Main loop

    for (int lines=0; lines < height; lines++)
    //  Prints new line and contains other loops which help in printing hashes and dots
    {
// spaces
            for (int spaces=0; spaces < (height-lines-1); spaces++)
            {
             printf(" ");
            }
// hashes
             for (int hashes = 0; hashes <= lines; hashes++)
                {

                 printf("#");
                 }
// 2 space in between
             printf("  ");

// Inverted pyramid

// hashes
             for (int hashes = 0; hashes <= lines; hashes++)
                {

                 printf("#");
                 }
//  new lines
            printf("\n");

                    }
}
/*So, in a pyramid of right side, the number of spaces is n-l-1 where n is the height of pyramid and l is line no.
So, in the above loop, I need to print the spaces then hashes and then new line.
We can create a simple loop which will print new lines(as we know that height = number of lines).
We will start by printing spaces. For hashes, it will be equal to the number of lines.
*/
