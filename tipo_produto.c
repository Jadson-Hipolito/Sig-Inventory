#include "produto.h"
#include "tipo_produto.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO_TIPOS "tipos.dat"
#define ARQUIVO_TIPOS_TEMPORARIOS "tipos.tmp"

void menu_tipo_produto(void){
  int option = 99;
  do {
    printf("\n==================================\n");
    printf("========== <Menu Tipos> ==========\n");
    printf("==================================\n");
    printf("1 - Cadastra Tipo Produto\n");
    printf("2 - Buscar Tipo de Troduto\n");
    printf("3 - Listar Tipos de Produtp\n");
    printf("4 - Excluir Cadastro de um Tipo\n");
    printf("0 - Voltar para <Menu Inventario>\n");
    printf("=====================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 0:
        break;
      case 1:
        Tipo *tipo_cad = (Tipo *) malloc(sizeof(Tipo));
        cadastro_tipo_produto(tipo_cad);
        gravar_tipo_produto(tipo_cad);
        break;
      case 2:
        char nome[45];
        printf("Digite o nome do tipo de produto a ser excluido\n");
        fgets(nome, 45, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        Tipo *tipo_excluir = buscar_tipo_produto(nome);
        excluir_tipo_produto(*tipo_excluir->nome);
        break;
      case 3:
        listar_tipo_produto();
        break;
      case 4:
        break;

      default:
        printf("Deve digitar um número valido");
        break;
    }
  } while (option != 0);
}

int listar_tipo_produto(void){
  int i = 0;
  FILE *fp;
    Tipo *tip = (Tipo*) malloc(sizeof(Tipo));
    
    fp = fopen(ARQUIVO_TIPOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("-------------------------- Lista de Alunos --------------------------------\n");
    while (fread(tip, sizeof(Tipo), 1, fp)) {
      i++;
      if (tip->stats == true){
       printf("%d-Nome: %s\n",
          i, tip->nome);
      }
    }
    printf("---------------------------------------------------------------------------\n");
    
};

void cadastro_tipo_produto(Tipo *tipo) {
    printf("\n=====================================\n");
    printf("==== <Cadastrar Tipo de Produto> ====\n");
    printf("=====================================\n");

    printf("Digite o nome do tipo do produto: ");
    fgets(tipo->nome, 45, stdin);
    tipo->nome[strcspn(tipo->nome, "\n")] = '\0';

    tipo->stats = 1;
};

int gravar_tipo_produto(Tipo *tipo){

  FILE *fp;
  fp = fopen(ARQUIVO_TIPOS, "at");
  if (fp == NULL) {
    printf("Erro na criacao do arquivo!\n");
    return 0;
  }
  fprintf(fp,
          "Nome: %s, status: %d\n",
          tipo->nome, tipo->stats);
  fclose(fp);
};

int excluir_tipo_produto(char nome){
    FILE *fleitura;
    FILE *fescrita;
    Tipo *auxiliarLeitura = (Tipo *) malloc(sizeof(Tipo));
 
    fleitura = fopen(ARQUIVO_TIPOS, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_TIPOS_TEMPORARIOS, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    while (fread(auxiliarLeitura, sizeof(Tipo), 1, fleitura))
    {
        if(*auxiliarLeitura->nome != nome){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Tipo), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_TIPOS_TEMPORARIOS,ARQUIVO_TIPOS);
    return 1;
};

Tipo* buscar_tipo_produto(char *nome){
    FILE *fp;
    Tipo *tipo = (Tipo *)malloc(sizeof(Tipo));
    fp = fopen(ARQUIVO_TIPOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return NULL;
    }
    while (fread(tipo, sizeof(Tipo), 1, fp))
    {
        if(strcmp(tipo->nome, nome) == 0){
            fclose(fp);
            return tipo;
        }
    }
    fclose(fp);
    return NULL;
};