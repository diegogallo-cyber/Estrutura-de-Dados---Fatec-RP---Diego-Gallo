#include "bst.h"
#include "entrada.h"
#include "fila.h"

#include <stdio.h>

static int ler_id_ou_encerrar(int *id) {
    ResultadoEntrada resultado = entrada_ler_id("ID: ", id);
    if (resultado == ENTRADA_FIM) {
        return 0;
    }
    return resultado == ENTRADA_OK ? 1 : 2;
}

static int ler_texto_ou_encerrar(const char *prompt, char texto[TAM_TEXTO]) {
    ResultadoEntrada resultado = entrada_ler_texto(prompt, texto);
    if (resultado == ENTRADA_FIM) {
        return 0;
    }
    return resultado == ENTRADA_OK ? 1 : 2;
}

static int cadastrar(NoBST **raiz) {
    Registro registro = {0};
    int estado;

    estado = ler_id_ou_encerrar(&registro.id);
    if (estado == 0) return 0;
    if (estado == 2) return 1;
    if (bst_buscar(*raiz, registro.id) != NULL) {
        puts("Já existe um registro com esse ID.");
        return 1;
    }

    estado = ler_texto_ou_encerrar("Nome do local: ", registro.nome);
    if (estado == 0) return 0;
    if (estado == 2) return 1;

    estado = ler_texto_ou_encerrar("Categoria: ", registro.categoria);
    if (estado == 0) return 0;
    if (estado == 2) return 1;

    estado = ler_texto_ou_encerrar("Bairro: ", registro.bairro);
    if (estado == 0) return 0;
    if (estado == 2) return 1;

    estado = bst_inserir(raiz, &registro);
    if (estado == 1) {
        puts("Registro cadastrado.");
    } else if (estado == 0) {
        puts("ID duplicado; cadastro rejeitado.");
    } else {
        puts("Não foi possível alocar memória para o registro.");
    }
    return 1;
}

static int buscar(const NoBST *raiz) {
    int id;
    int estado = ler_id_ou_encerrar(&id);
    const Registro *registro;

    if (estado == 0) return 0;
    if (estado == 2) return 1;

    registro = bst_buscar(raiz, id);
    if (registro == NULL) {
        puts("Registro não encontrado.");
    } else {
        printf("ID: %d | Nome: %s | Categoria: %s | Bairro: %s\n",
               registro->id, registro->nome, registro->categoria, registro->bairro);
    }
    return 1;
}

static int remover(NoBST **raiz) {
    int id;
    int estado;

    if (*raiz == NULL) {
        puts("BST vazia.");
        return 1;
    }

    estado = ler_id_ou_encerrar(&id);
    if (estado == 0) return 0;
    if (estado == 2) return 1;

    if (bst_remover(raiz, id)) {
        puts("Registro removido.");
    } else {
        puts("ID não encontrado na BST.");
    }
    return 1;
}

static int inserir_fila(Fila *fila) {
    int id;
    int estado = ler_id_ou_encerrar(&id);

    if (estado == 0) return 0;
    if (estado == 2) return 1;

    if (fila_enfileirar(fila, id)) {
        puts("ID inserido no fim da fila.");
    } else {
        puts("Não foi possível inserir na fila (memória insuficiente).");
    }
    return 1;
}

static int remover_fila(Fila *fila) {
    int id;

    if (!fila_desenfileirar(fila, &id)) {
        puts("Fila vazia; nada foi removido.");
        return 1;
    }
    printf("ID %d removido do início da fila.\n", id);
    return 1;
}

static void exibir_menu(void) {
    puts("\n========================================");
    puts(" SISTEMA DE ESTRUTURA DE DADOS");
    puts("========================================");
    puts("1 - Cadastrar registro na BST");
    puts("2 - Buscar registro por ID na BST");
    puts("3 - Remover registro da BST");
    puts("4 - Listar registros em ordem");
    puts("5 - Inserir ID na fila");
    puts("6 - Remover da fila");
    puts("7 - Exibir fila");
    puts("8 - Encerrar");
}

int main(void) {
    NoBST *raiz = NULL;
    Fila fila;
    int opcao;
    int executar = 1;

    fila_inicializar(&fila);

    while (executar) {
        ResultadoEntrada resultado;
        exibir_menu();
        resultado = entrada_ler_opcao("Escolha uma opção: ", &opcao);

        if (resultado == ENTRADA_FIM) {
            break;
        }
        if (resultado != ENTRADA_OK) {
            continue;
        }

        switch (opcao) {
            case 1:
                executar = cadastrar(&raiz);
                break;
            case 2:
                executar = buscar(raiz);
                break;
            case 3:
                executar = remover(&raiz);
                break;
            case 4:
                if (raiz == NULL) puts("BST vazia.");
                else bst_listar_em_ordem(raiz);
                break;
            case 5:
                executar = inserir_fila(&fila);
                break;
            case 6:
                executar = remover_fila(&fila);
                break;
            case 7:
                fila_exibir(&fila);
                break;
            case 8:
                executar = 0;
                break;
        }
    }

    bst_liberar(raiz);
    fila_liberar(&fila);
    puts("Memória liberada. Programa encerrado.");
    return 0;
}
