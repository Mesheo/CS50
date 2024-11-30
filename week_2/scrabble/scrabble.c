#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int player1_score = compute_score(player1);
    int player2_score = compute_score(player2);

    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2_score > player1_score)
    {
        printf("Player 2 wins!\n");
    }
    else if (player1_score == player2_score)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word){
    int len = strlen(word);
    int score = 0;

    for(int i =0; i< len; i++){
        char character = toupper(word[i]);
        if (isalpha(character))
        {
            score += POINTS[character - 'A'];
        }
     }
    return score;
}
