#include <stdio.h>
#include <cs50.h>

int main() {
    char name[20];
    printf("What's your name?");
    scanf("%s", name);
    printf("hello, %s!\n", name);
    return 0;
}
