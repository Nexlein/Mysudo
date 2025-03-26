/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <crypt.h>
#include <shadow.h>
#include <stdbool.h>
#include <grp.h>

#ifndef MY_H
    #define MY_H

    #define MAX_LENGHT 255

typedef struct flags_s {
    char **command;
    bool flag_u;
    char *user_u;
    bool flag_E;
    bool flag_g;
    char *group_g;
    bool flag_s;
    int i;
    int argc;
    char *userpasswd;
    char **env;
    char *executer_u;
} flags_t;

int flag_parser(char **argv, flags_t *flag);
void get_user(flags_t *flag, char *user);
void get_group(flags_t *flag, char *group);
int my_execvp(flags_t *flag);
char *get_username(void);
char *get_userpasswd(void);
char *bash_parser(flags_t *flag);
int set_uid(const char *username);
int set_gid(const char *group_name);
int set_uid_gid(const char *username);
void make_sudo(flags_t *flag);
int my_execve(flags_t *flag);
int check_passwd(char *root_hash, char *attempt);
void get_command(flags_t *flag, int argc, char **argv);
void my_sys(flags_t *flag);
void my_sysve(flags_t *flag);
void print_help(void);
#endif /* MY_H */
