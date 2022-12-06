void MenuSelecao(){
    int opcao;

    //opcao = getch(); nao deixa colocar numeros com dois digitos
    scanf("%d", &opcao);
    switch(opcao){

    case 1:
        CadastroCliente();
        break;
    case 2:
        ConsultaCliente();
        break;
    case 3:
        AlterarCliente();
        break;
    case 4:
        ExcluirCliente();
        break;
    case 5:
        CadastroFuncionario();
        break;
    case 6:
        ConsultaFuncionario();
        break;
    case 7:
        AlterarFuncionario();
        break;
    case 8:
        ExcluirFuncionario();
        break;
    case 9:
        ConsultaPerfil();
        break;
    case 10:
        AlterarPerfil();
        break;
    case 11:
        ExcluirPerfil();
        break;
    case 0:
        //return 0;
        abort();
        break;

    default:
        system("cls");
        Cabecalho();
        printf("\n|||| OPÇÃO INVÁLIDA |||\n\n");
        sleep(2);
        return MenuInterface();
        break;
    }

}
