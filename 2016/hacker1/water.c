/**
 * water.c
 * 
 * Bernard van de Meeberg
 * bernardmeeberg2000@gmail.com
 * 
 * spits out the # of bottles in a # mintes of showering
 * cs50X 2016 hacker1
 */

#include <cs50.h>
#include <stdio.h>

//prototype
int water(int minutes);

int main(void)
{
    // our var for # of minutes
    int shower;
    
    // check the input
    do
    {
        printf("minutes: ");
        shower = GetInt();
    }
    while (shower < 1);
    
    // calling our water function
    water(shower);
}

/**
 * returns # of bottles used while showering
 */
int water(int minutes)
{
   printf("bottles: %i\n", 12 * minutes);
   return 0;
}