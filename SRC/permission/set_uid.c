/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** get uid user name
*/

#include "../../include/my.h"

int set_uid2(uid_t uid, FILE *file)
{
    if (setuid(uid) == -1) {
        perror("setuid");
        fclose(file);
        exit(84);
    }
    fclose(file);
    return 0;
}

int set_uid(const char *username)
{
    char line[256];
    char *user;
    uid_t uid;
    FILE *file = fopen("/etc/passwd", "r");

    if (!file)
        return 84;
    while (fgets(line, sizeof(line), file)) {
        user = strtok(line, ":");
        if (user && strcmp(user, username) == 0) {
            strtok(NULL, ":");
            uid = atoi(strtok(NULL, ":"));
            return set_uid2(uid, file);
        }
    }
    fclose(file);
    perror("Error: User not found.");
    return 84;
}
