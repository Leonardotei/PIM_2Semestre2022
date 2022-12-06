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

void AlterarCliente(void);

typedef struct Cliente{
        char nome[50];
        char email[50];
        char fone[15];
        char ativo[2];
};

void AlterarCliente(){

    struct Cliente EditaCliente;
    arq = fopen("bd/Clientes/BD_Clientes.pro", "r+b");
    char nomeEdit[100];
    char muduloLog[50] = "CLIENTE";
    char actionLog[50] = "EDITAR";

    int opEdit;

    system("cls");
    system("color F0");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| ALTERAR CADASTRO DE CLIENTES                                                      |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("\n\n");

    //system("pause>nul");
    printf ("\n Digite o Telefone do Cliente: ");
    //gets(telEdit);
    scanf("%s", &telEdit);

    printf("\n\n");

    while (fread (&EditaCliente, sizeof(EditaCliente), 1, arq))
    {
        if(strcmp(telEdit, EditaCliente.fone) == 0 )
        {
            printf("CONFIRA OS DADOS QUE DEVEM SER ALTERADOS; \n NOME: %s \n E-MAIL: %s \n TELEFONE: %s \n ATIVO: %s \n\n", EditaCliente.nome,EditaCliente.email,EditaCliente.fone,EditaCliente.ativo);
            printf("\n Escolha uma opção de edição: \n1 - Nome \n2 - E-mail \n3 - Telefone \n4 - Ativo/Inativo ( Esta opção exclui o usuario de Sistema )\n5 - Voltar ao Menu ");
            scanf("%i",&opEdit);


                switch(opEdit){

                case 1:
                    printf ("\n Digite o Nome: ");
                    scanf("%s",&EditaCliente.nome);
                    break;
                case 2:
                    printf ("\n Digite o E-mail: ");
                    scanf("%s",&EditaCliente.email);
                    break;
                    break;
                case 3:
                    printf ("\n Digite o Numero: ");
                    scanf("%s",&EditaCliente.fone);
                    break;
                case 4:
                    printf ("\n Cliente Ativo? [ s/n ]: ");
                    scanf("%s",&EditaCliente.ativo);
                    break;
                case 5:
                    MenuInterface();
                    break;

                default:
                    system("cls");
                    printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
                    sleep(1);
                    return AlterarCliente();
                    break;
                }

                // CRIA LOG
                logSis(muduloLog,actionLog);

                fseek(arq,sizeof(struct Cliente)*-1, SEEK_CUR);
                fwrite(&EditaCliente, sizeof(EditaCliente), 1, arq);
                fseek(arq, sizeof(EditaCliente)* 0, SEEK_END);



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
