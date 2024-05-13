//ARDUINO MORSE LED
//Criado por: Lorena Ferreira
//Ano: 2024
//
// Código em C/C++
// SOBRE O PROJETO
// Código Morse sendo enviado por meio de LED.
// Mais detalhes do projeto e como construir o circuito leia o arquivo pdf.

// bibliotecas utilizadas
//nenhuma

//definições de  variáveis Macros
#define DEBUGG_COMENTARIO   false // configurar como true para ativar as mensagens de debugg do código 
#define PINO_LED1           10   //número do pino digital usado pelo LED 1 indica que há mensagem
#define PINO_LED2           12   //número do pino digital usado pelo LED 2 indica o morse
#define TEMPO_MIN           50   //Tempo minimo em milisegundos
#define PRIMEI_ASCII_MORSE  33   //mudar a numeracao para o primeiro sempre que acrescentar novos morses
#define ULTIMO_ASCII_MORSE 122   //mudar a numeracao para o ultimo sempre que acrescentar novos morses
#define TAM_LINHA_SIMBO     97   //Tamanho maximo de linha no array de símbolos
#define TAM_LINHA_MORSE     64   //Tamanho maximo de linha no array de morses
#define TAM_COLUNA_SIMBO     3   //Tamanho maximo de coluna no array de símbolos
#define TAM_COLUNA_MORSE    14   //Tamanho maximo de coluna no array de morses

bool inconsistenciaMorse = false; //indica inconsistência no morse caso não haja algum morse

typedef struct {
  // "n" é inexistência de morse, os simbolos e morses têm a mesma posição
  const char simbolosAlfaNumPonto[TAM_LINHA_SIMBO][TAM_COLUNA_SIMBO] = {
    "!","\"","#","$","%","&","'",
    "(",")","*","+",",","-",".","/",
    "0","1","2","3","4","5","6","7","8","9",
    ":",";","<","=",">","?","@","A","B","C",
    "D","E","F","G","H","I","J","K","L","M",
    "N","O","P","Q","R","S","T","U","V","W",
    "X","Y","Z","[","\\","]","^","_", 
    "`", "a","b","c","d","e","f","g","h","i",
    "j","k","l","m","n","o","p","q","r","s",
    "t","u","v","w","x","y","z","{","|","}","~","Ç"     
  };
  const char codigoEmMorse[TAM_LINHA_MORSE][TAM_COLUNA_MORSE] = {
  "- . - . - -",  // 33 (!) posição [0]
  ". - . . - .",  // 34 (") posição [1]
  "n",            // 35 (#) posição [2]
  ". . . - . . -",// 36 ($) posição [3]
  "n",            // 37 (%) posição [4]
  ". - . . .",    // 38 (&) posição [5]
  ". - - - - .",  // 39 (') posição [6]
  "- . - - .",    // 40 (() posição [7]
  "- . - - . -",  // 41 ()) posição [8]
  "n",            // 42 (*) posição [9]
  ". - . - .",    // 43 (+) posição [10]
  "- - . . - -",  // 44 (,) posição [11]
  "- . . . . -",  // 45 (-) posição [12]
  ". - . - . -",  // 46 (.) posição [13]
  "- . . - .",    // 47 (/) posição [14]
  "- - - - -",    // 48 (0) posição [15]
  ". - - - -",    // 49 (1) posição [16]
  ". . - - -",    // 50 (2) posição [17]
  ". . . - -",    // 51 (3) posição [18]
  ". . . . -",    // 52 (4) posição [19]
  ". . . . .",    // 53 (5) posição [20]
  "- . . . .",    // 54 (6) posição [21]
  "- - . . .",    // 55 (7) posição [22]
  "- - - . .",    // 56 (8) posição [23]
  "- - - -.",     // 57 (9) posição [24]
  "- - - . . .",  // 58 (:) posição [25]
  "- . - . - .",  // 59 (;) posição [26]
  "n",            // 60 (<) posição [27]
  "- . . . -",    // 61 (=) posição [28]
  "n",            // 62 (>) posição [29]
  ". . - - . .",  // 63 (?) posição [30]
  ". - - . - .",  // 64 (@) posição [31]
  ". -",          // 65 (A) posição [32]
  "- . . .",      // 66 (B) posição [33]
  "- . - .",      // 67 (C) posição [34]
  "- . .",        // 68 (D) posição [35]
  ".",            // 69 (E) posição [36]
  ". . - .",      // 70 (F) posição [37]
  "- - .",        // 71 (G) posição [38]
  ". . . .",      // 72 (H) posição [39]
  ". .",          // 73 (I) posição [40]
  ". - - -",      // 74 (J) posição [41]
  "- . -",        // 75 (K) posição [42]
  ". - . .",      // 76 (L) posição [43]
  "- -",          // 77 (M) posição [44]
  "- .",          // 78 (N) posição [45]
  "- - -",        // 79 (O) posição [46]
  ". - - .",      // 80 (P) posição [47]
  "- - . -",      // 81 (Q) posição [48]
  ". - .",        // 82 (R) posição [49]
  ". . .",        // 83 (S) posição [50]
  "-",            // 84 (T) posição [51]
  ". . -",        // 85 (U) posição [52]
  ". . . -",      // 86 (V) posição [53]
  ". - -",        // 87 (W) posição [54]
  "- . . -",      // 88 (X) posição [55]
  "- . - -",      // 89 (Y) posição [56]
  "- - . .",      // 90 (Z) posição [57]
  "n",            // 91 ([) posição [58]
  "n",            // 92 (\) posição [59]
  "n",            // 93 (]) posição [60]
  "n",            // 94 (^) posição [61]
  ". . - - . -"   // 95 (_) posição [62]
};
} caracteresTexto; 

