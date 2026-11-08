# Roteiro de testes

## Testes automatizados

Compile e execute:

```sh
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude tests/test_estruturas.c src/bst.c src/fila.c -o teste_estruturas
./teste_estruturas
```

A suíte verifica inserção e busca na BST, duplicidade e ID inválido, a ordem crescente dos nós, remoção de folha, nó com um filho e nó com dois filhos, busca/remoção de ID ausente, além da ordem FIFO, IDs repetidos e operações sobre fila vazia. O workflow em `.github/workflows/testes.yml` compila o programa e verifica a listagem em ordem usando o menu.

## Testes manuais de entrada e menu

| Caso | Ações | Resultado esperado |
|---|---|---|
| Texto vazio | Tentar cadastrar nome vazio ou composto só por espaços | Rejeição e retorno ao menu |
| Texto longo | Informar mais de 79 caracteres | Rejeição sem corromper a entrada seguinte |
| ID textual | Digitar letras no campo de ID | Mensagem de ID inválido; programa continua |
| ID fora do intervalo | Informar um número maior que `INT_MAX` | Rejeição sem conversão inválida |
| Remoção ausente | Remover ID que não existe | Informar não encontrado e manter o programa ativo |
| Fila independente | Enfileirar ID positivo que não esteja na BST | ID aceito |
| Fila vazia | Exibir ou remover em fila vazia | Avisar e continuar |
| Encerramento | Encerrar com elementos nas estruturas | Todos os nós são liberados |

## Evidências observadas

Preencha os dados do seu ambiente e resultados locais:

- Sistema operacional:
- Compilador e versão:
- Comandos usados:
- Resultado do workflow do GitHub Actions:
- Casos manuais executados e resultados observados:
