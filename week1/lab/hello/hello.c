#include <stdio.h>
#include <cs50.h>

int main(void)
{

    // Get user name from the user
    string user_name = get_string("What is your name?\n");

    // Greet the user
    printf("hello, %s\n", user_name);


}