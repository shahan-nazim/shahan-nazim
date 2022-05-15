#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* THIS C# program returns readibility level of the submited text. CS50 2022 pset 2- readibility
Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
*/

string s;
int scounter;
int sen_counter();
int letter_counter();
int word_counter();
float Let;
float Sen;
float Coleman_index;

int main(void)
{
    s = get_string ("Enter text here ");
    int letters = letter_counter(s);
    int words = word_counter(s);
    int sentences = sen_counter(s);
    Let = (letters * 100) / words;              // lesson learnt- in C when solving equations you need to round off the int- use a float
    Sen = (sentences * 100) / words;            // lesson learnt- in C when solving equations you need to round off the int- use a float
    Coleman_index = (0.0588 * Let) - (0.296 * Sen) - 15.8;      // used value as a FLOAT, then rounded it off to nearst int
    printf ("The number of letters are: %i\n", letters);
    printf ("The number of words are: %i\n", words);
    printf ("The number of sentences are: %i\n", sentences);
    if (Coleman_index > 15.0)
    {
        printf ("Readability level: Grade 16+\n");
    }
    else if (Coleman_index < 1.0)
    {
        printf ("Readability: Before Grade 1\n");
    }
    else
        printf ("Readability: Grade %i\n",(int) round(Coleman_index));
}

int letter_counter()
{
    int counter = 0;                        //counter is set to 0
    int n = strlen (s);                     //all characters including special characters are counted here
    {
    for (int i = 0; i < n+1; i++)           //we only count small/big letters and leave the rest
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))   //if statement works only when added more brackets b7w 2 arguments)
                {
                    counter = counter + 1;
                }
        }
    }
    return counter;
}

int word_counter()
{
    int wn = strlen (s);                     //all characters including special characters are counted here
    int wcount = 1;
    {
        for (int i = 0; i < wn+1; i++)           //we only count small/big letters and leave the rest
        {
            if (s[i] == ' ')
            {
                wcount = wcount + 1;
            }
        }
    }
    return wcount;
}

//count sentences ending with . ! or ? in this program
int sen_counter()
{
    int ln = strlen (s);                    //all characters including special characters are counted here
    scounter = 0;
    for (int i = 0; i < ln +1; i++)
    {
        if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
        scounter = scounter + 1;
        }
    }
    return scounter;
}
