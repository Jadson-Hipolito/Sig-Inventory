#ifndef TIPO_PRODUTO_H
#define TIPO_PRODUTO_H
#include <stdbool.h>

struct tipo {
    char nome[45];
    int stats;
};
typedef struct tipo Tipo;

void menu_tipo_produto(void);
void cadastro_tipo_produto(Tipo *);
int listar_tipo_produto(void);
int gravar_tipo_produto(Tipo *);
int excluir_tipo_produto(char);

#endif