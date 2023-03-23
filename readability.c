#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int compute(int l, int w, int s);// l-letters, w-words, s-sentences
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string input = get_string("Text: ");
    int l = count_letters(input);
    int w = count_words(input);
    int s = count_sentences(input);
    int index = compute(l, w, s);
    //printf("%s\n", input1);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

//counts letters in the entire text
int count_letters(string text)
{
    int l = strlen(text);
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) != 0 || text[i] < 65 || (text[i] > 90 && text[i] < 97) || text[i] > 122)
        {
            l = l - 1;
        }
    }
    //printf("l= %i\n", l);
    return l;
}

int count_words(string text)
{
    int w = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) != 0)
        {
            w += 1;
        }
    }
    //printf("%i\n", w);
    return w;
}

int count_sentences(string text)
{
    int s = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == (46) || text[i] == (63) || text[i] == (33))
        {
            s++;
        }

    }
    //printf("%i\n", s);
    return s;
}

int compute(int l, int w, int s)
{
    //index = 0.0588 * L - 0.296 * S - 15.8
    //L = letters/words * 100
    //S = sentences/words * 100
    float L = (l / (float)w) * 100;
    float S = (s / (float)w) * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    //printf("index= %i\n", index);
    return index;
}
