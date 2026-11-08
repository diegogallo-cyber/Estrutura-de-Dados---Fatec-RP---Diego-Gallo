#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    int id;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

/* TODO: implementar em src/fila.c.
 * A fila é independente da BST e aceita IDs repetidos.
 */
void fila_inicializar(Fila *fila);
int fila_enfileirar(Fila *fila, int id);
int fila_desenfileirar(Fila *fila, int *id_removido);
void fila_exibir(const Fila *fila);
void fila_liberar(Fila *fila);

#endif
