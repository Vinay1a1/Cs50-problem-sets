#include <stdio.h>
#include <cs50.h>
void print_row(int bricks, int spaces);

int main(void)
{
    int n;
    do
    {
       n = get_int("No. of boxes: ");
    }
    while (n<1);

    for (int i = 0; i < n; i++)
    {
        print_row(i + 1, n-i-1);
    }
}

void print_row(int bricks, int spaces)
{
    for (int i=0; i<spaces; i++)
    {
        printf(" ");
    }
    for (int i=0; i < bricks; i++)
    {
        printf("#");
    }

    printf("  ");

    for (int i=0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}


