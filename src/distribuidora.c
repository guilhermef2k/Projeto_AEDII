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

int altura(NO *n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int fatorBalanceamento(NO *n) {
    if (n == NULL)
        return 0;
    return altura(n->esq) - altura(n->dir);
}
NO *inicializar() {
    return NULL;
}

NO* rotacaoDireita(NO *y) {
    NO *x = y->esq;
    NO *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

NO* rotacaoEsquerda(NO *x) {
    NO *y = x->dir;
    NO *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

NO* novoNoAVL(Produto dado) {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return NULL;
    }
    novo->dado = dado;
    novo->esq = novo->dir = NULL;
    novo->altura = 1;  
    return novo;
}

void salvarProduto(FILE *arquivo, NO *no) {
    if (no == NULL) {
        fprintf(arquivo, "#\n");
        return;
    }

    fprintf(arquivo, "%d %s %d %f %s\n", no->dado.codigo, no->dado.nome, no->dado.estoque, no->dado.preco, no->dado.categoria);

    salvarProduto(arquivo, no->esq);
    salvarProduto(arquivo, no->dir);
}

NO* carregarProdutos(FILE *arquivo) {
    Produto dado;
    char buffer[100];

    if (!fgets(buffer, sizeof(buffer), arquivo)) {
        return NULL;
    }

    if (strcmp(buffer, "#\n") == 0) {
        return NULL;
    }

    sscanf(buffer, "%d %s %d %f %s", &dado.codigo, dado.nome, &dado.estoque, &dado.preco, dado.categoria);

    NO *no = novoNoAVL(dado); 

    no->esq = carregarProdutos(arquivo);
    no->dir = carregarProdutos(arquivo);

    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    return no;
}