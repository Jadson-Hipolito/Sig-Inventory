#include "produto.h"
#include "util.h"
#include "fornecedor.h"
#include "tipo_produto.h"
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
        printf("2 - Buscar Produto\n");
        printf("3 - Listar Produtos\n");
        printf("4 - Reativar Cadastro de um Produto\n");
        printf("0 - Voltar para <Menu Inventario>\n");
        printf("=====================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        getchar();
        switch(option){
            case 0:
                break;
            case 1:
                Produto *produto = (Produto *) malloc(sizeof(Produto));
                cadastro_produto(produto);
                free(produto);
                break;
            case 2:
              char codigo_produto[13] = "0";
              printf("Informe a codigo UPC do produto: ");
              fgets(codigo_produto, 13, stdin);
              getchar();
              Produto *produtox = buscar_produto(codigo_produto);
              if ((produtox != NULL) && (produtox->stats == 1)){
                exibir_produto(produtox);
                delay(1000);
                int editar = menu_buscar_produto();
                switch (editar){
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
                    atualizar_fornecedor_produto(produtox); 
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
                    if(excluir_produto(produtox)) printf("Produto excluído!!\n");
                    break;
                  default:
                    break;
                }
                free(produtox);
                break;
              }
              break;
            case 3:
              int escolha = menu_filtro_produto();
              switch (escolha)
              {
              case 0:
                listar_produto();
                getchar();
                break;

              case 1:
                char tipo_produto[45];
                printf("Digite um dos tipos de produto abaixo.\n");
                listar_tipo_produto();
                printf("Tipo: ");
                fgets(tipo_produto, 45, stdin);
                tipo_produto[strcspn(tipo_produto, "\n")] = '\0';
                limpaTela();
                listar_produto_tipo(tipo_produto);
                break;

              case 2:
                char fornecedor[50];
                printf("Digite um dos fornecedores abaixo.\n");
                listar_fornecedores();
                printf("Fornecedor: ");
                fgets(fornecedor, 45, stdin);
                fornecedor[strcspn(fornecedor, "\n")] = '\0';
                limpaTela();
                listar_produto_fornecedor(fornecedor);
                break;
              
              default:
                break;
              }
              limpaTela();
              break;

            case 4:
              reativar_produto();
              break;
              
            default:
              printf("Deve digitar um número valido\n");
              limpaTela();
              break;
        }
    } while (option != 0);
}

int cadastro_produto(Produto *produto) {
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

      if (buscar_produto(produto->codigo_produto) != NULL){
        printf("Já existe um produto com esse codigo UPC registrado\n");
        upc_valido = false;
      }

    }

    printf("Digite a quantidade do produto: ");
    scanf("%d", &produto->quantidade);
    getchar();
    
    int digito;
    printf("Digite o digito de um dos tipos abaixo\n");
    listar_tipo_produto();
    printf("Tipo: ");
    scanf("%d", &digito);
    getchar();
    Tipo *tip = selecionar_tipo_por_digito(digito);
    strcpy(produto->tipo_produto, tip->nome);

    printf("Digite o local do produto: ");
    fgets(produto->local_produto, 5, stdin);
    produto->local_produto[strcspn(produto->local_produto, "\n")] = '\0';
    getchar();


    printf("Digite o digito de um dos fornecedores abaixo\n");
    listar_fornecedores();
    printf("Fornecedor: ");
    scanf("%d", &digito);
    getchar();
    Fornecedor *forn = selecionar_fornecedor_por_digito(digito);
    strcpy(produto->fornecedor, forn->fornecedor);

    printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
    scanf("%d", &produto->quantidade_reposicao);
    getchar();

    printf("Digite uma nota de armazenamento para o produto (opcional): ");
    fgets(produto->anotacao_armazenamento, 100, stdin);
    produto->anotacao_armazenamento[strcspn(produto->anotacao_armazenamento, "\n")] = '\0';

    produto->stats = 1;

    printf("=====================================\n");

    gravar_produto(produto);
    return 0;
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

