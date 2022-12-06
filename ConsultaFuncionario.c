#include <stdio.h>
#define TAM 100

// ********** CONSULTA FUNCIONARIO **********
FILE *arq;
int contF;
int qtdF;

typedef struct Funcionario{
        char nome[50];
        char email[50];
        char cargo[50];
        char fone[15];
        char ativo[2];
}cadastroF;
cadastroF max[TAM];

void abreArquivoConsutaFuncionario(){

    char c,split[1000];
    int i = 0 , x = 1 , retorno;
    char tel[50] = "";

    arq = fopen("bd/Funcionarios/BD_Funcionarios.pro", "rb");
    if (arq == NULL){
        MensagemDeErro();
     }else{
            system("color F0");
            Cabecalho();
            printf (" PARA PESQUISAR DIGITE O TELEFONE OU 0 PARA MOSTRAR TODOS: ");
            scanf("%s",&tel);

            if ( strcmp(tel, "0") == 0 ){

                retorno = fread(&max[i], sizeof(cadastroF), 1, arq);
                while (retorno == 1){

                  if( strcmp(max[i].ativo, "s") == 0 ){
                      printf("\n # %i",x);
                      printf("\n Nome....: %s",max[i].nome);
                      printf("\n E-mail..: %s",max[i].email);
                      printf("\n Cargo..: %s",max[i].cargo);
                      printf("\n Fone....: %s",max[i].fone);
                      printf("\n Ativo...: %s",max[i].ativo);
                      printf("\n+-----------------------------------------------------------------------------------+");
                  }
                      i++;
                      x++;
                      retorno = fread(&max[i], sizeof(cadastroF), 1, arq);
                }

            }else{

                 retorno = fread(&max[i], sizeof(cadastroF), 1, arq);
                 while (retorno == 1){
                     if (strcmp(tel, max[i].fone) == 0 && strcmp(max[i].ativo, "s") == 0){
                        printf("\n+-----------------------------------------------------------------------------------+");
                        printf("\n+------------------------- RESULTADO DA BUSCA --------------------------------------+");
                        printf("\n+-----------------------------------------------------------------------------------+");
                        printf("\n Nome....: %s",max[i].nome);
                        printf("\n E-mail..: %s ",max[i].email);
                        printf("\n Cargo..: %s ",max[i].cargo);
                        printf("\n Fone....: %s",max[i].fone);
                        printf("\n Ativo...: %s",max[i].ativo);
                        contF++;
                     }
                 i++;
                 retorno = fread(&max[i], sizeof(cadastroF), 1, arq);
                 }

                 if(contF == 0){
                        system("color 4F");
                        printf("\n+-----------------------------------------------------------------------------------+");
                        printf("\n+------------------------- NENHUM REGISTRO ENCONTRADO ------------------------------+");
                        printf("\n+-----------------------------------------------------------------------------------+");

                        getch();
                 }

                 getch();

            }
            getch();
            fclose(arq);
     }
}

void ConsultaFuncionario(){

    char muduloLog[50] = "FUNCIONARIO";
    char actionLog[50] = "CONSULTA";

    logSis(muduloLog,actionLog);

    system("cls");

    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| CONSULTAR DADOS DE FUNCIONARIO                                                    |\n");
    printf("+-----------------------------------------------------------------------------------+\n");

    printf("\n\n");

    abreArquivoConsutaFuncionario();
    Cabecalho();
    MenuInterface();
}
