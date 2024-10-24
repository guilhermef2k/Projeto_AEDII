#ifndef DISTRIBUIDORA_H
#define DISTRIBUIDORA_H
#define MAX_HEAP_SIZE 100

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

typedef struct {
    Produto heap[MAX_HEAP_SIZE];
    int tamanho;
} MinHeap;

void MenuPrincipal();
void MenuUsuario();
void salvarProduto(FILE *arquivo, NO *no);
void mostrarProdutos(NO *raiz, int nivel);
int mostrarProdutosPorCategoria(NO *raiz, char *categoria);
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
NO* removerProduto(NO* raiz, int codigo);
NO* editarProduto(NO *raiz, int codigo);
void inicializarMinHeap(MinHeap *h);
void inserirMinHeap(MinHeap *h, Produto p);
Produto removerMinHeap(MinHeap *h);
void listarProdutosHeap(MinHeap *h);
void ordenarProdutosPorCodigo(NO **raiz, MinHeap *heap);
void inserirProdutosNoHeap(NO *raiz, MinHeap *heap);
float lerFloat();
int lerInteiro();
#endif
