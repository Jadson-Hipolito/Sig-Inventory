#include "funcionario.h"
#include "fornecedor.h"
#include "util.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO_FORNECEDORES "fornecedores.dat"
#define ARQUIVO_FORNECEDORES_TEMPORARIOS "fornecedor.tmp"

void menu_fornecedor(void){
  int option = 99;
  do {
    printf("\n======================================\n");
    printf("======== <Menu fornecedores> =========\n");
    printf("======================================\n");
    printf("1 - Cadastrar fornecedor\n");
    printf("2 - Excluir fornecedor\n");
    printf("3 - Listar fornecedores\n");
    printf("4 - Editar fornecedor\n");
    printf("0 - Voltar para <Menu Inventario>\n");
    printf("======================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 0:
        break;
      case 1:
        Fornecedor *fornecedor_cad = (Fornecedor *) malloc(sizeof(Fornecedor));
        cadastro_fornecedor(fornecedor_cad);
        break;
      case 2:
        char nome[45];
        printf("Digite o nome do fornecedor a ser excluido\n");
        fgets(nome, 45, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        Fornecedor *fornecedor_excl = buscar_fornecedor(nome);
        excluir_fornecedor(fornecedor_excl);
        break;
      case 3:
        listar_fornecedores();
        delay(2000);
        limpaTela();
        break;
      case 4:
        char antigo_nome[45] = "0";
        printf("Informe o nome do fornecedor que vai editar: ");
        fgets(antigo_nome, 13, stdin);
        getchar();
        Fornecedor *fornecedor_edit = buscar_fornecedor(antigo_nome);
        if ((fornecedor_edit != NULL) && (fornecedor_edit->stats == 1)){
            delay(2000);
            editar_nome_fornecedor(fornecedor_edit);
            if(atualizar_fornecedor(fornecedor_edit)) printf("Fornecedor Atualizado!!\n");
                    break;
        }

      default:
        printf("Deve digitar um número valido");
        break;
    }
  } while (option != 0);
}

int listar_fornecedores(void){
    FILE *fp;
    Fornecedor *fornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
    
    fp = fopen(ARQUIVO_FORNECEDORES, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    int num = 0;
    printf("---------------------- Lista de Fornecedores ----------------------------\n");
    while (fread(fornecedor, sizeof(Fornecedor), 1, fp))
    {
      if (fornecedor->stats == true){
       num++;
       printf("%d-%s\n",
          num, fornecedor->nome);
      }
    }
    printf("---------------------------------------------------------------------------\n");
};

void cadastro_fornecedor(Fornecedor *fornecedor_cad) {
    printf("\n=====================================\n");
    printf("====== <Cadastrar Fornecedor> =======\n");
    printf("=====================================\n");

    printf("Digite o nome do fornecedor: ");
    fgets(fornecedor_cad->nome, 50, stdin);
    fornecedor_cad->nome[strcspn(fornecedor_cad->nome, "\n")] = '\0';

    fornecedor_cad->stats = 1;
    gravar_fornecedor(fornecedor_cad);
};

int gravar_fornecedor(Fornecedor *fornecedor_cad){
    FILE* fp;
	fp = fopen("fornecedores.dat", "ab");
	if (fp == NULL) {
		printf("Erro na criação do arquivo");
	}
	fwrite(fornecedor_cad, sizeof(Fornecedor), 1, fp);
	fclose(fp);
    free(fornecedor_cad);
}

int excluir_fornecedor(Fornecedor *fornecedor){
    FILE *fleitura;
    FILE *fescrita;
    Fornecedor *auxiliarLeitura = (Fornecedor *) malloc(sizeof(Fornecedor));
 
    fleitura = fopen(ARQUIVO_FORNECEDORES, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_FORNECEDORES_TEMPORARIOS, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    //Lendo o arquivo atual
    while (fread(auxiliarLeitura, sizeof(Fornecedor), 1, fleitura))
    {
        //Caso a matricula seja diferente
        if(strcmp(auxiliarLeitura->nome, fornecedor->nome) != 0){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Fornecedor), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_FORNECEDORES_TEMPORARIOS,ARQUIVO_FORNECEDORES);
    free(auxiliarLeitura);
    return 1;
};

Fornecedor* buscar_fornecedor(char *nome){
    FILE *fp;
    Fornecedor *fornecedor = (Fornecedor *)malloc(sizeof(Fornecedor));
    fp = fopen(ARQUIVO_FORNECEDORES, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return NULL;
    }
    while (fread(fornecedor, sizeof(Fornecedor), 1, fp))
    {
        if(strcmp(fornecedor->nome, nome) == 0){
            fclose(fp);
            return fornecedor;
        }
    }
    fclose(fp);
    return NULL;
};

int editar_nome_fornecedor(Fornecedor *fornecedor_edit){
    fgets(fornecedor_edit->nome, 45, stdin);
    fornecedor_edit->nome[strcspn(fornecedor_edit->nome, "\n")] = '\0';
    free(fornecedor_edit);
};

int atualizar_fornecedor(Fornecedor *fornecedor_edit){
  int achou;
	FILE* fp;
	Fornecedor* fornecedor_lido;

	fornecedor_lido = (Fornecedor*) malloc(sizeof(Fornecedor));
	fp = fopen("fornecedores.dat", "r+b");
	if (fp == NULL) {
		printf("Falha na produção de arquivo\n");
	}
	achou = false;
	while(fread(fornecedor_lido, sizeof(Fornecedor), 1, fp) && !achou) {
		if (strcmp(fornecedor_lido->nome, fornecedor_edit->nome) == 0) {
			achou = true;
			fseek(fp, -1*sizeof(Fornecedor), SEEK_CUR);
        	fwrite(fornecedor_edit, sizeof(Fornecedor), 1, fp);
		}
	}
	fclose(fp);
	free(fornecedor_lido);
};

Fornecedor* selecionar_fornecedor_por_digito(int posicao) {
    FILE *fp;
    Fornecedor *forn = (Fornecedor *)malloc(sizeof(Fornecedor));

    if (forn == NULL) {
        perror("Erro ao alocar memória");
        return NULL;
    }

    fp = fopen("fornecedores.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        free(forn);
        return NULL;
    }

    // Mover o ponteiro do arquivo para a posição do tipo desejado
    if (fseek(fp, (posicao - 1) * sizeof(Fornecedor), SEEK_SET) != 0) {
        perror("Erro ao buscar a posição no arquivo");
        fclose(fp);
        free(forn);
        return NULL;
    }

    // Ler o tipo
    if (fread(forn, sizeof(Fornecedor), 1, fp) != 1) {
        if (feof(fp)) {
            fprintf(stderr, "Erro: A posição %d está além do final do arquivo.\n", posicao);
        } else {
            perror("Erro ao ler o registro do arquivo");
        }
        fclose(fp);
        free(forn);
        return NULL;
    }

    fclose(fp);
    getchar();
    return forn;
}