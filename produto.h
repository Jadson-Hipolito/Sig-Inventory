#ifndef PRODUTO_H
#define PRODUTO_H
#include <stdbool.h>

struct produto {
    char nome_produto[50];
    char codigo_produto[13];
    int quantidade;
    char tipo_produto[45];
    char local_produto[5];
    char fornecedor[50];
    int quantidade_reposicao;
    char anotacao_armazenamento[100];
    int stats;
};
typedef struct produto Produto;

void menu_produto(void);
int cadastro_produto(Produto *);
int gravar_produto(Produto *);
int excluir_produto(char codigo_produto);
int menu_buscar_produto(void);
int listar_produto();
int listar_produto_tipo(char *);
int listar_produto_fornecedor(char *);
bool validar_upc(const char *upc);
int atualiza_produto(Produto *);
void atualizar_nome_produto(Produto *);
void atualizar_quantidade(Produto *);
void atualizar_tipo_produto(Produto *);
void atualizar_local_produto(Produto *);
void atualizar_fornecedor_produto(Produto *);
void atualizar_quantidade_reposicao(Produto *);
void atualizar_anotacoes(Produto *);
Produto* buscar_produto(char *);
void exibir_produto(Produto *);
int reativar_produto(void);
int menu_filtro_produto(void);

#endif