#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>  // for strtol
#include <string.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX

//ci = (pi + k) % 26
//a ou A = 0 ...
//p= Hi em que p0=H (ou 7), p1=i (ou 8)
//k=3
// no texto cifrado c0=K, c1=L.
//ascii direto
//respeitando maiuscula e minuscula e numeros

int main(int argc, string argv[])
{
    char *p;
    int n;
    errno = 0;
    string text = 0;
    if (argc > 2 || argc < 1)
    {
        return 1;
    }

    if (argc != 2) //arqc qtd de palavras depois do nome do programa que vai no vetor argv
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    long number = strtol(argv[1], &p, 10);//convertendo string argv[1] em long
    
    if (errno != 0 || *p != '\0' || number > INT_MAX)
    {
        return 1;
    }

    else
    {
        n = number;// convertendo para int
        printf("%i\n", n);
    }


    text = get_string("plaintext: ");
    int index = 0;
    char cif = 0;
    string cipher = 0;

    printf("ciphertext: ");


    for (int i = 0, size = strlen(text); i < size; i++)
    {
        if ((text[i] >= 'a') && (text[i] <= 'z'))
        {
            index = (((text[i] - 'a') + n) % 26) + 'a';
            cif = index;
            cipher += cif;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            index = (((text[i] - 'A') + n) % 26) + 'A';
            cif = index;
            cipher += cif;
        }
        else
        {
            index = text[i];
            cif = index;
            cipher += cif;
        }

        printf("%c", cif);
    }
    printf("\n");

    return 0;
}
