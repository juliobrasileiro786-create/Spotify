Spotify de Terminal

Projeto desenvolvido para a disciplina de Estrutura de Dados, com o objetivo de aplicar as estruturas de Fila (FIFO) e Pilha (LIFO) em um sistema simples de reprodução de músicas pelo terminal.

Sobre o projeto

O programa simula um pequeno player de músicas no terminal.

O usuário pode visualizar um catálogo de músicas, adicionar músicas a uma fila de reprodução e controlar o histórico das músicas reproduzidas.

A fila é utilizada para organizar as próximas músicas que serão reproduzidas, enquanto a pilha armazena o histórico das músicas que já foram tocadas.

Estruturas utilizadas

Fila -

A fila segue o princípio FIFO (First In, First Out).

A primeira música adicionada à fila é a primeira a ser retirada para reprodução.

Pilha -

A pilha segue o princípio LIFO (Last In, First Out).

A última música colocada no histórico fica no topo e é a primeira a ser retirada.

Cada nó das estruturas armazena uma Musica e um ponteiro para o próximo nó.

Funcionalidades

O sistema possui as seguintes opções:

1-Ver catálogo — exibe as músicas disponíveis.
2-Adicionar à fila — adiciona uma música escolhida pelo ID à fila.
3-Próxima — retira a primeira música da fila e adiciona ao histórico.
4-Voltar — retira a música que está no topo do histórico.
5-Ver próxima música — mostra a primeira música da fila sem removê-la.
6-Limpar fila — remove as músicas que estão aguardando na fila.
7-Ver última música tocada — mostra a música que está no topo da pilha sem removê-la.
8-Ver estado das estruturas — exibe informações sobre a fila e a pilha.
0-Sair — encerra o programa e libera a memória utilizada.

Principais estruturas

Música

A estrutura Musica armazena:

ID
Título
Artista
Nó da fila

Cada NoFila possui:

Uma música
Ponteiro para o próximo nó
Nó da pilha

Cada NoPilha possui:

Uma música
Ponteiro para o próximo nó

Tecnologias -
Linguagem C
GCC
Visual Studio Code
Estruturas de Dados
Alocação dinâmica de memória

Compilação

No terminal, dentro da pasta do projeto:

gcc main.c musicas.c fila/fila.c pilha/pilha.c -o spotify

Depois, execute:

.\spotify
Objetivo acadêmico

O projeto busca demonstrar, de forma prática, o funcionamento das estruturas de dados fila e pilha, utilizando nós encadeados e alocação dinâmica de memória.

Além disso, o projeto trabalha conceitos como:

struct
ponteiros
nós encadeados
malloc
free
FIFO
LIFO
manipulação de strings
organização de arquivos em C
tratamento de entradas inválidas

Integrantes -
Júlio César Brasileiro
Felipe Andrade
João Arnizaut
