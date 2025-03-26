/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** check if passord is valid
*/

#include "../../include/my.h"

int check_passwd(char *user_hash, char *attempt)
{
    char *attempt_hash;

    if (user_hash == NULL || attempt == NULL)
        return 84;
    attempt_hash = crypt(attempt, user_hash);
    if (attempt_hash == NULL)
        return 84;
    if (strcmp(user_hash, attempt_hash) == 0)
        return 0;
    else
        return 84;
}
