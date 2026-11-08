#include "entrada.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static ResultadoEntrada ler_linha(const char *prompt, char *buffer, size_t tamanho) {
    size_t comprimento;
    int caractere;

    fputs(prompt, stdout);
    fflush(stdout);

    if (fgets(buffer, (int)tamanho, stdin) == NULL) {
        return ENTRADA_FIM;
    }

    comprimento = strlen(buffer);
    if (comprimento > 0 && buffer[comprimento - 1] == '\n') {
        buffer[--comprimento] = '\0';
        if (comprimento > 0 && buffer[comprimento - 1] == '\r') {
            buffer[--comprimento] = '\0';
        }
    } else if (!feof(stdin)) {
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
            /* Descarta o restante de uma linha grande demais. */
        }
        return ENTRADA_INVALIDA;
    }

    return ENTRADA_OK;
}

static ResultadoEntrada converter_inteiro(const char *texto, long minimo, long maximo, int *valor) {
    char *fim;
    long convertido;

    errno = 0;
    convertido = strtol(texto, &fim, 10);
    if (texto == fim || errno == ERANGE || convertido < minimo || convertido > maximo) {
        return ENTRADA_INVALIDA;
    }

    while (isspace((unsigned char)*fim)) {
        ++fim;
    }
    if (*fim != '\0') {
        return ENTRADA_INVALIDA;
    }

    *valor = (int)convertido;
    return ENTRADA_OK;
}

ResultadoEntrada entrada_ler_id(const char *prompt, int *id) {
    char linha[128];
    ResultadoEntrada resultado = ler_linha(prompt, linha, sizeof linha);

    if (resultado != ENTRADA_OK) {
        if (resultado == ENTRADA_INVALIDA) {
            puts("Entrada muito longa. Tente novamente.");
        }
        return resultado;
    }

    resultado = converter_inteiro(linha, 1, INT_MAX, id);
    if (resultado != ENTRADA_OK) {
        puts("ID inválido. Informe um inteiro positivo dentro do intervalo de int.");
    }
    return resultado;
}

ResultadoEntrada entrada_ler_opcao(const char *prompt, int *opcao) {
    char linha[128];
    ResultadoEntrada resultado = ler_linha(prompt, linha, sizeof linha);

    if (resultado != ENTRADA_OK) {
        if (resultado == ENTRADA_INVALIDA) {
            puts("Opção muito longa.");
        }
        return resultado;
    }

    resultado = converter_inteiro(linha, 1, 8, opcao);
    if (resultado != ENTRADA_OK) {
        puts("Opção inválida. Escolha um número de 1 a 8.");
    }
    return resultado;
}

ResultadoEntrada entrada_ler_texto(const char *prompt, char texto[TAM_TEXTO]) {
    char linha[TAM_TEXTO + 1];
    ResultadoEntrada resultado = ler_linha(prompt, linha, sizeof linha);
    char *inicio;
    size_t comprimento;

    if (resultado != ENTRADA_OK) {
        if (resultado == ENTRADA_INVALIDA) {
            puts("Texto muito longo. O limite é 79 caracteres.");
        }
        return resultado;
    }

    inicio = linha;
    while (*inicio != '\0' && isspace((unsigned char)*inicio)) {
        ++inicio;
    }

    comprimento = strlen(inicio);
    while (comprimento > 0 && isspace((unsigned char)inicio[comprimento - 1])) {
        inicio[--comprimento] = '\0';
    }

    if (comprimento == 0) {
        puts("O texto não pode ficar vazio.");
        return ENTRADA_INVALIDA;
    }

    if (comprimento >= TAM_TEXTO) {
        puts("Texto muito longo. O limite é 79 caracteres.");
        return ENTRADA_INVALIDA;
    }

    memmove(texto, inicio, comprimento + 1);
    return ENTRADA_OK;
}
