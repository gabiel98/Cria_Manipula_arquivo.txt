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
cria o arquivo de nome especificado em FILE_NAME. Ela utiliza a função open para criar o arquivo em modo de escrita (O_CREAT | O_WRONLY | O_TRUNC) com permissões de leitura e escrita para o usuário (S_IRUSR | S_IWUSR). Em seguida, a função close é chamada para fechar o descritor de arquivo e uma mensagem é exibida indicando que o arquivo foi criado com sucesso.
