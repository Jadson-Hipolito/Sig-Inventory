#include "funcionario.h"
#include "cargo.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO_CARGOS "cargo.dat"
#define ARQUIVO_CARGOS_TEMPORARIOS "cargo.tmp"

void menu_cargo(void){
  int option = 99;
  do {
    printf("\n======================================\n");
    printf("============ <Menu Cargos> ===========\n");
    printf("======================================\n");
    printf("1 - Cadastra cargo\n");
    printf("2 - Excluir Cargo\n");
    printf("3 - Listar Cargos\n");
    printf("0 - Voltar para <Menu Inventario>\n");
    printf("======================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 0:
        break;
      case 1:
        Cargo *cargo_cad = (Cargo *) malloc(sizeof(Cargo));
        cadastrar_cargo(cargo_cad);
        gravar_cargo(cargo_cad);
        break;
      case 2:
        char nome[45];
        printf("Digite o nome do cargo a ser excluido\n");
        fgets(nome, 45, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        Cargo *cargo_excluir = buscar_cargo(nome);
        excluir_cargo(*cargo_excluir->nome);
        break;
      case 3:
        listar_cargos();
        break;

      default:
        printf("Deve digitar um número valido");
        break;
    }
  } while (option != 0);
}

int listar_cargos(void){
  int i = 0;
  FILE *fp;
    Cargo *cargo = (Cargo*) malloc(sizeof(Cargo));
    
    fp = fopen(ARQUIVO_CARGOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("-------------------------- Lista de Alunos --------------------------------\n");
    while (fread(cargo, sizeof(Cargo), 1, fp)) {
      i++;
      if (cargo->stats == true){
       printf("%d-Nome: %s\n",
          i, cargo->nome);
      }
    }
    printf("---------------------------------------------------------------------------\n");
    
};

void cadastro_tipo_produto(Cargo *cargo) {
    printf("\n=====================================\n");
    printf("==== <Cadastrar Tipo de Produto> ====\n");
    printf("=====================================\n");

    printf("Digite o nome do tipo do produto: ");
    fgets(cargo->nome, 45, stdin);
    cargo->nome[strcspn(cargo->nome, "\n")] = '\0';

    cargo->stats = 1;
};

int gravar_tipo_produto(Cargo *cargo){

  FILE *fp;
  fp = fopen(ARQUIVO_CARGOS, "at");
  if (fp == NULL) {
    printf("Erro na criacao do arquivo!\n");
    return 0;
  }
  fprintf(fp,
          "Nome: %s, status: %d\n",
          cargo->nome, cargo->stats);
  fclose(fp);
};

int excluir_cargo(char nome){
    FILE *fleitura;
    FILE *fescrita;
    Cargo *auxiliarLeitura = (Cargo *) malloc(sizeof(Cargo));
 
    fleitura = fopen(ARQUIVO_CARGOS, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_CARGOS_TEMPORARIOS, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    while (fread(auxiliarLeitura, sizeof(Cargo), 1, fleitura))
    {
        if(*auxiliarLeitura->nome != nome){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Cargo), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_CARGOS_TEMPORARIOS,ARQUIVO_CARGOS);
    return 1;
};

Cargo* buscar_cargo(char *nome){
    FILE *fp;
    Cargo *cargo = (Cargo *)malloc(sizeof(Cargo));
    fp = fopen(ARQUIVO_CARGOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return NULL;
    }
    while (fread(cargo, sizeof(Cargo), 1, fp))
    {
        if(strcmp(cargo->nome, nome) == 0){
            fclose(fp);
            return cargo;
        }
    }
    fclose(fp);
    return NULL;
};