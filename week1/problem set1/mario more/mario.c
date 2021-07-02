#include <stdio.h>
#include <cs50.h>

int main(void)
{

    // Get the height from the user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);


    //Print the pyramids
    for (int i = 0; i < height; i++)
    {
        int j;

        //print the spaces
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        //print the hashes
        for (int n = 0; n < i + 1; n++)
        {
            printf("#");
        }

        //print the space separator
        printf("  ");

        //print the hashes right
        for (int n = 0; n < i + 1; n++)
        {
            printf("#");
        }


        printf("\n");
    }
}