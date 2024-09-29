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

NO* minimoValorNo(NO* node) {
    NO* atual = node;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
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
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novo->dado = dado;
    novo->esq = novo->dir = NULL;
    novo->altura = 1;  
    return novo;
}

NO* cadastrarProduto(NO* no, Produto dado) {
    int balanceamento;
    if (no == NULL)
        return novoNoAVL(dado);

    if (dado.codigo < no->dado.codigo)
        no->esq = cadastrarProduto(no->esq, dado);
    else if (dado.codigo > no->dado.codigo)
        no->dir = cadastrarProduto(no->dir, dado);
    else  
        return no;

    no->altura = 1 + max(altura(no->esq), altura(no->dir));
    balanceamento = fatorBalanceamento(no);

    if (balanceamento > 1 && dado.codigo < no->esq->dado.codigo)
        return rotacaoDireita(no);
    if (balanceamento < -1 && dado.codigo > no->dir->dado.codigo)
        return rotacaoEsquerda(no);
    if (balanceamento > 1 && dado.codigo > no->esq->dado.codigo) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }
    if (balanceamento < -1 && dado.codigo < no->dir->dado.codigo) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }
    return no;  
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
    NO *no; 
    char buffer[100];

    if (!fgets(buffer, sizeof(buffer), arquivo)) {
        return NULL;
    }

    if (strcmp(buffer, "#\n") == 0) {
        return NULL;
    }

    sscanf(buffer, "%d %s %d %f %s", &dado.codigo, dado.nome, &dado.estoque, &dado.preco, dado.categoria);
    no = novoNoAVL(dado);
    no->esq = carregarProdutos(arquivo);
    no->dir = carregarProdutos(arquivo);

    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    return no;
}
NO* buscarProduto(NO* raiz, int codigo) {
    if (raiz == NULL || raiz->dado.codigo == codigo)
        return raiz;

    if (codigo < raiz->dado.codigo)
        return buscarProduto(raiz->esq, codigo);

    return buscarProduto(raiz->dir, codigo);
}
void editarProduto(NO *raiz, int codigo) {
    int opcao;
    FILE *arquivo = fopen("produtos.txt", "w");
    NO *produto = buscarProduto(raiz, codigo); 

    if (produto == NULL) {
        printf("Produto com codigo %d nao encontrado.\n", codigo);
        return;
    }

    printf("Produto encontrado: %d (%s, Estoque: %d, Preco: %.2f)\n", 
           produto->dado.codigo, produto->dado.nome, produto->dado.estoque, produto->dado.preco);

    printf("O que voce deseja editar?\n");
    printf("1. Nome\n");
    printf("2. Estoque\n");
    printf("3. Preco\n");
    printf("4. Categoria\n");
    printf("Escolha uma opcao: ");
    
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Informe o novo nome: ");
            scanf("%s", produto->dado.nome);
            printf("Nome alterado com sucesso!\n");
            break;
        case 2:
            printf("Informe a nova quantidade em estoque: ");
            scanf("%d", &produto->dado.estoque);
            printf("Estoque alterado com sucesso!\n");
            break;
        case 3:
            printf("Informe o novo preco: ");
            scanf("%f", &produto->dado.preco);
            printf("Preco alterado com sucesso!\n");
            break;
        case 4:
            printf("Informe a nova categoria: ");
            scanf("%s", produto->dado.categoria);
            printf("Categoria alterada com sucesso!\n");
            break;
        default:
            printf("Opcao invalida. Nenhuma alteracao realizada.\n");
    }
    

	if (arquivo != NULL) {
	    salvarProduto(arquivo, raiz);
	    fclose(arquivo);
	    printf("Produto editado e salvo com sucesso.\n");
	} else {
	    printf("Erro ao salvar alteracoes no arquivo.\n");
	}
}

NO* removerProduto(NO* raiz, int codigo) {
    int balance;
    NO* temp;
    if (raiz == NULL) {
        printf("Produto nao encontrado.\n");
        return raiz;
    }
    if (codigo < raiz->dado.codigo) {
        raiz->esq = removerProduto(raiz->esq, codigo);
    } else if (codigo > raiz->dado.codigo) {
        raiz->dir = removerProduto(raiz->dir, codigo);
    } else {
        if (raiz->esq == NULL) {
            NO* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            NO* temp = raiz->esq;
            free(raiz);
            return temp;
        }     
        temp = minimoValorNo(raiz->dir);
        raiz->dado = temp->dado;
        raiz->dir = removerProduto(raiz->dir, temp->dado.codigo);
    }

    if (raiz == NULL)
        return raiz;

    
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

   
    balance = fatorBalanceamento(raiz);

    if (balance > 1 && fatorBalanceamento(raiz->esq) >= 0) {
        return rotacaoDireita(raiz);
    }

    if (balance > 1 && fatorBalanceamento(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (balance < -1 && fatorBalanceamento(raiz->dir) <= 0) {
        return rotacaoEsquerda(raiz);
    }

    if (balance < -1 && fatorBalanceamento(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}

void mostrarProdutos(NO *raiz, int nivel) {
    int i;
    if (raiz == NULL) {
        return;
    }

    mostrarProdutos(raiz->dir, nivel + 1);
    for (i = 0; i < nivel; i++) {
        printf("\t");
    }
    printf("%d (%s, Estoque: %d, Preco: %.2f)\n", raiz->dado.codigo, raiz->dado.nome, raiz->dado.estoque, raiz->dado.preco);

    mostrarProdutos(raiz->esq, nivel + 1);
}