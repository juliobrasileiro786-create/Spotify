// Tipo Musica e funcoes de leitura, criacao e catalogo de musicas.
#ifndef MUSICAS_H
#define MUSICAS_H

// Dados de uma musica. Os textos guardam ate 50 letras (+1 para o '\0' que marca o fim).
typedef struct
{
  int id;
  char titulo[51];
  char artista[51];
} Musica;

// Funcoes implementadas em musicas.c.
void limparBuffer(void);
int lerInteiro(void);
Musica criarMusica(int id, char titulo[], char artista[]);
void exibirMusica(const Musica *musica);
int carregarCatalogo(Musica catalogo[]);
void exibirCatalogo(Musica catalogo[], int quantidade);
int buscarMusicaPorId(Musica catalogo[], int quantidade, int id, Musica *musica);

#endif
