#ifndef USUARIOS_H
#define USUARIOS_H

typedef struct usuario {
  char id[20];
  char email[80];
  char senha[30];
  struct usuario *prox; 
} Usuario;

void initHash();
int toInt(char *id);
int h(char *id);
Usuario *novoUsuario(char *id, char *email, char *senha);
void cadastrarUsuario(char *id, char *email, char *senha);
void salvarUsuario(FILE* arquivo);
void carregarUsuarios(FILE *arquivo);

#endif