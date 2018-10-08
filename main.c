#include "funcoes.c"

int main(){

	int resp=1;
    char palavra[15];
	
	while(1){
        system("cls");
        printf("         *---------------------------*\n");
        printf("         |     MAQUINA DE TURING     |\n");
        printf("         *---------------------------*\n");
        printf("*--------------------------------------------*\n");
        printf("| |01| - Carregar Arquivo de Configuracao    |\n");
        printf("| |02| - Entrar Palavra                      |\n");
        printf("*--------------------------------------------*\n");
        printf("| |00| - Sair                                |\n");
        printf("*--------------------------------------------*\n\n");
        printf("ESCOLHA: ");
        fflush(stdin);
        printf("\n");

        scanf("%d", &resp);
        system("cls");

        switch(resp){
			case 1:

                inicializaArquivo("config.txt"); // carrega o arquivo de texto para o arquivo binario
                scanf("%*c");
                scanf("%*c");
                break;

            case 2:

                printf("Entre com a Palavra: \n");
                fflush(stdin);
                scanf("%[^\n]",&palavra);

                printf("\n");
                entrarPalavraMaquina(palavra);

                scanf("%*c");
                scanf("%*c");

                break;

			case 0:
                exit(1);
            default:
                printf("Invalido\n");
        }
    }
	return 0;
}
