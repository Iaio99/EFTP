#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


int get (void)
{
        return 1;
}

void list(void)
{
        DIR *dir;
        struct dirent *entry;

        // Apre la directory specificata
        dir = opendir();

        if (dir == NULL) {
            perror("Errore nell'apertura della directory\n");
            exit(EXIT_FAILURE);
        }

        // Legge ed elenca i file nella directory
        while ((entry = readdir(dir))) {
            if (entry->d_type == DT_REG)
                printf("%s\n", entry->d_name);
        }

        closedir(dir);
}

int put(void)
{
        return 1;
}