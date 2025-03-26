/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** get_user_and_group.c
*/
#include "../../include/my.h"

FILE *open_path(char *path)
{
    FILE *stream = fopen(path, "r");

    if (stream == NULL) {
        perror("fopen");
        exit(84);
    }
    return stream;
}

void exist(char *value, char *path)
{
    FILE *stream = open_path(path);
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stream);
    while (nread != -1) {
        sscanf(line, "%[^:]", line);
        if (strcmp(line, value) == 0) {
            fclose(stream);
            free(line);
            return;
        }
        nread = getline(&line, &len, stream);
    }
    printf("%s doesn't exist\n", value);
    fclose(stream);
    free(line);
    exit(84);
}

void get_user(flags_t *flag, char *user)
{
    exist(user, "/etc/shadow");
    flag->user_u = malloc(sizeof(char) * strlen(user));
    if (flag->user_u == NULL) {
        perror("malloc");
        return;
    }
    flag->user_u = user;
}

void get_group(flags_t *flag, char *group)
{
    exist(group, "/etc/group");
    flag->group_g = malloc(sizeof(char) * strlen(group));
    if (flag->group_g == NULL) {
        perror("malloc");
        return;
    }
    flag->group_g = group;
}
