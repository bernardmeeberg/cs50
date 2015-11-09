/**
 * water-weight.c
 * 
 * Bernard van de Meeberg
 * bernardmeeberg2000@gmail.com
 * 
 * berekent de ideale temperatuur van 1l water om 1 kilo te halen
 */

#include <stdio.h>

int main(void)
{
    double a = -0.0000073;
    double b = 0.0000584;
    double c = 0.9998832;
    
    double topX = -1 * (b / (a*2));
    
    double topY = ((topX*topX) * a) + (b * topX) + c;
    
    printf("%.20f\n", topX);
    printf("%.20f\n", topY);
}