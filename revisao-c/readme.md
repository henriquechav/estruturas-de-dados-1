# Exercícios de revisão da linguagem C

Aqui estão alguns exercícios de revisão da linguagem C. Realizados na primeira semana do curso, a fim de apresentar o ambiente de desenvolvimento e preparar os alunos.

## `printf` e `scanf`

Revisando as funções `printf` e `scanf` da linguagem C. Ambas requerem o primeiro argumento, sendo o endereço de uma cadeia de caracteres. Em meio à string, podem haver especificações de conversão que, no caso de `printf`, descrevem como escrever os demais argumentos da função. Por exemplo, `printf("media=%d\n", contaX/contaY);` mostra os caracteres `media=` seguidos dos caracteres correspondentes à expressão `contaX/contaY`.

As conversões possíveis são mostradas na tabela:

| Caractere | Tipo do argumento; Escrito como |
| -------- | ------- |
| `d`, `i` | `int`; número decimal |
| `o` | `int`; número octal sem sinal (sem zero à esquerda) |
| `x`, `X` | `int`; número hexadecimal sem sinal (sem `0x` à esquerda) |
| `u` | `int`; número decimal sem sinal |
| `c` | `int`; único caractere |
| `s` | `char *`; escreve caracteres de uma string até um `\0` ou o número de caracteres dado pela precisão |
| `f` | `double`; [-]*m.dddddd*, onde o número de *d*'s é dado pela precisão (6 por padrão) |
| `e`, `E` | `double`; [-]*m.dddddd*E+/-*xx* |
| `g`, `G` | `double`; usa `%e` se o expoente é menor que -4 ou maior ou igual à precisão, do contrário usa `%f` |
| `%` | nenhum argumento é convertido, escreve um `%` |

Os caracteres de especificação de convesão também são usados no primeiro argumento de `scanf`. Eles indicam as seguintes conversões:

| Caractere | Dado de entrada; Tipo do argumento |
| -------- | ------- |
| `d` | inteiro decimal; `int *` |
| `i` | inteiro; `int *`. O inteiro pode estar em octal (0 à esquerda) ou hexadecimal (0x à esquerda) |
| `o` | inteiro octal (com ou sem zero à esquerda); `int *` |
| `u` | inteiro decimal sem sinal; `unsigned int *` |
| `x` | inteiro hexadecimal (com ou sem 0x à esquerda); `int *` |
| `c` | caracteres; `char *` |
| `s` | string sem aspas; `char *`, apontando para um vetor de caracteres longo o bastante para a string e o `'\0'` que será adicionado no final. |
| `e`, `f`, `g` | ponto flutuante com sinal opcional, parte fracionária opcional e expoente opcional; `float *` |
