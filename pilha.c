// Implementacao da pilha do historico.
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Deixa a pilha vazia (topo NULL). Precisa ser chamada antes de usar a pilha.
void inicializarPilha(Pilha *pilha)
{
  pilha->topo = NULL;
}

// Devolve 1 se a pilha esta vazia e 0 se tem musica.
int verificarPilhaVazia(Pilha *pilha)
{
  if (pilha->topo == NULL)
  {
    return 1;
  }

  return 0;
}

// Coloca a musica no topo. Devolve 0 se deu certo e 1 se faltou memoria.
int empilhar(Pilha *pilha, Musica musica)
{
  NoPilha *novo = malloc(sizeof(NoPilha));

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->musica = musica;
  // O novo no aponta para o topo antigo e passa a ser o topo.
  novo->proximo = pilha->topo;
  pilha->topo = novo;

  printf("Musica adicionada ao historico com sucesso.\n");
  return 0;
}

// Remove a musica do topo e entrega em *musica (usada na opcao Voltar).
// Devolve 0 se deu certo e 1 se a pilha estava vazia.
int desempilhar(Pilha *pilha, Musica *musica)
{
  NoPilha *auxiliar;

  if (verificarPilhaVazia(pilha) == 1)
  {
    printf("A pilha esta vazia.\n");
    return 1;
  }

  auxiliar = pilha->topo;
  *musica = auxiliar->musica;

  // O topo passa para o proximo no. Se era o unico, vira NULL.
  pilha->topo = auxiliar->proximo;

  free(auxiliar);
  return 0;
}

// Mostra a ultima musica tocada sem tirar da pilha.
void exibirTopoPilha(Pilha *pilha)
{
  if (verificarPilhaVazia(pilha) == 1)
  {
    printf("A pilha esta vazia.\n");
    return;
  }

  printf("Ultima musica tocada: ");
  exibirMusica(&pilha->topo->musica);
}

// Conta quantas musicas ha no historico.
int contarPilha(Pilha *pilha)
{
  NoPilha *auxiliar = pilha->topo;
  int quantidade = 0;

  while (auxiliar != NULL)
  {
    quantidade++;
    auxiliar = auxiliar->proximo;
  }

  return quantidade;
}

// Libera todos os nos da pilha; no final o topo fica NULL.
void esvaziarPilha(Pilha *pilha)
{
  NoPilha *auxiliar;

  while (pilha->topo != NULL)
  {
    auxiliar = pilha->topo;
    // Avanca o topo antes do free, para nao perder o resto da pilha.
    pilha->topo = pilha->topo->proximo;
    free(auxiliar);
  }
}

// Mostra o topo e o endereco de cada no com o seu proximo (opcao 8 do menu).
void exibirEstadoPilha(Pilha *pilha)
{
  NoPilha *auxiliar = pilha->topo;

  printf("\n===== ESTADO DA PILHA =====\n");

  if (pilha->topo == NULL)
  {
    printf("Topo: NULL\n");
  }
  else
  {
    printf("Topo: %p (%s)\n", (void *)pilha->topo, pilha->topo->musica.titulo);
  }

  while (auxiliar != NULL)
  {
    if (auxiliar->proximo == NULL)
    {
      printf("[%p] %s -> proximo: NULL\n", (void *)auxiliar,
             auxiliar->musica.titulo);
    }
    else
    {
      printf("[%p] %s -> proximo: %p\n", (void *)auxiliar,
             auxiliar->musica.titulo, (void *)auxiliar->proximo);
    }

    auxiliar = auxiliar->proximo;
  }
}
