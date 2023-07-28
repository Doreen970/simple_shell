#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>


#define PATH_COMMAND 3
#define INVALID_COMMAND -1
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * struct area - maps a command name to a function
 *
 * @cmd: name of the command
 * @func: function that implements the command
 */
typedef struct area
{
	char *cmd;
	void (*func)(char **command);
} funs_area;

extern char **environ;
extern char *line;
extern char **commands;
extern char *my_shell;
extern int status;

void _write(char *str, int stm);
char **tokenizer(char *cmd, char *delim);
void no_nl(char *str);
int my_strlen(char *str);
void my_strcpy(char *s1, char *s2);
char *d_strtok(char *str, char *delim, char **new_ptr);
int my_atoi(char *str);
void *my_realloc(void *ptr, size_t prv_size, size_t now_size);
void ctrl_c(int);
void no_cmt(char *sig_val);
int our_strspn(char *s1, char *s2);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *s1, char *s2);
int my_strcspn(char *s1, char *s2);
char *d_str(char *s1, char s2);
int give_cmd(char *cmd);
void do_cmd(char **cmd_toks, int cmd_typ);
char *path_check(char *cmd);
void (*get_func(char *cmd))(char **);
char *find_environ(char *pt);
void my_env(char **cmd_toks);
void out(char **cmd_toks);
extern void no_talk(void);
extern void start(char **recent_command, int type_command);

#endif
