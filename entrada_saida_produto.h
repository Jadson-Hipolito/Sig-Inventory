#ifndef ENTRADA_SAIDA_PRODUTO_H
#define ENTRADA_SAIDA_PRODUTO_H

struct entrada_saida {
    char nome_do_funcionario[50];
    char produto_editado[13];
    int quantidade;
    char anotacao_da_entrada_saida[100];
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    int stats;
};
typedef struct entrada_saida Entrada_Saida;

void menu_entrada_saida_produto(void);
void confirma_entrada_saida_produto(void);
void entrada_saida_produto(void);
void editar_entrada_saida_produto(void);
void remove_entrada_saida_produto(void);

#endif