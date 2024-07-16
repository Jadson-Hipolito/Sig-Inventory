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
int excluir_produto(char);
int menu_buscar_produto(void);
int listar_produto(void);
bool validar_upc(const char *upc);
int atualiza_produto(Produto *);
void atualizar_nome_produto(Produto *);
void atualizar_quantidade(Produto *);
void atualizar_tipo_produto(Produto *);
void atualizar_local_produto(Produto *);
void atualizar_fornecedor(Produto *);
void atualizar_quantidade_reposicao(Produto *);
void atualizar_anotacoes(Produto *);
Produto* buscar_produto(char *);
void exibir_produto(Produto *);

#endif