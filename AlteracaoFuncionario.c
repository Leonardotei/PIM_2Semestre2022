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
char telEditF[30];

void AlterarFuncionario(void);

typedef struct Funcionario{
        char nome[50];
        char email[50];
        char cargo[50];
        char fone[15];
        char ativo[2];
};

void AlterarFuncionario(){

    struct Funcionario EditaFuncionario;
    arq = fopen("bd/Funcionarios/BD_Funcionarios.pro", "r+b");
    char nomeEdit[100];
    char muduloLog[50] = "FUNCIONARIO";
    char actionLog[50] = "EDITAR";

    int opEdit;

    system("cls");
    system("color F0");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| ALTERAR CADASTRO DE FUNCIONARIO                                                   |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("\n\n");

    printf ("\n Digite o Telefone do Funcionario: ");
    scanf("%s", &telEditF);

    printf("\n\n");

    while (fread (&EditaFuncionario, sizeof(EditaFuncionario), 1, arq))
    {
        if(strcmp(telEditF, EditaFuncionario.fone) == 0 )
        {
            printf("CONFIRA OS DADOS QUE DEVEM SER ALTERADOS; \n NOME: %s \n E-MAIL: %s \n CARGO: %s \n TELEFONE: %s \n ATIVO: %s \n\n", EditaFuncionario.nome,EditaFuncionario.email,EditaFuncionario.cargo,EditaFuncionario.fone,EditaFuncionario.ativo);
            printf("\n Escolha uma opção de edição: \n1 - Nome \n2 - E-mail \n3 - Cargo \n4 - Telefone \n5 - Ativo/Inativo ( Esta opção exclui o usuario de Sistema )\n6 - Voltar ao Menu ");
            scanf("%i",&opEdit);


                switch(opEdit){

                case 1:
                    printf ("\n Digite o Nome: ");
                    scanf("%s",&EditaFuncionario.nome);
                    break;
                case 2:
                    printf ("\n Digite o E-mail: ");
                    scanf("%s",&EditaFuncionario.email);
                    break;
                case 3:
                    printf ("\n Digite a Cargo: ");
                    scanf("%s",&EditaFuncionario.cargo);
                    break;
                case 4:
                    printf ("\n Digite o Numero: ");
                    scanf("%s",&EditaFuncionario.fone);
                    break;
                case 5:
                    printf ("\n Perfil Ativo? [ s/n ]: ");
                    scanf("%s",&EditaFuncionario.ativo);
                    break;
                case 6:
                    MenuInterface();
                    break;

                default:
                    system("cls");
                    printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
                    sleep(1);
                    return AlterarFuncionario();
                    break;
                }

                logSis(muduloLog,actionLog);

                fseek(arq,sizeof(struct Funcionario)*-1, SEEK_CUR);
                fwrite(&EditaFuncionario, sizeof(EditaFuncionario), 1, arq);
                fseek(arq, sizeof(EditaFuncionario)* 0, SEEK_END);



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
