# Cria Manipula arquivo.txt

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
```

Essas são as bibliotecas que foram utilizadas no código para lidar com operações de entrada/saída, alocação de memória, manipulação de strings, controle de arquivos, permissões e tipos do sistema.

```C
#define MAX_LINE_LENGTH 256
#define FILE_NAME "arquivo.txt"
#define FILE_NEW "novo_arquivo.txt"
```

MAX_LINE_LENGTH define o tamanho máximo de cada linha do arquivo

FILE_NAME é o nome do arquivo original 

FILE_NEW é o nome do arquivo renomeado.

```C
void createFile()
```
Cria o arquivo de nome especificado em FILE_NAME. Ela utiliza a função open para criar o arquivo em modo de escrita (O_CREAT | O_WRONLY | O_TRUNC) com permissões de leitura e escrita para o usuário (S_IRUSR | S_IWUSR). Em seguida, a função close é chamada para fechar o descritor de arquivo e uma mensagem é exibida indicando que o arquivo foi criado com sucesso.

```C
void writeFile()
```
Escreve um milhão de linhas no arquivo criado anteriormente. Ela utiliza a função open para abrir o arquivo em modo de escrita (O_WRONLY | O_APPEND). Em seguida, um loop é executado para escrever cada linha no arquivo. A função write é utilizada para escrever a linha no arquivo e, em caso de erro, uma mensagem de erro é exibida. Ao final, o descritor de arquivo é fechado e uma mensagem de sucesso é exibida.

```C
void readFile()
```
Lê o conteúdo do arquivo e o exibe na saída padrão. Ela utiliza a função open para abrir o arquivo em modo de leitura (O_RDONLY). Em seguida, um loop é executado, lendo cada linha do arquivo utilizando a função read e exibindo-a na saída padrão. Quando não há mais linhas para ler, o loop é interrompido. Se ocorrer um erro durante a leitura, uma mensagem de erro é exibida. Ao final, o descritor de arquivo é fechado.

```C
void renameFile()
```
Renomeia o arquivo original para o novo nome especificado em FILE_NEW. Ela utiliza a função rename para fazer a renomeação e, em caso de erro, exibe uma mensagem de erro. Ao final, uma mensagem indicando o novo nome do arquivo é exibida.

```C
void seekLine(int lineNum)
```
Procura uma linha específica no arquivo renomeado (FILE_NEW) e imprime uma mensagem correspondente. Ela utiliza a função fopen para abrir o arquivo em modo de leitura ("r") e, em seguida, percorre as linhas do arquivo utilizando a função fgets. Se a linha desejada for encontrada, uma mensagem é exibida indicando isso. Caso contrário, uma mensagem informando que a linha não foi encontrada é exibida. Ao final, o arquivo é fechado.

```C
void deleteFile()
```
Exclui o arquivo renomeado (FILE_NEW). Ela utiliza a função remove para excluir o arquivo e, em caso de erro, exibe uma mensagem de erro. Ao final, uma mensagem indicando que o arquivo foi excluído é exibida.

```C
int main()
```
Aqui começa a função principal do programa. 

Ela chama as funções na seguinte ordem: 

1. createFile() para criar o arquivo
2. writeFile() para escrever as linhas no arquivo 
3. readFile() para ler e exibir o conteúdo do arquivo
4. renameFile() para renomear o arquivo
5. seekLine(1000000) para procurar a linha de número 1000000 no arquivo renomeado
6. truncate(FILE_NEW, 100) para truncar o arquivo para 100 bytes  
7. deleteFile() para excluir o arquivo renomeado. 

No final, o programa retorna 0, indicando que foi executado com sucesso.
