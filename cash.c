#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    int i = 0, quarter = 0, dime = 0, nickel = 0, penny = 0, resto = 0, tot = 0;

    do
    {
        n = get_float("Change owed: "); //entrada usuario
    }
    while (n < 0); //validando entrada

    int cents = round(n * 100);

    quarter = (int)(((int)(cents)) / 25);
    //printf("num quarters: %i \n",quarter);
    resto = cents - (quarter * 25);
    //printf("balance owing1: %.2i$ \n", resto);
    
    dime = (int)(((int)(resto)) / 10);
    resto = resto - (dime * 10);
    //printf("num dimes: %i \n", dime);
    //printf("balance owing2: %.2i$ \n", resto);

    nickel = (int)(((int)(resto)) / 5);
    //printf("num nickels: %i \n", nickel);
    resto = resto - (nickel * 5);
    
    penny = (int)(resto);
    //printf("balance owing3: %.2i$ \n", resto);
    //printf("num pennies: %i \n", penny);

    tot = quarter + dime + nickel + penny;
    printf("\n");
    printf("%i", tot);
}
