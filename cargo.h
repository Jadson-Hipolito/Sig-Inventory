#ifndef CARGO_H
#define CARGO_H
#include <stdbool.h>

struct cargo {
    char nome[45];
    int stats;
};
typedef struct cargo Cargo;

void menu_cargo(void);
void cadastrar_cargo(Cargo *);
int listar_cargos(void);
int gravar_cargo(Cargo *);
int excluir_cargo(char);

#endif