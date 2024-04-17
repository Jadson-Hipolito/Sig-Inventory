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
    cadastro_produto();
    break;
   case 2:
    excluir_produto();
    break;
   case 3:
    alterar_produto();
    break;
   case 4:
    listar_produto();
    break;
  }
 } while (option != 0);
}

void cadastro_produto(void){
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
}

void excluir_produto(void){
  printf("\n=====================================\n");
  printf("========== <Excluir Produto> =========\n");
  printf("=====================================\n\n");
  printf("1 - Codigo do Produto:\n");
  printf("=====================================\n");
  printf("confirmar exclusão digite 1:\n");
}

void alterar_produto(void){
  printf("\n=====================================\n");
  printf("======== <Editar Produto> ===========\n");
  printf("=====================================\n\n");
  printf("1 - Codigo do Produto:\n");
  printf("=====================================\n\n");
  printf("1 - Nome do Produto:\n");
  printf("2 - Tipo de Produto:\n");
  printf("3 - Local do Produto:\n");
  printf("4 - Fornecedor:\n");
  printf("5 - Quantidade para pedir reposição:\n");
  printf("6 - Anotações de Armazenamento:\n");
}

void listar_produto(void){
  printf("\n=====================================\n");
  printf("========= <Lista de Produto> ========\n");
  printf("=====================================\n\n");
  printf("1 - Lista de Produtos Cadastrados:\n");
  printf("=====================================\n");
  printf("=====================================\n");
}