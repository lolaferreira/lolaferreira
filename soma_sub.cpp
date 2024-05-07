#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h> //unistd.h no UNIX, para usar o sleep

#define esc 27
//operador bit a bit só pode ser usado em tipo inteiro

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
        bit_wise = carry_and<<1;
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
      system("pause"); 
      system("cls");

    }while(_getch() != esc);
    system("pause");
    exit(0);
}
