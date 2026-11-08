# Projeto de Estruturas de Dados — Locais urbanos

Programa de terminal em C11 para cadastrar locais urbanos em uma árvore binária de busca (BST) e guardar IDs em uma fila dinâmica.

> O projeto foi desenvolvido com apoio de IA, conforme orientação do professor. O estudante deve revisar a implementação, executar os testes, completar o relatório com seus próprios resultados e estar preparado para explicar as decisões e o funcionamento.

## Tema e regras

- **Tema B — Locais urbanos**
- Registro: ID, nome do local, categoria e bairro.
- BST própria ordenada pelo ID: inserir, buscar, remover (zero, um ou dois filhos) e listar em ordem.
- Fila dinâmica própria, independente da BST. A fila armazena inteiros positivos, aceita repetidos e não exige que o ID exista na BST.
- Textos são armazenados em `char[80]`: até 79 caracteres mais o terminador nulo.
- IDs devem ser positivos e caber em `int`. IDs repetidos são rejeitados na BST.
- O menu usa a opção **8 — Encerrar**, conforme o enunciado.

## Organização

```text
include/registro.h
include/bst.h
include/fila.h
include/entrada.h
src/bst.c
src/fila.c
src/entrada.c
src/main.c
tests/test_estruturas.c
docs/roteiro-e-testes.md
docs/uso-de-ia.md
docs/relatorio-tecnico.pdf (a gerar após registrar os resultados observados)
.github/workflows/testes.yml
```

## Compilar e executar

Com GCC:

```sh
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude src/main.c src/bst.c src/fila.c src/entrada.c -o locais
./locais
```

No Windows com MinGW:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude src/main.c src/bst.c src/fila.c src/entrada.c -o locais.exe
.\locais.exe
```

## Testes automatizados

```sh
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude tests/test_estruturas.c src/bst.c src/fila.c -o teste_estruturas
./teste_estruturas
```

A suíte verifica inserção, busca, IDs repetidos e inválidos, ordem da BST, remoção de folha/nó com um filho/nó com dois filhos e comportamento FIFO da fila. O workflow do GitHub Actions também compila o programa e faz um teste de listagem em ordem pelo menu.

## Complexidade

Para uma BST sem balanceamento, inserir, buscar e remover custam O(h), onde h é a altura: O(log n) em uma árvore aproximadamente equilibrada e O(n) no pior caso. O percurso em ordem custa O(n). Na fila encadeada, enfileirar e desenfileirar custam O(1); exibir todos os IDs custa O(q). O uso total de memória é O(n + q).

## Relatório e autoria

O enunciado pede um relatório técnico em PDF de 2 a 4 páginas. Registre nele as ferramentas utilizadas (incluindo o apoio de IA), os testes que você realmente executou e os resultados observados. O roteiro de testes ajuda a coletar essa evidência. O histórico Git deve representar o desenvolvimento real; não invente etapas ou resultados.
