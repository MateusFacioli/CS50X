#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i = 1, j = 1, espace = 1;

    do
    {
        n = get_int("Height: "); //entrada usuario
    }
    while (n < 1 || n > 8); //validando entrada

    for (i = 1; i <= n; i++) //linhas
    {
    
        for (j = 1; j <= n - espace; j++) //espaços
        {
            printf(" ");
        }
        for (j = 1; j <= espace; j++) //espaços
        {
            printf("#");
        }
        printf("\n"); // outra linha
        espace++; //aumentando o contador para linha seguinte imprimir + do #
    }

}

