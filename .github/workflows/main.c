//# PIM
//PROJETO ACADEMICO
#include <conio.h> //para usar a função getchar fflush
#include <stdio.h>  //biblioteca para utilizar funções comuns como (printF, scanf etc)
#include <String.h> //biblioteca que permite a adição de funções dentro de outras funções...
#include <stdlib.h> //biblioteca que serve de emulador para que quando altere de MAC, para LINUX, WINDOWNS E ETC, os codigos são convertidos!
#include <locale.h> //biblioteca que permite fazer o programa entender o idioma do sistema operacional
#include <math.h> //permite utilizar algumas funções matematicas de maneira mais simples (quadrado, potencia, raiz e etc)
#define SIZE 200 //Variavel constante de 200, em momento nenhum esse valor pode ser mudado

///FAÇA UM SISTEMA DE LOGIN E CADASTROS UTILIZANDO FUNÇÕES E TUDO APRESENTADO ATÉ O MOMENTO:


///ESTRUTURA QUE ARMAZENA DADOS DE UM MEDICO
  typedef struct{
    char nome [SIZE] [50];
    char email [SIZE];
    char cpf[SIZE];
    char rg[SIZE];
    int telefone;
    char senha[9];
    char senhacomp[9];
  }pessoa; pessoa l;


typedef struct dados DADOS;

 struct dados{
    char cpf[SIZE];
    char senha[9];
    char nome[SIZE]
  };


///ESTRUTURA QUE ARMAZENA DADOS DE PACIENTES
   typedef struct{
      char nome [SIZE] [50];
      char email [SIZE];
      char cpf[20];
      char rg[20];
      int telefone;
      char consulta[SIZE];
      char data[12];
      char carteirinha[22];
   }Cliente; Cliente cad;


   ///VARIÁVEIS GLOBAIS FORA DE UMA ESTRUTURA
///------------------------------------------------------------------------------------------------------------------------------------------------------------
int direct = 0; //variavel comum inteiro
FILE* arquivo;//Variavel FILE para apontar arquivo aba funcionário
FILE* DadosFunci;
FILE *client; // variavel FILE para apontar em um arquivo
DADOS login_dados;



   ///PROTÓTIPO DE FUNÇÕES
///------------------------------------------------------------------------------------------------------------------------------------------------------------
 void cadastro(); //protótipo da função de cadastro funcionário
 void login(); //protótipo da função de login
 void areatrab(); //para menu de funcionários
 void cadclient(); //função de cadastro de clientes
 void agenda(); //função para agendamento de consultas
 void cadmedic(); //função de cadastro de médicos
 void pesquisa(); //protótipo da area de pesquisar clientes
 void feedback(); //função de feedback
 void cancela(); //função para cancelamentos de consultas
 void listar_dados(); //função de lista de clientes
 void cabecalho(); // função para retorna mensaens por meio ode parametros
 void mensagem_cmd(); // funão para imprimir mensagens por parametros

///------------------------------------------------------------------------------------------------------------------------------------------------------------

void cabecalho(int opcao){
   switch (opcao){
   case 1:
      printf("\n=======================================\n");
      printf("*                                     *\n");
      printf("*             Menu Inicio             *\n");
      printf("*                                     *\n");
      printf("=======================================\n");
      break;  
   case 2:
      printf("\n=======================================\n");
      printf("*                                     *\n");
      printf("*            Menu Cadastro            *\n");
      printf("*                                     *\n");
      printf("=======================================\n");
      break;
   case 3:
      printf("\n=======================================\n");
      printf("*                                     *\n");
      printf("*             Menu Login              *\n");
      printf("*                                     *\n");
      printf("=======================================\n");
      break;
   case 4:
      printf("\n=======================================\n");
      printf("*                                     *\n");
      printf("*             Menu Opções             *\n");
      printf("*                                     *\n");
      printf("=======================================\n");
      break;
   case 5:
      printf("\n=======================================\n");
      printf("*                                     *\n");
      printf("*        Cadastro de Cliente          *\n");
      printf("*                                     *\n");
      printf("=======================================\n");
      break;
   default:
      break;
   }

}

void mensagem_cmd(char mensagem[SIZE]){
   printf("\n================= %s =================\n", mensagem);
}


///MENU DE OPÇÕES
void main(){
   char usuario[SIZE];
   char senha[SIZE];
   setlocale(LC_ALL, "");
   cabecalho(1);

   printf("\n1 - LOGIN\n");
   printf("2 - CADASTRO\n");
   printf("\nEscolha sua opção: ");
   scanf("%d" , &direct);

   switch(direct){
      case 1:
         system("cls");
         login();

      break;
      case 2:
         system("cls");
         cadastro();
      break;
      default:
         printf("Opção inválida") ;
   }
}

