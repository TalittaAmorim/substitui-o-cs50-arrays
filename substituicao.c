#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main( int argc, string argv [])
{
    // console 1 - validar número de argumento de contagem
    if(argc != 2)
    {
        printf("Escreva dessa forma: ./substituição 'chave' ");
        return 1;
    }
    // CONSOLE 2 - validar se argv[1] tem o tamanho de 26(alfabeto)
   if(strlen(argv[1]) != 26)
   {
      printf(" *Chave necessita de 26 caracteres!");
      printf("\n");
      return 1;
           
   }
   // Validar a chave internamente
     int contar_letras = 0;
    for(int i =0;i<strlen(argv[1]); i++) // Esse loop vai contar todas os caract alfabéticos da chave, no final se os o carct alfabéticos não forem do tamanho de argv[1], isso quer dizer que há outros tipos de caracteres. portanto, o programa retornar erro.
    {
        if (isalpha(argv[1][i]))
        {
          contar_letras++;
        }
        else if (contar_letras != strlen(argv[1]))
        {
           printf(" * A chave tem que ser toltamente alfabética.");
           return 1;
                
        }
    
        // VERIFICAR CARACTERES REPETIDOS.
    for(int r = i +1; r <strlen(argv[1]); r++)  // Para verificar SE contém algum caract repetido, esse loop vai iniciar com contador de i +1 --- pq o índice[i] de cada posiçao da chave já tinha sido checado em outro loop, entao esse checamento +1, significa que teve um caract repetido 
        {
          if(argv[1][i] == argv[1][r])
            {
                printf(" *Nao repitar as letras!");
                return 1;
            }
        }
    }
         string plaintext = get_string(" Plaintext: ");
         string diferença = argv[1]; // array que vai receber a chave 
         
         // PROCESSO DE SUBSTITUIÇÃO 
         for( int w = 'A'; w < 'Z'; w++) // Esse loop da constante do alfabeto em int(ASCII)
         {
             diferença[w - 'A'] = toupper(diferença[w -'A']) - w; // isso aqui vai pegar a diferença em int do código ascii das letras maiúsculas. EX: A(65) - A(65) = 0; logo se o plaintext tem a letra A, ele vai fazer essa técnica que faz a substituição da letra A por alguma outra letra da chave que tem a posição 0.
         }
         printf("ciphertext: ");
         
         for( int w =0, len = strlen(plaintext); w<len; w++)
         { 
             if(isalpha(plaintext[w]))
             {
                 plaintext[w] = plaintext[w] + diferença[plaintext[w] - (isupper(plaintext[w]) ? 'A' : 'a')]; // aqui vai ocorrer a substituiçao. Se for maiusculas ele vai diminuir 65 se for minúscula 97.
                 printf("%c", plaintext[w]);
             }
             else
             {
                 printf("%c", plaintext[w]);
             }
         }
         
    22/06/2022 (Решить эту проблему было довольно сложно.)
}
