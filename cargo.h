#ifndef CARGO_H
#define CARGO_H
#include <stdbool.h>

struct cargo {
    char nome[50];
    int stats;
};
typedef struct cargo Cargo;

void menu_cargo(void);
void cadastro_cargo(Cargo *);
int listar_cargos(void);
int gravar_cargo(Cargo *);
int excluir_cargo(Cargo *);
Cargo* buscar_cargo(char *);
int atualizar_cargo(Cargo *);
int editar_nome_cargo(Cargo *);
Cargo* selecionar_cargo_por_digito(int posicao);

#endif