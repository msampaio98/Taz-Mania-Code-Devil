/*----------Declara��o das Bibliotecas----------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

using namespace std;

/*----------Defini��o do Tipo----------*/
typedef struct token {
    int classeToken;
    char lexema[100];
    int linhaLexema;
};

/*----------Declara��o das vari�veis----------*/
char c; //Caracter que vai ser analisado
int contadorLinha = 1;
int inicioLexema = 0;
int proxPontLexema = 0;
char *vetor; //Pointeiro que armazena o arquivo

/*----------In�cio da leitura do arquivo do programa----------*/
char leituraPrograma(char* nomePrograma){

    FILE *programa;//ponteiro do arquivo
    char caractere;//recebe um caracter lido do arquivo
    int contadorCaractere = 0; //Receber� o tanto de caracteres que o arquivo tem.
    int aux = 0; //Serve para auxiliar na inser��o de dados no vetor;

    //Abre o arquivo somente para leitura
/*-------------------------------------------
Se o arquivo n�o for encontrado ou n�o puder
se aberto retornara um mensagem de erro
--------------------------------------------*/
if((programa = fopen(nomePrograma,"r")) == NULL){
cout << ":.Erro na Abertura do Arquivo.:" << endl;
cout << "Verifique se o endere�o do arquivo est� correto..." << endl;
}
/*-------------------------------------------
Enquanto o caractere for diferente do ultimo caractere do arquivo,
ele ir� contar quantos caracteres existem.
--------------------------------------------*/
while((caractere = getc(programa)) != EOF){
    contadorCaractere++;
}

/*--------------------------------------------
Alocando vetor dinamicamente com a quantidade
de caracteres que contem no arquivo
--------------------------------------------*/
vetor = new char[contadorCaractere];


/*--------------------------------------------
Limpeza do vetor para garantir que ele esteja limpo, evitando que
caracteres antigos ou indesejados atrapalhem o novo conte�do.
--------------------------------------------*/
for(int i = 0; i < contadorCaractere; i++){
    vetor[i]=NULL;
}

//Retorna o ponteiro ao in�cio do arquivo
rewind(programa);

//Nova leitura de caracteres do arquivo, por�m agora inserindo caracteres no vetor
while((caractere = getc(programa)) != EOF){
    vetor[aux] = caractere;
    aux++;
}
/*--------------------------------------------
Insere '\0' no final do vetor para
que possa identificar o final.
--------------------------------------------*/
vetor[contadorCaractere] = '\0';

//Fecha o arquivo
fclose(programa);
}
/*----------Fim da leitura do arquivo do programa----------*/

/*----------Inicio da leitura do Pr�ximo Caractere----------*/
char ProximoCaractere(){
    c = vetor[linhaLexema++];
    if(c == '\n'){
        linha++;
    }
    return c;
}
/*----------Fim da leitura do Pr�ximo Caractere----------*/
