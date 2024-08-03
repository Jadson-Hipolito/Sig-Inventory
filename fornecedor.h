#ifndef FORNECEDOR_H
#define FORNECEDOR_H
#include <stdbool.h>

struct fornecedor {
    char nome[50];
    int stats;
};
typedef struct fornecedor Fornecedor;

void menu_fornecedor(void);
void cadastro_fornecedor(Fornecedor *);
int listar_fornecedores(void);
int gravar_fornecedor(Fornecedor *);
int excluir_fornecedor(Fornecedor *);
Fornecedor* buscar_fornecedor(char *);
int atualizar_fornecedor(Fornecedor *);
int editar_nome_fornecedor(Fornecedor *);

#endif