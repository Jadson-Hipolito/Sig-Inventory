#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdbool.h>

// struct Funcionario *funcionario;

struct funcionario {
    char cpf[12];
    char nome[50];
    char numero[11];
    char cargo[50];
    char endereco[100];
    float salario;
    char expediente[50];
    int stats;
};

typedef struct funcionario Funcionario;

void menu_funcionario(void);
int cadastro_funcionario(Funcionario *);
int gravar_funcionario(Funcionario *);
int excluir_funcionario(char);
int listar_funcionario(void);
Funcionario* buscar_funcionario(char[12]);
void exibir_funcionario(Funcionario *);
int menu_buscar_funcionario(void);
void atualizar_nome_funcionario(Funcionario *);
void atualizar_numero(Funcionario *);
void atualizar_cargo_funcionario(Funcionario *);
void atualizar_endereco(Funcionario *);
void atualizar_salario(Funcionario *);
void atualizar_expediente(Funcionario *);
int atualizar_funcionario(Funcionario *);
void reativar_funcionario(void);
#endif