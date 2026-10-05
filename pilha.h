// Pilha encadeada do historico de musicas tocadas (LIFO: entra e sai pelo topo).
#ifndef PILHA_H
#define PILHA_H

#include "../musicas.h"

// No da pilha: guarda uma musica e o endereco do no de baixo (NULL no ultimo).
typedef struct NoPilha
{
  Musica musica;
  struct NoPilha *proximo;
} NoPilha;

// A Pilha fica separada dos nos e guarda so o campo de controle.
// topo aponta para a ultima musica tocada. Pilha vazia = topo NULL.
typedef struct
{
  NoPilha *topo;
} Pilha;

// Funcoes implementadas em pilha.c.
void inicializarPilha(Pilha *pilha);
int verificarPilhaVazia(Pilha *pilha);
int empilhar(Pilha *pilha, Musica musica);
int desempilhar(Pilha *pilha, Musica *musica);
void exibirTopoPilha(Pilha *pilha);
int contarPilha(Pilha *pilha);
void esvaziarPilha(Pilha *pilha);
void exibirEstadoPilha(Pilha *pilha);

#endif
