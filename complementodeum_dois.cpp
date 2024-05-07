#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define esc 27
//quando o numero é par gera carry, impar não gera
//aqui d´para ver que os numeros são compatíveis ao tipode dado que pode contêlo, entao 10 é int, mas 60000 é unsigned e 100000 é long
int main(void)
{
    int num       = 0;
    int comp_um   = 0;
    int comp_dois = 0;
    int carry     = 0;
    
    do{
        int auxiliar = 0;
        printf("digite um numero: \n");
    
        scanf("%d", &num);
        if(num<0){ system("cls"); continue;}
        printf("numero:%d\n", num);
        comp_um = ~num;
        printf("complemento de um:%d\n\n"  ,   comp_um);
        comp_dois = comp_um^1;
        carry = comp_um&1;
        if(carry>0) auxiliar = comp_dois;
        while(carry>0)
        {
          printf("carry:%d\n", carry);

          carry = carry<<1;
          comp_dois = auxiliar^carry;
          printf("aux %d XOR carry %d:%d\n\n", auxiliar, carry, comp_dois);
          carry = auxiliar&carry;
          auxiliar = comp_dois;
        }
        printf("complemento de dois:%d\n\n", comp_dois);
        system("pause");
        system("cls");
        
    }while(_getch() != esc);
    
    system("pause");
    return 0;
}
