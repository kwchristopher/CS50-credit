#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int o = 0;
    int p;
    int r = 0;
    long long s;
    //Get user input for credit card number, must be a positive value
    do
    {
        s = get_long_long("Credit Card Number: ");
    }
    while (s < 0);

    //Take every other number starting from the second to last and working toward the beginning
    for (long long y = 100, z = 10; s * 10 > y; y *= 100, z *= 100)
    {
        int n;
        int x = s % y / z;
        //If x is greater than or equal to 5, multiply by two then split the number into individual digits then add them
        if (x >= 5)
        {
            n = x * 2 % 10 + 1;
        }
        //If x is less than 5, multiply the digit by two
        else
        {
            n = x * 2;
        }
        p = n;
        o = p + o;
    }
    //Take every number that remains untouch from the previous formula and add them together
    for (long long yy = 10, zz = 1; s * 10 > yy; yy *= 100, zz *= 100)
    {
        int q;
        int xx = s % yy / zz;
        q = xx;
        r = q + r;
    }
    //Add the two numbers together from the previous two formulas
    int t = r + o;
    //Check to see if the numbers added together are a multiple of 10
    if (t % 10 == 0)
    {
        //Check to see if the card is American Express
        if (s / 10000000000000 == 34 || s / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        //Check to see if the card is Master Card
        else if (s / 100000000000000 == 51 || s / 100000000000000 == 52 || s / 100000000000000 == 53 || s / 100000000000000 == 54
                 || s / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        //Check to see if the card is Visa
        else if (s / 1000000000000 == 4 || s / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        //Print out statement that credit card number is invalid if all previous checks fail
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
