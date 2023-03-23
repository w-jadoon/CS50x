#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


long get_number(void);
bool valid(long number); //checks if card# valid; Luhn's Algo.
void print_type(long number); //checks&prints card type e.g visa or invalid.


int main(void)
{
    long number = get_number();

    if (valid(number)) //call Luhn's algorithm
    {
        print_type(number); //check and print card type
    }


}

long get_number(void)// user inputs card#
{
    long number;
    do
    {
        number = get_long("Enter card#: ");
    }
    while (number < 0);
    return number;
}

bool valid(long number)//test validity of number with Luhn's algo
{
    //printf("%li\n", number);
    long card_num1 = number; //luhn case where digit*2
    long card_num2 = number; //other luhn case
    int sum1 = 0;
    int sum2 = 0;
    int total_sum = 0;
    int curr_dgt;
    int curr_dgtx2;


    card_num1 = card_num1 / 10; //to start with second to last digitfor first while loop

    //printf("%li\n", card_num1);

    while (card_num1 > 0)
    {
        curr_dgt = card_num1 % 10;

        curr_dgtx2 = curr_dgt * 2;
        sum1 = sum1 + (curr_dgtx2) % 10 + curr_dgtx2 / 10;
        //printf("%i\n", sum1);
        card_num1 = card_num1 / 100;
    }

    while (card_num2 > 0)// luhn second case
    {
        curr_dgt = card_num2 % 10;
        sum2 = sum2 + curr_dgt;
        card_num2 = card_num2 / 100;
    }

    total_sum = sum1 + sum2;
    //printf("%i\n", total_sum);

    if (total_sum % 10 > 0)
    {
        printf("INVALID\n");
        exit(0);// if luhn fail the print INVALID and exit
    }

    return 1;

}

void print_type(long number)
{
    long card_num = number;
    int length = 0;
    int frst_dig;
    int scnd_dig;

    while (card_num > 0)
    {
        length++;
        card_num = card_num / 10;

    }//printf("%i\n", length);

    if (length > 16 || length < 13)
    {
        printf("INVALID\n");
        exit(0);
    }

    card_num = number;

    for (int i = 1; i < length - 1; i++)
    {
        card_num = card_num / 10;
        if (i == length - 2)
        {
            frst_dig = card_num / 10;
            scnd_dig = card_num % 10;
            //printf("%i, %i\n", frst_dig, scnd_dig);
        }
    }

    if (frst_dig == 3 && (scnd_dig == 4 || scnd_dig == 7) && length == 15)
    {
        printf("AMEX\n");
    }

    else if (frst_dig == 5 && (scnd_dig == 4 || scnd_dig == 5 || scnd_dig == 1 || scnd_dig == 2 || scnd_dig == 3) && length == 16)
    {
        printf("MASTERCARD\n");
    }

    else if ((frst_dig == 4 && length == 13) || (frst_dig == 4 && length == 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}