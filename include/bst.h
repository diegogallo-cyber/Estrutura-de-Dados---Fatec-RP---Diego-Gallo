#ifndef BST_H
#define BST_H

#include "registro.h"

typedef struct NoBST {
    Registro registro;
    struct NoBST *esquerda;
    struct NoBST *direita;
} NoBST;

enum {
    BST_ERRO = -1,
    BST_DUPLICADO = 0,
    BST_OK = 1
};

/* A BST é ordenada pelo ID e rejeita IDs repetidos. */
int bst_inserir(NoBST **raiz, const Registro *registro);
const Registro *bst_buscar(const NoBST *raiz, int id);
int bst_remover(NoBST **raiz, int id);
void bst_listar_em_ordem(const NoBST *raiz);
void bst_liberar(NoBST *raiz);

#endif
