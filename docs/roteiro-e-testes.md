# Roteiro de implementação e testes

Use este arquivo para registrar os testes que você realmente executar: entrada, passos, resultado esperado e resultado observado. Os exemplos abaixo são casos mínimos sugeridos pelo enunciado.

## BST

| Caso | Preparação/entrada | Resultado esperado |
|---|---|---|
| Inserção e busca | Inserir IDs 40, 20 e 60; buscar 20 | Registro 20 encontrado |
| ID duplicado | Tentar inserir 20 novamente | Rejeitar sem alterar a árvore |
| Percurso em ordem | Árvore com 40, 20, 60 | Exibir 20, 40, 60 |
| Remoção de folha | Remover 20 da árvore acima | Remoção concluída; 40 e 60 permanecem |
| Remoção com um filho | Inserir 10 sob 20; remover 20 | Subárvore preservada e conectada |
| Remoção com dois filhos | Remover 40 de uma árvore com ambos os lados | Árvore continua válida e ordenada |
| ID inválido | Testar zero, negativo, texto e valor fora do intervalo de `int` | Rejeitar entrada e continuar o menu |

## Fila dinâmica

| Caso | Preparação/entrada | Resultado esperado |
|---|---|---|
| Ordem FIFO | Enfileirar 7, 3, 7; exibir | Mostrar 7, 3, 7 |
| Remoção | Desenfileirar uma vez | Remover 7 do início |
| Repetição | Enfileirar dois IDs iguais | Ambos permanecem na fila |
| Fila vazia | Exibir e tentar desenfileirar sem elementos | Informar que está vazia e continuar |
| Independência | Enfileirar ID inexistente na BST | Operação permitida, com validação numérica |

## Encerramento e memória

1. Encerrar com a BST e a fila vazias.
2. Encerrar com elementos nas duas estruturas.
3. Confirmar que a limpeza percorre e libera todos os nós.

## Registro dos resultados observados

Preencha após executar os testes no seu ambiente. Não copie resultados esperados como se fossem resultados observados.

- Sistema operacional:
- Compilador e versão:
- Comando de compilação:
- Teste:
- Resultado observado:
- Observações:
