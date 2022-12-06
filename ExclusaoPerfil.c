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
char telEdit[30];

void ExcluirPerfil(void);

typedef struct Perfil{
        char nome[50];
        char email[50];
        char senha[50];
        char fone[15];
        char ativo[2];
};

void ExcluirPerfil(){

    struct Perfil DeletaPerfil;
    arq = fopen("bd/Perfil/BD_Perfil.pro", "r+b");
    char telDelete[30];
    char muduloLog[50] = "PERFIL";
    char actionLog[50] = "DELETE";

    int opDeleta;

    system("cls");
    system("color F0");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| DELETAR PERFIL DO CADASTRO                                                       |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("\n\n");

    system("pause>nul");
    printf ("\n Digite o Telefone do Perfil: ");
    //gets(telDelete);
    scanf("%s", telDelete);

    printf("\n\n");

    while (fread (&DeletaPerfil, sizeof(DeletaPerfil), 1, arq))
    {
        if(strcmp(telDelete, DeletaPerfil.fone) == 0 )
        {
            printf("CONFIRA OS DADOS QUE DEVEM SER DELETADOS; \n NOME: %s \n E-MAIL: %s \n TELEFONE: %s \n ATIVO: %s \n\n", DeletaPerfil.nome,DeletaPerfil.email,DeletaPerfil.fone,DeletaPerfil.ativo);
            printf("\n Deseja Prosseguir???: \n1 - SIM \n2 - NÃO \n3 - Voltar ao Menu ");
            scanf("%i",&opDeleta);


                switch(opDeleta){

                case 1:

                    printf ("\n ESTA OPÇÃO NÃO DELETA OS DADOS DEFINITIVAMENTE, APENAS INATIVA O PERFIL DAS BUSCAS, ");
                    printf ("\n PARA REATIVAR O PERFIL NOVAMENTE BASTE ACESSAR MENU/PERFIL/ALTERAR PERFIL:");
                    printf ("\n DIGITE O TELEFONE DO PERFIL SELECIONE A OPÇÃO 4 E ATIVE O PERFIL NOVAMENTE. \n\n");
                    printf ("\n Perfil Ativo? [ s/n ]: ( s - Mantem o perfil cadastrado / n - Exclui os dados do Perfil ) ");
                    scanf("%s",&DeletaPerfil.ativo);
                    break;
                case 2:
                    MenuInterface();
                    break;

                default:
                    system("cls");
                    printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
                    sleep(1);
                    return ExcluirPerfil();
                    break;
                }

                // CRIA LOG
                logSis(muduloLog,actionLog);

                fseek(arq,sizeof(struct Perfil)*-1, SEEK_CUR);
                fwrite(&DeletaPerfil, sizeof(DeletaPerfil), 1, arq);
                fseek(arq, sizeof(DeletaPerfil)* 0, SEEK_END);



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
