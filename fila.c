// Implementacao da fila de proximas musicas.
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Deixa a fila vazia (inicio e fim NULL). Precisa ser chamada antes de usar a fila.
void inicializarFila(Fila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
}

// Devolve 1 se a fila esta vazia e 0 se tem musica.
int verificarFilaVazia(Fila *fila)
{
  if (fila->inicio == NULL)
  {
    return 1;
  }

  return 0;
}

// Insere a musica no fim da fila. Devolve 0 se deu certo e 1 se faltou memoria.
int enfileirar(Fila *fila, Musica musica)
{
  NoFila *novo = malloc(sizeof(NoFila));

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->musica = musica;
  novo->proximo = NULL;

  // Fila vazia: o novo no tambem vira o inicio. Senao, entra depois do ultimo.
  // O ponteiro fim evita percorrer a fila inteira para inserir.
  if (verificarFilaVazia(fila) == 1)
  {
    fila->inicio = novo;
  }
  else
  {
    fila->fim->proximo = novo;
  }

  fila->fim = novo;

  printf("Musica adicionada a fila com sucesso.\n");
  return 0;
}

// Remove a musica do inicio e entrega em *musica (usada na opcao Proxima).
// Devolve 0 se deu certo e 1 se a fila estava vazia.
int desenfileirar(Fila *fila, Musica *musica)
{
  NoFila *auxiliar;

  if (verificarFilaVazia(fila) == 1)
  {
    printf("A fila esta vazia.\n");
    return 1;
  }

  auxiliar = fila->inicio;
  *musica = auxiliar->musica;
  fila->inicio = auxiliar->proximo;

  // Se saiu o unico elemento, o fim tambem precisa voltar para NULL.
  if (fila->inicio == NULL)
  {
    fila->fim = NULL;
  }

  free(auxiliar);
  return 0;
}

// Mostra a proxima musica sem tirar da fila.
void exibirInicioFila(Fila *fila)
{
  if (verificarFilaVazia(fila) == 1)
  {
    printf("A fila esta vazia.\n");
    return;
  }

  printf("Proxima musica: ");
  exibirMusica(&fila->inicio->musica);
}

// Lista todas as musicas da fila, na ordem em que vao tocar.
void exibirFila(Fila *fila)
{
  NoFila *auxiliar = fila->inicio;
  int posicao = 0;

  if (verificarFilaVazia(fila) == 1)
  {
    printf("A fila esta vazia.\n");
    return;
  }

  while (auxiliar != NULL)
  {
    posicao++;
    printf("%d. ", posicao);
    exibirMusica(&auxiliar->musica);
    auxiliar = auxiliar->proximo;
  }
}

// Conta quantas musicas ha na fila.
int contarFila(Fila *fila)
{
  NoFila *auxiliar = fila->inicio;
  int quantidade = 0;

  while (auxiliar != NULL)
  {
    quantidade++;
    auxiliar = auxiliar->proximo;
  }

  return quantidade;
}

// Libera todos os nos da fila e deixa inicio e fim NULL.
void esvaziarFila(Fila *fila)
{
  NoFila *auxiliar;

  while (fila->inicio != NULL)
  {
    auxiliar = fila->inicio;
    // Avanca o inicio antes do free, para nao perder o resto da fila.
    fila->inicio = fila->inicio->proximo;
    free(auxiliar);
  }

  fila->fim = NULL;
}

// Mostra inicio, fim e o endereco de cada no com o seu proximo (opcao 8 do menu).
// %p imprime um endereco de memoria; o (void *) e exigido pelo printf.
void exibirEstadoFila(Fila *fila)
{
  NoFila *auxiliar = fila->inicio;

  printf("\n===== ESTADO DA FILA =====\n");

  if (fila->inicio == NULL)
  {
    printf("Inicio: NULL\n");
  }
  else
  {
    printf("Inicio: %p (%s)\n", (void *)fila->inicio, fila->inicio->musica.titulo);
  }

  if (fila->fim == NULL)
  {
    printf("Fim: NULL\n");
  }
  else
  {
    printf("Fim: %p (%s)\n", (void *)fila->fim, fila->fim->musica.titulo);
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

// Roda os 6 testes do enunciado numa fila separada, sem mexer na fila do usuario.
void testarFila(Musica catalogo[])
{
  Fila teste;
  Musica musica;

  inicializarFila(&teste);

  printf("\n===== TESTES DA FILA =====\n");

  printf("\nTeste 1: consulta e remocao com a fila vazia\n");
  exibirInicioFila(&teste);
  desenfileirar(&teste, &musica);

  printf("\nTeste 2: insercao de tres musicas e ordem de saida\n");
  enfileirar(&teste, catalogo[0]);
  enfileirar(&teste, catalogo[1]);
  enfileirar(&teste, catalogo[2]);
  exibirFila(&teste);

  for (int i = 0; i < 3; i++)
  {
    if (desenfileirar(&teste, &musica) == 0)
    {
      printf("Saiu da fila: ");
      exibirMusica(&musica);
    }
  }

  printf("\nTeste 3: consulta sem alterar a fila\n");
  enfileirar(&teste, catalogo[3]);
  enfileirar(&teste, catalogo[4]);
  exibirInicioFila(&teste);
  exibirInicioFila(&teste);
  printf("Quantidade de musicas: %d\n", contarFila(&teste));
  exibirFila(&teste);

  printf("\nTeste 4: remocao do unico elemento\n");
  if (desenfileirar(&teste, &musica) == 0)
  {
    printf("Saiu da fila: ");
    exibirMusica(&musica);
  }

  exibirEstadoFila(&teste);

  if (desenfileirar(&teste, &musica) == 0)
  {
    printf("Saiu da fila: ");
    exibirMusica(&musica);
  }

  exibirEstadoFila(&teste);

  printf("\nTeste 5: nova insercao depois de esvaziar\n");
  enfileirar(&teste, catalogo[5]);
  exibirEstadoFila(&teste);

  printf("\nTeste 6: encerramento com musicas pendentes\n");
  enfileirar(&teste, catalogo[6]);
  enfileirar(&teste, catalogo[7]);
  printf("Musicas pendentes: %d\n", contarFila(&teste));
  esvaziarFila(&teste);
  printf("Fila esvaziada com sucesso.\n");
  exibirEstadoFila(&teste);
}
