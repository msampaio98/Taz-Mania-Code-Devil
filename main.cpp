#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    //Leitura do arquivo com o programa
    programa("nomeArquivo.tmcd");

    //Retorno dos tokens
    RetornaToken ();

   return 0;
}
