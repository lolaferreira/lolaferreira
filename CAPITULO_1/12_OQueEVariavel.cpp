// CRIADO POR: Lorena Ferreira
// ANO: maio de 2024
// LEIA A LICENSA ANTES DE USAR
// FICOU COM DUVIDAS, TEM SUGESTOES, GOSTOU? ME MANDE UMA MENSAGEM!

//OBS.: cada projeto tem sua característica e estrutura. Verifique o ambiente e o padrão de desenvolvimento.
//Esse conteúdo tem por finalidade o estudo, a implementação dele em sistemas maiores varia de acordo com o contexto.


/*EXPLICACAO DO CODIGO

O que é variável?
Pense a variável é como se fosse uma caixa na qual será guardada uma informação.
Essa caixa precisa ser sinalizada com o tipo de informação que ela pode guardar, que podem ser:
TIPO    TAMANHO (em bits)  DESCRICAO
char      8                caractectere (segue a tabela ASCII)
int       16               inteiro 
float     32               ponto flutuante (casas decimais depois da vígula)
double    64               ponto flutuante de dupla precisão
void                       vazio

A atribuição de um valor deve ser feita por meio do sinal de igual seguido do valor e ponto e vírgula.

COMO DECLARAR? 
TIPO_VARIAVEL NOME_VARIAVEL = VALOR_VARIAVEL;

COMO NOMEAR?
- NÃO pode começar por numero.
- NÃO pode ter caractere especial, como: *, ... e outros. Pode sublinhado (_).
- NÃO pode ser nome de alguma palavra-chave da linguagem, como: if, else, int e afins.
- NÃO pode nome de funções.
- Caixa alta ou baixa indica variáveis distintas, ex.: x e X são variaveis diferentes.
*/

#include <stdio.h>

int main(void)
{
    int    var_inteiro   = 140.7648352;
    float  var_flutuante = 140.7648352;
    double var_duplo     = 140.7648352;
    char   var_caractere = 65; //decimal ASCII para A ("a" maiúsculo)
    
    printf("a variavel var_inteiro   %d\n"  , var_inteiro  );//mostra a parte inteira
    printf("a variavel var_flutuante %.3f\n", var_flutuante); //mostra a inteira com tres casas depois da vígula (indicado pelo %.3f)
    printf("a variavel var_duplo     %lf\n" , var_duplo    );
    printf("a variavel var_caractere %c\n"  , var_caractere);//mostra o caractere assocido ao inteiro 65

    return 0;
}
