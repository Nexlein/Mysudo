/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** env parser
*/

#include "../../include/my.h"

char *tok_bash(char *user_line)
{
    char *token = NULL;
    int end = 0;
    int len = 0;

    if (user_line != NULL) {
        token = strtok(user_line, ":");
        while (token[len - 1] != '\n') {
            token = strtok(NULL, ":");
            len = strlen(token);
        }
        if (token != NULL) {
            user_line = strdup(token);
            end = strlen(user_line);
            user_line[end - 1] = '\0';
        } else {
            free(user_line);
            user_line = NULL;
        }
    }
    return user_line;
}

char *get_linebash(char *username, FILE *file)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int len_username = strlen(username);
    char *user_line = NULL;

    read = getline(&line, &len, file);
    while (read != -1) {
        if (strncmp(line, username, len_username) == 0) {
            user_line = strdup(line);
            break;
        }
        read = getline(&line, &len, file);
    }
    free(line);
    return user_line;
}

char *bash_parser(flags_t *flag)
{
    char *user_line = NULL;
    FILE *file = fopen("/etc/passwd", "r");

    if (file == NULL) {
        perror("fopen");
        return NULL;
    }
    user_line = get_linebash(flag->user_u, file);
    fclose(file);
    return tok_bash(user_line);
}
