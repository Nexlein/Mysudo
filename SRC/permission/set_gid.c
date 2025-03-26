/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** set gid by group name
*/

#include "../../include/my.h"

int set_gid2(char *gid_str, FILE *file)
{
    gid_t gid;

    if (gid_str) {
        gid = (gid_t)atoi(gid_str);
        if (setgid(gid) == -1) {
            perror("setgid");
            fclose(file);
            return 84;
        }
        fclose(file);
        return 0;
    }
    return 0;
}

int set_gid(const char *group_name)
{
    FILE *file = fopen("/etc/group", "r");
    char line[256];
    char *name;
    char *gid_str;

    if (!file)
        return 84;
    while (fgets(line, sizeof(line), file)) {
        name = strtok(line, ":");
        if (name && strcmp(name, group_name) == 0) {
            strtok(NULL, ":");
            gid_str = strtok(NULL, ":");
            return set_gid2(gid_str, file);
        }
    }
    fclose(file);
    perror("Error: Group not found.");
    return 84;
}
