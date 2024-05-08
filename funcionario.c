#include "funcionario.h"
#include "biblioteca_verificar.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char nome_funcionario[50];
char cpf_funcionario[12];
char numero_funcionario[10];
char cargo_funcionario[50];
char endereco_funcionario[100];
int salario_funcionario = 0;
char expediente_funcionario[50];

struct Funcionario {
    char nome[50];
    char cpf[12];
    char numero[10];
    char cargo[50];
    char endereco[100];
    int salario;
    char expediente[50];
};

struct Funcionario funcionario;

void menu_funcionario(void){
  int option =5;
  do {
  printf("\n=====================================\n");
  printf("========= <Menu Funcionario> ========\n");
  printf("=====================================\n");
  printf("1 - Cadastra Funcionario Novo\n");
  printf("2 - Editar Cadastro\n");
  printf("3 - Listar Funcionarios\n");
  printf("4 - Excluir Funcionario\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch(option){
   case 1:
    cadastro_funcionario();
    break;
   case 2:
    editar_funcionario();
    break;
   case 3:
    listar_funcionario();
    break;
   case 4:
    excluir_funcionario();
    break;
   default:
    printf("Deve digitar um número");
    break;
  }
 } while (option != 0);  
}

#include <stdio.h>

void cadastro_funcionario(void) {
    printf("\n=====================================\n");
    printf("======= <Cadastro Funcionario> ======\n");
    printf("=====================================\n");

    printf("1 - Nome do Funcionario:\n");
    scanf("%s", funcionario.nome);
    getchar(); // Limpa o buffer do teclado

    printf("2 - CPF:\n");
    scanf("%s", funcionario.cpf);
    getchar(); // Limpa o buffer do teclado
    if (!validar_cpf(funcionario.cpf)) {
        printf("CPF inválido. Tente novamente.\n");
        return; // Retorna para evitar o cadastro de funcionário com CPF inválido
    }

    printf("3 - Numero:\n");
    scanf("%s", funcionario.numero);
    getchar(); // Limpa o buffer do teclado
    if (!verificar_telefone(funcionario.numero)) {
        printf("Número inválido. Tente novamente.\n");
        return; // Retorna para evitar o cadastro de funcionário com número inválido
    }

    printf("4 - Cargo:\n");
    scanf("%s", funcionario.cargo);
    getchar(); // Limpa o buffer do teclado

    printf("5 - Salário:\n");
    scanf("%d", &funcionario.salario);
    getchar(); // Limpa o buffer do teclado

    printf("6 - Expediente:\n");
    scanf("%s", funcionario.expediente);
    getchar(); // Limpa o buffer do teclado

    printf("7 - Endereço:\n");
    scanf("%s", funcionario.endereco);
    getchar(); // Limpa o buffer do teclado
    if (!verificar_endereco(funcionario.endereco)) {
        printf("Endereço inválido. Tente novamente.\n");
        return; // Retorna para evitar o cadastro de funcionário com endereço inválido
    }

    printf("=====================================\n");
}


void editar_funcionario(void){
  printf("\n=====================================\n");
  printf("==<Editar informação do Funcionario>=\n");
  printf("=====================================\n\n"); 

  printf("\n=====================================\n");
  printf("== Cpf do funcionario que ira editar:\n");
  printf("=====================================\n\n"); 

  printf("1 - Nome do Funcionario:\n");
  printf("2 - Numero:\n");
  printf("3 - Cargo:\n");
  printf("4 - Salário:\n");
  printf("5 - Espediente:\n");
  printf("6 - Endereço:\n");
  printf("0 - Voltar:\n");
  printf("=====================================\n");
}

void excluir_funcionario(void){
  printf("\n=====================================\n");
  printf("======= <Excluir Funcionario> =======\n");
  printf("=====================================\n\n"); 

  printf("\n=====================================\n");
  printf("== Cpf do funcionario que ira excluir\n");
  printf("=====================================\n\n");

  printf("Confirmar Exclusão:\n");
}

void listar_funcionario(void){
  printf("\n=====================================\n");
  printf("======= <Lista de Funcionario> ======\n");
  printf("=====================================\n\n");
  printf("1 - Lista de Funcionarios Cadastrados:\n");
  printf("=====================================\n");
}