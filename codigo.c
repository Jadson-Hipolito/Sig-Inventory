#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "funcionario.h"
#include "entrada_saida.h"
#include "fornecedor.h"
#include "produto.h"
#include "biblioteca_verificar.h"
#include "tipo_produto.h"
#include "cargo.h"

int main(){
 int menu = 5;
 do {
  printf("\n=====================================\n");
  printf("========= <Menu Inventario> =========\n");
  printf("=====================================\n");
  printf("1 - Produtos\n");
  printf("2 - Funcionarios\n");
  printf("3 - Entrada e Saida\n");
  printf("4 - Tipo produto\n");
  printf("5 - Cargos\n");
  printf("6 - Fornecedores\n");
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
    menu_entrada_saida();
    break;
   case 4:
    menu_tipo_produto();
    break;
   case 5:
    menu_cargo();
    break;
   case 6:
    menu_fornecedor();
    break;
   default:
    printf("Deve digitar um número");
    break;
   }
 } while (menu != 0);
 return 0;
} 