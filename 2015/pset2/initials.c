/**
 * initials.c
 *
 * Bernard van de Meeberg
 * bernardmeeberg@gmail.com
 *
 * prints out the first chracter from a given name
 * CS50X fall 2014 pset 2
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // ask and get user input
    string name = GetString();
    
    // prints the first character of the first name in uppercase
    printf("%c", toupper(name[0]));
    
    // loop through the rest 
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        // check space before first char and first char itself
        // notice the '' for chars
        if(name[i] == ' ' && name[i + 1] != '\0') 
        {
            // prints the char after the space
            printf("%c",toupper(name[i + 1])); 
            i++;
      
        }
       
    }
    // prints a new line
    printf("\n"); 
}