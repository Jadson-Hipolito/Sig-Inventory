#include <stdio.h>
#include "funcionario.h"
#include "entrada_saida_funcionario.h"
#include "entrada_saida_produto.h"
#include "produto.h"
int menu = 0;

int main(){
 do {
  printf("\n=====================================\n");
  printf("========= <Menu Inventario> =========\n");
  printf("=====================================\n");
  printf("1 - Produtos\n");
  printf("2 - Funcionarios\n");
  printf("3 - Entrada e Saida funcionario\n");
  printf("4 - Entrada e Saida produto\n");
  printf("0 - Finalizar Programa\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf(" %d", &menu);
  getchar();
  switch (menu) {
   case 1:
    menu_produto();
    break;
   case 2:
    menu_funcionario();
    break;
   case 3:
    menu_entrada_saida_funcionario();
    break;
   case 4:
    menu_entrada_saida_produto();
    break;
   }
 } while (menu != 0);
 return 0;
} 