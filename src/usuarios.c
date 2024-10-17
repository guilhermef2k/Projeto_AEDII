#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define N 16

typedef struct usuario {
  char id[20];
  char email[80];
  char senha[30];
  struct usuario *prox; 
} Usuario;

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
