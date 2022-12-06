#include <stdio.h>
#define TAM 100

// ********** CONSULTA PERFIL **********
FILE *arq;
int contP;
int qtdP;

typedef struct Perfil{
        char nome[50];
        char email[50];
        char senha[50];
        char fone[15];
        char ativo[2];
}cadastroP;
cadastroP max[TAM];

void abreArquivoConsutaPerfil(){

    char c,split[1000];
    int i = 0 , x = 1 , retorno;
    char tel[50] = "";

    arq = fopen("bd/Perfil/BD_Perfil.pro", "rb");
    if (arq == NULL){
        MensagemDeErro();
     }else{


            system("color F0");
            Cabecalho();
            printf (" PARA PESQUISAR DIGITE O TELEFONE OU 0 PARA MOSTRAR TODOS: ");// para procurar contato pelo nome
            scanf("%s",&tel);

            if ( strcmp(tel, "0") == 0 ){

                // MOSTRA TODSOS
                retorno = fread(&max[i], sizeof(cadastroP), 1, arq);
                while (retorno == 1){

                  if( strcmp(max[i].ativo, "s") == 0 ){
                      printf("\n # %i",x);
                      printf("\n Nome....: %s",max[i].nome);
                      printf("\n E-mail..: %s",max[i].email);
                      printf("\n Fone....: %s",max[i].fone);
                      printf("\n Ativo...: %s",max[i].ativo);
                      printf("\n+-----------------------------------------------------------------------------------+");
                  }
                      i++;
                      x++;
                      retorno = fread(&max[i], sizeof(cadastroP), 1, arq);
                }
                // MOSTRA TODSOS

            }else{

                 retorno = fread(&max[i], sizeof(cadastroP), 1, arq);
                 while (retorno == 1){
                     if (strcmp(tel, max[i].fone) == 0 && strcmp(max[i].ativo, "s") == 0){
                        printf("\n+-----------------------------------------------------------------------------------+");
                        printf("\n+------------------------- RESULTADO DA BUSCA --------------------------------------+");
                        printf("\n+-----------------------------------------------------------------------------------+");
                        printf("\n Nome....: %s",max[i].nome);
                        printf("\n E-mail..: %s ",max[i].email);
                        printf("\n Fone....: %s",max[i].fone);
                        printf("\n Ativo...: %s",max[i].ativo);
                        contP++;
                     }
                 i++;
                 retorno = fread(&max[i], sizeof(cadastroP), 1, arq);
                 }

                 if(contP == 0){
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

void ConsultaPerfil(){

    char muduloLog[50] = "PERFIL";
    char actionLog[50] = "CONSULTA";

    // CRIA LOG
    logSis(muduloLog,actionLog);

    system("cls");

    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| CONSULTAR DADOS DE PERFIL                                                       |\n");
    printf("+-----------------------------------------------------------------------------------+\n");

    printf("\n\n");

    abreArquivoConsutaPerfil();
    Cabecalho();
    MenuInterface();
}
