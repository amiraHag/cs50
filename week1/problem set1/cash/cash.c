#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get change value from the user
    float user_input;
    do
    {
        user_input = get_float("Change owed: ");

    }
    while (user_input < 0);

    //Adjust the change value to be integer
    int cents = round(user_input * 100);
    int coins = 0;

    //Calculate the number of coins
    if (cents >= 25)
    {
        coins += cents / 25;
        cents = cents % 25;
    }

    if (cents >= 10)
    {
        coins += cents / 10;
        cents = cents % 10;
    }

    if (cents >= 5)
    {
        coins += cents / 5;
        cents = cents % 5;
    }
    if (cents >= 1)
    {
        coins += cents;
    }

    //Print No of coints
    printf("%i \n", coins);


}