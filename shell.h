#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include "main.h"

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*---PROTOTYPES---*/
/* main.c */
void ctrlc(int ctr_c __attribute__((unused)));

/* shell_interactive.c */
char *gtinput(void);
char **toknise(char *str);
int exct(char **args);

/* execute_args */
int start_fork(char **args);
int is_absolute_path(const char *path);
int is_builtin(const char *command);
int execute_builtin(char **args);
int is_command_in_path(const char *command);
char *construct_path(const char *path_token, const char *command);
int my_execvp(const char *command, char *const args[]);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(char *str);
int _strcmp(const char *s1, const char *s2);

/* shell_no_interactive */

/*---Builtin func---*/
int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int _atoi(char *s);

/*--STRUCTURES--*/

/**
 * struct BuiltinFunction - select the collect builitin function
 * @name: name of command
 * @func: function corresponding to the name
 */

typedef struct BuiltinFunction
{
	const char *name;
	int (*func)(char **);
} BuiltinFunction;

#endif
