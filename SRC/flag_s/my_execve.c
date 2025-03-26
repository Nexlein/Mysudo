/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** execve
*/

#include "../../include/my.h"

void call_execve(flags_t *flag)
{
    char *path = bash_parser(flag);

    if (execve(path, flag->command, flag->env) == -1) {
        perror("execve");
        return;
    }
    free(path);
}

void is_root_execve(flags_t *flag)
{
    if (strcmp(flag->executer_u, "root") == 0) {
        call_execve(flag);
        exit(0);
    }
}

int my_execve(flags_t *flag)
{
    char *password;
    char *userpasswd = flag->userpasswd;
    int try = 0;

    is_root_execve(flag);
    while (try < 3) {
        printf("[my_sudo] password for %s: ", flag->executer_u);
        password = getpass("");
        if (check_passwd(userpasswd, password) == 0) {
            call_execve(flag);
            exit(0);
        }
        if (check_passwd(userpasswd, password) != 0 && try < 2)
            fprintf(stderr, "Sorry, try again.\n");
        try++;
    }
    fprintf(stderr, "my_sudo: 3 incorrect password attempts\n");
    exit(84);
}
