#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int scores(string compute);

int main(void) {
    // Define the number of points
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    //  Get 1st user input
    string player1 = get_string("Player 1: ");


    //  Get 2nd user input
    string player2 = get_string("Player 2: ");

   // Convert lowercase to upper using toupper
    for(int i=0,n = strlen(player1); i <= n; i++){
    player1[i] = toupper(player1[i]);}

    for(int i=0,n = strlen(player2); i <= n; i++){
    player2[i] = toupper(player2[i]);}

    // Calculate the points

    int ps1 = scores (player1);

    int ps2 = scores (player2);

    // Compare and print results
    if (ps1 > ps2)
    {
        printf("Player 1 wins!\n");
    } else if (ps2 > ps1)
    {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    };

}
// Function to return score. Subtracting A(65) should lead to the index value which can then be used for score
int scores(string compute)
    {
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    for (int i=0, n = strlen(compute); i < n; i++)
        {
          if (isupper(compute[i])){
            int index = compute[i] - 'A';
            score += points[index];}
        }
     return score;
    }

