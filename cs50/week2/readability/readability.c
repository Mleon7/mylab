#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters, words, sentences;
    double L, S, index;
    string text = get_string("Text: ");

    letters = count_letters(text);
    // printf("%d letters\n", letters);

    words = count_words(text);
    // printf("%d words\n", words);

    sentences = count_sentences(text);
    // printf("%d sentences\n", sentences);

    L = (double)letters / (double)words * 100;
    S = (double)sentences / (double)words * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;
    int int_index;
    int_index = round(index);

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index <= 15)
    {
        printf("Grade %d\n", int_index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("error!\n");
    }
}

int count_letters(string text)
{
    int cnt = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            cnt++;
        }
    }
    return cnt;
}

int count_words(string text)
{
    int cnt = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isblank(text[i]) || isspace(text[i]))
        {
            cnt++;
        }
    }

    return cnt;
}

int count_sentences(string text)
{
    int cnt = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            cnt++;
        }
    }

    return cnt;
}