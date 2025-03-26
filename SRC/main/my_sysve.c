/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** my_sys.c
*/
#include "../../include/my.h"

void call_sysve(flags_t *flag)
{
    if (execve(flag->command[0], flag->command, flag->env) == -1) {
        perror("execve");
        exit(84);
    }
}

void is_root_sysve(flags_t *flag)
{
    if (strcmp(flag->executer_u, "root") == 0) {
        call_sysve(flag);
        exit(0);
    }
}

void my_sysve(flags_t *flag)
{
    char *password;
    char *userpasswd = flag->userpasswd;
    int try = 0;

    is_root_sysve(flag);
    while (try < 3) {
        printf("[my_sudo] password for %s: ", flag->executer_u);
        password = getpass("");
        if (check_passwd(userpasswd, password) == 0) {
            call_sysve(flag);
            exit(0);
        }
        if (check_passwd(userpasswd, password) != 0 && try < 2)
            fprintf(stderr, "Sorry, try again.\n");
        try++;
    }
    fprintf(stderr, "my_sudo: 3 incorrect password attempts\n");
    exit(84);
}
