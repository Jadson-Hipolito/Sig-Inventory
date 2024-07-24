#include "produto.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO_PRODUTOS "produto.dat"
#define ARQUIVO_TIPOS "tipos.dat"
#define ARQUIVO_PRODUTOS_TEMPORARIOS "produtos.tmp"

void menu_produto(){
    int option = 99;
    do {
        printf("\n=====================================\n");
        printf("========== <Menu Produtos> ==========\n");
        printf("=====================================\n");
        printf("1 - Cadastra Produto Novo\n");
        printf("2 - Cadastra Novo Tipo de Produto\n");
        printf("3 - Buscar Produto\n");
        printf("4 - Listar Produtos\n");
        printf("5 - Reativar Cadastro de um Produto\n");
        printf("0 - Voltar para <Menu Inventario>\n");
        printf("=====================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        getchar();
        switch(option){
            case 0:
                break;
            case 1:
                Produto *produtoy = (Produto *) malloc(sizeof(Produto));
                cadastro_produto(produtoy);
                gravar_produto(produtoy);
                break;
            case 2:
                Tipo* tipo = (Tipo *) malloc(sizeof(Tipo));
                cadastro_tipo_produto(tipo);
                gravar_tipo_produto(tipo);
                break;
            case 3:
              char codigo_produto[13] = "0";
              printf("Informe a codigo UPC do produto: ");
              scanf("%s", codigo_produto);
              getchar();
              Produto *produtox = buscar_produto(codigo_produto);
              if ((produtox != NULL) && (*produtox->codigo_produto == 1)){
                exibir_produto(produtox);
                int editar = menu_buscar_produto();
                switch (editar)
                {
                case 1:
                  getchar();
                  atualizar_nome_produto(produtox);
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");
                  break;
                case 2:
                  atualizar_quantidade(produtox); 
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");;
                  break;
                case 3:
                  atualizar_tipo_produto(produtox); 
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");;
                  break;
                case 4:
                  atualizar_local_produto(produtox); 
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");;
                  break;
                case 5:
                  atualizar_fornecedor(produtox); 
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");;
                  break;
                case 6:
                  atualizar_quantidade_reposicao(produtox); 
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");;
                  break;
                case 7:
                  atualizar_anotacoes(produtox); 
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");;
                  break;
                case 8:
                  produtox->stats = 0;
                  if(atualiza_produto(produtox)) printf("Produto Atualizado!!\n");
                  break;
                case 9:
                  if(excluir_produto(*produtox->codigo_produto)) printf("Produto excluído!!\n");
                  break;
                default:
                  break;
              }
              break;
              }
              break;
            case 4:
              listar_produto();
              break;

            case 5:
              reativar_produto();
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
      fgets(produto->codigo_produto, 13, stdin);
      produto->codigo_produto[strcspn(produto->codigo_produto, "\n")] = '\0';
      printf("%s\n", produto->codigo_produto);

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
    getchar();

    printf("Digite o fornecedor do produto (opcional): ");
    fgets(produto->fornecedor, 50, stdin);
    produto->fornecedor[strcspn(produto->fornecedor, "\n")] = '\0';

    printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
    scanf("%d", &produto->quantidade_reposicao);
    getchar();

    printf("Digite uma nota de armazenamento para o produto (opcional): ");
    fgets(produto->anotacao_armazenamento, 50, stdin);
    produto->anotacao_armazenamento[strcspn(produto->anotacao_armazenamento, "\n")] = '\0';

    produto->stats = 1;

    printf("=====================================\n");
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

int menu_buscar_produto(void){
  int option = 99;
  printf("\n=======================================================\n");
  printf("================ <Menu buscar produto> ================\n");
  printf("=======================================================\n\n");
  printf("1 - Editar nome do produto:\n");
  printf("2 - Editar quantidade do produto:\n");
  printf("3 - Editar tipo do produto:\n");
  printf("4 - Editar local do produto:\n");
  printf("5 - Editar fornecedor do produto:\n");
  printf("6 - Editar quantidade para pedir reposição do produto:\n");
  printf("7 - Editar anotações de armazenamento do produto:\n");
  printf("8 - Desativar produto (Exclusão temporaria):\n");
  printf("9 - Exclusão completa do produto:\n");
  printf("0 - Retornar:\n");
  scanf("%d", &option);
  getchar;
  return option;
};

bool validar_upc(const char *upc) {
  if (strlen(upc) != 12) {
    printf("UPC inválido (tamanho incorreto).\n");
    printf("UPC: %s\n", upc);
    return false;
  }

  for (int i = 0; upc[i] != '\0'; i++) {
    if (upc[i] != '/' && !isdigit(upc[i])) {
      printf("UPC inválido (contem não digitos).\n");
      return false;
    }
  }

  //Verificar item verificador

  int som_impares;
  int som_pares;
  int dezena;
  int verificador;
  for (int i = 0; upc[i] == 10; i=i+2){
    som_impares += upc[i];
  }
  som_impares = som_impares*3;
  for (int i = 1; upc[i] == 9; i=i+2){
    som_pares += upc[i];
  }
  int som_som = som_impares + som_pares;
  if (som_som % 10 != 0) {
    dezena = (som_som/10 + 1)*10;
    verificador = dezena - som_som;
  }
  else {
    verificador = 0;
  }
  if (((int)upc[11] - 48) != verificador){
    for (int i = 0; upc[i] != '\0'; i++){
     printf("upc:%d\n",upc[i]-48);
    }
    printf("Numero verificador dado %d, numero verificado do codigo %d\n", upc[11] - 48, verificador);
    printf("UPC inválido (Numero verificador incorreto).\n");
    return false;
  }
  return true;
};

int gravar_produto(Produto *produtox){
    FILE *fp;
    fp = fopen(ARQUIVO_PRODUTOS, "ab");
    if (fp == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Insere o aluno no final do arquivo
    fwrite(produtox,sizeof(Produto),1,fp);
    fclose(fp);
    return 1;
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

int listar_produto(void){
    FILE *fp;
    Produto *produtox = (Produto*) malloc(sizeof(Produto));
    
    fp = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("-------------------------- Lista de Alunos --------------------------------\n");
    while (fread(produtox, sizeof(Produto), 1, fp))
    {
      if (produtox->stats == true){
       exibir_produto(produtox);
      }
    }
    printf("---------------------------------------------------------------------------\n");
    
};

void atualizar_nome_produto(Produto *produtox){
  printf("Informe o nome do produto: ");
  fgets(produtox->nome_produto, 50, stdin);
  produtox->nome_produto[strcspn(produtox->nome_produto, "\n")] = '\0';
};

void atualizar_quantidade(Produto *produto){
  printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
  scanf("%d", &produto->quantidade);
  getchar();
};

void atualizar_tipo_produto(Produto *produtox){
  printf("Digite o tipo do produto: ");
  fgets(produtox->tipo_produto, 20, stdin);
  produtox->tipo_produto[strcspn(produtox->tipo_produto, "\n")] = '\0';
};

void atualizar_local_produto(Produto *produtox){
  printf("Digite o local do produto: ");
  fgets(produtox->local_produto, 5, stdin);
  produtox->local_produto[strcspn(produtox->local_produto, "\n")] = '\0';
};

void atualizar_fornecedor(Produto *produtox){
  printf("Digite o fornecedor do produto (opcional): ");
  fgets(produtox->fornecedor, 50, stdin);
  produtox->fornecedor[strcspn(produtox->fornecedor, "\n")] = '\0';
};

void atualizar_quantidade_reposicao(Produto *produtox){
  printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
  scanf("%d", &produtox->quantidade_reposicao);
  getchar();
};

void atualizar_anotacoes(Produto *produtox){
  printf("Digite uma nota de armazenamento para o produto (opcional): ");
  fgets(produtox->anotacao_armazenamento, 50, stdin);
  produtox->anotacao_armazenamento[strcspn(produtox->anotacao_armazenamento, "\n")] = '\0';
};

int atualiza_produto(Produto *produtox){
  int achou;
	FILE* fp;
	Produto* produto_lido;

	produto_lido = (Produto*) malloc(sizeof(Produto));
	fp = fopen("produto.dat", "r+b");
	if (fp == NULL) {
		printf("Falha na produção de arquivo\n");
	}
	achou = false;
	while(fread(produto_lido, sizeof(Produto), 1, fp) && !achou) {
		if (strcmp(produto_lido->codigo_produto, produtox->codigo_produto) == 0) {
			achou = true;
			fseek(fp, -1*sizeof(Produto), SEEK_CUR);
        	fwrite(produtox, sizeof(Produto), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(produto_lido);
};

void reativar_produto(void){
  char codigo_produto[13] = "0";
  printf("Informe a codigo UPC do produto: ");
  scanf("%s", codigo_produto);
  getchar();
  Produto *produtox = buscar_produto(codigo_produto);

}

Produto* buscar_produto(char* codigo_produto){
    FILE *fp;
    Produto *produtox = (Produto *)malloc(sizeof(Produto));
    fp = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return NULL;
    }
    while (fread(produtox, sizeof(Produto), 1, fp))
    {
        if(strcmp(produtox->codigo_produto, codigo_produto) == 0){
            fclose(fp);
            return produtox;
        }
    }
    fclose(fp);
    return NULL;
};

void exibir_produto(Produto *produto){
    printf("Nome: %s, codigo: %s, quantidade: %d, tipo do produto: %s, local do produto: %s, fornecedor: %s, quantidade para requerir reposicao: %d, anotações de armazenamento: %s\n",
          produto->nome_produto, produto->codigo_produto, produto->quantidade,
          produto->tipo_produto, produto->local_produto, produto->fornecedor, produto->quantidade_reposicao,
          produto->anotacao_armazenamento);
}

int excluir_produto(char codigo_produto){
    FILE *fleitura;
    FILE *fescrita;
    Produto *auxiliarLeitura = (Produto *) malloc(sizeof(Produto));
 
    fleitura = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_PRODUTOS_TEMPORARIOS, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Lendo o arquivo atual
    while (fread(auxiliarLeitura, sizeof(Produto), 1, fleitura))
    {
        //Caso a matricula seja diferente
        if(*auxiliarLeitura->codigo_produto != codigo_produto){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Produto), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_PRODUTOS_TEMPORARIOS,ARQUIVO_PRODUTOS);
    return 1;
};