#include "entrada_saida.h"
#include <stdio.h>

void menu_Entrada_Saida(){
 int option;
 do {
  printf("\n=====================================\n");
  printf("====== <Menu Entrada e Saida> =======\n");
  printf("=====================================\n");
  printf("1 - Entrada e Saida de Produtos\n");
  printf("2 - Entrada e Saida de Funcionarios\n");
  printf("3 - Editar Entrada e Saida de Funcionario\n");
  printf("4 - Remover Entrada ou saida de Funcionario\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch (option){
   case 1:
    printf("\n=====================================\n");
    printf("===== <Entrada e Saida Produtos> ====\n");
    printf("=====================================\n\n");
   break;

   case 2:
    printf("\n=====================================\n");
    printf("=== <Entrada e Saida Funcionarios> ==\n");
    printf("=====================================\n\n");
   break;

   case 3:
    printf("\n===============================================\n");
    printf("=== <Editar Entrada e Saida de funcionario> ===\n");
    printf("\n===============================================\n");
    printf("Cpf do funcionario que ira editara entrada:\n");
    break;

   case 4:
    printf("===================================================\n");
    printf("=== <Remover Entrada ou Saida de Funcionario> ===\n");
    printf("===================================================\n");
    printf("Cpf do funcionario que ira remover entrada:\n");
    break;
  }
 } while (option != 0);
}