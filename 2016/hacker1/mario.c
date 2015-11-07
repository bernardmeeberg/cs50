/**
 * mario.c
 * 
 * Benard van de Meeberg
 * bernardmeeberg2000@gmail.com
 * 
 * (re)creates the famous Mario pyramid
 * cs50X 2016 hacker1
 */

#include <cs50.h>
#include <stdio.h>

// prototype
void mario(int height);

int main(void)
{
    // our var for the # of lines
    int height;
    
    // ask until a valid number is inputted
    do
    {
        printf("Enter a height between 0 and 23 please: ");
        height = GetInt();
    }
    while(height < 0 || height > 23);
    
    // call our mario function
    mario(height);
}

/**
 * prints the mario pyramid
 * no need to print spaces right, since the block are already aligned left
 */
void mario(int height)
{
    // loops through all the lines
    for (int i = 1; i <= height; i++)
    {
        // print height - 1 spaces
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        
        // print an amount of i blocks
        for(int k = 1; k <= i; k++)
        {
            printf("#");
        }
        
        // print two spaces
        printf("  ");
        
        // print an amount of i blocks right
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        
        // print new line
        printf("\n");
    }
}