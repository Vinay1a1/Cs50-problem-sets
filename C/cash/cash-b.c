#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int cash;
    int coins = 0;
    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash < 1);

    coins += cash/25;
    cash %= 25;

    coins += cash/10;
    cash %= 10;

    coins += cash/5;
    cash %= 5;

    coins += cash/1;
    cash %= 1;

    printf("%i\n", coins);
}
