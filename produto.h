#ifndef PRODUTO_H
#define PRODUTO_H
#include <stdbool.h>

struct produto {
    char nome_produto[50];
    char codigo_produto[13];
    int quantidade;
    char tipo_produto[20];
    char local_produto[5];
    char fornecedor[50];
    int quantidade_reposicao;
    char anotacao_armazenamento[100];
    int stats;
};
typedef struct produto Produto;

struct tipo {
    char nome[45];
    int stats;
};
typedef struct tipo Tipo;

void menu_produto(void);
void cadastro_produto(Produto *);
void cadastro_tipo_produto(Tipo *);
int gravar_produto(Produto *);
int gravar_tipo_produto(Tipo *);
void excluir_produto(void);
void alterar_produto(void);
int listar_produto(void);
bool validar_upc(const char *upc);

#endif