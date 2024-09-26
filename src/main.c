#include <stdio.h>
#include <string.h> 
#include "distribuidora.h"

int main() {
    int opcao, opcaoUsuario, cod, tentativas = 0, maxTentativas = 3;
    NO *raiz = inicializar();  
    Produto A;
    char user[50];
    int senha;
    FILE *arquivo = fopen("produtos.txt", "r+");  
	if (arquivo != NULL) {
    	raiz = carregarProdutos(arquivo);  
    	fclose(arquivo);
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
                    scanf("%d", &senha);

                    if ((strcmp(user, "usuario") == 0) && (senha == 123)) {
                        printf("\nLogin bem-sucedido!\n");
                        tentativas = 0; 

                        do {
                            MenuUsuario();
                            scanf("%d", &opcaoUsuario);
                            switch (opcaoUsuario) {
                                case 1:
                                    printf("\nInforme o codigo, nome, preco, categoria do produto e quantidade em estoque.\n");
                                    scanf("%d %s %f %s %d", &A.codigo, A.nome, &A.preco, A.categoria, &A.estoque);
                                    raiz = cadastrarProduto(raiz, A);
                                    break;
                                case 2:
                                    printf("\nInforme o codigo do produto que deseja alterar:");
                                    scanf("%d", &cod);
                                    editarProduto(raiz, cod); 
                                    break;                                 
                                case 3:
                                    mostrarProdutos(raiz, 0);
                                    break;
                                case 4:         
                                    printf("\nInforme o codigo do produto que deseja buscar:");
                                    scanf("%d", &cod);
                                    
                                    break;
                                case 5:
                                    printf("\nInforme o codigo do produto que deseja excluir:");
                                    scanf("%d", &cod);
                                    
                                    break;
                                case 6:
                                    
                                    break;
                                case 7:
                                    
                                    break;
                                case 8:
                                    printf("Logout realizado com sucesso.\n");
                                    break;            
                                case 0:
                                    printf("Saindo do programa...\n");
                                    break;
                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                            }
                        } while (opcaoUsuario != 0 && opcaoUsuario != 8);

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

                break;
            case 3:
                mostrarProdutos(raiz, 0);
                break;
            case 4:
                printf("\nInforme o codigo do produto que deseja buscar:");
                scanf("%d", &cod);
              
                break;
            case 5:
               
                break;  
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
