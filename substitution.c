#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    int cont_key_caractere = 0;
    int cont_repeat_caractere = 0;
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                cont_key_caractere+=1;
            }
        }
        for (int j = 0, n = strlen(argv[1]); j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (tolower(argv[1][j]) == tolower(argv[1][k]))
                {
                    cont_repeat_caractere+=1;
                }
            }
        }
        if (strlen(argv[1]) != 26)
        {
            printf("Não Foi digitado 26 letras.\n");
            return 1;
        }
        else if (cont_key_caractere != strlen(argv[1]))
        {
            printf("A chave de conter somente letras\n");
            return 1;
        }
        else if (cont_repeat_caractere != 0)
        {
            printf("A chave não deve conter letras repetidas\n");
            return 1;
        }
        else
        {
            string plain = get_string("Plaintext: ");
            printf("Ciphertext:");
            for (int w = 0, x = strlen(plain); w < x; w++)
            {
                if (isalpha(plain[w]) && isupper(plain[w]))
                {
                    int upper = (plain[w] - 65);
                    printf("%c", toupper(argv[1][upper]));
                }
                else if (isalpha(plain[w]) && islower(plain[w]))
                {
                    int lower = (plain[w] - 97);
                    printf("%c", tolower(argv[1][lower]));
                }
                else
                {
                    printf("%c", plain[w]);
                }
            }
            printf("\n");
            return 0;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

