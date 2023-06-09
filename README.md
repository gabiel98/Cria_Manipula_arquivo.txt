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
