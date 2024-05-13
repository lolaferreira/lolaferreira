// AUTORA: Lorena Ferreira
// ANO: 2024
// LEIA A LICENSA ANTES DE USAR
// FICOU COM DUVIDAS, TEM SUGESTOES, GOSTOU? ME MANDE UMA MENSAGEM!

//OBS.: cada projeto tem sua característica e estrutura. Verifique o ambiente e o padrão de desenvolvimento.
//Esse conteúdo tem por finalidade o estudo, a implementação dele em sistemas maiores varia de acordo com o contexto.

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <termios.h>

#define esc 27

//DETALHE IMPORTANTE: operador bit a bit só pode ser usado em tipo inteiro
/*EXPLICACAO DE COMO OCORRE A SOMA E SUBTRACAO
1- Quando o numero é par gera carry (sobe um), impar não gera. Carry e verificado com a porta logica AND.
tabela verdade XOR e AND:
A B XOR   A B AND
0 0  0    0 0  0
1 0  1    1 0  0
0 1  1    0 1  0
1 1  0    1 1  1

Como a soma acontece com essas portas?
1+1 = 2
0001 XOR 0001 = 0000 (xor e usado na soma, mas na pratica nao consegue acrescentar o carry, por isso resulta em zero)
0001 AND 0001 = 0001 (and gera carry se ambas as entradas forem 1, no caso
ha carry na primeira posicao que precisa ir para a posicao do lado)
Muda o bit 1 do resultado de AND para a esquerda -> de 0001 para 0010.
faz XOR de 0000 com 0010 = 0010 que resulta em 2.

A subtracao seria uma soma de um numero positivo e um numero negativo, sabendo o complemento de um e dois, que pode ser visto no codigo
complementodeum_dois, a compreensao do fenomeno fica melhor.
*/

int main(void)
{
    int num_1 = 0;
    int num_2 = 0;
    
    do
    {
      int soma_xor      = 0;
      int carry_and     = 0;
      int bit_wise      = 0;
      int resultado_xor = 0;
      int auxiliar      = 0;
      
      printf("digite o primeiro numero:\n");
      scanf("%d", &num_1);   
      printf("digite o segundo numero:\n");
      scanf("%d", &num_2);   
      soma_xor = num_1^num_2;
      printf("\n%d XOR %d: %d\n", num_1, num_2, soma_xor);
      carry_and = num_1&num_2;

      if(carry_and > 0 || carry_and < 0)
      {
        //caso for soma de numeros negativos o carry dará negativo
        printf("CARRY! %d AND %d: %d\n", num_1, num_2, carry_and);
        auxiliar = soma_xor;
      }
      if( carry_and == 0)
      {
        resultado_xor = soma_xor;
        printf("SEM CARRY!\n");
      }
      
      while(carry_and > 0 || carry_and < 0)
      {
        bit_wise = carry_and << 1;
        printf("Mudando 1 bit para esquerda: de %d para %d\n", carry_and, bit_wise);
        resultado_xor = auxiliar^bit_wise;
        printf("%d XOR %d: %d\n", soma_xor, bit_wise, resultado_xor); 
        carry_and = auxiliar&bit_wise;
        if(carry_and > 0 || carry_and < 0)
        {
           printf("CARRY!! %d AND %d: %d\n", soma_xor, bit_wise, carry_and); 
           auxiliar = resultado_xor;
        }
      }
      printf("\nRESULTADO FINAL de %d + %d = %d\n\n", num_1, num_2, resultado_xor); 

    }while(_getchar() != esc);
    
    exit(0); //função que faz o mesmo que o return
}
