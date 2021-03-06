#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/gestionEnregistrement.h"

char filename[100];

/**
 * @brief Create a Game File
 * 
 * @param joueur 
 */
void createGameFile(joueur joueur)
{
    char *str = malloc(sizeof(char));
    FILE *fp;
    strcpy(filename, FOLDER_NAME);
    strcat(filename, strcat(joueur.nom, ".csv"));

    fp = fopen(filename, "r+");
    if (fp != NULL)
    {
        fclose(fp);
        printf("Entrez un nom de fichier :");
        scanf("%s", str);
        strcpy(filename, FOLDER_NAME);
        strcat(filename, strcat(str, ".csv"));
        fp = fopen(filename, "r+");
        while (fp != NULL)
        {
            fclose(fp);
            printf("Veuillez saisir un nom de fichier disponible.");
            printf("\nEntrez un nom de fichier :");
            scanf("%s", str);
            strcpy(filename, FOLDER_NAME);
            strcat(filename, strcat(str, ".csv"));
            printf("%s\n", filename);
            fp = fopen(filename, "r+");
        }
    }
    fclose(fp);
    fp = fopen(filename, "w+");
    fclose(fp);

    free(str);
}
