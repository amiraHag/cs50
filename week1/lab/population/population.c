#include <cs50.h>
#include <stdio.h>

int noYears(int start, int end);

int main(void)
{
    // Get the start size from the user
    int start_size;
    do
    {
        start_size = get_int("Start size: ");

    }
    while (start_size < 9);


    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");

    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int years = noYears(start_size, end_size);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}


//Function to calculate no of years
int noYears(int start, int end)
{

    int years = 0;
    int population = start;

    //loop to get no of years
    while (population < end)
    {
        //calculation for no of years
        int born = population / 3;
        int pass_away = population / 4;
        population += born - pass_away;
        years++;

    }

    return years;
}