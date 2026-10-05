// Programa principal: menu do player e ligacao entre a fila e a pilha.
#include <stdio.h>
#include <stdlib.h>
#include "fila/fila.h"
#include "pilha/pilha.h"

void mostrarEstado(Fila *fila, Pilha *pilha);

int main(void)
{
    int opcao = -1;
    int quantidade_catalogo = 0;
    Musica catalogo[10];
    // fila = proximas musicas; historico = musicas ja tocadas.
    Fila fila;
    Pilha historico;

    inicializarFila(&fila);
    inicializarPilha(&historico);
    quantidade_catalogo = carregarCatalogo(catalogo);

    do
    {
        printf("\n====================================\n");
        printf("              SPOTIFY \n");
        printf("====================================\n");
        printf("1. Ver catalogo\n");
        printf("2. Adicionar na fila\n");
        printf("3. Proxima\n");
        printf("4. Voltar\n");
        printf("5. Ver proxima musica\n");
        printf("6. Limpar fila\n");
        printf("7. Ver ultima musica tocada\n");
        printf("8. Ver estado das estruturas\n");
        printf("0. Sair\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");

        // Se a pessoa digitar letra, descarta a linha e mostra o menu de novo.
        // opcao comeca em -1 para o do-while nao encerrar nesse caso.
        if (scanf("%d", &opcao) != 1)
        {
            while (getchar() != '\n')
            {
            }

            printf("\nEntrada invalida. Digite um numero.\n");
            continue;
        }

        switch (opcao)
        {
        case 1:
            exibirCatalogo(catalogo, quantidade_catalogo);
            break;

        // Adicionar: escolhe a musica pelo ID no catalogo e coloca no fim da fila.
        case 2:
        {
            int id = 0;
            Musica musica;

            exibirCatalogo(catalogo, quantidade_catalogo);
            printf("Digite o ID da musica: ");
            id = lerInteiro();

            if (buscarMusicaPorId(catalogo, quantidade_catalogo, id, &musica) == 0)
            {
                enfileirar(&fila, musica);
            }
            else
            {
                printf("Musica nao encontrada.\n");
            }
        }
        break;

        // Proxima: a musica sai do inicio da fila (FIFO) e vai para o topo do historico (LIFO).
        case 3:
        {
            Musica musica;

            if (desenfileirar(&fila, &musica) == 0)
            {
                printf("\nTocando agora: ");
                exibirMusica(&musica);
                empilhar(&historico, musica);
            }
        }
        break;

        // Voltar: tira a ultima musica do historico e toca de novo. Ela nao volta para a fila.
        case 4:
        {
            Musica musica;

            if (desempilhar(&historico, &musica) == 0)
            {
                printf("\nTocando novamente: ");
                exibirMusica(&musica);
            }
        }
        break;

        case 5:
            exibirInicioFila(&fila);
            break;

        case 6:
            esvaziarFila(&fila);
            printf("Fila esvaziada com sucesso.\n");
            break;

        case 7:
            exibirTopoPilha(&historico);
            break;

        case 8:
            mostrarEstado(&fila, &historico);
            break;

        // Sair: libera a fila e a pilha antes de encerrar.
        case 0:
            printf("\nLiberando memoria...\n");
            printf("Musicas pendentes na fila: %d\n", contarFila(&fila));
            printf("Musicas no historico: %d\n", contarPilha(&historico));
            esvaziarFila(&fila);
            esvaziarPilha(&historico);
            printf("Programa encerrado.\n");
            break;

        default:
            printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

// Mostra os ponteiros de controle da fila e da pilha (opcao 8).
void mostrarEstado(Fila *fila, Pilha *pilha)
{
    exibirEstadoFila(fila);
    exibirEstadoPilha(pilha);
}
