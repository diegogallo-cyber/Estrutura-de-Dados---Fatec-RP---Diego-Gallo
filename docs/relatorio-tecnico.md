# Relatorio tecnico - Sistema de cadastro de locais urbanos

**Disciplina:** Estrutura de Dados - ADS, 3o semestre  
**Linguagem:** C11  
**Tema:** B - Locais urbanos  
**Estruturas:** arvore binaria de busca (BST) e fila dinamica  
**Estudante:** Diego Gallo  
**Data:** 8 de novembro de 2026

## 1. Objetivo e modelagem

O programa de terminal cadastra locais urbanos por meio de uma BST ordenada pelo identificador. Cada registro guarda um ID inteiro, nome do local, categoria e bairro. Os campos textuais usam vetores char[80], permitindo no maximo 79 caracteres e o terminador nulo. A entrada remove espacos nas extremidades e rejeita campos vazios.

Cada no da BST contem um registro e ponteiros para os filhos esquerdo e direito. Para cada no, IDs menores ficam na subarvore esquerda e IDs maiores na direita; IDs repetidos sao rejeitados. A estrutura linear escolhida e uma fila encadeada independente da BST. Cada no da fila armazena um ID positivo e um ponteiro para o proximo elemento. A fila permite IDs repetidos e nao exige que o ID esteja cadastrado na arvore.

O menu apresenta as operacoes de cadastro, busca, remocao e percurso em ordem da BST, insercao e remocao da fila, exibicao da fila e encerramento. O encerramento libera todos os nos alocados nas duas estruturas.

## 2. Implementacao

O codigo foi separado em include/ e src/. bst.c implementa insercao, busca, remocao e percurso em ordem. A remocao trata os casos sem filhos, com um filho e com dois filhos; neste ultimo, substitui o registro removido pelo sucessor em ordem e libera o no sucessor. O percurso em ordem exibe os IDs em ordem crescente.

fila.c insere no final e remove do inicio, mantendo ponteiros para o inicio e o fim. Ao remover o ultimo elemento, ambos os ponteiros voltam a nulo. A fila tambem tem exibicao e rotina de liberacao.

entrada.c le linhas com fgets, converte inteiros com strtol e verifica erros de conversao e limites. IDs aceitos sao positivos e cabem em int; o menu aceita opcoes de 1 a 8. Linhas grandes demais, texto vazio e valores nao numericos sao rejeitados. main.c integra as estruturas com o menu solicitado.

## 3. Testes e evidencias

O workflow do GitHub Actions compila o programa e os testes com GCC usando -std=c11 -Wall -Wextra -pedantic. No commit 7c99adf, a execucao do workflow terminou com sucesso.

A suite automatizada verificou:
- insercao e busca de registros;
- rejeicao de ID duplicado e ID zero na BST;
- ordem crescente dos IDs armazenados;
- remocao de folha, no com um filho e no com dois filhos;
- busca e remocao de IDs ausentes;
- comportamento FIFO, repeticao de IDs e fila vazia.

O teste de integracao pelo menu cadastrou os IDs 40, 20 e 60 e conferiu a listagem 20, 40, 60. O workflow compilou tanto o aplicativo quanto a suite e executou ambos sem erros.

O roteiro em docs/roteiro-e-testes.md tambem descreve entradas textuais invalidas, texto acima de 79 caracteres, valores fora do intervalo e encerramento com estruturas preenchidas. Esses casos manuais nao foram registrados como executados nesta evidencia automatizada.

## 4. Analise de complexidade

Seja n a quantidade de registros da BST, h a altura da arvore, q a quantidade de IDs na fila e L o tamanho do texto digitado.

| Operacao | Complexidade |
|---|---:|
| Buscar, inserir e remover na BST | O(h) |
| Caso medio de arvore aproximadamente equilibrada | O(log n) |
| BST degenerada, pior caso | O(n) |
| Listar todos os registros em ordem | O(n) |
| Enfileirar e desenfileirar | O(1) |
| Exibir a fila | O(q) |
| Validar ou copiar um campo textual | O(L) |
| Memoria das estruturas | O(n + q) |

A BST nao e auto-balanceada. A ordem de insercao pode produzir uma arvore degenerada, portanto as operacoes da BST podem chegar a O(n).

## 5. Conclusao e ferramentas utilizadas

A implementacao aplica ponteiros, alocacao dinamica, modularizacao e as duas estruturas solicitadas. Os testes automatizados confirmaram os casos principais da BST, da fila e da listagem ordenada pelo menu. A limitacao estrutural principal e a ausencia de balanceamento automatico da BST.

Utilizei uma ferramenta de IA como apoio para organizar a estrutura do repositorio, redigir e revisar partes do codigo, o roteiro de testes e este relatorio. O uso foi registrado no repositorio. O codigo deve ser explicado individualmente durante a demonstracao da disciplina.
