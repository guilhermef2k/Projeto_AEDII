#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define N 16

Usuario* hash[N];

void initHash() {
  int i=0;
  for (i = 0; i < N; i++) {
    hash[i] = NULL;
  }
}

int toInt(char *id) {
    unsigned int hash = 0;
    int i;
    for (i = 0; id[i] != '\0'; i++) {
        hash = (hash * 31 + id[i]); 
    }
    return hash;
}

int h(char *id) { return toInt(id) % N; }

void cadastrarUsuario(char *id, char *email, char *senha) {
    unsigned int indice = h(id);
    Usuario* novo = novoUsuario(id, email, senha);

    if (hash[indice] == NULL) {
        hash[indice] = novo;
    } else {
        Usuario *atual = hash[indice];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

Usuario *novoUsuario(char *id, char *email, char *senha) {
  Usuario *d = (Usuario *)malloc(sizeof(Usuario));
  strcpy(d->id, id);
  strcpy(d->email, email);
  strcpy(d->senha, senha);
  d->prox = NULL;
  return d;
}

void salvarUsuario(FILE* arquivo) {
    int i;
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

 
    for (i = 0; i < N; i++) {
        Usuario* atual = hash[i];

        while (atual != NULL) {
            
            fprintf(arquivo, "%s %s %s\n", atual->id, atual->email, atual->senha);
            atual = atual->prox;
        }
    }
}

void carregarUsuarios(FILE *arquivo) {
    char nome[50], email[50], senha[50];
    if (arquivo == NULL) {
        return;
    }
    while (fscanf(arquivo, "%s %s %s", nome, email, senha) != EOF) {
        cadastrarUsuario(nome, email, senha); 
    }
    fclose(arquivo);
}