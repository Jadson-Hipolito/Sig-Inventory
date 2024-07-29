#include "funcionario.h"
#include "biblioteca_verificar.h"
#include "util.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO_FUNCIONARIOS "funcionarios.dat"
#define ARQUIVO_FUNCIONARIOS_TEMPORARIOS "funcionarios.tmp"

void menu_funcionario(void) {
  int option = 99;
  do {
    printf("\n=====================================\n");
    printf("========= <Menu Funcionario> ========\n");
    printf("=====================================\n");
    printf("1 - Cadastra Funcionario Novo\n");
    printf("2 - Buscar Funcionarios\n");
    printf("3 - Listar Funcionario");
    printf("4 - Excluir Funcionario\n");
    printf("0 - Voltar para <Menu Inventario>\n");
    printf("=====================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &option);
    getchar();
    if (isdigit(option))
    switch (option) {
    case 1:
      Funcionario *funcionario_cad = (Funcionario *) malloc(sizeof(Funcionario));
      cadastro_funcionario(funcionario_cad);
      gravar_funcionario(funcionario_cad);
      break;
    case 2:
      char cpf[12] = "0";
      printf("Informe o cpf do funcionario: ");
      scanf("%s", cpf);
      getchar();
      Funcionario *funcionario_busc = buscar_funcionario(cpf);
      if ((funcionario_busc != NULL) && (*funcionario_busc->cpf == 1)){
        exibir_funcionario(funcionario_busc);
        int edit = 99;
        printf("Deseja editar o funcionario? ");
        scanf("%d", &edit);
        getchar();
        if(edit = 1){
          int editar = 0;
          if(comparar_senha(funcionario_busc) == true){
            editar = menu_buscar_funcionario();
          }
          else{
            printf("Senha Incorreta!");
            delay(2);
          }
          switch (editar){
            case 0:
              break;
            case 1:
              getchar();
              atualizar_nome_funcionario(funcionario_busc);
              if(atualizar_funcionario(funcionario_busc)) printf("Funcionario Atualizado!!\n");
              break;
            case 2:
              atualizar_numero(funcionario_busc); 
              if(atualizar_funcionario(funcionario_busc)) printf("Funcionario Atualizado!!\n");;
              break;
            case 3:
              atualizar_cargo(funcionario_busc); 
              if(atualizar_funcionario(funcionario_busc)) printf("Funcionario Atualizado!!\n");;
              break;
            case 4:
              atualizar_endereco(funcionario_busc); 
              if(atualizar_funcionario(funcionario_busc)) printf("Funcionario Atualizado!!\n");;
              break;
            case 5:
              atualizar_salario(funcionario_busc); 
              if(atualizar_funcionario(funcionario_busc)) printf("Funcionario Atualizado!!\n");;
              break;
            case 6:
              atualizar_expediente(funcionario_busc); 
              if(atualizar_funcionario(funcionario_busc)) printf("Funcionario Atualizado!!\n");;
              break;
            case 7:
              funcionario_busc->stats = 0;
              if(atualizar_funcionario(funcionario_busc)) printf("Funcionario Atualizado!!\n");
              break;
            case 8:
              if(excluir_funcionario(*funcionario_busc->cpf)) printf("Funcionario excluído!!\n");
              break;
            default:
              printf("Digite um número valido\n");
              break;
          }
        }
        break;
      }
      break;
    case 4:
      listar_funcionario();
      break;
    case 5:
      reativar_funcionario();
      break;
    default:
      printf("Deve digitar um número");
      break;
    }
  } while (option != 0);
}

void cadastro_funcionario(Funcionario *funcionario) {
  printf("\n=========================================\n");
  printf("======== <Cadastrar Funcionario> ========\n");
  printf("=========================================\n");

  printf("Digite o nome do funcionario: ");
  fgets(funcionario->nome, 50, stdin);
  funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';

  bool cpf_valido = false;
  while (!cpf_valido) {
    printf("Digite o cpf do funcionario: ");
    fgets(funcionario->cpf, 12, stdin);
    funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0';
    printf("%s\n", funcionario->cpf);

    cpf_valido = validar_cpf(funcionario->cpf);
    if (!cpf_valido) {
      printf("cpf invalido! Digite novamente.\n");
    }
  }
  getchar();

  printf("Digite o número do funcionario: ");
  fgets(funcionario->numero, 11, stdin);
  funcionario->numero[strcspn(funcionario->numero, "\n")] = '\0';
  getchar();

  printf("Digite o cargo do funcionario: ");
  fgets(funcionario->cargo, 50, stdin);
  funcionario->cargo[strcspn(funcionario->cargo, "\n")] = '\0';

  printf("Digite o endereço do funcionario: ");
  fgets(funcionario->endereco, 100, stdin);
  funcionario->endereco[strcspn(funcionario->endereco, "\n")] = '\0';

  printf("Digite a salario do funcionario (reais): ");
  scanf("%e", &funcionario->salario);
  getchar();

  printf("Digite o expediente do funcionario: ");
  fgets(funcionario->expediente, 50, stdin);
  funcionario->expediente[strcspn(funcionario->expediente, "\n")] = '\0';

  bool senha_segura = false;
  while (!senha_segura) {
    printf("Digite a senha do funcionario (Minimo 8 digitos, Maximo 20 digitos, ao menos uma letra e um número): ");
    fgets(funcionario->password, 21, stdin);
    funcionario->password[strcspn(funcionario->password, "\n")] = '\0';
    printf("%s\n", funcionario->password);

    senha_segura = verificar_senha(funcionario->cpf);
    if (!cpf_valido) {
      printf("senha invalida! Digite novamente.\n");
    }
  }
  getchar();

  funcionario->stats = 1;

  printf("=====================================\n");
};

int gravar_funcionario(Funcionario *funcionario_grav){
    FILE *fp;
    fp = fopen(ARQUIVO_FUNCIONARIOS, "ab");
    if (fp == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Insere o aluno no final do arquivo
    fwrite(funcionario_grav,sizeof(Funcionario),1,fp);
    fclose(fp);
    return 1;
};

int excluir_funcionario(char cpf){
    FILE *fleitura;
    FILE *fescrita;
    Funcionario *auxiliarLeitura = (Funcionario *) malloc(sizeof(Funcionario));
 
    fleitura = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_FUNCIONARIOS_TEMPORARIOS, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Lendo o arquivo atual
    while (fread(auxiliarLeitura, sizeof(Funcionario), 1, fleitura))
    {
        //Caso a matricula seja diferente
        if(*auxiliarLeitura->cpf != cpf){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Funcionario), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_FUNCIONARIOS_TEMPORARIOS,ARQUIVO_FUNCIONARIOS);
    return 1;
};

int listar_funcionario(void){
    FILE *fp;
    Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    
    fp = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("-------------------------- Lista de Alunos --------------------------------\n");
    while (fread(funcionario, sizeof(Funcionario), 1, fp))
    {
      if (funcionario->stats == true){
       exibir_funcionario(funcionario);
      }
    }
    printf("---------------------------------------------------------------------------\n");
    
};

void exibir_funcionario(Funcionario *funcionario){
    printf("Nome: %s, cpf: %s, numero: %s, cargo: %s, endereço: %s, salário: %e, expediente: %s\n",
          funcionario->nome, funcionario->cpf, funcionario->numero,
          funcionario->cargo, funcionario->endereco, funcionario->salario, funcionario->expediente);
}

Funcionario* buscar_funcionario(char* cpf){
    FILE *fp;
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    fp = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return NULL;
    }
    while (fread(funcionario, sizeof(Funcionario), 1, fp))
    {
        if(strcmp(funcionario->cpf, cpf) == 0){
            fclose(fp);
            return funcionario;
        }
    }
    fclose(fp);
    return NULL;
};

void reativar_funcionario(void){
  char cpf[12] = "0";
  printf("Informe a cpf do funcionario: ");
  scanf("%s", cpf);
  getchar();
  Funcionario *funcionario = buscar_funcionario(cpf);
};

int menu_buscar_funcionario(void){
  int option = 99;
  printf("\n===========================================================\n");
  printf("================ <Menu buscar funcionario> ================\n");
  printf("===========================================================\n\n");
  printf("1 - Editar nome do funcionario:\n");
  printf("2 - Editar número do funcionario:\n");
  printf("3 - Editar cargo do funcionario:\n");
  printf("4 - Editar endereço do funcionario:\n");
  printf("5 - Editar salario do funcionario:\n");
  printf("6 - Editar expediente do funcionario:\n");
  printf("7 - Desativar funcionario (Exclusão temporaria):\n");
  printf("8 - Exclusão completa do funcionario:\n");
  printf("0 - Retornar:\n");
  scanf("%d", &option);
  getchar();
  return option;
};

void atualizar_nome_funcionario(Funcionario *funcionario_busc){
  printf("Informe o nome do produto: ");
  fgets(funcionario_busc->nome, 50, stdin);
  funcionario_busc->nome[strcspn(funcionario_busc->nome, "\n")] = '\0';
};

void atualizar_numero(Funcionario *funcionario_busc){
  printf("Informe o nome do produto: ");
  fgets(funcionario_busc->numero, 11, stdin);
  funcionario_busc->numero[strcspn(funcionario_busc->numero, "\n")] = '\0';
};

void atualizar_cargo(Funcionario *funcionario_busc){
  printf("Informe o nome do produto: ");
  fgets(funcionario_busc->cargo, 50, stdin);
  funcionario_busc->cargo[strcspn(funcionario_busc->cargo, "\n")] = '\0';
};

void atualizar_endereco(Funcionario *funcionario_busc){
  printf("Informe o nome do produto: ");
  fgets(funcionario_busc->endereco, 100, stdin);
  funcionario_busc->endereco[strcspn(funcionario_busc->endereco, "\n")] = '\0';
};

void atualizar_salario(Funcionario *funcionario_busc){
  printf("Digite a quantidade do produto para avisar nescessidade de reposição (Opcional): ");
  scanf("%e", &funcionario_busc->salario);
  getchar();
};

void atualizar_expediente(Funcionario *funcionario_busc){
  printf("Informe o nome do produto: ");
  fgets(funcionario_busc->expediente, 50, stdin);
  funcionario_busc->expediente[strcspn(funcionario_busc->expediente, "\n")] = '\0';
};

int atualizar_funcionario(Funcionario *funcionario_busc){
  int achou;
	FILE* fp;
	Funcionario* produto_lido;

	produto_lido = (Funcionario*) malloc(sizeof(Funcionario));
	fp = fopen("funcionarios.dat", "r+b");
	if (fp == NULL) {
		printf("Falha na produção de arquivo\n");
	}
	achou = false;
	while(fread(produto_lido, sizeof(Funcionario), 1, fp) && !achou) {
		if (strcmp(produto_lido->cpf, funcionario_busc->cpf) == 0) {
			achou = true;
			fseek(fp, -1*sizeof(Funcionario), SEEK_CUR);
        	fwrite(funcionario_busc, sizeof(Funcionario), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(produto_lido);
};

bool comparar_senha(Funcionario *funcionario_checar){
  char password[21];
  printf("Digite a senha do funcionario, %s:", funcionario_checar->nome);
  fgets(password, 21, stdin);
  password[strcspn(password, "\n")] = '\0';
  if((strcmp(funcionario_checar->password, password) || verificar_senha_de_emergencia(password))){
    return true;
  }
  return false;
};

bool verificar_senha_de_emergencia(char *password){
  if (strcmp(senha_mestre, password)) {
    return true;
  }
  FILE *fp;
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    fp = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return NULL;
    }
    while (fread(funcionario, sizeof(Funcionario), 1, fp))
    {
        if(strcmp(funcionario->cargo, "Gerente") == 0){
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return NULL;
};