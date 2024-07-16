#include "produto.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO_PRODUTOS "produto.txt"
#define ARQUIVO_TIPOS "tipos.txt"
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
                gravar_produto(produto);
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
              getchar;
              Produto *produtox = buscar_produto(codigo_produto);
              if (produto != NULL){
                exibir_produto(produtox);
                int editar = menu_buscar_produto();
                switch (editar)
                {
                case 1:
                    atualizar_nome_produto(produto);
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");
                    break;
                case 2:
                    atualizar_quantidade(produto); 
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");;
                    break;
                case 3:
                    atualizar_tipo_produto(produto); 
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");;
                    break;
                case 4:
                    atualizar_local_produto(produto); 
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");;
                    break;
                case 5:
                    atualizar_fornecedor(produto); 
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");;
                    break;
                case 6:
                    atualizar_quantidade_reposicao(produto); 
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");;
                    break;
                case 7:
                    atualizar_anotacoes(produto); 
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");;
                    break;
                case 8:
                    produto->stats = 0;
                    if(atualiza_produto(produto)) printf("Produto Atualizado!!\n");;
                    break;
                case 9:
                    if(excluir_produto(*produto->codigo_produto)) printf("Produto excluído!!\n");
                    break;
                default:
                    break;
              }
                break;
              }
            case 4:
                listar_produto();
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
}

void cadastro_tipo_produto(Tipo *tipo) {
    printf("\n=====================================\n");
    printf("==== <Cadastrar Tipo de Produto> ====\n");
    printf("=====================================\n");

    printf("Digite o nome do tipo do produto: ");
    fgets(tipo->nome, 45, stdin);
    tipo->nome[strcspn(tipo->nome, "\n")] = '\0';

    tipo->stats = 1;
}

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
  }

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
}

int gravar_produto(Produto *produto){

  FILE *fp;
  fp = fopen(ARQUIVO_PRODUTOS, "at");
  if (fp == NULL) {
    printf("Erro na criacao do arquivo!\n");
    return 0;
  }
  fprintf(fp,
          "Nome: %s, codigo: %s, quantidade: %d, tipo do produto: %s, local do produto: %s, fornecedor: %s, quantidade de reposicao: %d, anotação de armazenamento: %s, status: %d\n",
          produto->nome_produto, produto->codigo_produto, produto->quantidade,
          produto->tipo_produto, produto->local_produto, produto->fornecedor, produto->quantidade_reposicao,
          produto->anotacao_armazenamento, produto->stats);
  fclose(fp);
}

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
}

int listar_produto(void)
{
  FILE *fp;
  char letra;
  char linha[320];
  int cursorLinha = -1;


  fp = fopen(ARQUIVO_PRODUTOS, "rt");
  if (fp == NULL)
  {
      printf("Erro no acesso do arquivo\n!");
      return 0;
  }
  printf("-------------------------- Lista de Produtos --------------------------------\n");
  letra = fgetc(fp);
  while (letra != EOF)
  {
      if(letra != '\n'){
          linha[++cursorLinha] = letra;          
      }else{
          linha[++cursorLinha] = '\0';
          printf("%s\n",linha);
          for (int i = 0; i < cursorLinha; i++)
          {
              linha[i] = ' ';
          }          
          cursorLinha = -1;                   
      }
      letra = fgetc(fp);
  }
  printf("---------------------------------------------------------------------------\n");
  fclose(fp);
  getchar();
};

void atualizar_nome_produto(Produto *produto){
  printf("Informe o nome do aluno: ");
  fgets(produto->nome_produto, 50, stdin);
  produto->nome_produto[strcspn(produto->nome_produto, "\n")] = '\0';
}

void atualizar_quantidade(Produto *produto){
  printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
  scanf("%d", &produto->quantidade_reposicao);
  getchar();
}

void atualizar_tipo_produto(Produto *produto){
  printf("Digite o tipo do produto: ");
  fgets(produto->tipo_produto, 20, stdin);
  produto->tipo_produto[strcspn(produto->tipo_produto, "\n")] = '\0';
}

void atualizar_local_produto(Produto *produto){
  printf("Digite o local do produto: ");
  fgets(produto->local_produto, 5, stdin);
  produto->local_produto[strcspn(produto->local_produto, "\n")] = '\0';
}

void atualizar_fornecedor(Produto *produto){
  printf("Digite o fornecedor do produto (opcional): ");
  fgets(produto->fornecedor, 50, stdin);
  produto->fornecedor[strcspn(produto->fornecedor, "\n")] = '\0';
}

void atualizar_quantidade_reposicao(Produto *produto){
  printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
  scanf("%d", &produto->quantidade_reposicao);
  getchar();
}

void atualizar_anotacoes(Produto *produto){
  printf("Digite uma nota de armazenamento para o produto (opcional): ");
  fgets(produto->anotacao_armazenamento, 50, stdin);
  produto->anotacao_armazenamento[strcspn(produto->anotacao_armazenamento, "\n")] = '\0';
}

int atualiza_produto(Produto *produto){
    FILE *fp;
    Produto *auxiliar = (Produto *) malloc(sizeof(Produto));
    fp = fopen(ARQUIVO_PRODUTOS, "r+b");
    if (fp == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Busca o aluno no arquivo para posicionar o cursor do arquivo
    while (fread(auxiliar, sizeof(Produto), 1, fp))
    {
        if(auxiliar->codigo_produto == produto->codigo_produto){
            //Reposiciona o cursor para a posição inicial do Aluno
            fseek(fp, -1*sizeof(Produto), SEEK_CUR);
            //Reescreve o aluno
            fwrite(produto, sizeof(Produto), 1, fp);        
            fclose(fp);           
            return 1;
        }
    }  
    fclose(fp);
    printf("Erro na atualização do aluno.\n!");
    return 0;
};

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
        if(*produtox->codigo_produto == *codigo_produto){
            fclose(fp);
            return produtox;
        }
    }
    fclose(fp);
    return NULL;
}

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