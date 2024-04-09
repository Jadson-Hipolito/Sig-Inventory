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
    break;
   case 2:
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
    break;
   case 3:
    printf("\n=====================================\n");
    printf("======= <Excluir Funcionario> =======\n");
    printf("=====================================\n\n"); 

    printf("\n=====================================\n");
    printf("== Cpf do funcionario que ira excluir\n");
    printf("=====================================\n\n");

    printf("Confirmar Exclusão:\n");
    break;
  }
 } while (option != 0);  
}