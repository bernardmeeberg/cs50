/**
 * note: my primaryu language is Dutch, I'm from The Netherlands
 *
 * mario.c
 *
 * Bernard van de Meeberg
 * bernardmeeberg@gmail.com
 *
 * re-makes the classic Mario Piramid
 * cs50x fall 2014 pset 1
 */
 
#include <cs50.h>
#include <stdio.h>

/**
 * prints the mario piramid 
 */
int main(void)
{
    // asking for user input
    int height;
    do 
    {
        printf("Give a height between 1 and 23 for the piramid please: ");
        height = GetInt();
    }
    // checking for correct user input
    while (height < 0 || height > 23);
    
    // drawing the actual piramid
    for(int i = 1; i <= height; i++)
    {
        // printing the spaces from the left
        for(int j = height - i ;j > 0; j--)
        {
            printf(" ");
        }

        // drawing the blocks
        for(int k = 0;k <= i; k++)
        {
            printf("#");
        }
        
        // sets the cursor to the new line
        printf("\n");
    }
    return 0;
}