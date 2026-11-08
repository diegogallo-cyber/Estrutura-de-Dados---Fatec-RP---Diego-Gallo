# Projeto de Estruturas de Dados — Locais urbanos

> **Estado:** estrutura inicial de estudo. O programa está incompleto e ainda não atende aos requisitos para entrega.

Projeto individual da disciplina de Estrutura de Dados (C11), com uma árvore binária de busca (BST) para registros de locais urbanos e uma fila dinâmica implementada manualmente.

## Tema e estruturas

- **Tema B — Locais urbanos**
- Registro: ID inteiro, nome do local, categoria e bairro.
- BST própria, ordenada pelo ID.
- Fila dinâmica própria, independente da BST; ela armazena IDs e permite repetidos.

Os textos devem respeitar o limite do enunciado: campos com até 79 caracteres mais o terminador nulo em vetores `char[80]`. IDs devem ser inteiros positivos dentro do intervalo de `int`. A BST rejeita IDs duplicados; a fila não.

## Organização

```text
include/registro.h  definição do registro
include/bst.h       interface da BST
include/fila.h      interface da fila
src/bst.c           implementação da BST (pendente)
src/fila.c          implementação da fila (pendente)
src/main.c          menu e integração (pendentes)
docs/roteiro-e-testes.md
```

## Próximas etapas

1. Implementar e testar a inserção, a busca e a remoção da BST (zero, um e dois filhos).
2. Implementar o percurso em ordem e confirmar que os IDs aparecem em ordem crescente.
3. Implementar enfileirar, desenfileirar e exibir do início ao fim, incluindo a fila vazia.
4. Criar o menu único pedido no enunciado e validar as entradas sem encerrar o programa por erro.
5. Liberar todos os nós alocados ao encerrar.
6. Executar e registrar os casos do roteiro em [docs/roteiro-e-testes.md](docs/roteiro-e-testes.md).
7. Atualizar este README com os comandos que você usou para compilar e executar no seu sistema.
8. Produzir o relatório técnico de 2 a 4 páginas e anexá-lo no Classroom conforme o enunciado.

## Compilação

A compilação final deve usar um compilador C11, por exemplo:

```sh
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude src/main.c src/bst.c src/fila.c -o locais
```

Esse comando só deve ser usado depois que as funções pendentes estiverem implementadas.

## Histórico e autoria

Esta base foi preparada como ponto de partida de estudo. Continue o histórico com commits que registrem o seu progresso real, revise cada trecho e siga as regras da disciplina sobre declaração de ferramentas utilizadas. Não apresente esta estrutura incompleta como implementação pronta.
