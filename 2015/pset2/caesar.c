/**
 * caesar.c
 *
 * Bernard van de Meeberg 
 * bernardmeeberg@gmail.com
 *
 * Implementation of caesar cryptography
 * CS50X fall 2014 pset 2
 */
 
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // settting variables
    int key;
    int result;
    
    // checking the input
    if (argc != 2)
    {
        printf("Provide a key too please.\n");
        return 1;
    }
    
    // convert key to a number
    key = atoi(argv[1]);
    
    // get the plain text from user
    string plainTxt = GetString();
    
    // when key >= 26
    if (key >= 26)
    {
        key = (key % 26);
    }
    
    // actual encrypting
    for (int i = 0, length = strlen(plainTxt); i < length; i++)
    {
        // basic encrypting
        result = (plainTxt[i] + key);
        
        // if upp char is above 'Z'
        if (isupper(plainTxt[i]) && (result > 'Z'))
        {
            result = (result - 26);
        }
        
        // if low char is below 'z'
        if (islower(plainTxt[i]) && (result > 'z'))
        {
            result = (result - 26);
        }
        
        // if char in alphabet, print it
        if (isalpha(plainTxt[i]))
        {
            printf("%c", result);
        }
        
        // if not, print it as it is
        else 
        {
            printf("%c", plainTxt[i]);
        }
    }
    
    // print a new line
    printf("\n");
    // return correct number
    return 0;
}