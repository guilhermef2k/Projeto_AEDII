#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "distribuidora.h"

void MenuPrincipal() {
    printf("\n======PONTEIRO SEM PONTA=======\n");
  	printf("\nMenu Principal:\n");
    printf("1. Login\n");
    printf("2. Cadastrar novo usuario\n");
    printf("3. Listar produtos\n");
    printf("4. Buscar produto\n");
    printf("5. Mostrar por categoria\n");
    printf("0. Sair\n");
    printf("\nEscolha uma opcao: ");
}

void MenuUsuario(){
  	printf("\nMenu do Usuario:\n");
    printf("1. Cadastrar novo produto\n");
	printf("2. Editar produto\n");
	printf("3. Listar produtos\n");
	printf("4. Buscar produto\n");
	printf("5. Excluir produto\n");
	printf("6. Ordenar produtos por codigo\n");
    printf("7. Excluir usuario\n");
    printf("8. Logout\n");
    printf("0. Sair\n");
    printf("\nEscolha uma opcao: ");
}
