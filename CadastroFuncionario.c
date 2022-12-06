#include <stdio.h>
#define TAM 100

// ********** CADASTRO FUNCIONARIO **********
FILE *arq;
int contF = 0;
int retornoF;
int qtdF = 0;

typedef struct Funcionario{
        char nome[50];
        char email[50];
        char cargo [50];
        char fone[15];
        char ativo[2];
}cadastroF;
cadastroF max[TAM];

void AbreArquivoDeDadosFuncionario(){
    char op = 's';

    arq = fopen("bd/Funcionarios/BD_Funcionarios.pro", "ab");
    if (arq == NULL){
        MensagemDeErro();
     }else{
        while ((contF < TAM) && (op == 's')){
            system("color F0");

            printf ("\n Digite o Nome: ");
            scanf("%s", max[contF].nome);
            printf ("\n Digite o E-mail: ");
            scanf("%s", max[contF].email);
            printf("\n Digite sua Cargo: ");
            scanf("%s", max[contF].cargo);
            printf ("\n Digite o Numero: ");
            scanf("%s", max[contF].fone);
            printf ("\n Perfil Ativo? [ s/n ]: ");
            scanf("%s", max[contF].ativo);

            if ( (strcmp(max[contF].nome, "") == 0 ) || (strcmp(max[contF].email, "") == 0 ) || (strcmp(max[contF].cargo, "") == 0 ) || (strcmp(max[contF].fone, "") == 0 ) || (strcmp(max[contF].ativo, "") == 0 ) ){

                system("color 4F");
                printf("\n");
                printf("+-----------------------------------------------------------------------------------+\n");
                printf("| TODOS OS CAMPOS SÃO OBRIGATÓRIOS, O CLIENTE NÃO FOI INSERIDO, TENTE NOVAMENTE     |\n");
                printf("+-----------------------------------------------------------------------------------+\n");
                op = ConfirmaAddPerfil();


                }else{

                    retornoF = fwrite(&max[contF], sizeof(cadastroF) ,1,arq);

                    if (retornoF == 1) {
                       printf("\n DADOS INSERIDOS COM SUCESSO! ");
                       ConfirmaSemPrintf();
                    }else{
                       printf("\n ERRO AO INSERIR DADOS! ");
                    }

                    contF++;
                    op = ConfirmaAddPerfil();
                    qtdF++;

                }

        }

     }

     fclose (arq);
}

void CadastroFuncionario(){
    system("cls");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| CADASTRO DE FUNCIONARIO                                                           |\n");
    printf("+-----------------------------------------------------------------------------------+\n");

    printf("\n\n");

    AbreArquivoDeDadosFuncionario();
}

void ConfirmaAddFuncionario(){

    char muduloLog[50] = "FUNCIONARIO";
    char actionLog[50] = "CADASTRO";
    char op;

    logSis(muduloLog,actionLog);
    do {
      printf("\n DESEJA INSERIR UM NOVO FUNCIONARIO? [S ou N]? " );
      op = getch();
      if (op == 'S' || op == 's'){
        CadastroFuncionario();
      }
   } while (op != 's' && op != 'n');

   return main();
}