///AREA DE TRABALHO
  void areatrab(){
     system("cls");
     cabecalho(4);
     printf("\nInformações:\nNome utilizador: %s\nCPF: %s\n", login_dados.nome, login_dados.cpf);
     printf("=============================\n\n");
     printf("\n1 - CADASTRO DE CLIENTES");
     printf("\n2 - CADASTRO DE MÉDICOS");
     printf("\n3 - PESQUISA MEDICOS/PACIENTES");
     printf("\n4 - AGENDAMENTOS");
     printf("\n5 - CANCELAMENTO DE CONSULTAS");
     printf("\n6 - LISTA DE CLIENTES/MEDICOS CADASTRADOS");
     printf("\n7 - LISTAR");

     printf("\nEscolha sua opção: ");
     scanf("%d" , &direct);

    switch(direct){
    case 1:
       printf("Iniciando CADASTRO DE CLIENTES...\n");
       cadclient();

    case 2:
       printf("Iniciando CADASTRO DE MÉDICOS...\n");
       //cadmedic();
       break;

    case 3:
       printf("Iniciando AGENDAMENTOS...\n");
       //agenda();
       break;

     case 4:
       printf("\nIniciando PESQUISAR...\n");
       pesquisa_funcionario();
       break;

    case 5:
       printf("Iniciando FEEDBACK...\n");
       //feedback();
       break;

    case 6:
       printf("Iniciando CANCELAMENTO DE CONSULTAS...\n");
       //cancela();
       break;

    case 7:
       printf("Iniciando LISTA DE CLIENTES/MEDICOS CADASTRADOS...\n");
       listar_dados();
       break;


    default:
        printf("OPÇÃO INVÁLIDA\n");
       }
 }


// PARTE CADASTRO UTILIZADOR

 void cadastro(){
    arquivo = fopen("Dados/Login.txt", "ab");
    system("cls");
   do{

      cabecalho(2);

      printf("\nDigite nome do utilizador do sistema: ");
      fflush(stdin);
      gets(login_dados.nome);


      printf("\nDigite sua cpf sem pontuação(servirá como login): ");
      fflush(stdin);
      gets(login_dados.cpf);

      printf("\nDigite sua senha(apenas 8 dígitos): ");
      fflush(stdin);
      gets(login_dados.senha);

   if(arquivo == NULL){
      printf("Erro na abertura do arquivo");
   }
      fwrite(&login_dados, sizeof(DADOS), 1, arquivo);
      fclose(arquivo);

        system("cls");
        mensagem_cmd("Usúario cadastrado com sucesso!");
        printf("\n1 - Para cadastrar novamente \n2 - para continuar\nDigite sua opção: ");
        fflush(stdin);
        scanf("%i", &direct);

      }while(direct==1);

       system("cls");
       printf("\n1 - SEGUIR PARA LOGIN");
       printf("\n2 - SAIR");
       printf("\nDigite sua opção: ");
       scanf("%i", &direct);

       switch(direct){
           case 1:
              system("cls");
               printf("Seguindo para login...");
              login();
              break;
           case 2:
               printf("Saindo...");
               system("exit");
               break;
           default:
             printf("Opção inválida!");
             main();

       }
    } 
// FINAL PARTE CADASTRO UTILIZADOR


///PARTE DO LOGIN
int api_login(char cpf_login[SIZE], char senha_login[SIZE]){
   arquivo = fopen("Dados/Login.txt", "rb");

   while(fread(&login_dados, sizeof(DADOS), 1, arquivo) == 1){
         if((strcmp(cpf_login, login_dados.cpf) == 0) && (strcmp(senha_login, login_dados.senha) == 0 ) ){
              return 1;
         }
   }
   fclose(arquivo);
   return 0;
}
  void login(){
      char login[SIZE];
      char senhalog[9];
      int Verificacao = 0;

     do{
       system("cls");
       cabecalho(3);

       printf("\nDigite o Login(CPF sem pontuacao): ");
       scanf("%s", login);

       printf("Digite sua Senha(MAX 8 Digitos): ");
       scanf("%s", senhalog);

        if(api_login(login, senhalog) == 1 ) {
           Verificacao = 1;
           mensagem_cmd("Usuario Autenticado!");
           sleep(2);
           areatrab();
         }else{
           Verificacao = 0;
           mensagem_cmd("Usuario ou senha incorretos");
           mensagem_cmd("Pressione qualquer teclar para continuar");
           system("pause");
           system("cls");
         }
      }while(Verificacao == 0);
   }
// FINAL PARTE DE LOGIN



