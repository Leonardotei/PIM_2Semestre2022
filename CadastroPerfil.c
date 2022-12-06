#include <stdio.h>
#define TAM 100

// ********** CADASTRO PERFIL **********
FILE *arq;
int contP = 0;
int retornoP;
int qtdP = 0;
typedef struct Perfil{
        char nome[50];
        char email[50];
        char senha[50];
        char fone[15];
        char ativo[2];
}cadastroP;
cadastroP max[TAM];


void AbreArquivoDeDadosPerfil(){
    char op = 's';

    arq = fopen("bd/Perfil/BD_Perfil.pro", "ab");
    if (arq == NULL){
        MensagemDeErro(); //VER
     }else{

        while ((contP < TAM) && (op == 's')){
            system("color F0");
            //system("pause");

            printf ("\n Digite o Nome: ");
            scanf("%s", max[contP].nome);
            printf ("\n Digite o E-mail: ");
            scanf("%s", max[contP].email);
            printf("\n Digite sua senha: ");
            scanf("%s", max[contP].senha);
            printf ("\n Digite o Numero: ");
            scanf("%s", max[contP].fone);
            printf ("\n Perfil Ativo? [ s/n ]: ");
            scanf("%s", max[contP].ativo);

            if ( (strcmp(max[contP].nome, "") == 0 ) || (strcmp(max[contP].email, "") == 0 ) || (strcmp(max[contP].senha, "") == 0 ) || (strcmp(max[contP].fone, "") == 0 ) || (strcmp(max[contP].ativo, "") == 0 ) ){

                system("color 4F");
                printf("\n");
                printf("+-----------------------------------------------------------------------------------+\n");
                printf("| TODOS OS CAMPOS SÃO OBRIGATÓRIOS, O CLIENTE NÃO FOI INSERIDO, TENTE NOVAMENTE     |\n");
                printf("+-----------------------------------------------------------------------------------+\n");
                op = ConfirmaAddPerfil();


                }else{

                    retornoP = fwrite(&max[contP], sizeof(cadastroP) ,1,arq);

                    if (retornoP == 1) {
                       printf("\n DADOS INSERIDOS COM SUCESSO! ");
                       ConfirmaSemPrintf();
                    }else{
                       printf("\n ERRO AO INSERIR DADOS! ");
                    }

                    contP++;
                    op = ConfirmaAddPerfil();
                    qtdP++;

                }

        }

     }

     fclose (arq);

}

void CadastroPerfil(){
    system("cls");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| CADASTRO DE PERFIL                                                               |\n");
    printf("+-----------------------------------------------------------------------------------+\n");

    printf("\n\n");

    AbreArquivoDeDadosPerfil();
}
void ConfirmaAddPerfil(){

    char muduloLog[50] = "PERFIL";
    char actionLog[50] = "CADASTRO";
    char op;

    // CRIA LOG
    logSis(muduloLog,actionLog);
    do {
      printf("\n DESEJA INSERIR UM NOVO PERFIL? [S ou N]? " );
      op = getch();
      if (op == 'S' || op == 's'){
        CadastroPerfil();
      }
   } while (op != 's' && op != 'n');

   return main();
}
void ConfirmaSemPrintf(){
    char muduloLog[50] = "PERFIL";
    char actionLog[50] = "CADASTRO";
    char op;

    // CRIA LOG
    logSis(muduloLog,actionLog);
    return MenuInterface();
}
