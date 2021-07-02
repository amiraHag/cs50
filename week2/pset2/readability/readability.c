#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototype for the used functions
int get_letters_count(string text);
int get_words_count(string text);
int get_sentences_count(string text);

int main(int argc, string argv[])
{

    //Get the etxt from the user
    string user_input = get_string("Text: ");

    //Calculate the no of letters
    int letters = get_letters_count(user_input);

    //Calculate the no of words
    int words = get_words_count(user_input);

    //Calculate the no of sentences
    int sentences = get_sentences_count(user_input);

    //Calculate no of letters per 100 words
    float no_letters_100_word = (((float) letters) / words) * 100;

    //Calculate no of sentences per 100 words
    float no_sentences_100_word = (((float) sentences) / words) * 100;

    //Get the grade number using Coleman-Liau
    int index = round(0.0588 * no_letters_100_word - 0.296 * no_sentences_100_word - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }



}


//Calculte no of letters
int get_letters_count(string text)
{

    int count = 0;

    // Lop through the string to get no of letters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            count++;
        }
    }

    return count;
}

//Calculate no of words
int get_words_count(string text)
{

    int count = 0;

    //Loop through string and check to get no of words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    //Increase count by one to adjust word count
    count ++;
    return count;
}


//Calculate no of sentences
int get_sentences_count(string text)
{

    int count = 0;

    //llop to get no of sentences in the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //check if we reach end of sentence or not
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}