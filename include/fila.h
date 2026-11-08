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

/* Estrutura independente da BST; IDs positivos repetidos são permitidos. */
void fila_inicializar(Fila *fila);
/* Retorna 1 quando insere e 0 em caso de ID inválido ou falha de alocação. */
int fila_enfileirar(Fila *fila, int id);
/* Retorna 1 quando remove, 0 quando vazia ou inválida. */
int fila_desenfileirar(Fila *fila, int *id_removido);
void fila_exibir(const Fila *fila);
void fila_liberar(Fila *fila);

#endif
