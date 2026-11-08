# Roteiro de testes

## Testes automatizados

Compile e execute:

```sh
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude tests/test_estruturas.c src/bst.c src/fila.c -o teste_estruturas
./teste_estruturas
```

A saída esperada é `Todos os testes automatizados passaram.`. Registre no relatório a saída que você observar ao executar o comando no seu ambiente.

A suíte cobre inserção e busca na BST, ID repetido e inválido, remoção de folha, nó com um filho e nó com dois filhos, busca e remoção de ID ausente, além da ordem FIFO, repetição de IDs e operações sobre fila vazia.

## Testes manuais do menu

| Caso | Ações | Resultado esperado |
|---|---|---|
| Texto vazio | Tentar cadastrar nome vazio ou composto só por espaços | Rejeição e retorno ao menu |
| Texto longo | Informar mais de 79 caracteres | Rejeição sem corromper a entrada seguinte |
| ID textual | Digitar letras no campo de ID | Mensagem de ID inválido; programa continua |
| ID fora do intervalo | Informar um número maior que `INT_MAX` | Rejeição sem conversão inválida |
| Ordenação | Cadastrar IDs 40, 20, 60 e escolher listagem | Mostrar 20, 40, 60 |
| Remoção | Remover ID inexistente e depois um existente | Mensagens adequadas; menu continua |
| Fila independente | Enfileirar ID positivo que não esteja na BST | ID aceito |
| Fila vazia | Exibir ou remover em fila vazia | Avisar e continuar |
| Encerramento | Encerrar com elementos nas estruturas | Todos os nós são liberados |

## Evidências observadas

Preencha após executar no seu ambiente:

- Sistema operacional:
- Compilador e versão:
- Comandos usados:
- Saída observada dos testes automatizados:
- Casos manuais executados e resultados:
