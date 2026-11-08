#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

static NoBST *criar_no(const Registro *registro) {
    NoBST *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return NULL;
    }

    novo->registro = *registro;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

int bst_inserir(NoBST **raiz, const Registro *registro) {
    NoBST *atual;

    if (raiz == NULL || registro == NULL || registro->id <= 0) {
        return -1;
    }

    atual = *raiz;
    if (atual == NULL) {
        *raiz = criar_no(registro);
        return *raiz == NULL ? -1 : 1;
    }

    while (1) {
        if (registro->id == atual->registro.id) {
            return 0;
        }
        if (registro->id < atual->registro.id) {
            if (atual->esquerda == NULL) {
                atual->esquerda = criar_no(registro);
                return atual->esquerda == NULL ? -1 : 1;
            }
            atual = atual->esquerda;
        } else {
            if (atual->direita == NULL) {
                atual->direita = criar_no(registro);
                return atual->direita == NULL ? -1 : 1;
            }
            atual = atual->direita;
        }
    }
}

const Registro *bst_buscar(const NoBST *raiz, int id) {
    const NoBST *atual = raiz;

    while (atual != NULL) {
        if (id == atual->registro.id) {
            return &atual->registro;
        }
        atual = id < atual->registro.id ? atual->esquerda : atual->direita;
    }
    return NULL;
}

static NoBST *extrair_menor(NoBST **raiz) {
    NoBST *menor;

    if ((*raiz)->esquerda == NULL) {
        menor = *raiz;
        *raiz = menor->direita;
        return menor;
    }
    return extrair_menor(&(*raiz)->esquerda);
}

static int remover_recursivo(NoBST **raiz, int id) {
    NoBST *alvo;
    NoBST *sucessor;

    if (*raiz == NULL) {
        return 0;
    }

    if (id < (*raiz)->registro.id) {
        return remover_recursivo(&(*raiz)->esquerda, id);
    }
    if (id > (*raiz)->registro.id) {
        return remover_recursivo(&(*raiz)->direita, id);
    }

    alvo = *raiz;
    if (alvo->esquerda == NULL) {
        *raiz = alvo->direita;
        free(alvo);
        return 1;
    }
    if (alvo->direita == NULL) {
        *raiz = alvo->esquerda;
        free(alvo);
        return 1;
    }

    sucessor = extrair_menor(&alvo->direita);
    alvo->registro = sucessor->registro;
    free(sucessor);
    return 1;
}

int bst_remover(NoBST **raiz, int id) {
    if (raiz == NULL || id <= 0) {
        return 0;
    }
    return remover_recursivo(raiz, id);
}

void bst_listar_em_ordem(const NoBST *raiz) {
    if (raiz == NULL) {
        return;
    }

    bst_listar_em_ordem(raiz->esquerda);
    printf("ID: %d | Nome: %s | Categoria: %s | Bairro: %s\n",
           raiz->registro.id,
           raiz->registro.nome,
           raiz->registro.categoria,
           raiz->registro.bairro);
    bst_listar_em_ordem(raiz->direita);
}

void bst_liberar(NoBST *raiz) {
    if (raiz == NULL) {
        return;
    }

    bst_liberar(raiz->esquerda);
    bst_liberar(raiz->direita);
    free(raiz);
}
