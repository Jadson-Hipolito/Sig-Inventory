#include "funcionario.h"
#include "biblioteca_verificar.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char nome_funcionario[50];
char cpf_funcionario[12];
char numero_funcionario[10];
char cargo_funcionario[50];
char endereco_funcionario[100];
int salario_funcionario = 0;
char expediente_funcionario[50];
int stats;

#define ARQUIVO_FUNCIONARIOS "funcionarios.txt"

void menu_funcionario(void) {
  int option = 5;
  do {
    printf("\n=====================================\n");
    printf("========= <Menu Funcionario> ========\n");
    printf("=====================================\n");
    printf("1 - Cadastra Funcionario Novo\n");
    printf("2 - Editar Cadastro\n");
    printf("3 - Listar Funcionarios\n");
    printf("4 - Excluir Funcionario\n");
    printf("0 - Voltar para <Menu Inventario>\n");
    printf("=====================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
    case 1:
        Funcionario* funcionario = (Funcionario *) malloc(sizeof(Funcionario));
        cadastro_funcionario(funcionario);
        gravar_funcionario(funcionario);
      break;
    case 2:
      editar_funcionario();
      break;
    case 3:
      listar_funcionario();
      break;
    case 4:
      excluir_funcionario();
      break;
    default:
      printf("Deve digitar um número");
      break;
    }
  } while (option != 0);
}

void cadastro_funcionario(Funcionario *funcionario) {
  printf("Digite o nome do funcionario: ");
  fgets(funcionario->nome, 50, stdin);
  funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';

  bool cpf_valido = false;
  while (!cpf_valido) {
    printf("Digite o CPF do funcionario: ");
    fgets(funcionario->cpf, 12, stdin);
    funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0';

    cpf_valido = validar_cpf(funcionario->cpf);
    if (!cpf_valido) {
      printf("CPF invalido! Digite novamente.\n");
    }
  }

  bool telefone_valido = false;
  while (!telefone_valido) {
    printf("Digite o numero de telefone do funcionario: ");
    fgets(funcionario->numero, 10, stdin);
    funcionario->numero[strcspn(funcionario->numero, "\n")] = '\0';

    telefone_valido = verificar_telefone(funcionario->numero);
    if (!telefone_valido) {
      printf("Numero de telefone invalido! Digite novamente.\n");
    }
  }

  printf("Digite o cargo do funcionario: ");
  fgets(funcionario->cargo, 50, stdin);
  funcionario->cargo[strcspn(funcionario->cargo, "\n")] = '\0';

  bool endereco_valido = false;
  while (!endereco_valido) {
    printf("Digite o endereco do funcionario: ");
    fgets(funcionario->endereco, 100, stdin);
    funcionario->endereco[strcspn(funcionario->endereco, "\n")] = '\0';

    endereco_valido = verificar_endereco(funcionario->endereco);
    if (!endereco_valido) {
      printf("Endereco invalido! Digite novamente.\n");
    }
  }

  printf("Digite o salario do funcionario: ");
  scanf("%d", &funcionario->salario);

  getchar();

  printf("Digite o expediente do funcionario: ");
  fgets(funcionario->expediente, 50, stdin);
  funcionario->expediente[strcspn(funcionario->expediente, "\n")] = '\0';

  printf("Digite o status do funcionario (1 para ativo, 0 para inativo): ");
  scanf("%d", &funcionario->stats);

  getchar();
}

int gravar_funcionario(Funcionario *funcionario) {

  FILE *fp;
  fp = fopen(ARQUIVO_FUNCIONARIOS, "at");
  if (fp == NULL) {
    printf("Erro na criacao do arquivo!\n");
    return 0;
  }
  fprintf(fp,
          "Nome: %s, CPF: %s, Numero: %s, Cargo: %s, Endereco: %s, Salario: "
          "%d, Expediente: %s, Status: %d\n",
          funcionario->nome, funcionario->cpf, funcionario->numero,
          funcionario->cargo, funcionario->endereco, funcionario->salario,
          funcionario->expediente, funcionario->stats);
  fclose(fp);
}

void editar_funcionario(void) {
  printf("\n=====================================\n");
  printf("==<Editar informação do Funcionario>=\n");
  printf("=====================================\n\n");

  printf("\n=====================================\n");
  printf("== Cpf do funcionario que ira editar:\n");
  printf("=====================================\n\n");

  printf("1 - Nome do Funcionario:\n");
  printf("2 - Numero:\n");
  printf("3 - Cargo:\n");
  printf("4 - Salário:\n");
  printf("5 - Espediente:\n");
  printf("6 - Endereço:\n");
  printf("0 - Voltar:\n");
  printf("=====================================\n");
}

void excluir_funcionario(void) {
  printf("\n=====================================\n");
  printf("======= <Excluir Funcionario> =======\n");
  printf("=====================================\n\n");

  printf("\n=====================================\n");
  printf("== Cpf do funcionario que ira excluir\n");
  printf("=====================================\n\n");

  printf("Confirmar Exclusão:\n");
}