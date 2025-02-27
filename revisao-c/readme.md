# Exercícios de revisão da linguagem C

Aqui estão alguns exercícios de revisão da linguagem C. Realizados na primeira semana do curso, a fim de apresentar o ambiente de desenvolvimento e preparar os alunos.

## `printf`

Revisando as funções `printf` e `scanf` da linguagem C. Ambas requerem o primeiro argumento, sendo o endereço de uma cadeia de caracteres. Em meio à string, podem haver especificações de conversão que, no caso de `printf`, descrevem como escrever os demais argumentos da função. Por exemplo, `printf("media=%d\n", contaX/contaY);` mostra os caracteres `media=` seguidos dos caracteres correspondentes à expressão `contaX/contaY`.

As conversões possíveis são mostradas na tabela:

| Código | Formato |
| -------- | ------- |
| `%c` | Caractere |
| `%d`, `%i` | Inteiros decimais com sinal |
| `%e`, `%E` | Notação científica (`e` minúsculo ou `E` maiúsculo) |
| `%f` | Ponto flutuante decimal |
| `%g`, `%G` | Usa `%e`/`%E` ou `%f`/`%F`, o que for mais curto |
| `%o` | Octal sem sinal |
| `%s` | String de caracteres |
| `%u` | Inteiros decimais sem sinal |
| `%x`, `%X` | Hexadecimal sem sinal (letras minúsculas ou maiúsculas) |
| `%p` | Apresenta um ponteiro |
| `%n` | O argumento associado é um ponteiro para inteiro no qual o número de caracteres escritos até esse ponto é colocado |
| `%%` | Escreve o símbolo `%` |   

Entre o `%` e o caractere de conversão, modificadores de formato podem ser adicionados. Por exemplo, ao colocar um número neste espaço, indicamos a largura mínima do campo que será exibido, preenchendo o valor com espaços caso seja preciso. Pode-se ainda colocar um zero antes do número para que o preenchimento seja com zeros, em vez de espaços.

Há também o especificador de precisão, consistindo num ponto seguido por um número, logo após a largura mínima de campo. Para numéros `float` ele especifica a quantidade de casas decimais; para strings, a quantidade máxima de caracteres; para inteiros, a quantidade de dígitos; e para notação científica, a quantidade de números significativos.

A justificação à esquerda é indicada por um sinal `-` logo depois do `%`. O modificador `#` pode ser usado para mostrar certos prefixos, e o modificador `*` serve para informar a largura mínima de campo e a precisão como argumentos.

## `scanf`

Os caracteres de especificação de conversão também são usados no primeiro argumento de `scanf`. Eles indicam as seguintes conversões:

| Código | Significado |
| -------- | ------- |
| `%c` | Lê um único caractere |
| `%d`, `%i` | Lê um inteiro decimal |
| `%e`, `%f`, `%g` | Lê um número em ponto flutuante |
| `%o` | Lê um número octal |
| `%s` | Lê uma string |
| `%x` | Lê um número hexadecimal |
| `%p` | Lê um ponteiro |
| `%n` | Recebe um valor inteiro igual ao número de caracteres lidos até então |
| `%u` | Lê um inteiro sem sinal |
| `%[]` | Busca por um conjunto de caracteres |

Assim como `printf` admite modificadores de formato, `scanf` também os aceita. Um número colocado entre `%` e o especificador, por exemplo, representa a largura máxima de campo. 

Pode-se também informar para a função ler um campo de entrada sem atribuí-lo a nenhuma variável com o modificador `*` precedendo o especificador, por exemplo `scanf("%d%*c%d", &x, &y)`. Um caractere, entre dois inteiros, será ignorado.

## Funções de alocação dinâmica de memória em C

Usamos alocação dinâmica quando um programa precisa de quantidades de armazenamento variáveis, decididas durante a execução. A memória alocada dinamicamente fica numa região chamada *heap* que fica entre o programa, a área de armazenamento permanente e a pilha (onde as variáveis locais são guardadas).

Em C, a alocação dinâmica é feita usando as funções `malloc()` e `free()`. A primeira reserva uma quantidade de memória e a segunda a libera, devolvendo ao sistema. Ambas estão declaradas no arquivo de cabeçalho `stdlib.h`. `malloc()` recebe como argumento a quantidade de bytes que se deseja alocar, e retorna um ponteiro para a primeira posição da região alocada. Ex:

```
char *p;
p = malloc(1000); /* obtém 1000 bytes */
```

Normalmente usamos `sizeof` para assegurar a portabilidade:

```
int *p;
p = malloc(50*sizeof(int)); /* aloca espaço para 50 inteiros */
```

Após o uso devemos liberar a memória com `free(p);`.
