#include "header.h"

void entrarPalavraMaquina(char* palavra){

    char estado_atual[5],palavraAux[15],estado_aux[5];
    char* Aux;
    Aux = malloc(15*sizeof(char));

    strcat(palavra,"$");

    strcpy(estado_atual,"[");
    strcat(estado_atual,"q0");
    strcat(estado_atual,"]");
    strcpy(estado_aux,"q0");

    strcpy(Aux,estado_atual);
    strcat(Aux,palavra);
     	
    strcpy(palavraAux, Aux);
    free(Aux);

	int i=0;
    int parou = 0;

    do{
        int k=0;
        printf("*%s\n",palavraAux);
        while(k < n_transicoes){
            if(palavra[i] == vetorTransicao[k].sLidoFita && strcmp(estado_aux,vetorTransicao[k].estadoAtual)==0)
                break;
            k++;
        }
        if(k == n_transicoes){
            parou = 1;
        }else{
            strcpy(estado_atual,"[");
            strcat(estado_atual,vetorTransicao[k].proximoEstado);
            strcat(estado_atual,"]");
            strcpy(estado_aux,vetorTransicao[k].proximoEstado);
             
            palavra[i] = vetorTransicao[k].escritoFita;
            if(vetorTransicao[k].direcao == 'D'){
                int j;
                char s[100];
                int c=0;
                for(j=i+1;j<strlen(palavra);j++){
                    s[c] = palavra[j];          
                    c++;        
                }
                s[c] = '\0';
                strncpy(palavraAux,palavra,i+1);
                palavraAux[i+1] = '\0';
                strcat(palavraAux,estado_atual);
                strcat(palavraAux,s);
                i++;
                 
            }
            else if(vetorTransicao[k].direcao == 'E'){
                int j;
                char s[50];
                int c=0;
                for(j=i-1;j<strlen(palavra);j++){
                    s[c] = palavra[j];          
                    c++;        
                }
                s[c] = '\0';
                strncpy(palavraAux,palavra,i-1);
                palavraAux[i-1] = '\0';
                strcat(palavraAux,estado_atual);
                strcat(palavraAux,s);
                i--;
             
            }
        }
    }while(parou == 0);

}

void inicializaArquivo(char* txt){
	char s[200];
	n_transicoes=0;

	FILE *arq;
	if((arq = fopen(txt,"r")) == NULL){
		printf("Erro ao abrir o arquivo texto\n"); //erro na abertura do arquivo
	}else{
		fseek(arq,0,SEEK_SET);								//posiciona o cursor no comeco do arquivo texto
			
		int i,k;
		char aux[10];


		while(fgets(s,100,arq) != 0){
			for(i=0;i<10;i++){
	        	aux[i] = '\0';
	    	}
	    	k = 0;
			i = 0;

			if(s[0] == 'Q'){
				k = 0;
				i = 2;

				for(k=0; i<strlen(s)-1; i++,k++){	
					aux[k] = s[i];
				}

				int numeroEstados = atoi(aux);

				for(i=0;i < numeroEstados;i++){
					char estado[3];
					char num[2];

					itoa(i,num,10);

					strcpy(estado,"q");
					strcat(estado,num);

					strcpy(estados[i], estado);
				}

			}
			if(s[0] == 'F'){
				k = 0;
				i = 3;

				int contaEstados = 1;

				while(s[i] != '}'){
					if(s[i] == ','){
						contaEstados++;	
					}
					i++;
				}

				k = 0;
				i = 3;

				for(int j=0;j < contaEstados;j++){
					if(j != contaEstados-1){
						while(s[i] != ','){
							aux[k] = s[i];
							i++;k++;
						}

						k = 0;
						i += 1;
					}else{
						while(s[i] != '}'){
							aux[k] = s[i];	
							i++;k++;
						}
					}
					strcpy(estados_finais[i], aux);
				}
				n_estados_finais = contaEstados;
			}
			if(s[0] == 'a'){
				k = 0;
				i = 10;

				for(i=0;i<10;i++){
	        		alfabetoFita[i] = '\0';
	    		}

				while(s[i] != '}'){
					if(s[i] != ','){
						alfabetoFita[k] = s[i];
						i++;
						k++;
					}else{
						i++;
					}
				}
			}
			if(s[0] == '('){
				k = 0;
				i = 1;

				while(s[i] != ','){
					aux[k] = s[i];
					i++;
					k++;
				}

				strcpy(vetorTransicao[n_transicoes].estadoAtual, aux);

				i += 1;

				vetorTransicao[n_transicoes].sLidoFita = s[i];

				for(k=0;k<10;k++){
		        	aux[k] = '\0';
		    	}

				k = 0;
				i += 4;

				while(s[i] != ','){
					aux[k] = s[i];
					i++;
					k++;
				}

				strcpy(vetorTransicao[n_transicoes].proximoEstado, aux);

				i += 1;

				vetorTransicao[n_transicoes].escritoFita = s[i];

				i += 2;

				vetorTransicao[n_transicoes].direcao = s[i];

				n_transicoes++;	
			}
		}

		fclose(arq);
	    printf("O arquivo foi inicializado com sucesso!\n");
	}
}