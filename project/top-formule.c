/**
 * top-formule
 * 
 * Bernard van de Meeberg
 * bernardmeeberg2000@gmail.com
 * 
 * de formule voor Xtop
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Wat is a? ");
    double a = GetDouble();
    printf("Wat is b? ");
    double b = GetDouble();
    
    double Xtop = -1 * (b / (a * 2));
    
    printf("Xtop = %.20f\n", Xtop);
}