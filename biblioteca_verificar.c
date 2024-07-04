#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca_verificar.h"

bool validar_cpf(const char *cpf) {
    if (cpf == NULL) {
        return false; // CPF inválido se for NULL
    }

    // Verifica se a string tem 11 caracteres
    int i = 0;
    while (cpf[i] != '\0') {
        if (!isdigit(cpf[i])) {
            return false; // CPF inválido se contiver caracteres não numéricos
        }
        i++;
    }
    if (i != 11) {
        return false; // CPF inválido se não tiver 11 dígitos
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int primeiroDigito = 11 - (soma % 11);

    if (primeiroDigito >= 10) {
        primeiroDigito = 0;
    }

    // Verifica o primeiro dígito verificador
    if (cpf[9] - '0' != primeiroDigito) {
        return false; // CPF inválido se o primeiro dígito verificador estiver errado
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int segundoDigito = 11 - (soma % 11);

    if (segundoDigito >= 10) {
        segundoDigito = 0;
    }

    // Verifica o segundo dígito verificador
    if (cpf[10] - '0' != segundoDigito) {
        return false; // CPF inválido se o segundo dígito verificador estiver errado
    }

    return true; // CPF válido
}

bool verificar_endereco(const char *endereco) {
    if (endereco == NULL) {
        return false;
    }

    if (strlen(endereco) == 0) {
        return false;
    }

    return true; 
}

bool verificar_telefone(const char *telefone) {
    printf("%s\n", telefone);
    int tamanho = strlen(telefone);
    
    // Verifica o comprimento da string
    if(tamanho != 10) {
        return false; // Tamanho inválido
    }
    
    // Verifica se todos os caracteres são dígitos
    for(int i = 0; i < tamanho; i++) {
        if(!isdigit(telefone[i])) {
            return false; // Encontrou um caractere não dígito
        }
    }
    
    return true; // Telefone válido
}