/*FUNÇÃO: receberMensagemDeTextoEmAlfa(void)
 * Recebe texto alfanumérico pelo monitor serial.
 * PARÊMETROS: [void] nenhum.
 * RETORNO: [String] retorna texto em simbolos alfanuméricos
 */
String receberMensagemDeTextoEmSimbolo(void)
{  
  String textoEmSimbolo = "";
  
  if (DEBUGG_COMENTARIO == true) Serial.println(F("receberMensagemDeTextoEmSimbolo - inicio"));
  
  Serial.println(F("ESCREVA UMA MENSAGEM:\n"));//coloca a mensagem no monitor serial
  while (Serial.available() <= 0) //verifica os bytes existentes. sem byte ele repete
  {
  }
  if(Serial.available()>0)
  {
     textoEmSimbolo = Serial.readString();
     if (DEBUGG_COMENTARIO == true) Serial.print(F("receberMensagemDeTextoEmSimbolo - tamanho texto simbolo:"));
     if (DEBUGG_COMENTARIO == true) Serial.println(sizeof(textoEmSimbolo));
     if (DEBUGG_COMENTARIO == true) Serial.print(F("receberMensagemDeTextoEmSimbolo - comprimento texto simbolo:"));
     if (DEBUGG_COMENTARIO == true) Serial.println(textoEmSimbolo.length());
     if (DEBUGG_COMENTARIO == true) Serial.print(F("receberMensagemDeTextoEmSimbolo - texto simbolo:"));
     Serial.println(textoEmSimbolo);
     if (DEBUGG_COMENTARIO == true) Serial.println(F("receberMensagemDeTextoEmSimbolo - fim"));
     return textoEmSimbolo;
  }
  if (DEBUGG_COMENTARIO == true) Serial.println(F("receberMensagemDeTextoEmSimbolo - fim"));

}

/*FUNÇÃO: colocarMorseEspacoEntreLetra(char proximoCaractere, char *textoEmDitDah, int letra)
 * Coloca asterisco como espaco entre letra para poder gerar tempo entre uma letra e outra no morse
 * PARÊMETROS: [IN] const char proximoCaractere, [IN/OUT] char *textoEmDitDah, [IN] const int letra.
 * RETORNO: [void] nenhum
 */
