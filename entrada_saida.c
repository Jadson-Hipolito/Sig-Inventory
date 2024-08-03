#include "entrada_saida.h"
#include "produto.h"
#include "funcionario.h"
#include "util.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

#define ARQUIVO_ENTRADA_E_SAIDA "entrada_e_saida.dat"
#define ARQUIVO_ENTRADA_E_SAIDA_TEMPORARIO "entrada_e_saida.tmp"

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
  printf("6 - listar entradas e saidas\n");
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
      entrada_e_saida(entrada_saida_sub, -1);
      break;

    case 3:
      editar_entrada_saida_produto();
      break;

    case 4:
      remove_entrada_saida_produto();
      break;

    case 5:
      listar_produto(3);
      break;

    case 6:
      listar_entrada_saida();
      break;

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
    strcpy(entrada_saida->produto_editado, produtox->codigo_produto);

    printf("Cpf do funcionario que registrou a entrada: ");
    scanf("%s", cpf);
    Funcionario * funcionario = buscar_funcionario(cpf);
    strcpy(entrada_saida->cpf_do_funcionario, funcionario->cpf);
    printf("a\n\n\n");

    printf("\nQuantidade de produtos que chegaram ou sairam: ");
    scanf("%d", &entrada_saida->quantidade);
    getchar();
    produtox->quantidade += entrada_saida->quantidade*sinal;

    printf("Digite uma nota sobre a chegada ou saida do produto (opcional): ");
    fgets(entrada_saida->anotacao_da_entrada_saida, 100, stdin);
    entrada_saida->anotacao_da_entrada_saida[strcspn(entrada_saida->anotacao_da_entrada_saida, "\n")] = '\0';

    printf("%s\n", entrada_saida->tipo);
    delay(5000);

    time_t now;
    time(&now);

    // Converter a hora atual para o tempo local
    struct tm *local = localtime(&now);

    // Extrair ano, mês, dia, hora, minuto e segundo
    entrada_saida->codigo = (local->tm_year + 1900)*10000000000;
    entrada_saida->codigo += (local->tm_mon + 1)*100000000;
    entrada_saida->codigo += (local->tm_mday)*1000000;
    entrada_saida->codigo += (local->tm_hour)*10000;
    entrada_saida->codigo += (local->tm_min)*100;
    entrada_saida->codigo += (local->tm_sec);

    entrada_saida->stats = 1;

    * entrada_saida->tipo = sinal;
    

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

int excluir_entrada_saida(Entrada_Saida *entrada_saida){
    FILE *fleitura;
    FILE *fescrita;
    Entrada_Saida *auxiliarLeitura = (Entrada_Saida *) malloc(sizeof(Entrada_Saida));
    int codigo;
 
    fleitura = fopen(ARQUIVO_ENTRADA_E_SAIDA, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_ENTRADA_E_SAIDA_TEMPORARIO, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    //Lendo o arquivo atual
    while (fread(auxiliarLeitura, sizeof(Entrada_Saida), 1, fleitura))
    {
        //Caso a matricula seja diferente
        if(auxiliarLeitura->codigo != entrada_saida->codigo){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Entrada_Saida), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_ENTRADA_E_SAIDA_TEMPORARIO,ARQUIVO_ENTRADA_E_SAIDA);
    free(auxiliarLeitura);
    return 1;
};

void exibir_entrada_saida(Entrada_Saida *entrada_saida){
    char tipo[10];
    if (entrada_saida > 0){
      strcpy(tipo,"entrada");
    }
    if (entrada_saida < 0){
      strcpy(tipo,"entrada");
    }
    printf("Codigo %d, o funcionario de cpf %s, registrou a %s de %d produtos de codigo UPC %s\n",
          entrada_saida->codigo, entrada_saida->cpf_do_funcionario, tipo, entrada_saida->quantidade, entrada_saida->produto_editado);
};

int listar_entrada_saida(void){
    FILE *fp;
    Entrada_Saida *entrada_saida = (Entrada_Saida*) malloc(sizeof(Entrada_Saida));
    
    fp = fopen(ARQUIVO_ENTRADA_E_SAIDA, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("--------------------- Lista de Entradas e Saida --------------------------\n");
    while (fread(entrada_saida, sizeof(Entrada_Saida), 1, fp))
    {
      if (entrada_saida->stats == true){
       exibir_entrada_saida(entrada_saida);
      }
    }
    printf("---------------------------------------------------------------------------\n");
    getchar();
    limpaTela();
};