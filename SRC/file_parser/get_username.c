/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** env parser
*/

#include "../../include/my.h"

char *get_username(void)
{
    FILE *fd = fopen("/etc/passwd", "r");
    size_t size = 0;
    int uid = getuid();
    char *buff = NULL;
    char *username = NULL;
    char *uid_str = NULL;

    if (fd == NULL)
        exit(84);
    while (getline(&buff, &size, fd) != -1) {
        username = strtok(buff, ":");
        strtok(NULL, ":");
        uid_str = strtok(NULL, ":");
        if (uid == atoi(uid_str)) {
            fclose(fd);
            return username;
        }
    }
    return NULL;
}
