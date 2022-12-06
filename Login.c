#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

FILE *arq;
FILE *arqSession;

typedef struct Perfil{
        char nome[50];
        char email[50];
        char senha[50];
        char fone[15];
        char ativo[2];
};

void usuarioNaoEncontrado(){
    system("cls");
    system("color 4F");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| USUÁRIO NÃO ENCONTRADO                                                            |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    system("pause");
    Login();

}

void verificaLogin(email, senha){
    char ativo[10] = "s";
    char muduloLog[50] = "LOGIN";
    char actionLog[50] = "ACESSO";
    int retornoLogin;

    struct Perfil LoginPerfil;
    arq = fopen("bd/Perfil/BD_Perfil.pro", "r+b"); // ALTERAR PARA PERFIL ///
    system("cls");

    while ( fread (&LoginPerfil, sizeof(LoginPerfil), 1, arq) )//mudar para loop
    {
        if( strcmp(senha, LoginPerfil.senha) == 0 && strcmp(email, LoginPerfil.email) == 0 && strcmp(ativo, LoginPerfil.ativo) == 0  )//mudar poara loop-
        {

            system("color AF");
            printf("+-----------------------------------------------------------------------------------+\n");
            printf("| USUÁRIO ENCONTRADO                                                                |\n");
            printf("+-----------------------------------------------------------------------------------+\n");

            printf("LOGIN PARA O USUARIO: \n NOME: %s \n E-MAIL: %s \n TELEFONE: %s \n ATIVO: %s \n\n", LoginPerfil.nome,LoginPerfil.email,LoginPerfil.senha,LoginPerfil.ativo);
            printf("PRECIONE QUALQUER TECLA PARA CONTINUAR");

            // CRIA ARQUIVO DE SESSÃO
            arqSession = fopen("bd/Session/BD_Session.pro", "w");
            fputs(email, arqSession);
            fputs(" | ", arqSession);
            fputs(senha, arqSession);
            fclose(arqSession);
            fclose(arq);

            // LOG

            logSis(muduloLog,actionLog);

            // INICIA SISTEMA
            system("pause>null");
            system("cls");
            system("color 0A");
            Inicializar();
            MenuInterface();

        }else{

            usuarioNaoEncontrado();

        }
    }

}

void topoLogin(){
system("cls");
system("color F0");
Cabecalho();
printf("| LOGIN                                                                             |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("| TODOS OS CAMPOS SÃO OBRIGATÓRIOS                                                  |\n");
printf("+-----------------------------------------------------------------------------------+\n");
}

void Login(){

char email[100], senha[50];

topoLogin();
printf("\n\n");
printf("DIGITE SEU EMAIL:");
scanf("%s",&email);
printf("DIGITE SUA SENHA:");
scanf("%s",&senha);

verificaLogin(email,senha);

}
