#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 256
#define FILE_NAME "arquivo.txt"
#define FILE_NEW "novo_arquivo.txt"

// vai criar um arquivo.txt 
void createFile() {
    int fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Erro ao criar o arquivo");
        exit(1);
    }
    close(fd);
    printf("Arquivo criado: %s\n", FILE_NAME);
}

// vai escrever 1 milhão de linhas
void writeFile() {
    int fd = open(FILE_NAME, O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    for (int i = 1; i <= 1000000; i++) {
        char line[MAX_LINE_LENGTH];
        snprintf(line, MAX_LINE_LENGTH, "Linha %d\n", i);
        ssize_t bytesWritten = write(fd, line, strlen(line));
        if (bytesWritten == -1) {
            perror("Erro ao escrever no arquivo");
            exit(1);
        }
    }
    close(fd);
    printf("Arquivo escrito com sucesso.\n");
}

// vai ler o arquivo 
void readFile() {
    int fd = open(FILE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, line, sizeof(line) - 1)) > 0) {
        line[bytesRead] = '\0';
        printf("%s", line);
    }
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        exit(1);
    }
    close(fd);
}
// vai renomear o aqruivo para novo_arquivo.txt
void renameFile() {
    char newFileName[] = "novo_arquivo.txt";
    if (rename(FILE_NAME, newFileName) == -1) {
        perror("Erro ao renomear o arquivo");
        exit(1);
    }
    printf("Arquivo renomeado para: %s\n", newFileName);
}

// vai procurar a linha escolhida e mudar o nome dela
void seekLine(int lineNum) {
    FILE* file = fopen(FILE_NEW, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    for (int i = 1; i < lineNum; i++) {
        if (fgets(line, sizeof(line), file) == NULL) {
            printf("Linha %d não encontrada.\n", lineNum);
            fclose(file);
            return;
        }
    }
    if (fgets(line, sizeof(line), file) != NULL) {
        printf("Linha %d: NÃO AGUENTO MAIS AHHH.\n", lineNum);
    } else {
        printf("Linha %d não encontrada.\n", lineNum);
    }
    fclose(file);
}
// depois de truncar vai deletar o arquivo
 void deleteFile() {
    if (remove(FILE_NEW) == -1) {
        perror("Erro ao excluir o arquivo");
        exit(1);
    }
    printf("Arquivo excluído: %s\n", FILE_NEW);
} 

int main() {
    createFile();
    writeFile();
    readFile();
    renameFile();
    seekLine(1000000);
  
// vai truncar o arquivo para 100bytes
if (truncate(FILE_NEW, 100) == -1) {
        perror("Erro ao truncar o arquivo");
        exit(1);
    }
    printf("Arquivo truncado com sucesso.\n"); 

    deleteFile();
    return 0;
  
}
