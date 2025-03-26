/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** get_command.c
*/
#include "../../include/my.h"

int count_command(flags_t *flag, int argc)
{
    int j = 0;

    for (int i = flag->i; i < argc; i++)
        j++;
    if (j == 0 && flag->flag_s == false) {
        print_help();
        exit(84);
    }
    if (j == 0 && flag->flag_s == true)
        return 1;
    flag->command = malloc(sizeof(char *) * (j));
    if (flag->command == NULL) {
        perror("malloc");
        exit(84);
    }
    return 0;
}

void get_command(flags_t *flag, int argc, char **argv)
{
    int k = 0;
    int lencmd = 0;

    if (count_command(flag, argc) == 1)
        return;
    for (; flag->i < argc; flag->i++) {
        lencmd = strlen(argv[flag->i]);
        flag->command[k] = malloc(sizeof(char) * (lencmd + 1));
        if (flag->command[k] == NULL) {
            perror("malloc");
            exit(84);
        }
        flag->command[k] = argv[flag->i];
        k++;
    }
    flag->command[k] = NULL;
}
