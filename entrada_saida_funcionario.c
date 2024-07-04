#include "entrada_saida_funcionario.h"
#include <stdio.h>

void menu_entrada_saida_funcionario(void){
 int option = 5;
 do {
  printf("\n========================================\n");
  printf("== <Menu Entrada e Saida funcionario> ==\n");
  printf("========================================\n");
  printf("1 - Entradas e Saidas\n");
  printf("2 - Editar Entrada e Saida\n");
  printf("3 - Remover Entrada ou saida\n");
  printf("4 - Confirmar chegada e saida de produto\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch (option){
   case 1:
    entrada_saida_funcionario();
   break;

   case 2:
    editar_entrada_saida_funcionario();
   break;

   case 3:
    remove_entrada_saida_funcionario();
    break;

   case 4:
    confirma_entrada_saida_funcionario();
    break;
   
   default:
    printf("Deve digitar um número");
    break;
  }
 } while (option != 0);
}

void entrada_saida_funcionario(void){
  printf("\n=====================================\n");
  printf("========== <Entrada e Saida> ==========\n");
  printf("=======================================\n\n");
  printf("Digite o cpf do funcionario");
}

void editar_entrada_saida_funcionario(void){
  printf("\n===============================================\n");
  printf("=== <Editar Entrada e Saida de funcionario> ===\n");
  printf("\n===============================================\n");
  printf("Cpf do funcionario que ira editar entrada:\n");
}

void remove_entrada_saida_funcionario(void){
  printf("\n=================================================\n");
  printf("=== <Remover Entrada ou Saida de Funcionario> ===\n");
  printf("===================================================\n");
  printf("Cpf do funcionario que ira remover entrada:\n");
}

void confirma_entrada_saida_funcionario(void){
  printf("\n=================================================\n");
  printf("=== <Confirmar Entrada ou Saida de Funcionario> ===\n");
  printf("===================================================\n");
  printf("Cpf do funcionario que ira remover entrada:\n");
}