#ifndef ENTRADA_SAIDA_H
#define ENTRADA_SAIDA_H

struct entrada_saida {
    char produto_editado[13];
    char cpf_do_funcionario[12];
    int quantidade;
    char anotacao_da_entrada_saida[100];
    int tipo;
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    int stats;
};
typedef struct entrada_saida Entrada_Saida;

void menu_entrada_saida(void);
void entrada_e_saida(Entrada_Saida *, int sinal);
void editar_entrada_saida_produto(void);
void remove_entrada_saida_produto(void);
int gravar_entrada_ou_saida(Entrada_Saida *);

#endif