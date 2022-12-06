#include <stdio.h>
#define TAM 100

// ********** CADASTRO CLIENTE **********
FILE *arq;
int contC = 0;
int retornoC;
int qtdC = 0;

typedef struct Cliente{
        char nome[50];
        char email[50];
        char fone[15];
        char ativo[2];
}cadastroC;
cadastroC max[TAM];


void abreArquivoDeDadosCliente(){
    char op = 's';

    arq = fopen("bd/Clientes/BD_Clientes.pro", "ab");
    if (arq == NULL){
        MensagemDeErro();
     }else{

        while ((contC < TAM) && (op == 's')){
        system("color F0");

        printf ("\n Digite o Nome: ");
        scanf("%s", max[contC].nome);
        printf ("\n Digite o E-mail: ");
        scanf("%s", max[contC].email);
        printf ("\n Digite o Numero: ");
        scanf("%s", max[contC].fone);
        printf ("\n Cliente Ativo? [ s/n ]: ");
        scanf("%s", max[contC].ativo);

            if ( (strcmp(max[contC].nome, "") == 0 ) || (strcmp(max[contC].email, "") == 0 ) || (strcmp(max[contC].fone, "") == 0 ) || (strcmp(max[contC].ativo, "") == 0 ) ){

                system("color 4F");
                printf("\n");
                printf("+-----------------------------------------------------------------------------------+\n");
                printf("| TODOS OS CAMPOS SÃO OBRIGATÓRIOS, O CLIENTE NÃO FOI INSERIDO, TENTE NOVAMENTE     |\n");
                printf("+-----------------------------------------------------------------------------------+\n");
                op = ConfirmaAddClientes();

            }else{

                retornoC = fwrite(&max[contC], sizeof(cadastroC) ,1,arq);

                if (retornoC == 1) {
                   printf("\n DADOS INSERIDOS COM SUCESSO! ");
                }else{
                   printf("\n ERRO AO INSERIR DADOS! ");
                }

                contC++;
                op = ConfirmaAddClientes();
                qtdC++;

            }

        }

     }

     fclose (arq);

}

void CadastroCliente(){

    system("cls");

    Cabecalho();
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| CADASTRO DE CLIENTES                                                              |\n");
    printf("+-----------------------------------------------------------------------------------+\n");

    printf("\n\n");

    abreArquivoDeDadosCliente();

}

void ConfirmaAddClientes(){

    char muduloLog[50] = "CLIENTE";
    char actionLog[50] = "CADASTRO";
    char op;

    // CRIA LOG
    logSis(muduloLog,actionLog);

   do {
      printf("\n DESEJA INSERIR UM NOVO CLIENTE? [S ou N]? " );
      op = getch();
      if (op == 'S' || op == 's'){
        CadastroCliente();
      }
   } while (op != 's' && op != 'n');

   return MenuInterface();
}
