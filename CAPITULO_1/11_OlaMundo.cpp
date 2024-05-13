// Criado por: Lorena Ferreira
//ano: maio de 2024
// LEIA A LICENSA ANTES DE USAR
// FICOU COM DUVIDAS, TEM SUGESTOES, GOSTOU? ME MANDE UMA MENSAGEM!

//OBS.: cada projeto tem sua característica e estrutura. Verifique o ambiente e o padrão de desenvolvimento.
//Esse conteúdo tem por finalidade o estudo, a implementação dele em sistemas maiores varia de acordo com o contexto.


/*EXPLICACAO DO CODIGO
Esse código é o mais simples e básico que costuma ser ensinado.

Nele é apresentado o uso de algumas bibliotecas, a função main(), ou principal,
e a função printf(), ou print formatted.

O QUE É BIBLIOTECA?
É um arquivo de extensão .h (arquivo de cabeçalho) que apresenta referências (prototipagem) de um conjunto de funções
que são de instruções preestabelecidas e que são usadas para criar outras funções. Essas funções são geralmente 
de uso comum, que se repetem com frequência.

Para referencia-la use no topo do código: 
     #include <NOME_BIBLIOTECA.h> // <> -> procura o arquivo no diretorio definido com arquivos de inclusao
  ou #include "NOME_BIBLIOTECA.h" // "" -> procura o arquivo no diretorio atual

#include é uma diretiva de preprocessamento para o compilador ler e compilar o código fonte do arquivo referenciado

O QUE É FUNÇÃO?
É  um tipo de bloco onde se encontram as instruções que o computador deve realizar.
Sua estrutura:
    TIPO_FUNCAO NOME_FUNCAO(PARAMETROS_FUNCAO)
    {
      INSTRUCOES_FUNCAO
    }
Observe essa estrutura com a main() e a printf(). Vê alguma diferença na implementação?

MAIN()
Prototipaçao (nesse código): int main(void);

A função main() é a principal. 
Por padrão ela sempre será chamada primeiro na execução de um arquivo de extensão .c ou .cpp...
Isso quer dizer que todo código deve tê-la como ponto inicial.
De modo geral, ela pode ser de diferentes tipos e ter ou não parametros e retornos. 

PRINTF()
Prototipação: int printf(const char*,...);
Sua biblioteca: stdio.h (standard input output, padrao de entrada e saída)

É usado para imprimir uma informação em uma tela.

- Recebe um parametro (variável) do tipo char point (ou ponteiro de char) que não pode ser alterado, constante.
É o conteudo que será impresso.
- Os três pontos do protótipo indicam a possibilidade de uso de parametros para apresentar informações a serem substituídas,
por meio de um marcador, indicado pela porcentagem (%), seguido pelo código de formato. Exemplos:

          printf("Sou o/a %s\n", "SEU_NOME"); // %s para string. Coloque seu nome nas aspas duplass         
          printf("Sou o/a %s %s\n", "SEU_NOME", "SEU_SOBRENOME"); //coloque seu nome e sobrenome nas aspas duplass       
          printf("Hoje é %d%d%d\n", DIA, MES, ANO); //%d para inteiros decimais com sinal. Coloque o dia, mes e ano em numero inteiro.

*/

#include <stdio.h>
//#include <stdlib.h> //opcional: biblioteca para uso da função system(), descomente para usar

int main(void)
{
    printf("hello world!\n");
    
    //system("pause");//opcional: use caso a execução esteja rápida demais. Irá pedir para teclar qualquer tecla para prosseguir
    return 0; // return é um comando de desvio para retornar para aonde a função main foi chamada (processo chamador), encerrando a execução.
    // Retorno de inteiro 0, por padrão ANSI, indica sucesso na execução. Ele não é usado para funções do tipo void, ou seja, que não retornam valor.
}