void colocarMorseEspacoEntreLetra(const char proximoCaractere, char *textoEmDitDah, const int letra)
{
    if (DEBUGG_COMENTARIO == true) Serial.println(F("colocarMorseEspacoEntreLetra - inicio"));
    if (DEBUGG_COMENTARIO == true) Serial.print(F("colocarMorseEspacoEntreLetra - proximo caractere:"));
    if (DEBUGG_COMENTARIO == true) Serial.println(proximoCaractere);
    if (DEBUGG_COMENTARIO == true) Serial.print(F("colocarMorseEspacoEntreLetra - numero da letra no texto original:"));
    if (DEBUGG_COMENTARIO == true) Serial.println(letra);
    if(int(proximoCaractere) != 32 && int(proximoCaractere) != 0 && int(proximoCaractere) != 10)
    {
      //coloca * como espaço entre letra
      sprintf(&textoEmDitDah[strlen(textoEmDitDah)], "*");
     
      if (DEBUGG_COMENTARIO == true) Serial.print(F("colocarMorseEspacoEntreLetra - Espaco letra, texto morse:"));
      if (DEBUGG_COMENTARIO == true) Serial.println(textoEmDitDah);
    } 
    else if (DEBUGG_COMENTARIO == true) Serial.println(F("colocarMorseEspacoEntreLetra - nada a colocar"));

    if (DEBUGG_COMENTARIO == true) Serial.println(F("colocarMorseEspacoEntreLetra - fim"));
}

/*FUNÇÃO: converterTextoEmDitDat(char *textoMorse)
 * Converte texto em dit dah.
 * PARÂMETROS: [IN] String textoEmSimbolos (recebe texto em simbolos alfanumericos de acordo com ASCII), [OUT] char *textoDitDah (ponteiro para receber o texto convertido em dit e dah)
 * RETORNO: [String] retorna texto em dit e dah
 */
