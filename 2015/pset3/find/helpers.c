/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    while (n > 0) 
    {
        int mid = round(n/2);
        
        if(values[mid] == value)
        {
            return true;
        }
        
        else if (values[mid] > value)
        {
            for (int i = mid; i > 0; i--)
            {
                if(values[i] == value)
                {
                    return true;
                }
            }
        }
            
        else if (values[mid] < value)
        {
            for (int i = mid; i < n; i++)
            {
                if(values[i] == value)
                {
                    return true;
                }
            }
        }
    n--;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // temp variable
    int temp; 
    
    for (int i = 0; i < n; i++)
    {
        // check for right half of array
        for (int j = i; j < n - 1; j++)
        {
            if (values[j] > values[j+1])
            {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    return;
}
