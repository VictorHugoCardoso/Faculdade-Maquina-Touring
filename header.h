#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    char estadoAtual[10];
    char sLidoFita;
    char proximoEstado[10];
    char escritoFita;
    char direcao;
}transicao;


char estados[50][5],estados_finais[50][5],alfabetoFita[10];
int n_transicoes=0,n_estados_finais;
transicao vetorTransicao[50];

void entrarPalavraMaquina(char* palavra);

void inicializaArquivo(char* txt);

