#include <stdio.h>
int menu = 0;
int main(){
 printf("\n=====================================\n");
 printf("=== <Menu Inventario> ===\n");
 printf("=====================================\n");
 printf("1 - Produtos\n");
 printf("2 - Funcionarios\n");
 printf("3 - Entrada e Saida\n");
 printf("0 - Finalizar Programa\n");
 printf("=====================================\n");
 printf("Escolha uma opção: ");
 scanf("%d", &menu);
 switch (menu) {
   case 1:
    int menu_produto;
    printf("\n=====================================\n");
    printf("=== <Menu Produtos> ===\n");
    printf("=====================================\n");
    printf("1 - Cadastra Produto Novo\n");
    printf("2 - Excluir Produto\n");
    printf("3 - Mudar Quantidade do Produto\n");
    printf("0 - Voltar para <Menu Inventario>\n");
    printf("=====================================\n");
    printf("Escolha uma opção: ");
    switch(menu_produto){
     case 1:
      printf("\n=====================================\n");
      printf("=== <Cadastro Produto> ===\n");
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
      printf("Escolha uma opção: ");
    }
    break;
}
}
