#ifndef DISTRIBUIDORA_H
#define DISTRIBUIDORA_H

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    char categoria[50];
    int estoque;
} Produto;

typedef struct NO {
    Produto dado;
    struct NO* esq;
    struct NO* dir;
    int altura;
} NO;

void logo();
void MenuPrincipal();
void MenuUsuario();
void salvarProduto(FILE *arquivo, NO *no);
void editarProduto(NO *raiz, int codigo);
void mostrarProdutos(NO *raiz, int nivel);
int altura(NO *n);
int max(int a, int b);
int fatorBalanceamento(NO *n);
NO* inicializar();
NO* rotacaoDireita(NO *y);
NO* rotacaoEsquerda(NO *x);
NO* cadastrarProduto(NO* no, Produto dado);
NO* novoNoAVL(Produto dado);
NO* carregarProdutos(FILE *arquivo);
NO* buscarProduto(NO* raiz, int codigo);
#endif
