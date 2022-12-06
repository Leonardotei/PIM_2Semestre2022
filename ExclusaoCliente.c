// *****************************
// ********** CLIENTE **********
// *****************************

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

FILE *arq;
char telEdit[30];

void ExcluirCliente(void);

typedef struct Cliente{
        char nome[50];
        char email[50];
        char fone[15];
        char ativo[2];
};

void ExcluirCliente(){

    struct Cliente DeletaCliente;
    arq = fopen("bd/Clientes/BD_Clientes.pro", "r+b");
    char telDelete[30];
    char muduloLog[50] = "CLIENTE";
    char actionLog[50] = "DELETE";

    int opDeleta;

    system("cls");
    system("color F0");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| DELETAR CLIENTE DO CADASTRO                                                       |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("\n\n");

    system("pause>nul");
    printf ("\n Digite o Telefone do Cliente: ");
    //gets(telDelete);
    scanf("%s", &telDelete);

    printf("\n\n");

    while (fread (&DeletaCliente, sizeof(DeletaCliente), 1, arq))
    {
        if(strcmp(telDelete, DeletaCliente.fone) == 0 )
        {
            printf("CONFIRA OS DADOS QUE DEVEM SER DELETADOS; \n NOME: %s \n E-MAIL: %s \n TELEFONE: %s \n ATIVO: %s \n\n", DeletaCliente.nome,DeletaCliente.email,DeletaCliente.fone,DeletaCliente.ativo);
            printf("\n Deseja Prosseguir???: \n1 - SIM \n2 - NÃO \n3 - Voltar ao Menu ");
            scanf("%i",&opDeleta);


                switch(opDeleta){

                case 1:

                    printf ("\n ESTA OPÇÃO NÃO DELETA OS DADOS DEFINITIVAMENTE, APENAS INATIVA O CLIENTE DAS BUSCAS, ");
                    printf ("\n PARA REATIVAR O CLIENTE NOVAMENTE BASTE ACESSAR MENU/CLIENTE/ALTERAR CLIENTE:");
                    printf ("\n DIGITE O TELEFONE DO CLIENTE SELECIONE A OPÇÃO 4 E ATIVE O CLIENTE NOVAMENTE. \n\n");
                    printf ("\n Cliente Ativo? [ s/n ]: ( s - Mantem o cliente cadastrado / n - Exclui os dados do Cliente ) ");
                    scanf("%s",&DeletaCliente.ativo);
                    break;
                case 2:
                    MenuInterface();
                    break;

                default:
                    system("cls");
                    printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
                    sleep(1);
                    return ExcluirCliente();
                    break;
                }

                // CRIA LOG
                logSis(muduloLog,actionLog);

                fseek(arq,sizeof(struct Cliente)*-1, SEEK_CUR);
                fwrite(&DeletaCliente, sizeof(DeletaCliente), 1, arq);
                fseek(arq, sizeof(DeletaCliente)* 0, SEEK_END);



        }
    }


    printf("\n DADOS ALTERADOS COM SUCESSO! [ precione enter para voltar ao menu principal ]");

    system("pause>nul");

    system("color 0a");
    MenuInterface();

}

// *****************************
// ********** CLIENTE **********
// *****************************
