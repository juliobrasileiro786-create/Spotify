// Implementacao das funcoes de musicas.h.
#include <stdio.h>
#include <string.h>
#include "musicas.h"

// Descarta o que sobrou digitado no teclado, ate o Enter.
void limparBuffer(void)
{
  int caractere;

  while ((caractere = getchar()) != '\n' && caractere != EOF)
  {
  }
}

// Le um numero inteiro. Se a pessoa digitar letras, limpa a entrada e pede de novo,
// em vez de travar o programa num loop infinito.
int lerInteiro(void)
{
  int valor = 0;

  // scanf devolve 1 quando consegue ler um numero e 0 quando recebe letras.
  while (scanf("%d", &valor) != 1)
  {
    limparBuffer();
    printf("Valor invalido. Digite novamente: ");
  }

  return valor;
}

// Monta e devolve uma Musica com os dados recebidos.
Musica criarMusica(int id, char titulo[], char artista[])
{
  Musica musica;

  musica.id = id;
  // Texto em C nao se copia com =, por isso o strcpy.
  strcpy(musica.titulo, titulo);
  strcpy(musica.artista, artista);

  return musica;
}

// Mostra uma musica em uma linha: ID: 3 | Titulo - Artista.
void exibirMusica(const Musica *musica)
{
  printf("ID: %d | %s - %s\n", musica->id, musica->titulo, musica->artista);
}

// Preenche o catalogo com as 10 musicas disponiveis e devolve a quantidade.
int carregarCatalogo(Musica catalogo[])
{
  catalogo[0] = criarMusica(1, "Evidencias", "Chitaozinho e Xororo");
  catalogo[1] = criarMusica(2, "Asa Branca", "Luiz Gonzaga");
  catalogo[2] = criarMusica(3, "Tempo Perdido", "Legiao Urbana");
  catalogo[3] = criarMusica(4, "Garota de Ipanema", "Tom Jobim");
  catalogo[4] = criarMusica(5, "Aquarela", "Toquinho");
  catalogo[5] = criarMusica(6, "Pais e Filhos", "Legiao Urbana");
  catalogo[6] = criarMusica(7, "Bohemian Rhapsody", "Queen");
  catalogo[7] = criarMusica(8, "Billie Jean", "Michael Jackson");
  catalogo[8] = criarMusica(9, "Blinding Lights", "The Weeknd");
  catalogo[9] = criarMusica(10, "Shape of You", "Ed Sheeran");

  return 10;
}

// Lista todas as musicas do catalogo.
void exibirCatalogo(Musica catalogo[], int quantidade)
{
  printf("\n===== CATALOGO =====\n");

  for (int i = 0; i < quantidade; i++)
  {
    exibirMusica(&catalogo[i]);
  }
}

// Procura a musica pelo ID. Se achar, copia para *musica e devolve 0; se nao, devolve 1.
// Nao imprime nada: a mensagem fica por conta do menu.
int buscarMusicaPorId(Musica catalogo[], int quantidade, int id, Musica *musica)
{
  for (int i = 0; i < quantidade; i++)
  {
    if (catalogo[i].id == id)
    {
      *musica = catalogo[i];
      return 0;
    }
  }

  return 1;
}
