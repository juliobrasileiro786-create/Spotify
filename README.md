Spotify de Terminal

Aplicação desenvolvida em C para simular um sistema de reprodução de músicas pelo terminal, utilizando Fila e Pilha como principais estruturas de dados.

O projeto foi desenvolvido como atividade prática da disciplina de Estrutura de Dados, com foco na aplicação de estruturas encadeadas, ponteiros e alocação dinâmica de memória em um cenário prático.

Sobre o projeto

O sistema permite gerenciar uma fila de reprodução e manter um histórico das músicas reproduzidas.

A Fila organiza as músicas que aguardam reprodução seguindo o princípio FIFO (First In, First Out), enquanto a Pilha armazena o histórico seguindo o princípio LIFO (Last In, First Out).

Dessa forma, o projeto demonstra como estruturas de dados podem ser utilizadas para representar funcionalidades comuns em sistemas de reprodução de músicas.

Funcionalidades
Visualização do catálogo de músicas
Adição de músicas à fila de reprodução
Reprodução da próxima música
Controle do histórico de músicas reproduzidas
Visualização da próxima música da fila
Limpeza da fila
Visualização da última música registrada no histórico
Visualização do estado das estruturas
Tratamento de entradas inválidas
Liberação da memória utilizada pelo programa

Estruturas de Dados
Fila — FIFO

A fila representa as músicas que estão aguardando reprodução.

A primeira música adicionada é a primeira a ser retirada.

Primeira → [A] → [B] → [C] → Última
Pilha — LIFO

A pilha representa o histórico das músicas reproduzidas.

A última música adicionada ao histórico fica no topo e é a primeira a ser retirada.

Topo
 ↓
[C]
 ↓
[B]
 ↓
[A]
🛠️ Tecnologias
C
GCC
Visual Studio Code
Ponteiros
struct
Alocação dinâmica de memória
Estruturas encadeadas

Como executar

Compile o projeto utilizando o GCC:

gcc main.c musicas.c fila/fila.c pilha/pilha.c -o spotify

Depois, execute:

.\spotify

Objetivo

Aplicar, de forma prática, os conceitos de Fila e Pilha, trabalhando também com:

Manipulação de ponteiros
Criação e utilização de nós
Alocação e liberação de memória
Organização de dados por meio de estruturas encadeadas
Modularização de um projeto em C
Tratamento de erros e entradas inválidas

Integrantes
Júlio César Brasileiro
Felipe Andrade
João Arnizaut
