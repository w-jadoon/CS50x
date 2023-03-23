#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // eliminates 0 and 1 since are not prime numbers
    if (number == 0 || number == 1)
    {
        return 0;
    }

    //performs function to test if prime number or not
    else
    {
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                return 0;
            }
        }

    }
    //if all tests above pass then function returns 1 meaning
    //condition passes go ahead and print
    return 1;
}
