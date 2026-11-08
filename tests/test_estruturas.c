#include "bst.h"
#include "fila.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static Registro registro(int id) {
    Registro r = {0};
    r.id = id;
    snprintf(r.nome, sizeof r.nome, "Local %d", id);
    strcpy(r.categoria, "teste");
    strcpy(r.bairro, "centro");
    return r;
}

static void testar_bst(void) {
    NoBST *raiz = NULL;
    Registro r40 = registro(40);
    Registro r20 = registro(20);
    Registro r60 = registro(60);
    Registro r10 = registro(10);
    Registro r30 = registro(30);
    Registro repetido = registro(40);

    assert(bst_inserir(&raiz, &r40) == 1);
    assert(bst_inserir(&raiz, &r20) == 1);
    assert(bst_inserir(&raiz, &r60) == 1);
    assert(bst_inserir(&raiz, &r10) == 1);
    assert(bst_inserir(&raiz, &r30) == 1);
    assert(bst_inserir(&raiz, &repetido) == 0);
    assert(bst_inserir(&raiz, &(Registro){.id = 0}) == -1);
    assert(bst_buscar(raiz, 30) != NULL);
    assert(bst_buscar(raiz, 30)->id == 30);
    assert(bst_buscar(raiz, 999) == NULL);

    /* Folha 10. */
    assert(bst_remover(&raiz, 10) == 1);
    assert(bst_buscar(raiz, 10) == NULL);

    /* Nó 20 tem um filho (30) após a remoção da folha 10. */
    assert(bst_remover(&raiz, 20) == 1);
    assert(bst_buscar(raiz, 20) == NULL);
    assert(bst_buscar(raiz, 30) != NULL);

    /* Raiz 40 tem dois filhos. */
    assert(bst_remover(&raiz, 40) == 1);
    assert(bst_buscar(raiz, 40) == NULL);
    assert(bst_buscar(raiz, 30) != NULL);
    assert(bst_buscar(raiz, 60) != NULL);

    assert(bst_remover(&raiz, 1234) == 0);
    assert(bst_remover(&raiz, 0) == 0);
    bst_liberar(raiz);
}

static void testar_fila(void) {
    Fila fila;
    int id;

    fila_inicializar(&fila);
    assert(fila.inicio == NULL && fila.fim == NULL);
    assert(fila_desenfileirar(&fila, &id) == 0);
    assert(fila_enfileirar(&fila, 7) == 1);
    assert(fila_enfileirar(&fila, 3) == 1);
    assert(fila_enfileirar(&fila, 7) == 1);
    assert(fila_desenfileirar(&fila, &id) == 1 && id == 7);
    assert(fila_desenfileirar(&fila, &id) == 1 && id == 3);
    assert(fila_desenfileirar(&fila, &id) == 1 && id == 7);
    assert(fila.inicio == NULL && fila.fim == NULL);
    assert(fila_desenfileirar(&fila, &id) == 0);
    assert(fila_enfileirar(&fila, 0) == 0);
    fila_liberar(&fila);
}

int main(void) {
    testar_bst();
    testar_fila();
    puts("Todos os testes automatizados passaram.");
    return 0;
}
