#ifndef PRODUTO_H
#define PRODUTO_H

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

void menu_produto(void);
void cadastro_produto(Produto *);
int gravar_produto(Produto *);
void excluir_produto(void);
void alterar_produto(void);
void listar_produto(void);
int validar_upc(char *codigo);

#endif