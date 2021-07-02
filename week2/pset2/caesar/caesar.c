#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{


    // Check if there is a key or not
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // Check if the key is numberic or not
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        //Check for each char is digit
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Convert string to int
    int key = atoi(argv[1]);

    // Get string from the user
    string user_input = get_string("plaintext:  ");

    //Print ciper text title
    printf("ciphertext: ");

    //Covert plain text to cipher text and print it
    for (int i = 0, n = strlen(user_input); i < n; i++)
    {
        // initialize with the char input
        int char_digit = user_input[i];

        //Check if it is uppercase
        if (isupper(user_input[i]))
        {
            char_digit -= 'A';
            char_digit += key;
            char_digit %= 26;
            char_digit += 'A';
        }

        //Check if it is lowercase
        else if (islower(user_input[i]))
        {
            char_digit -= 'a';
            char_digit += key;
            char_digit %= 26;
            char_digit += 'a';
        }

        printf("%c", char_digit);
    }
    printf("\n");
}