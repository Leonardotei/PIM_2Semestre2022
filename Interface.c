#include <windows.h>

void Inicializar(){
printf("\n   _______________________________________________________________________\n");
Sleep(15);
printf("   *       SSSSSSSSSSSSSSS  KKKKKKKKK    KKKKKKK TTTTTTTTTTTTTTTTTTTTTTT *\n");
Sleep(20);
printf("   *     SS:::::::::::::::S K:::::::K    K:::::K T:::::::::::::::::::::T *\n");
Sleep(25);
printf("   *    S:::::SSSSSS::::::S :::::::K     K:::::K T:::::::::::::::::::::T *\n");
Sleep(35);
printf("   *    S:::::S     SSSSSSS K:::::::K   K::::::K T:::::TT:::::::TT:::::T *\n");
Sleep(40);
printf("   *    S:::::S             KK::::::K  K:::::KKK TTTTTT  T:::::T  TTTTTT *\n");
Sleep(45);
printf("   *    S:::::S               K:::::K K:::::K            T:::::T         *\n");
Sleep(50);
printf("   *     S::::SSSS            K::::::K:::::K             T:::::T         *\n");
Sleep(55);
printf("   *      SS::::::SSSSS       K:::::::::::K              T:::::T         *\n");
Sleep(60);
printf("   *        SSS::::::::SS     K:::::::::::K              T:::::T         *\n");
Sleep(65);
printf("   *           SSSSSS::::S    K::::::K:::::K             T:::::T         *\n");
Sleep(70);
printf("   *                S:::::S   K:::::K K:::::K            T:::::T         *\n");
Sleep(75);
printf("   *                S:::::S KK::::::K  K:::::KKK         T:::::T         *\n");
Sleep(80);
printf("   *    SSSSSSS     S:::::S K:::::::K   K::::::K       TT:::::::TT       *\n");
Sleep(85);
printf("   *    S::::::SSSSSS:::::S K:::::::K    K:::::K       T:::::::::T       *\n");
Sleep(90);
printf("   *    S:::::::::::::::SS  K:::::::K    K:::::K       T:::::::::T       *\n");
Sleep(95);
printf("   *     SSSSSSSSSSSSSSS    KKKKKKKKK    KKKKKKK       TTTTTTTTTTT       *\n");
Sleep(100);
printf("   *                                                                     *\n");
printf("   *_______________________________SISTEMS_______________________________*\n");
Sleep(1000);

}

void Cabecalho(){
    system("cls");
    printf("\t\t\t  ______     __  __     ______  \n");
    printf("\t\t\t /\\  ___\\   /\\ \\/ /    /\\__  _\\ \n");
    printf("\t\t\t \\ \\___  \\  \\ \\  _'-.  \\/_/\\ \\/ \n");
    printf("\t\t\t  \\/\\_____\\  \\ \\_\\ \\_\\    \\ \\_\\ \n");
    printf("\t\t\t   \\/_____/   \\/_/\\/_/     \\/_/ \n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("|                                 SISTEMA DE GESTÃO                                 |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
}

void MenuInterface(){

system("color 0A");

Cabecalho();

printf("|                                 ESCOLHA UMA OPÇÃO                                 |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("|                                      CLIENTE                                      |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("|                                1 - Cadastar                                       |\n");
printf("|                                2 - Consultar                                      |\n");
printf("|                                3 - Alterar                                        |\n");
printf("|                                4 - Excluir                                        |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("|                                    FUNCIONÁRIO                                    |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("|                                5 - Cadastar                                       |\n");
printf("|                                6 - Consultar                                      |\n");
printf("|                                7 - Alterar                                        |\n");
printf("|                                8 - Excluir                                        |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("|                                       PERFIL                                      |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("|                                9 - Consultar                                      |\n");
printf("|                                10 - Alterar                                       |\n");
printf("|                                11 - Excluir                                       |\n");
printf("+-----------------------------------------------------------------------------------+\n");
printf("|                                                                                   |\n");
printf("|                                0 - SAIR                                           |\n");
printf("|                                                                                   |\n");
printf("+-----------------------------------------------------------------------------------+\n");



MenuSelecao();

}

void MensagemDeErro(){

        system("cls");
        system("color 4F");
        printf("\n\n\n\n\n\n");
        printf("+-----------------------------------------------------------------------------------+\n");
        printf("|                          ERRO AO ABRIR BASE DE DADOS                              |\n");
        printf("+-----------------------------------------------------------------------------------+\n");
        printf("\n\n\n\n\n\n");
        system("pause");
        Cabecalho();
        MenuInterface();

}
