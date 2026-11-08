#ifndef BST_H
#define BST_H

#include "registro.h"

typedef struct NoBST {
    Registro registro;
    struct NoBST *esquerda;
    struct NoBST *direita;
} NoBST;

/* TODO: implementar cada operação em src/bst.c.
 * A BST deve ser ordenada pelo campo registro.id.
 */
int bst_inserir(NoBST **raiz, const Registro *registro);
const Registro *bst_buscar(const NoBST *raiz, int id);
int bst_remover(NoBST **raiz, int id);
void bst_listar_em_ordem(const NoBST *raiz);
void bst_liberar(NoBST *raiz);

#endif
