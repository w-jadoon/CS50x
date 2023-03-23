#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n > 8);

    for (int m = 1; m <= n; m++) //m for main loop
    {
        for (int j = n - m; j > 0; j--) //print space before #
        {
            printf(" ");
        }

        for (int i = 0; i < m; i++)
        {
            printf("#");
        }

        printf("  "); // prints gap within pyramid

        for (int k = 0; k < m; k++) //prints last block
        {
            printf("#");
        }
        printf("\n");
    }




}