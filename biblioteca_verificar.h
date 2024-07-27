#ifndef BIBLIOTECA_VERIFICAR_H
#define BIBLIOTECA_VERIFICAR_H
#include <stdbool.h> 

int validar_nome(const char *nome);
bool validar_cpf(const char *cpf);
bool verificar_endereco(const char *endereco);
bool verificar_telefone(const char *telefone);
bool verificar_senha(const char *password);
#endif