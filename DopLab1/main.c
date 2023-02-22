#include <stdio.h>

int main() {
    FILE *fp;
    char path[1035];

    fp = popen("DEL need_to_remove.txt", "r"); // выполнить команду "dir" и открыть поток для чтения ее вывода
    if (fp == NULL) {
        printf("Ошибка выполнения команды\n");
        return 1;
    }

    while (fgets(path, sizeof(path)-1, fp) != NULL) { // читать вывод команды построчно
        printf("%s", path);
    }

    pclose(fp); // закрыть поток
    return 0;
}






