#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

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
void cadastro_funcionario(Funcionario *);
int gravar_funcionario(Funcionario *);
void editar_funcionario(void);
int excluir_funcionario(char);
int listar_funcionario(void);
Funcionario* buscar_funcionario(char[12]);
void exibir_funcionario(Funcionario *);
int menu_buscar_funcionario(void);
void atualizar_nome_funcionario(Funcionario *funcionario_busc);
void atualizar_numero(Funcionario *funcionario_busc);
void atualizar_cargo(Funcionario *funcionario_busc);
void atualizar_endereco(Funcionario *funcionario_busc);
void atualizar_salario(Funcionario *funcionario_busc);
void atualizar_expediente(Funcionario *funcionario_busc);
int atualizar_funcionario(Funcionario *funcionario_busc);
void reativar_funcionario(void);

#endif