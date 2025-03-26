/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** get root passwd
*/

#include "../../include/my.h"

char *tok_passwd(char *root_line)
{
    char *token = NULL;

    if (root_line != NULL) {
        token = strtok(root_line, ":");
        token = strtok(NULL, ":");
        if (token != NULL) {
            root_line = strdup(token);
        } else {
            free(root_line);
            root_line = NULL;
        }
    }
    return token;
}

char *get_linepasswd(char *username, FILE *file)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int len_username = strlen(username);
    char *root_line = NULL;

    read = getline(&line, &len, file);
    while (read != -1) {
        if (strncmp(line, username, len_username) == 0) {
            root_line = strdup(line);
            break;
        }
        read = getline(&line, &len, file);
    }
    free(line);
    return root_line;
}

char *get_userpasswd(void)
{
    char *root_line = NULL;
    FILE *file = fopen("/etc/shadow", "r");
    char *username = get_username();

    if (file == NULL) {
        perror("fopen");
        return NULL;
    }
    root_line = get_linepasswd(username, file);
    fclose(file);
    return tok_passwd(root_line);
}
