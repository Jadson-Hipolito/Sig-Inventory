#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// struct Funcionario *funcionario;

struct funcionario {
    char cpf[12];
    char nome[50];
    char numero[11];
    char cargo[50];
    char endereco[100];
    int salario;
    char expediente[50];
    int stats;
};

typedef struct funcionario Funcionario;

void menu_funcionario(void);
void cadastro_funcionario(Funcionario *);
int gravar_funcionario(Funcionario *);
void editar_funcionario(void);
void excluir_funcionario(void);
int lista_arquivo_funcionario();
Funcionario* buscar_funcionario(char[12]);

#endif