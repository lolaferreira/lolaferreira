// AUTORA: Lorena Ferreira
// ANO: 2024
// LEIA A LICENSA ANTES DE USAR
// FICOU COM DUVIDAS, TEM SUGESTOES, GOSTOU? ME MANDE UMA MENSAGEM!

//OBS.: cada projeto tem sua característica e estrutura. Verifique o ambiente e o padrão de desenvolvimento.
//Esse conteúdo tem por finalidade o estudo, a implementação dele em sistemas maiores varia de acordo com o contexto.


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define esc 27 //macro para tecla ESC

/*EXPLICACAO DO CODIGO
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
0001 AND 0001 = 0001 (and gerou carry se ambas as entradas forem 1, verifica que 
ha carry na primeira posicao que precisa ir para a posicao do lado)
Muda o bit 1 do resultado de AND para a esquerda -> de 0001 para 0010.
faz XOR de 0000 com 0010 = 0010 que resulta em 2.

2 - COMPLEMENTO DE UM e quando inverte 1 em 0 ou vice e versa no binario. 
Entao, complemento de um de 0000 -> 1111. Isso cria duas representacoes do decimal 0, +0 e -0.
Caso faca subtracao usando complemento de um, pode encontrar erro matematico, como: 
5+(-3) = 2  -> 0101 (5)
            -> 0011 (3) e 1100 (-3) aqui usa complemento de um para achar a representacao negativa     
    0101
XOR 1100 =
    0001, aqui ja considerei o carry na conta, e resultou em 1.
    
3 - Para resolver isso se usa o COMPLEMENTO DE DOIS que seria somar 1 ao inverso.
-3 que e 1100 acrescido de 0001
    0101
XOR 1101 =
    0010, aqui ja considerei o carry na conta, e resultou em 2.
    O complemento de dois nao tem duas representacoes de zero, pois o mais 1 ajusta.
    Ele tambem usa do bit mais significativo a esquerda para representar numeros, entao se o bit inicial for 1,
o numero seria negativo, se 0, positivo, ou seja, 0001 seria o decimal 1 e o 1111 seria o decimal -1. O seu sentido matematico
esta que o primeiro bit a esquerda seria negativo: 1111 seria, considerando os bits ligados, -8+4+2+1 = -1.
outro exemplo: 1001 seria -8+1 = -7. Isso gera os tipos de dados signed (considera o bit mais signifitivo para 
ter numeros positivos e negativos) e o unsigned (os numeros sao sempre positivos).

4 - Nesse codigo da para ver que os numeros são compatíveis ao tipo de dado que pode contêlo,
entao 10 é int, mas 60000 é unsigned e 100000 é long
*/
int main(void) 
{
    int num       = 0;
    int comp_um   = 0;
    int comp_dois = 0;
    int carry     = 0;
    
    do{
        int auxiliar = 0;
        
        printf("digite um numero positivo: \n");
        scanf("%d", &num); //quando numero
        
        if(num<0){ system("cls"); continue;} //se o numero colocado for negativo, limpa tela e pede numero novamente
        printf("numero:%d\n", num); //mostra numero colocado
        comp_um = ~num;//inverte numero (comp de um)
        printf("complemento de um:%d\n\n"  ,   comp_um);
        comp_dois = comp_um^1; //(faz xor de 1 ao numero, comp de dois)
        carry = comp_um&1; //verifica carry
        if(carry>0) auxiliar = comp_dois; //guarda o resultado no auxiliar para fazer a conta no loop
        while(carry>0)
        {
          //loop para continuar a conta enquanto houver carry
          printf("carry:%d\n", carry);

          carry = carry<<1; // muda um bit para esquerda para receber o carry na posicao certa
          comp_dois = auxiliar^carry;//soma carry
          printf("aux %d XOR carry %d:%d\n\n", auxiliar, carry, comp_dois);
          carry = auxiliar&carry;//verifica carry
          auxiliar = comp_dois;
        }
        printf("complemento de dois:%d\n\n", comp_dois);
        system("pause");//espera clicar alguma tecla
        system("cls");//limpa tela
        
    }while(_getch() != esc);//sai apenas se apertar esc
    
    system("pause");
    return 0;//retorna sucesso, em sistema embarcado e importante cuidar para os retornos
    //seguirem um padrao para o SO voltar a ter controle e nao ficar com processos fantasmas
}
