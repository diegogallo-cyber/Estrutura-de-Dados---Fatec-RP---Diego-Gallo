#ifndef ENTRADA_H
#define ENTRADA_H

#include "registro.h"

typedef enum {
    ENTRADA_FIM = -1,
    ENTRADA_INVALIDA = 0,
    ENTRADA_OK = 1
} ResultadoEntrada;

ResultadoEntrada entrada_ler_id(const char *prompt, int *id);
ResultadoEntrada entrada_ler_opcao(const char *prompt, int *opcao);
ResultadoEntrada entrada_ler_texto(const char *prompt, char texto[TAM_TEXTO]);

#endif
