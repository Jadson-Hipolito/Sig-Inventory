#include "entrada_saida.h"
#include "produto.h"
#include "funcionario.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

#define ARQUIVO_ENTRADA_E_SAIDA "entrada_e_saida.dat"

void menu_entrada_saida(void){
 int option = 5;
 do {
  printf("\n=============================================\n");
  printf("====== <Menu Entrada e Saida produto> =======\n");
  printf("=============================================\n");
  printf("1 - Entradas de Produto\n");
  printf("2 - Saida de Produto\n");
  printf("3 - Editar Entrada e Saida\n");
  printf("4 - Remover Entrada ou saida\n");
  printf("5 - listar produtos que precisam repor\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch (option){
    case 1:
      Entrada_Saida *entrada_saida_adi = (Entrada_Saida *) malloc(sizeof(Entrada_Saida));
      entrada_e_saida(entrada_saida_adi, 1);
      break;

    case 2:
      Entrada_Saida *entrada_saida_sub = (Entrada_Saida *) malloc(sizeof(Entrada_Saida));
      entrada_e_saida(entrada_saida_sub, 1);
      break;

    case 3:
      editar_entrada_saida_produto();

    case 4:
      remove_entrada_saida_produto();
      break;

    case 5:
      listar_produto(3);

    default:
      printf("Deve digitar um número");
      break;
  }
 } while (option != 0);
}

void entrada_e_saida(Entrada_Saida *entrada_saida, int sinal){
  int quant;
  char codigo_produto[13] = "0";
  char cpf[12];
  printf("Informe a codigo UPC do produto: ");
  scanf("%s", codigo_produto);
  getchar();
  Produto *produtox = buscar_produto(codigo_produto);
  if (produtox != NULL){
    printf("a");
    exibir_produto(produtox);
    * entrada_saida->produto_editado = * produtox->codigo_produto;

    printf("Cpf do funcionario que registrou a entrada: ");
    scanf("%s", cpf);
    Funcionario * funcionario = buscar_funcionario(cpf);
    * entrada_saida->cpf_do_funcionario = * funcionario->cpf;

    printf("\nQuantidade de produtos que chegaram ou sairam: ");
    scanf("%d", &entrada_saida->quantidade);
    getchar();
    produtox->quantidade += entrada_saida->quantidade*sinal;

    printf("Digite uma nota sobre a chegada ou saida do produto (opcional): ");
    fgets(entrada_saida->anotacao_da_entrada_saida, 100, stdin);
    entrada_saida->anotacao_da_entrada_saida[strcspn(entrada_saida->anotacao_da_entrada_saida, "\n")] = '\0';

    entrada_saida->tipo = sinal;

    time_t now;
    time(&now);

    // Converter a hora atual para o tempo local
    struct tm *local = localtime(&now);

    // Extrair ano, mês, dia, hora, minuto e segundo
    entrada_saida->ano = local->tm_year + 1900;
    entrada_saida->mes = local->tm_mon + 1;
    entrada_saida->dia = local->tm_mday;
    entrada_saida->hora = local->tm_hour;
    entrada_saida->minuto = local->tm_min;
    entrada_saida->segundo = local->tm_sec;

    gravar_entrada_ou_saida(entrada_saida);
    atualiza_produto(produtox);

  }
}

int gravar_entrada_ou_saida(Entrada_Saida *entrada_saida){
  FILE *fp;
    fp = fopen(ARQUIVO_ENTRADA_E_SAIDA, "ab");
    if (fp == NULL)
    {
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    //Insere o aluno no final do arquivo
    fwrite(entrada_saida,sizeof(Entrada_Saida),1,fp);
    fclose(fp);
}

void editar_entrada_saida_produto(void){
  printf("\n===============================================\n");
  printf("=== <Editar Entrada e Saida de Produto> ===\n");
  printf("\n===============================================\n");
  printf("Codigo do produto que ira editar a entrada:\n");
}

void remove_entrada_saida_produto(void){
  printf("===================================================\n");
  printf("=== <Remover Entrada ou Saida de Produto> ===\n");
  printf("===================================================\n");
  printf("Codigo do produto que ira remover entrada:\n");
}
