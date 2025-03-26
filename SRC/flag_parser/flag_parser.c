/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** flag_parser.c
*/
#include "../../include/my.h"

void flag_u(char **argv, int j, flags_t *flag)
{
    flag->flag_u = true;
    if (argv[flag->i][j + 1] == '\0') {
        if (flag->i + 1 <= flag->argc - 1) {
            get_user(flag, argv[flag->i + 1]);
            flag->i++;
        } else
            exit(84);
    } else {
        get_user(flag, argv[flag->i] + (j + 1));
    }
}

void flag_g(char **argv, int j, flags_t *flag)
{
    flag->flag_g = true;
    if (argv[flag->i][j + 1] == '\0') {
        if (flag->i + 1 <= flag->argc - 1) {
            get_group(flag, argv[flag->i + 1]);
            flag->i++;
        } else
            exit(84);
    } else {
        get_group(flag, argv[flag->i] + (j + 1));
    }
}

int flag_checker(char **argv, int j, flags_t *flag)
{
    if (argv[flag->i][j] == 'u') {
        flag_u(argv, j, flag);
        return (1);
    }
    if (argv[flag->i][j] == 'g') {
        flag_g(argv, j, flag);
        return (1);
    }
    if (argv[flag->i][j] == 'E') {
        flag->flag_E = TRUE;
        return (0);
    }
    if (argv[flag->i][j] == 's') {
        flag->flag_s = TRUE;
        return (0);
    }
    print_help();
    exit(84);
    return (1);
}

int flag_parser(char **argv, flags_t *flag)
{
    for (int j = 1; argv[flag->i][j] != '\0'; j++) {
        if (flag_checker(argv, j, flag) == 1)
            return 0;
    }
    return 0;
}
