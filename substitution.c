#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>  // for strtol
#include <string.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <ctype.h> //for toupper


int main(int argc, string argv[])
{

    if (argc > 2 || argc < 1) //se  muitos argumentos ou nenhum
    {
        return 1;
    }

    if (argc != 2  || argc == 1) //se mais ou menos que 2
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string text = 0, key = argv[1];
    int tam = strlen(key), cont = 0, flag = 0;

    if (tam != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < tam; i++) //apenas letras
        {


            if ((key[i] >= 'a' && key[i] <= 'z')
                || (key[i] >= 'A' && key[i] <= 'Z'))
            {
                flag = 1;
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                flag = 0;
                return 1;
            }

            for (int j = tam; j > 0; j--) //apenas letras
            {
                if (key[i] == key[j] && i != j) // se tem letra repetida
                {
                    cont++;
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
    }


    text = get_string("plaintext: ");
    int index = 0, n = 0;
    char cif = 0;
    string cipher = 0;
    errno = 0;
    printf("ciphertext: ");


    for (int i = 0, size = strlen(text); i < size; i++)
    {
        
        //    index = (((text[i] - 'a') + n) % 26) + 'a';
        if ((text[i] >= 'a') && (text[i] <= 'z'))
        {
            index = text[i] - 97;// posicao futura
            cif = key[index];// carater vem da chave
            cif = tolower(cif);
            cipher += cif;// salva em uma string
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            index = text[i] - 65;// posicao futura
            cif = key[index];// carater vem da chave
            cif = toupper(cif);
            cipher += cif;// salva em uma string
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
