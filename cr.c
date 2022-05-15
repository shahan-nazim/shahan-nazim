#include <cs50.h>
#include <stdio.h>

// declared variables and functions on the top
int x1;
int x2;
int x3;
int x4;
int x5;
int y;
int y1;
int sum;
long credit;
int visa;
int visa2;
int amex;
int amex2;
long div;
long i;

int main(void)
{
    {
        credit = get_long ("Enter the credit card number: ");
    }
/*
now it chooses only the numbers 13-17 digit numbers > in WHILE loop there was an additonal space on the right side
while (!(credit > 999999999999 && credit < 9999999999999999));
*/
    visa = credit / 1000000000000;
    visa2 = visa%10;
    amex = visa / 10;
    amex2 = amex / 100;

    //if its a VISA card
    if ( visa > 0 && visa < 10 && visa2 == 4)
    {
        printf ("VISA\n");
    }
    // if its a Amex card
    else if ( amex == 34 || amex == 37)
    {
        printf ("AMEX\n");
    }
    // if its a MC card
    else if ( amex2 == 4)
    {
        printf ("VISA\n");
    }
    else if (amex > 500 && amex < 560)
    {
        printf ("MASTERCARD\n");
    }
    else
    {
        printf ("INVALID\n");
    }

    y = 0;
    y1 = 0;
    //x2 is every second integer
    for (i = 10; i < 100000000000000000; i = i *100)
        {
            x2 = ((credit - (credit%i))/i)%10;
            // int is doubled here
            x3 = 2 * x2;
            {
            // first digit
                x4 = x3%10;
            // second digit
                x5 = ((x3 - x4)/10);
            }
            y = y + x4 + x5;
        }
    //for getting sum of every second digit
    for (i = 1; i < 100000000000000000; i = i *100)
        {
            x1 = ((credit - (credit%i))/i)%10;
            y1 = y1 + x1;
        }
/* Now let’s add those products’ digits (i.e., not the products themselves) together:
2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
the sum prints 2x the sum of all second numbers and thhen the remaining numbers
*/
    sum = y1 + y;
    if (sum%10 > 0)
    {
        printf ("INVALID\n");
    }
/*
    int a = 371449635398431 / 1000000000000;
    printf ("%i\n", a);
*/
}
