#include "produto.h"
#include <stdio.h>

void menu_produto(){
 int option;
 do {
  printf("\n=====================================\n");
  printf("========== <Menu Produtos> ==========\n");
  printf("=====================================\n");
  printf("1 - Cadastra Produto Novo\n");
  printf("2 - Excluir Produto\n");
  printf("3 - Alterar Produto\n");
  printf("4 - Listar Produtos\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch(option){
   case 1:
    printf("\n=====================================\n");
    printf("======== <Cadastrar Produto> ========\n");
    printf("=====================================\n");
    printf("1 - Nome do Produto:\n");
    printf("2 - Codigo de Barra:\n");
    printf("3 - Quantidade Atual:\n");
    printf("4 - Tipo de Produto:\n");
    printf("5 - Local do Produto:\n");
    printf("6 - Fornecedor(Opcional):\n");
    printf("7 - Quantidade para pedir reposição (Opcional):\n");
    printf("8 - Anotações de Armazenamento(Opcional):\n");
    printf("=====================================\n");
    break;
   case 2:
    printf("\n=====================================\n");
    printf("========== <Editar Produto> =========\n");
    printf("=====================================\n\n");
    printf("1 - Codigo do Produto:\n");
    printf("=====================================\n");
    printf("1 - Nome do Produto:\n");
    printf("2 - Codigo de Barra:\n");
    printf("3 - Quantidade Atual:\n");
    printf("4 - Tipo de Produto:\n");
    printf("5 - Local do Produto:\n");
    printf("6 - Fornecedor(Opcional):\n");
    printf("7 - Quantidade para pedir reposição (Opcional):\n");
    printf("8 - Anotações de Armazenamento(Opcional):\n");
    printf("=====================================\n");
    printf("=====================================\n");
    break;
   case 3:
    printf("\n=====================================\n");
    printf("========= <Lista de Produto> ========\n");
    printf("=====================================\n\n");
    printf("1 - Lista de Produtos Cadastrados:\n");
    printf("=====================================\n");
    printf("=====================================\n");
    break;
  }
 } while (option != 0);
}