#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
bool checkLuhn(string number);
string validate(string number);
//regras Luhn’s Algorithm
//1) da direita para esquerda dobrar cada segundo dígito, pule o dígito de controle(último dígito) (1 sim 1 não)
//2) somar todos os dígitos individuais da soma anterior com os dígitos que não dobrou (1 não 1 sim)
//3) se a soma for múltiplo de 10 está válido

int main(void)
{
    string n = 0;
    do
    {
        n = get_string("Number: "); //entrada usuario
    }
    while (n < 0); //validando entrada


    string kind = validate(n); //chamada função
    string check = "INVALID";

    if (strcmp(kind, check) != 0)
    {
        printf("%s\n", kind);
    }
    else
    {
        printf("INVALID\n");
    }


}
bool checkLuhn(string number)
{

    int size = strlen(number);
    int last = (int)(number[size - 1]);
    
    int last2 = last - '0';
    
    int sum = 0;
    int val2 = 0;
    
    for (int i = size; i > 0; i--) // somando um sim um não excluindo digito de controle
    {
        int val = (int)(number[i - 1]);
        if (val != 0)
        {
            val2 = val - '0';
        }
        if (size % 2 == 0)
        {
            if (i % 2 != 0 && i != size)
            {
                val2 *= 2;
            }
            if (val2 > 9)
            {
                val2 -= 9;
            }

            sum += val2;

        }
        else
        {

            if (i % 2 == 0 && i != size) //numero posicao par multiplica por 2
            {
                val2 *= 2;
            }

            if (val2 > 9) // se for maior que 9 somando os dígitos ex(18= 1+8=9), o mesmo se obtem subtraindo 9
            {
                val2 -= 9;
            }//ou val2 % 10 +1

            sum += val2; // essa soma aqui talvez ta errada pq o for pega size-1 e i+2 variavel aux= number-[ultima]
        }
    }


    if (sum % 10 == 0)
    {
        return true;
    }
    return false;

}
//restriçoes
//American Express - 15 dígitos começando com 34 ou 37
//Master Card - 16 dígitos começando com 51, 52, 53, 54 ou 55
//Visa - 13 ou 16 dígitos começando com 4
//inválido - qqr intervalo fora desses
string validate(string number)
{
    int size = strlen(number);
    bool check = checkLuhn(number);
    if (number[0] == '3' && (number[1] == '4' || number[1] == '7')) // American Express
    {
        if (size == 15 && check == true)
        {
            return ("AMEX");
        }
        else 
        { 
            return ("INVALID");
        }
    }
    if (number[0] == '5' && (number[1] == '1' || number[1] == '2'
                             || number[1] == '3' || number[1] == '4'
                             || number[1] == '5'))// Mater Card
    {
        if (size == 16 && check == true)
        {
            return ("MASTERCARD");
        }
        else 
        { 
            return ("INVALID");
        }
    }
    if (number[0] == '4') // Visa
    {
        if ((size == 13 || size == 16) && check == true)
        {
            return ("VISA");
        }
        else 
        { 
            return ("INVALID");
        }
    }
    if (size < 13 || size == 14 || size > 16 || check == false)
    { 
        return ("INVALID");
    }
    return ("INVALID");
}
