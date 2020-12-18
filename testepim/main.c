#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int login(){
    char nome[30], senha[7], senha1[7];

    printf("Por favor digite seu usuario....: ");
    scanf("%s", &nome);

    printf("\n\nPor favor digite sua senha com ate 4 caracteres...: ");


    scanf("%4d", &senha);

    printf("\nPor favor digite novamente a senha...: ");


    scanf("%4d", &senha1);


        // Se as duas senhas que forem apresentadas forem iguais conclua o Login
        if (strcmp(senha,senha1) == 0){
            system ("cls");
            printf("\n\n--------Login efetuado com sucesso--------");
            printf("\n\n--------Ola, %s-----------------\n\n", nome);
            return menu();
        // Se as senhas forem diferentes tente fazer o login novamente
        } else {
            printf("\n\nUsuario ou senha errado, tente novamente\n\n");
            return login();
            system("cls");
        }

}

int menu(){
    int caso = 0;
    printf("\n\n------Menu Principal------\n\n");
    printf("\n\n------Selecione seu caso------\n\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Fechar programa\n");
    scanf("%d", &caso);
    fflush(stdin);
        if (caso == 1){
            return cadastro();
        }

            if (caso == 2){ //encerra o programa
                exit(0);
            }
}


int cadastro(){

    //criando arquivo da ficha
    struct Paciente{ //Registro da ficha do paciente
        char nome[30];
        char cpf[30];
        char tel[30];
        char rua[90];
        char num[10];
        char bair[90];
        char cida[90];
        char esta[90];
        char cep[15];

        char dataNasc[15];
        char email[90];
        char dataDiag[15];
        char comorbi[10];
    }paciente;


    char nomeArq[100];
    FILE* ficha;

    printf("\n\nDigite o nome do paciente...: "); //preenchimento dos dados da ficha
        fflush(stdin);
        gets(paciente.nome);
        sprintf(nomeArq, "%s.txt", paciente.nome);
        ficha = fopen(nomeArq, "a");
//        puts(nomeArq);



    printf("\n\nDigite o cpf (apenas numeros)...: ");
        fprintf(ficha, "%s", "CPF: ");
        fflush(stdin);
        fgets(paciente.cpf, 30, stdin);
        fputs(paciente.cpf, ficha);


    printf("\n\nAgora informe o telefone...: ");
        fprintf(ficha, "%s", "Tel: ");
        fflush(stdin);
        fgets(paciente.tel, 30, stdin);
        fputs(paciente.tel, ficha);

    printf("\n\nDigite o endereço\t");
    printf("\n\nInforme o bairro...: ");
        fprintf(ficha, "%s", "Bairro: ");
        fflush(stdin);
        fgets(paciente.bair, 60, stdin);
        fputs(paciente.bair, ficha);


    printf("\nInforme a rua...: ");
        fprintf(ficha, "%s", "Rua: ");
        fflush(stdin);
        fgets(paciente.rua, 90, stdin);
        fputs(paciente.rua, ficha);

    printf("\nInforme o Numero da casa...: ");
        fprintf(ficha, "%s", "Num: ");
        fflush(stdin);
        fgets(paciente.num, 10, stdin);
        fputs(paciente.num, ficha);

    printf("\n\nInforme a cidade...: ");
        fprintf(ficha, "%s", "Cidade: ");
        fflush(stdin);
        fgets(paciente.cida, 90, stdin);
        fputs(paciente.cida, ficha);

    printf("\n\nInforme o Estado...: ");
        fprintf(ficha, "%s", "Estado: ");
        fflush(stdin);
        fgets(paciente.esta, 90, stdin);
        fputs(paciente.esta, ficha);

    printf("\n\nInforme o cep...: ");
        fprintf(ficha, "%s", "CEP: ");
        fflush(stdin);
        fgets(paciente.cep, 15, stdin);
        fputs(paciente.cep, ficha);

    printf("\n\nInforme a Data de Nascimento...: "); //O trabalho exige calcular a idade!!!!!
        fprintf(ficha, "%s", "Data de Nasc.: ");
        fflush(stdin);
        fgets(paciente.dataNasc, 15, stdin);
        fputs(paciente.dataNasc, ficha);

    printf("\n\nInforme o e-mail...: ");
        fprintf(ficha, "%s", "E-mail: ");
        fflush(stdin);
        fgets(paciente.email, 90, stdin);
        fputs(paciente.email, ficha);

    printf("\n\nInforme a Data do Diagnóstico...: ");
        fprintf(ficha, "%s", "Data do Diag: ");
        fflush(stdin);
        fgets(paciente.dataDiag, 15, stdin);
        fputs(paciente.dataDiag, ficha);

    printf("\n\nAlguma Comorbidade? (diabetes, obesidade, hipertensao, tuberculose, outros)...:");//
        fflush(stdin);
        fgets(paciente.comorbi, 10, stdin);
        fputs(paciente.comorbi, ficha);

   printf("\n\nCadastrar novo paciente?...:(S/N)");
    char resp;
    scanf("%c", &resp);
        if(resp == "S" || resp == "s"){
            ficha = fopen("ficha do paciente.txt", "wb+");
            return cadastro();
        } else if(resp == 0){
            printf("Erro: opcao inexistente");
            return menu();
        } else {
            return menu();
        }
        fclose(ficha);//fechando o arquivo

        return(0);

}












void main(){

    printf("\n\n>>>>>>Bem-vindo a central de registro de casos de COVID19<<<<<< \n\n");
    login();
    menu();

    //printf("\n\n>>>>>>Vamos ao cadastro do paciente<<<<<<\n\n");
    //cadastro();

    return 0;
}
