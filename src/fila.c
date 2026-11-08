#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

void fila_inicializar(Fila *fila) {
    if (fila == NULL) {
        return;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}

int fila_enfileirar(Fila *fila, int id) {
    NoFila *novo;

    if (fila == NULL || id <= 0) {
        return 0;
    }

    novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return 0;
    }

    novo->id = id;
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
    return 1;
}

int fila_desenfileirar(Fila *fila, int *id_removido) {
    NoFila *removido;

    if (fila == NULL || fila->inicio == NULL) {
        return 0;
    }

    removido = fila->inicio;
    if (id_removido != NULL) {
        *id_removido = removido->id;
    }

    fila->inicio = removido->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(removido);
    return 1;
}

void fila_exibir(const Fila *fila) {
    const NoFila *atual;

    if (fila == NULL || fila->inicio == NULL) {
        puts("Fila vazia.");
        return;
    }

    printf("Início -> ");
    for (atual = fila->inicio; atual != NULL; atual = atual->proximo) {
        printf("%d", atual->id);
        if (atual->proximo != NULL) {
            printf(" -> ");
        }
    }
    puts(" -> Fim");
}

void fila_liberar(Fila *fila) {
    int id_ignorado;

    if (fila == NULL) {
        return;
    }
    while (fila_desenfileirar(fila, &id_ignorado)) {
        /* Cada nó é liberado por fila_desenfileirar. */
    }
}
