#include <cs50.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_readability(int letters_count, int words_count, int senteces_count );
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters_count = count_letters(text);
    int words_count = count_words(text);
    int senteces_count = count_sentences(text);

    int readability_index = compute_readability(letters_count, words_count, senteces_count );


    if (readability_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readability_index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) readability_index);
    }
}

int count_sentences(string text)
{
    int sentences_count = 0;
    for (int i =0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences_count += 1;
        }
    }

    return sentences_count;
}

int count_letters(string text)
{
    int letters_count = 0;

    for (int i =0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters_count += 1;
        }
    }

    return letters_count;
}

int count_words(string text)
{
    if (strlen(text) == 0)
    {
        return 0;
    }

    int words_count = 1;
    for (int i =0; i < strlen(text); i++)
    {
        char ch = text[i];
        if (ch == ' ')
        {
            words_count += 1;
        }
    }

    return words_count;
}


int compute_readability(int letters_count, int words_count, int sentences_count)
{
    //index = 0.0588 * L - 0.296 * S - 15.8
    float avg_letter_per_word = ( (float) letters_count / (float) words_count) * 100;
    float avg_sentence_per_word = ( (float) sentences_count / (float) words_count) * 100;

    int index =  round(0.0588 * avg_letter_per_word - 0.296 * avg_sentence_per_word - 15.8);

    return index;
}
