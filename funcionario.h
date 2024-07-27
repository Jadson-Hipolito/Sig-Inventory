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
    char password[21];
    int stats;
};

char senha_mestre[21];


typedef struct funcionario Funcionario;

struct cargo {
    char nome[45];
    int stats;
};
typedef struct cargo Cargo;

void menu_funcionario(void);
void cadastro_funcionario(Funcionario *);
int gravar_funcionario(Funcionario *);
int excluir_funcionario(char);
int listar_funcionario(void);
Funcionario* buscar_funcionario(char[12]);
void exibir_funcionario(Funcionario *);
int menu_buscar_funcionario(void);
void atualizar_nome_funcionario(Funcionario *);
void atualizar_numero(Funcionario *);
void atualizar_cargo(Funcionario *);
void atualizar_endereco(Funcionario *);
void atualizar_salario(Funcionario *);
void atualizar_expediente(Funcionario *);
int atualizar_funcionario(Funcionario *);
void reativar_funcionario(void);
bool comparar_senha(Funcionario *);
bool verificar_senha_de_emergencia(char *);
#endif