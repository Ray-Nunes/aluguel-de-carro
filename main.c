/*Sistema de Aluguel de Carros

Funções:
• Login
• Cadastrar Carro (Modelo, Ano, Preço por Dia, Disponibilidade)
• Listar Carros Disponíveis

• Alugar Carro (Selecionar Carro e Informar Período de Aluguel)
• Devolver Carro (Calcular Total a Pagar)
• Exibir Histórico de Alugueis*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char nomeGlobal[50] = "admin";
char senhaGlobal[50] = "Admin123";
int opcao, acesso = 0;

int login(){ 
    char nome[50];
    char senha[50];

    printf("\nDigite seu nome: \n");
    scanf("%s", &nome);

    printf("Digite a sua senha: \n");
    scanf("%s", &senha);

    if(strcmp(nome, nomeGlobal) == 0 && strcmp(senha, senhaGlobal) == 0){
        printf("Acesso liberado\n");
        acesso++;

        system("pause");
        system("cls");

    }else{
        system("cls");
        printf("Nome ou senha incorreto tente novamente.");
        login();
    }
}

char carro[10][5][30]; 
int quantidadeCarro = 0;
int idCarro = 1;

int cadastrarCarro(){

    char addCarro[4];

    do{

        if(quantidadeCarro >= 10){
            printf("Limite de carros cadastrados atingidos");
            break;
        }

        sprintf(carro[quantidadeCarro][0], "%d", idCarro);

        printf("Modelo do carro: ");
        scanf("%s", carro[quantidadeCarro][1]);

        printf("Ano do carro: ");
        scanf("%s", carro[quantidadeCarro][2]);

        printf("Preco por dia do carro: ");
        scanf("%s", carro[quantidadeCarro][3]);

        printf("Disponibilidade do carro: ");
        scanf("%s", carro[quantidadeCarro][4]);

        printf("\nCarro cadastrado com sucesso:\n");
        printf("id - %s | ", carro[quantidadeCarro][0]);
        printf("M - %s | ", carro[quantidadeCarro][1]);
        printf("A - %s | ", carro[quantidadeCarro][2]);
        printf("P - %s | ", carro[quantidadeCarro][3]);
        printf("D - %s  ", carro[quantidadeCarro][4]);

        quantidadeCarro++;
        idCarro++;

        printf("\n\nDeseja adicionar algum carro: ");
        scanf("%s", addCarro); // retirei o \n pq nao estava voltando para a função main 
        system("cls");
    }while(strcmp(addCarro, "sim") == 0);
    
    system("cls");
       
}

void listarCarrosDisponiveis(){

    printf("\nOpcoes de carros: \n\n");

    int i;
    for(i = 0; i < quantidadeCarro; i++){
        if(strcmp(carro[i][4], "sim") == 0){
            printf("id- %s| ", carro[i][0]);
            printf("M - %s| ", carro[i][1]);
            printf("A - %s| ", carro[i][2]);
            printf("P - %s| ", carro[i][3]);
            printf("D - %s\n", carro[i][4]);
        }
    }

    printf("\n\nEsses sao os carros disponiveis. \n");
    system("pause");
    system("cls");

}

void alugarCarro(){

    int idAluguel = 0;
    int tempoAluguel = 0;
    int valorAluguel = 0;

    printf("Aluque seu carro agora\n\n");
    printf("Qual e o codigo do Id do carro que deseja alugar: ");
    scanf("%d", &idAluguel);

    idAluguel--;
    printf("Esse e o carro selecionado: \n");
    printf("id- %s| ", carro[idAluguel][0]);
    printf("M - %s| ", carro[idAluguel][1]);
    printf("A - %s| ", carro[idAluguel][2]);
    printf("P - %s| ", carro[idAluguel][3]);
    printf("D - %s\n\n", carro[idAluguel][4]);

    printf("Por quantos dias voce quer alugar esse carro: ");
    scanf("%d", &tempoAluguel);

    valorAluguel = atoi(carro[idAluguel][3]) * tempoAluguel;

    printf("Esse e o valor do aluguel do carro: %d\n\n", valorAluguel);

    sprintf(carro[idAluguel][4], "%s", "nao");

    system("pause");
    system("cls");
}

void devolverCarro(){
    printf("Esses sao os carros alugados para serem devolvidos:\n");
    int i;
    
    for(i = 0; i < quantidadeCarro; i++){
        if(strcmp(carro[i][4], "nao") == 0){
            printf("id- %s| ", carro[i][0]);
            printf("M - %s| ", carro[i][1]);
            printf("A - %s| ", carro[i][2]);
            printf("P - %s| ", carro[i][3]);
            printf("D - %s\n\n", carro[i][4]);
        }
    }

    system("pause");

}

void historicoAlugueis(){

}

int main(){
    while(1 == 1){
        if(acesso == 0){// so usar se o usuario não tiver acessado a conta 
                printf("\nFaca o seu login\n\n");
                printf("#### Tela de login ####");

                login();
        }

        if(acesso == 1){ // so libera os codigos de aceeso se estiver logado 
            printf("CODIGOS PARA ACESSAR AS FUNCIONALIDADES");
            printf("\n  1 -  Cadastrar carro");
            printf("\n  2 -  Listar Carros Disponiveis");
            printf("\n  3 -  Alugar Carro");
            printf("\n  4 -  Devolver Carro");
            printf("\n  5 -  Exibir Historico de Alugueis\n\n");
            printf("Digite o codigo aqui: ");
            scanf("%d", &opcao); // depois que o usuario digitou o codigo em seguida tem que ser atribuido o valor de 0 para que quando voltar para essa função não der erro   
            
            switch (opcao){
                case 1: cadastrarCarro(); break;
                case 2: listarCarrosDisponiveis(); break;
                case 3: alugarCarro(); break;
                case 4: devolverCarro(); break;
                case 5: historicoAlugueis(); break;
            }  
        
        }else{
            printf("Acesso negado.");
        }
    }  
}