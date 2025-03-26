/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** my_sudo.c
*/
#include "../../include/my.h"

void put_uid_gid(flags_t *flag)
{
    if (flag->flag_u == false && flag->flag_g == false)
        set_uid_gid(flag->user_u);
    if (flag->flag_u == true && flag->flag_g == false) {
        set_uid_gid(flag->user_u);
    }
    if (flag->flag_u == false && flag->flag_g == true) {
        set_gid(flag->group_g);
        setuid(getuid());
    }
    if (flag->flag_u == true && flag->flag_g == true) {
        set_gid(flag->group_g);
        set_uid(flag->user_u);
    }
}

void init_struct(flags_t *flag, char **env, int argc)
{
    flag->executer_u = get_username();
    flag->env = env;
    flag->user_u = "root";
    flag->group_g = "root";
    flag->flag_u = false;
    flag->flag_g = false;
    flag->flag_E = false;
    flag->userpasswd = get_userpasswd();
    flag->command = NULL;
    flag->argc = argc;
}

void error_handling(int argc, char **argv)
{
    if (argc == 1) {
        print_help();
        exit(84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        if (argc == 2) {
            print_help();
            exit(0);
        } else {
            print_help();
            exit(84);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    flags_t *flag;

    error_handling(argc, argv);
    flag = malloc(sizeof(flags_t));
    if (flag == NULL) {
        perror("malloc");
        return 84;
    }
    init_struct(flag, env, argc);
    for (flag->i = 1; flag->i < argc; flag->i++) {
        if (argv[flag->i][0] == '-')
            flag_parser(argv, flag);
        else
            break;
    }
    get_command(flag, argc, argv);
    put_uid_gid(flag);
    make_sudo(flag);
    return 0;
}