int menu_filtro_produto(void){
  int option = 99;
  printf("\n=======================================================\n");
  printf("============ <Escolha como deseja filtrar> ============\n");
  printf("=======================================================\n\n");
  printf("0 - Sem filtro:\n");
  printf("1 - Filtrar por tipo:\n");
  printf("2 - Filtrar por fornecedor:\n");
  scanf("%d", &option);
  getchar;
  limpaTela();
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

int gravar_produto(Produto *produto){
    FILE* fp;

	fp = fopen("produto.dat", "ab");
	if (fp == NULL) {
		printf("Erro na criação do arquivo");
	}
	fwrite(produto, sizeof(Produto), 1, fp);
	fclose(fp);
}

int listar_produto(){
  FILE *fp;
  Produto *produto = (Produto*) malloc(sizeof(Produto));
    
  fp = fopen(ARQUIVO_PRODUTOS, "rb");
  if (fp == NULL){
    printf("Erro no acesso do arquivo\n!");
    return 0;
  }
  printf("-------------------------- Lista de Funcionarios --------------------------------\n");
  while (fread(produto, sizeof(Produto), 1, fp)){
    if (produto->stats == true){
      exibir_produto(produto);
    }
  }
  printf("---------------------------------------------------------------------------\n");
  getchar();
};

int listar_produto_tipo(char *tipo_produto){
  FILE *fp;
  Produto *produto = (Produto*) malloc(sizeof(Produto));
    
  fp = fopen(ARQUIVO_PRODUTOS, "rb");
  if (fp == NULL){
    printf("Erro no acesso do arquivo\n!");
    return 0;
  }
  printf("-------------------------- Lista de Funcionarios --------------------------------\n");
  while (fread(produto, sizeof(Produto), 1, fp)){
    if ((produto->stats == true) && (strcmp(produto->tipo_produto, tipo_produto) == 0)){
      exibir_produto(produto);
    }
  }
  printf("---------------------------------------------------------------------------\n");
  getchar();
  free(produto);
};

int listar_produto_fornecedor(char *fornecedor){
  FILE *fp;
  Produto *produto = (Produto*) malloc(sizeof(Produto));
    
  fp = fopen(ARQUIVO_PRODUTOS, "rb");
  if (fp == NULL){
    printf("Erro no acesso do arquivo\n!");
    return 0;
  }
  printf("-------------------------- Lista de Funcionarios --------------------------------\n");
  while (fread(produto, sizeof(Produto), 1, fp)){
    if ((produto->stats == true) && (strcmp(produto->fornecedor, fornecedor) == 0)){
      exibir_produto(produto);
    }
  }
  printf("---------------------------------------------------------------------------\n");
  getchar();
  free(produto);
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

void atualizar_local_produto(Produto *produtox){
  printf("Digite o local do produto: ");
  fgets(produtox->local_produto, 5, stdin);
  produtox->local_produto[strcspn(produtox->local_produto, "\n")] = '\0';
};

void atualizar_fornecedor_produto(Produto *produtox){
  printf("Digite o fornecedor do produto (opcional): ");
  fgets(produtox->fornecedor, 50, stdin);
  produtox->fornecedor[strcspn(produtox->fornecedor, "\n")] = '\0';
};

void atualizar_tipo_produto(Produto *produtox){
  printf("Digite o tipo do produto (opcional): ");
  fgets(produtox->tipo_produto, 45, stdin);
  produtox->tipo_produto[strcspn(produtox->tipo_produto	, "\n")] = '\0';
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

int reativar_produto(void){
  char codigo_produto[13] = "0";
  printf("Informe a codigo UPC do produto: ");
  scanf("%s", codigo_produto);
  getchar();
  FILE *fp;
    Produto *produtox = (Produto *)malloc(sizeof(Produto));
    fp = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    while (fread(produtox, sizeof(Produto), 1, fp))
    {
        if(strcmp(produtox->codigo_produto, codigo_produto) == 0){
            fclose(fp);
            produtox->stats = 1;
            atualiza_produto(produtox);
            return 0;
        }
    }
    fclose(fp);
    limpaTela();
    return 0;

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

int excluir_produto(Produto *produto){
    FILE *fleitura;
    FILE *fescrita;
    Produto *auxiliarLeitura = (Produto *) malloc(sizeof(Produto));
 
    fleitura = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_PRODUTOS_TEMPORARIOS, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criação do arquivo\n!");
        return 0;
    }
    //Lendo o arquivo atual
    while (fread(auxiliarLeitura, sizeof(Produto), 1, fleitura))
    {
        //Caso a matricula seja diferente
        if(strcmp(auxiliarLeitura->codigo_produto, produto->codigo_produto) != 0){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Tipo), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_PRODUTOS_TEMPORARIOS,ARQUIVO_PRODUTOS);
    free(auxiliarLeitura);
    return 1;
};