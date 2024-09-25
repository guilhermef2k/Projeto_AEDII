#ifndef DISTRIBUIDORA_H
#define DISTRIBUIDORA_H

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    char categoria[50];
    int estoque;
} Produto;

void logo();
void MenuPrincipal();
void MenuUsuario();

#endif
