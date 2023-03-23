#include <cs50.h>
#include <stdio.h>

int years;
int main(void)
{
    // TODO: Prompt for start size
    int start_pop;
    do
    {
        start_pop = get_int("Starting Population: ");
    }
    while (start_pop < 9);


    // TODO: Prompt for end size
    int end_pop;
    do
    {
        end_pop = get_int("Ending Population: ");
    }
    while (end_pop < start_pop);


    // TODO: Calculate number of years until we reach threshold
    int curr_pop = start_pop;
    for (years = 0; end_pop > start_pop; years ++)
    {
        curr_pop = start_pop + (start_pop / 3) - (start_pop / 4);
        start_pop = curr_pop;
    }


    // TODO: Print number of years
    printf("Years: %i\n", years);
    printf("Actual Current population %i\n", curr_pop);
}
