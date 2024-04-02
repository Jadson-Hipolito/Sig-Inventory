  #include <stdio.h>
  int menu = 0;

void menu_produto();
void menu_funcionario();
void menu_Entrada_Saida();

int main(){
 do {
  printf("\n=====================================\n");
  printf("========= <Menu Inventario> =========\n");
  printf("=====================================\n");
  printf("1 - Produtos\n");
  printf("2 - Funcionarios\n");
  printf("3 - Entrada e Saida\n");
  printf("0 - Finalizar Programa\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf(" %d", &menu);
  getchar();
  switch (menu) {
   case 1:
    menu_produto();
    break;
   case 2:
    menu_funcionario();
    break;
   case 3:
    menu_Entrada_Saida();
    break;
   }
 } while (menu != 0);
} 

void menu_produto(){
 int option;
 do {
  printf("\n=====================================\n");
  printf("========== <Menu Produtos> ==========\n");
  printf("=====================================\n");
  printf("1 - Cadastra Produto Novo\n");
  printf("2 - Excluir Produto\n");
  printf("3 - Alterar Produto\n");
  printf("4 - Listar Produtos\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch(option){
   case 1:
    printf("\n=====================================\n");
    printf("======== <Cadastrar Produto> ========\n");
    printf("=====================================\n");
    printf("1 - Nome do Produto:\n");
    printf("2 - Codigo de Barra:\n");
    printf("3 - Quantidade Atual:\n");
    printf("4 - Tipo de Produto:\n");
    printf("5 - Local do Produto:\n");
    printf("6 - Fornecedor(Opcional):\n");
    printf("7 - Quantidade para pedir reposição (Opcional):\n");
    printf("8 - Anotações de Armazenamento(Opcional):\n");
    printf("=====================================\n");
    break;
   case 2:
    printf("\n=====================================\n");
    printf("========== <Editar Produto> =========\n");
    printf("=====================================\n\n");
    printf("1 - Codigo do Produto:\n");
    printf("=====================================\n");
    printf("1 - Nome do Produto:\n");
    printf("2 - Codigo de Barra:\n");
    printf("3 - Quantidade Atual:\n");
    printf("4 - Tipo de Produto:\n");
    printf("5 - Local do Produto:\n");
    printf("6 - Fornecedor(Opcional):\n");
    printf("7 - Quantidade para pedir reposição (Opcional):\n");
    printf("8 - Anotações de Armazenamento(Opcional):\n");
    printf("=====================================\n");
    printf("=====================================\n");
    break;
   case 3:
    printf("\n=====================================\n");
    printf("========= <Lista de Produto> ========\n");
    printf("=====================================\n\n");
    printf("1 - Lista de Produtos Cadastrados:\n");
    printf("=====================================\n");
    printf("=====================================\n");
    break;
  }
 } while (option != 0);
}

void menu_funcionario(){
  int option;
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
  switch(option){
   case 1:
    printf("\n=====================================\n");
    printf("======= <Cadastro Funcionario> ======\n");
    printf("=====================================\n");
    printf("1 - Nome do Funcionario:\n");
    printf("2 - CPF:\n");
    printf("3 - Numero:\n");
    printf("4 - Cargo:\n");
    printf("5 - Salário:\n");
    printf("6 - Espediente:\n");
    printf("7 - Endereço:\n");
    printf("0 - Voltar:\n");
    printf("=====================================\n");
    break;
   case 2:
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
    break;
   case 3:
    printf("\n=====================================\n");
    printf("======= <Excluir Funcionario> =======\n");
    printf("=====================================\n\n"); 

    printf("\n=====================================\n");
    printf("== Cpf do funcionario que ira excluir\n");
    printf("=====================================\n\n");

    printf("Confirmar Exclusão:\n");
    break;
  }
 } while (option != 0);  
}

void menu_Entrada_Saida(){
 int option;
 do {
  printf("\n=====================================\n");
  printf("====== <Menu Entrada e Saida> =======\n");
  printf("=====================================\n");
  printf("1 - Entrada e Saida de Produtos\n");
  printf("2 - Entrada e Saida de Funcionarios\n");
  printf("3 - Editar Entrada e Saida de Funcionario\n");
  printf("4 - Remover Entrada ou saida de Funcionario\n");
  printf("0 - Voltar para <Menu Inventario>\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &option);
  getchar();
  switch (option){
   case 1:
    printf("\n=====================================\n");
    printf("===== <Entrada e Saida Produtos> ====\n");
    printf("=====================================\n\n");
   break;

   case 2:
    printf("\n=====================================\n");
    printf("=== <Entrada e Saida Funcionarios> ==\n");
    printf("=====================================\n\n");
   break;

   case 3:
    printf("\n===============================================\n");
    printf("=== <Editar Entrada e Saida de funcionario> ===\n");
    printf("\n===============================================\n");
    printf("Cpf do funcionario que ira editara entrada:\n");
    break;

   case 4:
    printf("===================================================\n");
    printf("=== <Remover Entrada ou Saida de Funcionario> ===\n");
    printf("===================================================\n");
    printf("Cpf do funcionario que ira remover entrada:\n");
    break;
  }
 } while (option != 0);
}