///FUNÇÃO PARA CADASTRAR CLIENTES
 void cadclient(){

   do{
   system("cls");
   cabecalho(5);

   printf("\nDigite o Nome do Cliente: ");
   fflush(stdin);
   gets(cad.nome);

   printf("\nDigite o Email do Cliente: ");
   scanf("%s", &cad.email);

   printf("\nDigite o CPF do Cliente: ");
   scanf("%s", &cad.cpf);

   printf("\nDigite o RG do Cliente: ");
   scanf("%s", &cad.rg);

   printf("\nDigite o Telefone do cliente: ");
   scanf("%i" , &cad.telefone);

   printf("\nInforme sobre a Consulta Marcada: ");
   fflush(stdin);
   gets(cad.consulta);

   printf("\nInforme a Data da Consulta: ");
   fflush(stdin);

   printf("\nDigite o Nº da Carterinha: ");
   scanf("%s", &cad.carteirinha);
   fwrite(&cad, sizeof(Cliente),  1, client);

    //abrir um arquivo
    client = fopen(cad.nome, "w");
    if(client == NULL)
      {
       printf("Erro na abertura do arquivo");
       return 1;
      }
    printf("\ndados salvos com sucesso!");

    fprintf(client,"EMAIL: %s", cad.email);
    fprintf(client,"\nCPF: %s", cad.cpf);
    fprintf(client,"\nRG: %s", cad.rg);
    fprintf(client,"\nTELEFONE: %i", cad.telefone);
    fprintf(client,"\nCONSULTA: %s", cad.consulta);
    fprintf(client,"\nDATA: %s", cad.data);
    fprintf(client,"\nCARTEIRINHA: %s", cad.carteirinha);
    fclose(client);
    getch();

   printf("\n\nDigite 1 para continuar ou outro valor para sair: ");
   fflush(stdin);
   scanf("%i", &direct);
   gets(cad.data);
   }while(direct==1);

   system("pause");
   printf("\nAperte enter para voltar...");
   areatrab();
 }



// PARTE DE PESQUIESAR FUNCIONARIO

void api_Pfuncionario(char procurar_funcionario[SIZE]){
   char nome_capturado[SIZE];
   char email_capturado[SIZE];
   char cpf_capturado[SIZE];
   char rg_capturado[SIZE];
   char tel_capturado[SIZE];
   arquivo = fopen("Medicos/DADOS_DO_FUNCIONÁRIO.txt","r");
   while(fscanf(arquivo, "%s %s %s %s %s",nome_capturado, email_capturado, cpf_capturado, rg_capturado, tel_capturado) !=EOF){
      if(!strcmp(nome_capturado, procurar_funcionario)){
         printf("\n***************** DADOS DO FUNCIONARIO *****************\n");
         printf("\n========================================================\n");
         printf("\nNome: %s\nE-Mail: %s\nCPF: %s\nRG: %s\nTelefone: %s \n", nome_capturado, email_capturado, cpf_capturado, rg_capturado, tel_capturado);
         printf("\n========================================================\n\n\n");
      }

   }

    printf("1 - Pesquisar Novamento\n");
    printf("2 - Ir para Menu\n");
    printf("3 - Sair Do Programa\n");
    printf("Escolha sua opção: ");
    scanf("%d" , &direct);
    switch(direct){
      case 1:
          system("cls");
          pesquisa_funcionario();
          break;
      case 2:
         system("cls");
         areatrab();
         break;
      case 3:
          exit(0);
          break;
      default:
         printf("Opção inválida!\n") ;
    }
}

void pesquisa_funcionario(){

char procurar_funcionario[SIZE];
arquivo = fopen("Medicos/DADOS_DO_FUNCIONÁRIO.txt","r");

   system("cls");
   printf("*****************ÁREA DE PESQUISA*****************\n");

      if(arquivo == NULL){ // Verifica se existe o arquivo TXT para ler os dados, se existe executa void normal, caso não exista vai voltar para tela de opções
         printf("***************** Erro na abertura do arquivo *****************\n" ); // Mostra mensagem de erro para usúario ficar ciente que tem erro no arquivo
         printf("***************** Voltando para tela de opções! *****************\n");
         sleep(3); // Agurda 3 segundos
         system("cls"); // Aqui limpamos a tela do CMD com comando "cls"
         areatrab();// Aqui voltamos para tela de opções
      }

      printf("Infome nome do cliente: ");
      scanf("%s", procurar_funcionario);
      api_Pfuncionario(procurar_funcionario);

} // FINAL DA PARTE DE PESQUISAR FUNCIONARIO


//PARTE PARA LISTAR OS DADOS

void api_listarDados(int tipo_dados){
   system("cls");
   if(tipo_dados == 0){

      cabecalho("Iniciando lista de pacientes");
      arquivo = fopen("Pacientes/lista_pacientes.txt", "r");

         while(fread(&login_dados, sizeof(DADOS), 1, arquivo) == 1){
            printf("NOME: %s \nCPF: %s\nSENHa %s\n", login_dados.nome, login_dados.cpf, login_dados.senha );
            printf("\n\n-----------------------------\n\n");
      }
   }else{

         cabecalho("Iniciando lista medicos");
         arquivo = fopen("Medicos/lista_medicos.txt", "r");
         
             while(fread(&login_dados, sizeof(DADOS), 1, arquivo) == 1){
                printf("NOME: %s \nCPF: %s\nSENHa %s\n", login_dados.nome, login_dados.cpf, login_dados.senha );
                printf("\n\n-----------------------------\n\n");
      }
   }
   fclose(arquivo);
}

void listar_dados(){
   int tipo_dados = 0;
      cabecalho("Iniciando lista...");

         printf("Desejar listar quais dados? (Pacientes = 0 | Medicos = 1): ");
         scanf("%i", &tipo_dados);
         api_listarDados(tipo_dados);

}
