#include "entrada_saida_produto.h"
#include "produto.h"
#include "funcionario.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO_ENTRADA_E_SAIDA "entrada_e_saida.txt"

void menu_entrada_saida_produto(void){
 int option = 5;
 do {
  printf("\n=============================================\n");
  printf("====== <Menu Entrada e Saida produto> =======\n");
  printf("=============================================\n");
  printf("1 - Entradas de Produto\n");
  printf("2 - Saida de Produto");
  printf("3 - Editar Entrada e Saida\n");
  printf("4 - Remover Entrada ou saida\n");
  printf("5 - Confirmar chegada e saida de produto\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch (option){
   case 1:
    entrada_de_produto();
   break;

   case 2:
    editar_entrada_saida_produto();
   break;

   case 3:
    remove_entrada_saida_produto();
    break;

   case 4:
    confirma_entrada_saida_produto();
    break;

   default:
    printf("Deve digitar um número");
    break;
  }
 } while (option != 0);
}

void entrada_de_produto(void){
  int quant;
  char codigo_produto[13] = "0";
  char cpf[12];
  printf("Informe a codigo UPC do produto: ");
  scanf("%s", codigo_produto);
  getchar();
  Produto *produtox = buscar_produto(codigo_produto);
  if ((produtox != NULL) && (*produtox->codigo_produto == 1)){
    exibir_produto(produtox);
    printf("Cpf do funcionario que registrou a entrada: ");
    scanf("%e", cpf);
    buscar_funcionario(cpf); 
    printf("\nQuantidade de produtos que chegaram: ");
    scanf("%e", quant);
    getchar();
    produtox->quantidade += quant;
    atualiza_produto(produtox);
  }
  return 0;
}

void saida_de_produto(void){
  int quant;
  char codigo_produto[13] = "0";
  printf("Informe a codigo UPC do produto: ");
  scanf("%s", codigo_produto);
  getchar();
  Produto *produtox = buscar_produto(codigo_produto);
  if ((produtox != NULL) && (*produtox->codigo_produto == 1)){
    exibir_produto(produtox);
    Produto *produtox = buscar_produto(codigo_produto);
    printf("\nQuantidade de produtos que chegaram: ");
    scanf("%e", quant);
    getchar();
    produtox->quantidade += quant;
    atualiza_produto(produtox);
  }
  return 0;
}

void editar_entrada_saida_produto(void){
  printf("\n===============================================\n");
  printf("=== <Editar Entrada e Saida de Produto> ===\n");
  printf("\n===============================================\n");
  printf("Codigo do produto que ira editara entrada:\n");
}

void remove_entrada_saida_produto(void){
  printf("===================================================\n");
  printf("=== <Remover Entrada ou Saida de Produto> ===\n");
  printf("===================================================\n");
  printf("Codigo do produto que ira remover entrada:\n");
}

void confirma_entrada_saida_produto(void){
  printf("===================================================\n");
  printf("=== <Confirmar Entrada ou Saida de Produto> ===\n");
  printf("===================================================\n");
  printf("Codigo do produto que ira remover entrada:\n");
}