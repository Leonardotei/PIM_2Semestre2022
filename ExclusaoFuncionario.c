// *****************************
// ******** FUNCIONARIO ********
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

void ExcluirFuncionario(void);

typedef struct Funcionario{
        char nome[50];
        char email[50];
        char cargo[50];
        char fone[15];
        char ativo[2];
};

void ExcluirFuncionario(){

    struct Funcionario DeletaFuncionario;
    arq = fopen("bd/Funcionarios/BD_Funcionarios.pro", "r+b");
    char telDelete[30];
    char muduloLog[50] = "FUNCIONARIO";
    char actionLog[50] = "DELETE";

    int opDeleta;

    system("cls");
    system("color F0");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| DELETAR FUNCIOANRIO DO CADASTRO                                                   |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("\n\n");

    //system("pause>nul");
    printf ("\n Digite o Telefone do Funcionario: ");
    //gets(telDelete);
    scanf("%s", telDelete);

    printf("\n\n");

    while (fread (&DeletaFuncionario, sizeof(DeletaFuncionario), 1, arq))
    {
        if(strcmp(telDelete, DeletaFuncionario.fone) == 0 )
        {
            printf("CONFIRA OS DADOS QUE DEVEM SER DELETADOS; \n NOME: %s \n E-MAIL: %s  \n CARGO: %s  \n TELEFONE: %s \n ATIVO: %s \n\n", DeletaFuncionario.nome,DeletaFuncionario.email,DeletaFuncionario.cargo, DeletaFuncionario.fone,DeletaFuncionario.ativo);
            printf("\n Deseja Prosseguir???: \n1 - SIM \n2 - NÃO \n3 - Voltar ao Menu ");
            scanf("%i",&opDeleta);


                switch(opDeleta){

                case 1:

                    printf ("\n ESTA OPÇÃO NÃO DELETA OS DADOS DEFINITIVAMENTE, APENAS INATIVA O FUNCIOANRIO DAS BUSCAS, ");
                    printf ("\n PARA REATIVAR O FUNCIONARIO NOVAMENTE BASTE ACESSAR MENU/FUNCIONARIO/ALTERAR FUNCIONARIO:");
                    printf ("\n DIGITE O TELEFONE DO FUNCIONARIO SELECIONE A OPÇÃO 4 E ATIVE O FUNCIONARIO NOVAMENTE. \n\n");
                    printf ("\n Funcionario Ativo? [ s/n ]: ( s - Mantem o Funcionario cadastrado / n - Exclui os dados do Funcionario ) ");
                    scanf("%s",&DeletaFuncionario.ativo);
                    break;
                case 2:
                    MenuInterface();
                    break;

                default:
                    system("cls");
                    printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
                    sleep(1);
                    return ExcluirFuncionario();
                    break;
                }

                logSis(muduloLog,actionLog);

                fseek(arq,sizeof(struct Funcionario)*-1, SEEK_CUR);
                fwrite(&DeletaFuncionario, sizeof(DeletaFuncionario), 1, arq);
                fseek(arq, sizeof(DeletaFuncionario)* 0, SEEK_END);



        }
    }


    printf("\n DADOS ALTERADOS COM SUCESSO! [ precione enter para voltar ao menu principal ]");

    system("pause>nul");

    system("color 0a");
    MenuInterface();

}

// *****************************
// ******** FUNCIONARIO ********
// *****************************
