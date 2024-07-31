#include "funcionario.h"
#include "cargo.h"
#include "util.h"
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
    printf("4 - Editar Cargo\n");
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
        cadastro_cargo(cargo_cad);
        gravar_cargo(cargo_cad);
        break;
      case 2:
        char nome[50];
        printf("Digite o nome do cargo a ser excluido\n");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        Cargo *cargo_excluir = buscar_cargo(nome);
        excluir_cargo(*cargo_excluir->nome);
        break;
      case 3:
        listar_cargos();
        delay(2000);
        limpaTela();
        break;
      case 4:
        char antigo_nome[45] = "0";
        printf("Informe o nome do cargo que vai editar: ");
        fgets(antigo_nome, 13, stdin);
        getchar();
        Cargo *cargo_edit = buscar_cargo(antigo_nome);
        if ((cargo_edit != NULL) && (cargo_edit->stats == 1)){
            delay(2000);
            editar_nome_cargo(cargo_edit);
            if(atualizar_cargo(cargo_edit)) printf("Cargo Atualizado!!\n");
                    break;
        }

      default:
        printf("Deve digitar um número valido");
        break;
    }
  } while (option != 0);
}

int listar_cargos(void){
    FILE *fp;
    Cargo *cargo = (Cargo*) malloc(sizeof(Cargo));
    
    fp = fopen(ARQUIVO_CARGOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("-------------------------- Lista de Cargos --------------------------------\n");
    while (fread(cargo, sizeof(Cargo), 1, fp))
    {
      if (cargo->stats == true){
       printf("Nome: %s\n",
          cargo->nome);
      }
    }
    printf("---------------------------------------------------------------------------\n");
};

void cadastro_cargo(Cargo *cargo_cad) {
    printf("\n=====================================\n");
    printf("==== <Cadastrar Cargo> ====\n");
    printf("=====================================\n");

    printf("Digite o nome do cargo: ");
    fgets(cargo_cad->nome, 45, stdin);
    cargo_cad->nome[strcspn(cargo_cad->nome, "\n")] = '\0';

    cargo_cad->stats = 1;
};

int gravar_cargo(Cargo *cargo_cad){
    FILE* fp;
	fp = fopen("cargo.dat", "ab");
	if (fp == NULL) {
		printf("Erro na criação do arquivo");
	}
	fwrite(cargo_cad, sizeof(Cargo), 1, fp);
	fclose(fp);
}

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

int editar_nome_cargo(Cargo *cargo_edit){
    fgets(cargo_edit->nome, 50, stdin);
    cargo_edit->nome[strcspn(cargo_edit->nome, "\n")] = '\0';
};

int atualizar_cargo(Cargo *cargo_edit){
  int achou;
	FILE* fp;
	Cargo* cargo_lido;

	cargo_lido = (Cargo*) malloc(sizeof(Cargo));
	fp = fopen("cargo.dat", "r+b");
	if (fp == NULL) {
		printf("Falha na produção de arquivo\n");
	}
	achou = false;
	while(fread(cargo_lido, sizeof(Cargo), 1, fp) && !achou) {
		if (strcmp(cargo_lido->nome, cargo_edit->nome) == 0) {
			achou = true;
			fseek(fp, -1*sizeof(Cargo), SEEK_CUR);
        	fwrite(cargo_edit, sizeof(Cargo), 1, fp);
		}
	}
	fclose(fp);
	free(cargo_lido);
};