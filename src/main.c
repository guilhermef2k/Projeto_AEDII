#include <stdio.h>
#include <string.h> 
#include "distribuidora.h"
#include "usuarios.h"

int main() {
    int opcao, opcaoUsuario, encontrados, confirmarExclusao, cod, tentativas = 0, maxTentativas = 3;
    NO *raiz = inicializar();
    NO* produto;
    NO* produtoExcluir;
    Produto A;
    Usuario B;
    Usuario* usuarioEncontrado;
    char user[50];
    char senha[50];
    char categoria[50];
    FILE *arquivo;
    FILE *arquivo2;
    MinHeap heap;
	inicializarMinHeap(&heap);
    initHash();

    arquivo = fopen("produtos.txt", "r");  
	if (arquivo != NULL) {
    	raiz = carregarProdutos(arquivo);  
    	fclose(arquivo);
	}
    arquivo2 = fopen("usuarios.txt", "r");  
	if (arquivo2 != NULL) {
    	carregarUsuarios(arquivo2);  
    	fclose(arquivo2);
	}

    do {
        MenuPrincipal();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                do {
                    printf("\nInforme o seu ID:\n");
                    scanf("%s", user);
                    printf("\nInforme a senha:\n");
                    scanf("%s", senha);

                    usuarioEncontrado = buscarUsuario(user);
                    if (usuarioEncontrado != NULL && strcmp(usuarioEncontrado->senha, (char*)senha) == 0) {
                        printf("\nLogin bem-sucedido!\n");
                        tentativas = 0;

                        do {
                            MenuUsuario();
                            scanf("%d", &opcaoUsuario);
                            switch (opcaoUsuario) {
                                case 1:
                                    printf("\nInforme o codigo: \n");
                                    A.codigo = lerInteiro();
                                    printf("\nInforme o nome: \n");
                                    scanf("%s", A.nome);
                                    printf("\nInforme o preco: \n");
                                    A.preco = lerFloat();
                                    printf("\nInforme a categoria do produto: \n");
                                    scanf("%s", A.categoria);
                                    printf("\nInforme a quantidade em estoque: \n");
                                    A.estoque = lerInteiro();
                                    raiz = cadastrarProduto(raiz, A);
                                    inserirMinHeap(&heap, A);
                                    printf("\nProduto cadastrado com sucesso!\n");
                                    break;
                                case 2:
                                    printf("\nInforme o codigo do produto que deseja alterar: ");
                                    scanf("%d", &cod);
                                    raiz = editarProduto(raiz, cod); 
                                    break;                                 
                                case 3:
                                    mostrarProdutos(raiz, 0);
                                    break;
                                case 4:         
                                    printf("\nInforme o codigo do produto que deseja buscar: ");
                                    scanf("%d", &cod);
                                    produto = buscarProduto(raiz, cod);
                                    if (produto) {
                                        printf("Produto encontrado: %d (%s, Estoque: %d, Preco: %.2f)\n", 
                                               produto->dado.codigo, produto->dado.nome, produto->dado.estoque, produto->dado.preco);
                                    } else {
                                        printf("Produto não encontrado.\n");
                                    }
                                    break;
                                case 5:
                                    printf("\nInforme o codigo do produto que deseja excluir: ");
                                    scanf("%d", &cod);
                                    produtoExcluir = buscarProduto(raiz, cod);
								    if (produtoExcluir) {
								        printf("\nProduto encontrado: %d (%s, Estoque: %d, Preco: %.2f)\n",
								               produtoExcluir->dado.codigo, produtoExcluir->dado.nome,
								               produtoExcluir->dado.estoque, produtoExcluir->dado.preco);
								        
								        printf("Tem certeza que deseja excluir este produto? (1-Sim, 0-Nao)\n");
								        scanf("%d", &confirmarExclusao);								
								        if (confirmarExclusao == 1){ 
								            raiz = removerProduto(raiz, cod);
                                            printf("Produto excluido com sucesso!\n");
                                        }								            
								        else 
								            printf("Exclusao cancelada.\n");								        
								    } else {
								        printf("Produto nao encontrado.\n");
								    }
                                    break;
                                case 6:
                                    ordenarProdutosPorCodigo(&raiz, &heap);
                                    break;
                                case 7:
	                                printf("Informe a categoria que deseja buscar: ");
	                                scanf("%s", categoria);
	                                encontrados = mostrarProdutosPorCategoria(raiz, categoria);
	                                    if (encontrados == 0) {
		                                printf("Nenhum produto encontrado na categoria '%s'.\n", categoria);
	                                }
	                                break;
                                case 8:
                                    printf("Informe o nome de usuario para excluir: ");
                                    scanf("%s", user);
                                    excluirUsuario(user);
                                    break; 
                                case 9:
                                    arquivo = fopen("produtos.txt", "w");
                                    if (arquivo != NULL) {
	                                    salvarProduto(arquivo, raiz);
	                                    fclose(arquivo);
	                                    printf("Alteracoes salvas.\n");
                                    }
                                break;                
                                case 0:                 
	                                    printf("Saindo do programa...\n");
                                    break;                                
                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                            }
                        } while (opcaoUsuario != 0);

                    } else {
                        tentativas++;
                        printf("\nLogin falhou. Tentativa %d de %d.\n", tentativas, maxTentativas);
                    }

                } while (tentativas < maxTentativas && opcaoUsuario != 0);

                if (tentativas == maxTentativas) {
                    printf("Numero maximo de tentativas atingido. Encerrando programa...\n");
                    return 0;  
                }
                break;

            case 2:
                printf("Nome de usuario: ");
                scanf("%s", B.id);
                printf("Email: ");
                scanf("%s", B.email);
                printf("Senha: ");
                scanf("%s", B.senha);
                cadastrarUsuario(B.id, B.email, B.senha);
                printf("\nUsuario cadastrado com sucesso!\n");
                break;
            case 3:
                mostrarProdutos(raiz, 0);
                break;
            case 4:
                printf("\nInforme o codigo do produto que deseja buscar: ");
                scanf("%d", &cod);
                produto = buscarProduto(raiz, cod);
                if (produto) {
                    printf("Produto encontrado: %d (%s, Estoque: %d, Preco: %.2f)\n", 
                            produto->dado.codigo, produto->dado.nome, produto->dado.estoque, produto->dado.preco);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
            case 5:
                printf("Informe a categoria que deseja buscar: ");
	            scanf("%s", categoria);
	            encontrados = mostrarProdutosPorCategoria(raiz, categoria);
	                if (encontrados == 0) {
		            printf("Nenhum produto encontrado na categoria '%s'.\n", categoria);
	                }
                break;  
            case 0:
                arquivo2 = fopen("usuarios.txt", "w");
                if (arquivo2 != NULL) {
	                salvarUsuario(arquivo2);
	                fclose(arquivo2);
	                printf("Saindo do programa...\n");
                }
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);
    return 0;
}