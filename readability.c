#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

float ColemanLiau(string text);

int main(void)
{
    string n = 0;
    do
    {
        n = get_string("Text: "); //entrada usuario
    }
    while (n < 0); //validando entrada
    printf("%s\n", n);

    float grade = ColemanLiau(n); //chamada da função 
    
    grade = round(grade);
 
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (grade > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", (int)grade);
    }

}

float ColemanLiau(string n)
{
    int words = 0, letters = 0, insideword = 0, sentences = 0;
    float index = 0;
    
    for (int i = 0, size = strlen(n); i < size; i++)
    {
        if ((!insideword) && (n[i] - ' '))
        {
            insideword = 1;
            words++;//conting words
        }
        
        if (n[i] - ' ') // in case of more than one space between two words
        {
            if ((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z'))
            {
                letters++;//conting letters
            }
            
            if ((n[i] == '.') || (n[i] == '!') || (n[i] == '?'))
            {
                sentences++;//conting sentences
            }
        }
        
        else
        {
            insideword = 0;
        }
    }
    float L = (letters * 100 / (float)words), S = (sentences * 100 / (float)words);
    index = (0.0588 * L) - (0.296 * S) - 15.8;
    return index;
}
//index = 0.0588 * L - 0.296 * S - 15.8  L= num medio de letras a cada 100 palavras
// s num medio de sentenças a cada 100 palavras
//L=num letras*100/num palavras
//S= num sentencas*100/ num palavras
