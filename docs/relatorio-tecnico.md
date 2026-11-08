# Relatorio tecnico - Sistema de cadastro de locais urbanos

**Disciplina:** Estrutura de Dados - ADS, 3o semestre  
**Linguagem:** C11  
**Tema:** B - Locais urbanos  
**Estruturas:** arvore binaria de busca (BST) e fila dinamica  
**Estudante:** Diego Gallo  
**Data:** 8 de novembro de 2026

## 1. Objetivo e modelagem

O programa de terminal cadastra locais urbanos por meio de uma BST ordenada pelo identificador. Cada registro guarda um ID inteiro, nome do local, categoria e bairro. Os campos textuais usam vetores char[80], permitindo no maximo 79 caracteres mais o terminador nulo. A entrada remove espacos nas extremidades e rejeita campos vazios.

Cada no da BST contem um registro e ponteiros para os filhos esquerdo e direito. IDs menores ficam na subarvore esquerda e IDs maiores na direita; IDs repetidos sao rejeitados. A estrutura linear escolhida e uma fila encadeada independente da BST. Cada no da fila armazena um ID positivo e um ponteiro para o proximo. A fila permite IDs repetidos e nao exige que o ID exista na arvore.

O menu apresenta cadastro, busca, remocao e percurso em ordem da BST, insercao e remocao da fila, exibicao da fila e encerramento. No encerramento, o programa libera os nos das duas estruturas.

## 2. Implementacao

O codigo e modularizado em include/ e src/. bst.c implementa insercao, busca, remocao e percurso em ordem. A remocao trata os casos sem filhos, com um filho e com dois filhos; neste ultimo, substitui o registro removido pelo sucessor em ordem e libera o no sucessor. O percurso em ordem exibe IDs crescentes.

fila.c insere no final e remove do inicio, mantendo ponteiros para inicio e fim. Ao remover o ultimo elemento, ambos voltam a nulo. A fila tambem tem exibicao e rotina de liberacao.

entrada.c le linhas com fgets e converte inteiros com strtol, verificando erros e limites. IDs aceitos sao positivos e cabem em int; o menu aceita opcoes de 1 a 8. Linhas longas demais, texto vazio e valores nao numericos sao rejeitados. main.c integra as estruturas.

## 3. Testes e evidencias

O workflow do GitHub Actions executou com sucesso no commit 1b0f346. Ele compilou aplicativo e testes com GCC usando -std=c11 -Wall -Wextra -pedantic.

A suite automatizada verificou insercao e busca; ID duplicado e zero na BST; ordem crescente dos nos; remocao de folha, no com um filho e no com dois filhos; IDs ausentes; comportamento FIFO; IDs repetidos; e fila vazia.

O teste integrado cadastrou os IDs 40, 20 e 60 pelo menu e confirmou a listagem 20, 40, 60. Outros casos integrados rejeitaram um ID textual (abc), rejeitaram um campo de texto com 80 caracteres e confirmaram insercao/remocao na fila e mensagens de fila vazia.

Os testes manuais adicionais em docs/roteiro-e-testes.md, como texto vazio e valor acima de INT_MAX, nao foram registrados como executados. A evidência automatizada do workflow esta disponivel no historico do repositorio.

## 4. Analise de complexidade

Seja n a quantidade de registros na BST, h a altura, q a quantidade de IDs na fila e L o tamanho do texto digitado.

| Operacao | Complexidade |
|---|---:|
| Busca, insercao e remocao na BST | O(h) |
| Caso medio de arvore aproximadamente equilibrada | O(log n) |
| BST degenerada, pior caso | O(n) |
| Percurso em ordem | O(n) |
| Enfileirar e desenfileirar | O(1) |
| Exibir a fila | O(q) |
| Validar ou copiar texto | O(L) |
| Memoria das estruturas | O(n + q) |

A BST nao e auto-balanceada. A ordem de insercao pode produzir uma arvore degenerada; nesse caso, operacoes da BST chegam a O(n).

## 5. Conclusao e ferramentas utilizadas

A implementacao aplica ponteiros, alocacao dinamica, modularizacao e as estruturas solicitadas. A suite e o workflow confirmaram os casos principais da BST, da fila, da validacao de texto longo, da fila vazia e da listagem ordenada. A limitacao principal e a ausencia de balanceamento automatico.

Utilizei uma ferramenta de IA como apoio para organizar o repositorio e redigir/revisar partes do codigo, dos testes e deste relatorio. O uso foi registrado no repositorio. O estudante deve compreender e explicar o codigo durante a demonstracao.
