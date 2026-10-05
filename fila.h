// Fila encadeada das proximas musicas (FIFO: entra no fim, sai no inicio).
#ifndef FILA_H
#define FILA_H

#include "../musicas.h"

// No da fila: guarda uma musica e o endereco do proximo no (NULL no ultimo).
typedef struct NoFila
{
  Musica musica;
  struct NoFila *proximo;
} NoFila;

// Controle da fila, separado dos nos: inicio aponta para a proxima musica a tocar
// e fim para a ultima adicionada. Fila vazia = os dois NULL.
typedef struct
{
  NoFila *inicio;
  NoFila *fim;
} Fila;

// Funcoes implementadas em fila.c.
void inicializarFila(Fila *fila);
int verificarFilaVazia(Fila *fila);
int enfileirar(Fila *fila, Musica musica);
int desenfileirar(Fila *fila, Musica *musica);
void exibirInicioFila(Fila *fila);
void exibirFila(Fila *fila);
int contarFila(Fila *fila);
void esvaziarFila(Fila *fila);
void exibirEstadoFila(Fila *fila);
void testarFila(Musica catalogo[]);

#endif
