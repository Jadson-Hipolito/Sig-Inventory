#include "produto.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char nome_produto[50];
char codigo_produto[13];
int quantidade = 0;
char tipo_produto[20];
char local_produto[5];
char fornecedor[50];
int quantidade_reposicao = 0;
char anotacao_armazenamento[100];



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

            default:
                printf("Deve digitar um número");
                break;
        }
    } while (option != 0);
}

void cadastro_produto(void){
    printf("\n=====================================\n");
    printf("======== <Cadastrar Produto> ========\n");
    printf("=====================================\n");
    printf("1 - Nome do Produto:\n");
    scanf("%s", nome_produto); 
    printf("2 - Codigo UPC do produto:\n");
    do {
        printf("Digite o código UPC (12 dígitos): ");
        scanf("%s", codigo_produto);
        getchar();
        if (validar_upc(codigo_produto) != 1) {
            printf("Código UPC inválido. Tente novamente.\n");
        }
    } while (validar_upc(codigo_produto) != 1);
    printf("3 - Quantidade Atual:\n");
    scanf("%d", &quantidade); 
    getchar();
    printf("4 - Tipo de Produto:\n");
    scanf("%s", &tipo_produto);
    getchar();
    printf("5 - Local do Produto:\n");
    scanf("%s", &local_produto);
    getchar();
    printf("6 - Fornecedor(Opcional):\n");
    scanf("%s", &fornecedor);
    getchar();
    printf("7 - Quantidade para pedir reposição (Opcional):\n");
    scanf("%d", &quantidade_reposicao);
    getchar();
    printf("8 - Anotações de Armazenamento(Opcional):\n");
    scanf("%s", &anotacao_armazenamento); 
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