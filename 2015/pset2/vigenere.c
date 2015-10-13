/**
 * vigenere.c
 *
 * Bernard van de Meeberg
 * bernardmeeberg@gmail.com
 *
 * implentation of vigene encryption
 * cs50x fall 2014 pset
 */
 
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // set variables
    int shift;
    int keyvalue;
    
    // checks commands
    if (argc != 2)
    {
        printf("Only two commands please\n");
        return 1;
    }
    
    // get the key
    string key = argv[1];
    
    // make sure the key is alphabetical
    for (int n = 0, keylength = strlen(argv[1]); n < keylength; n++)
    {
        if ((key[n] >= '0') && (key[n] <= '9'))
        {
            printf("Enter a valid key please.\n");
            return 1;
        }
    }
    
    // get input to encrypt
    string plainText = GetString();
    
    // actual encrypting
    for (int i = 0, j = 0, length = strlen(plainText); i < length; i++, j++)
    {
        // checking if key is shorter than plainText
        if (j >= strlen(key))
        {
            j = 0;
        }
        
        // finding keyvalue for each iteration/char
        keyvalue = key[j];
        
        // find lastest key value if key is not alphabetical
        if (!isalpha(plainText[i]))
        {
            j = (j - 1);
        }
        
        // makes Aa = 0, Zz = 25 for the uppercase letters 
        if ((keyvalue >= 'A') && (keyvalue <= 'Z'))
        {
            keyvalue = (keyvalue - 'A');
        }
        
        // makes Aa = 0, Zz = 25 for the lowercase letters
        if ((keyvalue >= 'a') && (keyvalue <= 'z'))
        {
            keyvalue = (keyvalue - 'a');
        }
        
        // actual encryption
        shift = (plainText[i] + keyvalue);
        
        // wrap back to the beginning if > 'Z'
        if (isupper(plainText[i]) && (shift > 'Z'))
        {
            shift = (shift - 26);
        }
        
         // wrap back to the beginning if > 'z'
        if (islower(plainText[i]) && (shift > 'z'))
        {
            shift = (shift - 26);
        }
        
        // if encrypted char is alpha, print it
        if (isalpha(plainText[i]))
        {
            printf("%c", shift);
        }
        
        // if not, print it too
        else 
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
    return 0;
}