int converterTextoEmDitDat(String textoEmSimbolos, char *textoEmDitDah)
{
  int letra = 0;
  caracteresTexto caractere;
      
  if (DEBUGG_COMENTARIO == true) Serial.println(F("converterTextoEmDitDat - inicio"));

  inconsistenciaMorse = false;
  if(textoEmSimbolos.length() <= 0)
  {
    if (DEBUGG_COMENTARIO == true) Serial.println(F("converterTextoEmDitDat - Erro: parametro textoEmSimbolos vazia"));
    return -1;
  }
      
  for (letra = 0; letra<textoEmSimbolos.length(); letra++)
  {
    if (DEBUGG_COMENTARIO == true) Serial.print(letra);
    if (DEBUGG_COMENTARIO == true) Serial.println("\n");
    if (DEBUGG_COMENTARIO == true) Serial.print(F("converterTextoEmDitDat - letra:"));
    if (DEBUGG_COMENTARIO == true) Serial.println(textoEmSimbolos[letra]);
    if (DEBUGG_COMENTARIO == true) Serial.print(F("converterTextoEmDitDat - Codigo decimal ascii da letra:"));
    if (DEBUGG_COMENTARIO == true) Serial.println(int(textoEmSimbolos[letra]));
    
    switch(int(textoEmSimbolos[letra]))
    {
      case 0:
      case 10:
      {
        //se for o final do array ele para o loop = null em ascii
        if (DEBUGG_COMENTARIO == true) Serial.print(F("converterTextoEmDitDat - Fim da mensagem\n"));
        break;
      }
      case 32:
      {
        //espaço por palavra
        sprintf(&textoEmDitDah[strlen(textoEmDitDah)], "#");
        if (DEBUGG_COMENTARIO == true) Serial.print(F("converterTextoEmDitDat - Espaco palavra, texto morse: "));
        if (DEBUGG_COMENTARIO == true) Serial.println(textoEmDitDah);
        continue;//continua o loop do for
      }
      default:
      {
             
        if(int(textoEmSimbolos[letra])>ULTIMO_ASCII_MORSE || int(textoEmSimbolos[letra])<PRIMEI_ASCII_MORSE) 
        {
          //entra aqui ser o ascii for menor que o primeiro da lista ou maior que o ultimo da lista
          Serial.print(F("Morse não existe para: "));
          Serial.println(textoEmSimbolos[letra]);
          inconsistenciaMorse = true;
          colocarMorseEspacoEntreLetra(textoEmSimbolos[letra+1], textoEmDitDah, letra);
          continue;
        }
        else
        {
          // debugg
          if (DEBUGG_COMENTARIO == true) Serial.print(F("converterTextoEmDitDat - Letra na struct:"));
          if (DEBUGG_COMENTARIO == true) Serial.println(caractere.simbolosAlfaNumPonto[int(textoEmSimbolos[letra])-33]);
          if (DEBUGG_COMENTARIO == true) Serial.print(F("converterTextoEmDitDat - Letra morse na struct simbolo:"));
          if (DEBUGG_COMENTARIO == true) Serial.println(int(*caractere.simbolosAlfaNumPonto[int(textoEmSimbolos[letra])-33]));
          
          if (int(*caractere.simbolosAlfaNumPonto[int(textoEmSimbolos[letra])-33]) == int(textoEmSimbolos[letra]))
          {
             //entra aqui se o simbolo existir na tabela
             if(int(textoEmSimbolos[letra]) >= 97 && int(textoEmSimbolos[letra]) <= 122)
             {
              //entra se for ascii de a-z, morse é igual de A-Z
              sprintf(&textoEmDitDah[strlen(textoEmDitDah)], caractere.codigoEmMorse[int(textoEmSimbolos[letra])-32-33]);
              colocarMorseEspacoEntreLetra(textoEmSimbolos[letra+1], textoEmDitDah, letra);
              continue;
             }
             else
             {
                if (int(*caractere.codigoEmMorse[int(textoEmSimbolos[letra])-33]) == int('n'))
                {
                  //entra aqui se na lista de morse tiver "n" indicndo inexistencia de morse
                  Serial.print(F("Morse não existe para: "));
                  Serial.println(textoEmSimbolos[letra]);
                  inconsistenciaMorse = true;
                  colocarMorseEspacoEntreLetra(textoEmSimbolos[letra+1], textoEmDitDah, letra);
                  continue;
                }
                else
                {
                  sprintf(&textoEmDitDah[strlen(textoEmDitDah)], caractere.codigoEmMorse[int(textoEmSimbolos[letra])-33]);
                  colocarMorseEspacoEntreLetra(textoEmSimbolos[letra+1], textoEmDitDah, letra);
                  continue;
                }
             }
          }
          else
          {
             if (caractere.codigoEmMorse[int(textoEmSimbolos[letra])-33] == "n")
             {
                //entra aqui se na lista de morse tiver "n" indicndo inexistencia de morse
                Serial.print(F("Morse não existe para: "));
                Serial.println(textoEmSimbolos[letra]);
                inconsistenciaMorse = true;
                colocarMorseEspacoEntreLetra(textoEmSimbolos[letra+1], textoEmDitDah, letra);
                continue;
             }
             else
             {
              inconsistenciaMorse = true; //aqui pode ser colocado outros cases além do if acima
              colocarMorseEspacoEntreLetra(textoEmSimbolos[letra+1], textoEmDitDah, letra);
              continue;
             }
          }
        }
          
        continue;//continua o loop for
      }
    }
  }
  
  if (strlen(textoEmDitDah)>0)
  {
      Serial.println("Morse gerado ");
      if(inconsistenciaMorse == true) Serial.println(F("com inconsistencia. "));
      Serial.print(F("Morse:"));
      Serial.println(textoEmDitDah);
      if (DEBUGG_COMENTARIO == true) Serial.println(F("converterTextoEmDitDat - fim"));
      return 1;
  }
}
/*FUNÇÃO: mandarMensagemMorseNoLed(char *textoMorse)
 * Acender LEDs conforme texto em morse
 * LED 1: enquanto estiver aceso há mensagem
 * LED 2: acende conforme texto e respectivo tempo em morse
 * PARÊMETROS: [IN] char *textoMorse (recebe texto em morse)
 * RETORNO: [int] 1 para ok e -1 para erro
 */
