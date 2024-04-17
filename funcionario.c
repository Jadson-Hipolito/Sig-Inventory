#include "funcionario.h"
#include <stdio.h>

void menu_funcionario(void){
  int option;
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
  }
 } while (option != 0);  
}

void cadastro_funcionario(void){
 printf("\n=====================================\n");
 printf("======= <Cadastro Funcionario> ======\n");
 printf("=====================================\n");
 printf("1 - Nome do Funcionario:\n");
 printf("2 - CPF:\n");
 printf("3 - Numero:\n");
 printf("4 - Cargo:\n");
 printf("5 - Salário:\n");
 printf("6 - Espediente:\n");
 printf("7 - Endereço:\n");
 printf("0 - Voltar:\n");
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