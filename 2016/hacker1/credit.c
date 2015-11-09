/**
 * credit.c
 * 
 * Bernard van de Meeberg
 * bernardmeeberg2000@gmail.com
 * 
 * reports information about creditcard number
 */

#include <cs50.h>
#include <stdio.h>

// prototype
string credit(long long number);
string bankCredit(long long number);
int checkCredit(long long number);

int main(void)
{
    // ensure proper input
    do
    {
        printf("What is your creditcard number? ");
        long long creditcard = GetLongLong();
    }
    while(creditcard < 1);
    
    // our credit algorithm
    credit(creditcard);
    
    // ensure proper working
    return 0;
}

/**
 * combines other two functions in a answer
 */
string credit(long long number)
{
    // ensure proper working
    return 0;
}

/**
 * reports bank
 */
string bankCredit(long long number)
{
    // ensure proper working
    return 0;
}

/**
 * reports if number is valid or not
 */
int checkCredit(long long number)
{
    // ensure proper working
    return 0;
}