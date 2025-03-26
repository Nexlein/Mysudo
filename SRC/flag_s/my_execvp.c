/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** execvp
*/

#include "../../include/my.h"

void call_execvp(flags_t *flag)
{
    char *path = bash_parser(flag);

    if (execvp(path, flag->command) == -1) {
        perror("execve");
        return;
    }
    free(path);
}

void is_root_execvp(flags_t *flag)
{
    if (strcmp(flag->executer_u, "root") == 0) {
        call_execvp(flag);
        exit(0);
    }
}

int my_execvp(flags_t *flag)
{
    char *password;
    char *userpasswd = flag->userpasswd;
    int try = 0;

    is_root_execvp(flag);
    while (try < 3) {
        printf("[my_sudo] password for %s: ", flag->executer_u);
        password = getpass("");
        if (check_passwd(userpasswd, password) == 0) {
            call_execvp(flag);
            exit(0);
        }
        if (check_passwd(userpasswd, password) != 0 && try < 2)
            fprintf(stderr, "Sorry, try again.\n");
        try++;
    }
    fprintf(stderr, "my_sudo: 3 incorrect password attempts\n");
    exit(84);
}
