// *****************************
// ********** PERFIL **********
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
char telEditP[30];

void AlterarPerfil(void);

typedef struct Perfil{
        char nome[50];
        char email[50];
        char senha[50];
        char fone[15];
        char ativo[2];
};

void AlterarPerfil(){

    struct Perfil EditaPerfil;
    arq = fopen("bd/Perfil/BD_Perfil.pro", "r+b");
    char nomeEdit[100];
    char muduloLog[50] = "PERFIL";
    char actionLog[50] = "EDITAR";

    int opEdit;

    system("cls");
    system("color F0");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| ALTERAR CADASTRO DE PERFIL                                                      |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("\n\n");

    system("pause>nul");
    printf ("\n Digite o Telefone do Perfil: ");
    scanf("%s", &telEditP);

    printf("\n\n");

    while (fread (&EditaPerfil, sizeof(EditaPerfil), 1, arq))
    {
        if(strcmp(telEditP, EditaPerfil.fone) == 0 )
        {
            printf("CONFIRA OS DADOS QUE DEVEM SER ALTERADOS; \n NOME: %s \n E-MAIL: %s \n SENHA: %s \n TELEFONE: %s \n ATIVO: %s \n\n", EditaPerfil.nome,EditaPerfil.email,EditaPerfil.senha,EditaPerfil.fone,EditaPerfil.ativo);
            printf("\n Escolha uma opção de edição: \n1 - Nome \n2 - E-mail \n3 - Senha \n4 - Telefone \n5 - Ativo/Inativo ( Esta opção exclui o usuario de Sistema )\n6 - Voltar ao Menu ");
            scanf("%i",&opEdit);


                switch(opEdit){

                case 1:
                    printf ("\n Digite o Nome: ");
                    scanf("%s",&EditaPerfil.nome);
                    break;
                case 2:
                    printf ("\n Digite o E-mail: ");
                    scanf("%s",&EditaPerfil.email);
                    break;
                case 3:
                    printf ("\n Digite a Senha: ");
                    scanf("%s",&EditaPerfil.senha);
                    break;
                case 4:
                    printf ("\n Digite o Numero: ");
                    scanf("%s",&EditaPerfil.fone);
                    break;
                case 5:
                    printf ("\n Perfil Ativo? [ s/n ]: ");
                    scanf("%s",&EditaPerfil.ativo);
                    break;
                case 6:
                    MenuInterface();
                    break;

                default:
                    system("cls");
                    printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
                    sleep(1);
                    return AlterarPerfil();
                    break;
                }

                // CRIA LOG
                logSis(muduloLog,actionLog);

                fseek(arq,sizeof(struct Perfil)*-1, SEEK_CUR);
                fwrite(&EditaPerfil, sizeof(EditaPerfil), 1, arq);
                fseek(arq, sizeof(EditaPerfil)* 0, SEEK_END);



        }
    }


    printf("\n DADOS ALTERADOS COM SUCESSO! [ precione enter para voltar ao menu principal ]");

    system("pause>nul");

    system("color 0a");
    MenuInterface();

}

// *****************************
// ********** PERFIL **********
// *****************************
