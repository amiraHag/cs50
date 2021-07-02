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
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Check the length of the key
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }


    // Check if the key is alphabetically and not contain repeated char
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {

        //Check for each char is digit
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must contain unique 26 characters.\n");
                return 1;
            }
        }
    }



    //Convert string to int
    string key = argv[1];

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
            char_digit = user_input[i] - 'A';
            char_digit = toupper(key[char_digit]);

        }

        //Check if it is lowercase
        else if (islower(user_input[i]))
        {
            char_digit = user_input[i] - 'a';
            char_digit = tolower(key[char_digit]);
        }

        printf("%c", char_digit);
    }
    printf("\n");
}