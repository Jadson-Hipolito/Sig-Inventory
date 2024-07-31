#include "produto.h"
#include "tipo_produto.h"
#include "util.h"
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
        delay(2000);
        limpaTela();
        break;
      case 4:
        listar_tipo_produto();
        char nome_exluir[45];
        printf("Digite o nome do tipo do produto: ");
        fgets(nome_exluir, 45, stdin);
        nome_exluir[strcspn(nome_exluir, "\n")] = '\0';
        excluir_tipo_produto(* nome_exluir);
        break;

      default:
        printf("Deve digitar um número valido");
        break;
    }
  } while (option != 0);
}

int listar_tipo_produto(void){
    FILE *fp;
    Tipo *tipo = (Tipo*) malloc(sizeof(Tipo));
    
    fp = fopen(ARQUIVO_TIPOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("-------------------------- Lista de Alunos --------------------------------\n");
    while (fread(tipo, sizeof(Tipo), 1, fp))
    {
      if (tipo->stats == true){
       exibir_tipo(tipo);
      }
    }
    printf("---------------------------------------------------------------------------\n");
};

void cadastro_tipo_produto(Tipo *tipo_cad) {
    printf("\n=====================================\n");
    printf("==== <Cadastrar Tipo de Produto> ====\n");
    printf("=====================================\n");

    printf("Digite o nome do tipo do produto: ");
    fgets(tipo_cad->nome, 45, stdin);
    tipo_cad->nome[strcspn(tipo_cad->nome, "\n")] = '\0';

    tipo_cad->stats = 1;
    gravar_tipo_produto(tipo_cad);
};

int gravar_tipo_produto(Tipo *tipo_cad){
    FILE *fp;
    fp = fopen(ARQUIVO_TIPOS, "ab");
    if (fp == NULL){
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    fwrite(tipo_cad,sizeof(Tipo),1,fp);
    fclose(fp);
    return 1;
};

void exibir_tipo(Tipo *tipo){
    printf("Nome: %s\n",
          tipo->nome);
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