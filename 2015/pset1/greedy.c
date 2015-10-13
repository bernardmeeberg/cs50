/**
 * greedy.c
 *
 * Bernard van de Meeberg
 * bernardmeeberg@gmail.com
 *
 * prints out the minimum total coints to give back
 * cs50x fall 2014 pset 1
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>

// defines the 4 possible coints
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

/**
 * returns the minimum total of coints
 */
int main(void)
{
    float input_change;
    int total_coins = 0;    
    
    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n");
        input_change = GetFloat();
    }
    while (input_change <= 0);
    
    // converts input to cents
    int change_cents = round(input_change * 100);
    
    // while's the fasted loop to use here
    // while the change is more than a Quarter
    while (change_cents >= QUARTER)
    {
        change_cents -= QUARTER;
        total_coins++;
    }
    
    // while the change is more than a Dime
    while (change_cents >= DIME)
    {
        change_cents -= DIME;
        total_coins++;
    }
    
    // while the change is more than a Nickel
    while (change_cents >= NICKEL)
    {
        change_cents -= NICKEL;
        total_coins++;
    }
    
    // while the change is more than a Penny
    while (change_cents >= PENNY)
    {
        change_cents -= PENNY;
        total_coins++;
    }
    
    printf("%i\n", total_coins);
}