/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-mysudo-nielsen.combe-bracciale
** File description:
** exec sudo with the corrects flags
*/

#include "../../include/my.h"

void make_sudo(flags_t *flag)
{
    if (flag->flag_s == true && flag->command == NULL) {
        if (flag->flag_E == true) {
            my_execve(flag);
        } else {
            my_execvp(flag);
        }
    } else {
        if (flag->flag_E == true) {
            my_sysve(flag);
        } else {
            my_sys(flag);
        }
    }
}
