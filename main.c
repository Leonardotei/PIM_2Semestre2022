#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

FILE *arq;
    int op;
    char criaBase[50];

void PerguntaCriaBdClientes(){

    conf();
    printf(" ATENÇÃO: Ao criar uma nova base todos os dados anteriores serão perdidos.\n\n ");
    printf(" DESEJA CRIAR UMA NOVA BASE DE DADOS DE CLIENTES [ s/n ] ? \n ");
    gets(criaBase);

    if( (strcmp(criaBase, "s") == 0 ) || (strcmp(criaBase, "S") == 0 ) ){
        arq = fopen("bd/Clientes/BD_Clientes.pro", "w");
    }

    VerificaBancoDeDados();

}

void PerguntaCriaBdFuncionarios(){

    conf();
    printf(" ATENÇÃO: Ao criar uma nova base todos os dados anteriores serão perdidos.\n\n ");
    printf(" DESEJA CRIAR UMA NOVA BASE DE DADOS DE FUNCIONÁRIOS [ s/n ] ? \n ");
    gets(criaBase);

    if( (strcmp(criaBase, "s") == 0 ) || (strcmp(criaBase, "S") == 0 ) ){
        arq = fopen("bd/Funcionarios/BD_Funcionarios.pro", "w");
    }

    VerificaBancoDeDados();

}

void PerguntaCriaBdPerfil(){

    conf();
    printf(" ATENÇÃO: Ao criar uma nova base todos os dados anteriores serão perdidos.\n\n ");
    printf(" DESEJA CRIAR UMA NOVA BASE DE DADOS DE PERFIL [ s/n ] ? \n ");
    gets(criaBase);

    if( (strcmp(criaBase, "s") == 0 ) || (strcmp(criaBase, "S") == 0 ) ){
        arq = fopen("bd/Perfil/BD_Perfil.pro", "w");
    }

    VerificaBancoDeDados();

}

void MensagemDeErroAbrirArquivo2(op){

    printf("[ ERRO ] NÃO FOI POSSÍVEL ABRIR A BASE DE DADOS \n\n\n");
    Sleep(100);

    switch(op){

    case 1:
        PerguntaCriaBdClientes();
    break;

    case 2:
        PerguntaCriaBdFuncionarios();
    break;

    case 3:
        PerguntaCriaBdPerfil();
    break;

    default:
        printf("def");
    break;

    }

}

void conf(){
    system("color 0A");
    system("cls");
    printf("\n\n\n\n\n");
}

void Clientes(){

    conf();
    op = 1;
    arq = fopen("bd/Clientes/BD_Clientes.pro", "r");
    if (arq == NULL){
        MensagemDeErroAbrirArquivo2(op);
     }

}

void Funcionarios(){

    conf();
    op = 2;
    arq = fopen("bd/Funcionarios/BD_Funcionarios.pro", "r");
    if (arq == NULL){
        MensagemDeErroAbrirArquivo2(op);
     }

}

void Perfil(){

    conf();
    op = 3;
    arq = fopen("bd/Perfil/BD_Perfil.pro", "r");
    if (arq == NULL){
        MensagemDeErroAbrirArquivo2(op);
     }

}

void CriaBDLog(){
    arq = fopen("bd/Log/BD_Log.txt", "r");
    if (arq == NULL){
        arq = fopen("bd/Log/BD_Log.txt", "w");
    }
}

void VerificaBancoDeDados(){

    conf();
    printf(" VERIFICANDO BASE DE DADOS, AGUARDE... \n\n ");
    Sleep(100);

    Clientes();
    printf(" BASE DE DADOS DE CLIENTES \n ");
    printf("[========================== [ 26%% ]                                              ] \n\n ");
    Sleep(100);

    Funcionarios();
    printf(" BASE DE DADOS DE FUNCIONÁRIOS \n ");
    printf("[=================================================== [ 52%% ]                     ] \n\n ");
    Sleep(100);

    Perfil();
    printf(" BASE DE DADOS DE PERFIS \n ");
    printf("[======================================================================= [ 99%% ]] \n\n ");
    Sleep(100);
    system("cls");

    CriaBDLog();

}

int main(){

    int option;

    /// *** CONFIGURA TAMANHO DA TELA
    //system("MODE con cols=85 lines=40");
    system("title Sistema [ SKT SISTEMS ]");
    system("color 1F");
    setlocale(LC_ALL, "");
    VerificaBancoDeDados();
    Inicializar();
    Cabecalho();
    //MenuInterface();

    printf("| ESCOLHA UMA OPÇÃO ABAIXO                                                          |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| 1 - LOGIN                                                                         |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| 2 - CADASTRAR NOVO PERFIL                                                         |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    scanf("%i",&option);

    switch(option){

    case 1:
        Login();
        break;
    case 2:
        CadastroPerfil();
        break;

    default:
        system("cls");
        printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
        sleep(1);
        return main();
        break;
    }
}

