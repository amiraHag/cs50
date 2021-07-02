#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get input from the user
    long user_input;

    do
    {
        user_input = get_long("Number: ");
    }
    while (user_input < 0);

    //Initialize helper values
    int checksum = 0;
    long tenth_value = 10;
    int counter = 0;
    long user_input_check = user_input;

    // Check the checksum value
    while (user_input > 0)
    {
        int remainder_value = (user_input % tenth_value) / (tenth_value / 10) ;

        counter += 1;


        if (remainder_value > 0)
        {
            // MUltiple the other digit by 2
            if (counter % 2 == 0)
            {
                int internal_remainder_value = remainder_value * 2;

                //Add the digits itself if the number larger than 9
                if (internal_remainder_value > 9)
                {
                    checksum += (internal_remainder_value % 10) + (internal_remainder_value / 10);
                }
                //Add the number if it less than 10
                else
                {
                    checksum += internal_remainder_value;
                }
            }
            else
            {
                // add the number without multiplication if it is odd index number
                checksum += remainder_value;
            }

            user_input -= remainder_value * (tenth_value / 10);
        }

        tenth_value *= 10;
    }

    //Check The exact type of Card
    if (checksum % 10 == 0 && (counter == 16 || counter == 15 || counter == 13))
    {
        // Get the last two digits from the user input
        int last_digits_check = user_input_check / (tenth_value / 1000);

        //Check for Mastercard
        if ((counter == 16) && last_digits_check >= 51 && last_digits_check < 56)
        {
            printf("MASTERCARD\n");
        }

        //Check for American Express card
        else if ((counter == 15) && (last_digits_check == 34 || last_digits_check == 37))
        {
            printf("AMEX\n");
        }

        //Check for Visa card
        else if ((counter == 13 || counter == 16) && (last_digits_check >= 40 && last_digits_check < 50))
        {
            printf("VISA\n");
        }

        //Display invalid if it is not visa, mastercard or american express
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