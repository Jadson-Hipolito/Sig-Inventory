#include "produto.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nome_produto[50];
char codigo_produto[13];
int quantidade = 0;
char tipo_produto[20];
char local_produto[5];
char fornecedor[50];
int quantidade_reposicao = 0;
char anotacao_armazenamento[100];

#define ARQUIVO_PRODUTOS "produto.txt"

void menu_produto(){
    int option = 5;
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
                Produto* produto = (Produto *) malloc(sizeof(Produto));
                cadastro_produto(produto);
                gravar_produto(produto);
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

            default:
                printf("Deve digitar um número");
                break;
        }
    } while (option != 0);
} 

void cadastro_produto(Produto *produto) {
    printf("\n=====================================\n");
    printf("======== <Cadastrar Produto> ========\n");
    printf("=====================================\n");

    printf("Digite o nome do produto: ");
    fgets(produto->nome_produto, 50, stdin);
    produto->nome_produto[strcspn(produto->nome_produto, "\n")] = '\0';

    bool upc_valido = false;
    while (!upc_valido) {
      printf("Digite o UPC do produto: ");
      fgets(produto->codigo_produto, 12, stdin);
      produto->codigo_produto[strcspn(produto->codigo_produto, "\n")] = '\0';

      upc_valido = validar_upc(produto->codigo_produto);
      if (!upc_valido) {
        printf("UPC invalido! Digite novamente.\n");
      }
    }

    printf("Digite a quantidade do produto: ");
    scanf("%d", &produto->quantidade);
    getchar();

    printf("Digite o tipo do produto: ");
    fgets(produto->tipo_produto, 20, stdin);
    produto->tipo_produto[strcspn(produto->tipo_produto, "\n")] = '\0';

    printf("Digite o local do produto: ");
    fgets(produto->local_produto, 5, stdin);
    produto->local_produto[strcspn(produto->local_produto, "\n")] = '\0';

    printf("Digite o fornecedor do produto (opcional): ");
    fgets(produto->fornecedor, 50, stdin);
    produto->fornecedor[strcspn(produto->fornecedor, "\n")] = '\0';

    printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
    scanf("%d", &produto->quantidade_reposicao);
    getchar();

    printf("Digite uma nota de armazenamento para o produto (opcional): ");
    fgets(produto->anotacao_armazenamento, 50, stdin);
    produto->anotacao_armazenamento[strcspn(produto->anotacao_armazenamento, "\n")] = '\0';

    printf("Digite o status do produto (1 para ativo, 0 para inativo): ");
    scanf("%d", &produto->stats);
    getchar();

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

int validar_upc(char *codigo) {
 int soma = 0;

 if (strlen(codigo) != 12) {
  return 0;
 }
 for (int i = 0; i < 11; i += 2) {
  soma += (codigo[i] - '0') * 3;
 }
 for (int i = 1; i < 11; i += 2) {
  soma += (codigo[i] - '0');
 }
 int digito_verificacao = 10 - (soma % 10);
 if (digito_verificacao == 10) {
  digito_verificacao = 0;
 }
 if (digito_verificacao == codigo[11] - '0') {
  return 1;
 }
 else {
  return 0;
 }
}

int gravar_produto(Produto *produto){

  FILE *fp;
  fp = fopen(ARQUIVO_PRODUTOS, "at");
  if (fp == NULL) {
    printf("Erro na criacao do arquivo!\n");
    return 0;
  }
  fprintf(fp,
          "Nome: %s, codigo: %s, quantidade: %d, tipo do produto: %s, local do produto: %s, fornecedor: %s, quantidade de reposicao: %d, anotação de armazenamento: %s, status: %d\n",
          produto->nome_produto, produto->codigo_produto, produto->quantidade,
          produto->tipo_produto, produto->local_produto, produto->fornecedor, produto->quantidade_reposicao,
          produto->anotacao_armazenamento, produto->stats);
  fclose(fp);
}