int mandarMensagemMorseNoLed(char *textoMorse)
{
  int tempoDit  = TEMPO_MIN; //dit e espaco entre dit e dah tem tempo de um dit
  int tempoDah  = 3 * tempoDit;//dah e espalo entre palavras tem empo s 
  int tempoEspacoPalavra  = 7 * tempoDit;//dah e espaço entre palavras tem tempo de 7 dit 

  if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - inicio"));
  
  if (strlen(textoMorse) <= 0) return -1;
  else
  {
    delay(2500);
    digitalWrite(PINO_LED1, HIGH);
    delay(1500);
  }
  if (DEBUGG_COMENTARIO == true) Serial.print(F("mandarMensagemMorseNoLed - tamanho texto morse: "));
  if (DEBUGG_COMENTARIO == true) Serial.println(sizeof(textoMorse));
  if (DEBUGG_COMENTARIO == true) Serial.print(F("mandarMensagemMorseNoLed - comprimento texto morse: "));
  if (DEBUGG_COMENTARIO == true) Serial.println(strlen(textoMorse));
  for (int contador = 0; contador<=strlen(textoMorse); contador++)
  {
    if (DEBUGG_COMENTARIO == true) Serial.print(F("mandarMensagemMorseNoLed - digito morse: "));
    if (DEBUGG_COMENTARIO == true) Serial.println(textoMorse[contador]);
    if (DEBUGG_COMENTARIO == true) Serial.print(F("mandarMensagemMorseNoLed - posição morse: "));
    if (DEBUGG_COMENTARIO == true) Serial.println(contador);
    switch (textoMorse[contador])
    {
      case '.':
      {
        digitalWrite(PINO_LED2, HIGH);
        if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - dit"));
        delay(tempoDit);
        continue;
      }
      case '-':
      {
        digitalWrite(PINO_LED2, HIGH);
        if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - dah"));
        delay(tempoDah);
        continue;
      }
      case '*':
      {
        digitalWrite(PINO_LED2, LOW);
        delay(tempoDah);
        if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - espaco letra"));
        continue;
      }
      case ' ':
      {
        digitalWrite(PINO_LED2, LOW);
        delay(tempoDit);
        if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - espaco dit dah"));
        continue;
      }
      case '#':
      {
        digitalWrite(PINO_LED2, LOW);
        delay(tempoEspacoPalavra);
        if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - espaco palavra"));
        continue;
      }
      case 'n':
      {
        //morse nao existe
        if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - morse não existe"));
        continue;
      }
      default: 
      {
        digitalWrite(PINO_LED2, LOW);
        continue;
      }
    }
  }
  digitalWrite(PINO_LED2, LOW);
  delay(1000); // delay de um segundo para apagar o LED 1
  digitalWrite(PINO_LED1, LOW);
  if (DEBUGG_COMENTARIO == true) Serial.println(F("mandarMensagemMorseNoLed - fim"));
  return 1;
}

/*FUNÇÃO: setup()
 * Configura pino ou portas referentes aos LEDs e o Monitor Serial
 * PARÊMETROS: void, nenhum
 * RETORNO: void
 */
void setup( void)
{
  Serial.begin(9600);//aciona o motor serial para manda mensagens de 9600 bits/s
  if (DEBUGG_COMENTARIO == true)  Serial.println(F("setup - inicio"));
  pinMode(PINO_LED1, OUTPUT);//configura o pino como modo saída
  pinMode(PINO_LED2, OUTPUT);//configura o pino como modo saída
  if (DEBUGG_COMENTARIO == true) Serial.println(F("setup - fim"));
}

/*FUNÇÃO: loop()
 * Rodará toda a estrutura do código pra receber e converter mensagem texto em morse e depois apresentar nos LEDs
 * PARÊMETROS: void
 * RETORNO: void
 */
void loop(void)
{
  String textoEmSimbolos = "";
  caracteresTexto caractere;
        
  if (DEBUGG_COMENTARIO == true) Serial.println(F("loop - inicio"));

  inconsistenciaMorse = false;

  textoEmSimbolos = receberMensagemDeTextoEmSimbolo();

  if(sizeof(textoEmSimbolos) > 0)
  {
    char textoEmDitDah [100*sizeof(textoEmSimbolos)] = "";
    memset(textoEmDitDah, 0, sizeof(textoEmDitDah));
  

    if(converterTextoEmDitDat(textoEmSimbolos, textoEmDitDah) <= 0)
    {
       if (DEBUGG_COMENTARIO == true) Serial.print(F("loop - Erro em converterTextoEmDitDat\n"));
    }
    
    if(mandarMensagemMorseNoLed(textoEmDitDah)<=0)
    {
      if (DEBUGG_COMENTARIO == true) Serial.print(F("loop - Erro em mandarMensagemMorseNoLed\n"));
    }
  }
  if (DEBUGG_COMENTARIO == true) Serial.println(F("loop - fim"));

}
